#!/usr/bin/env python3
"""
daily_solver.py - Automated UPES 100 Days of Code Daily Solver
Generates C solution files, updates README.md, and creates backdated git commits.
"""

import os
import sys
import re
import argparse
import subprocess
from datetime import datetime, date, timedelta, timezone

# Add script directory to sys.path to import solutions_data
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.abspath(os.path.join(SCRIPT_DIR, ".."))
if SCRIPT_DIR not in sys.path:
    sys.path.insert(0, SCRIPT_DIR)

from solutions_data import SOLUTIONS

# IST Timezone (UTC +5:30)
IST = timezone(timedelta(hours=5, minutes=30))
START_DATE = date(2026, 8, 10)
BREAK_START = date(2026, 9, 7)
BREAK_END = date(2026, 9, 10)

GIT_AUTHOR_NAME = "amb3r04"
GIT_AUTHOR_EMAIL = "amberchaurasia418@outlook.com"


def get_current_ist_date():
    return datetime.now(IST).date()


def date_to_day(d):
    """Calculates the challenge day number for a given calendar date."""
    if d < START_DATE:
        return 0
    if BREAK_START <= d <= BREAK_END:
        return 28
    days_elapsed = (d - START_DATE).days
    if d < BREAK_START:
        return days_elapsed + 1
    else:
        return days_elapsed + 1 - 4


def day_to_date(day):
    """Calculates the calendar date for a given challenge day."""
    if day <= 28:
        return START_DATE + timedelta(days=day - 1)
    else:
        return START_DATE + timedelta(days=day - 1 + 4)


def find_highest_day(repo_root):
    """Finds the highest challenge day currently implemented in the repository."""
    pattern = re.compile(r"^day(\d+)_")
    highest = 0
    for fname in os.listdir(repo_root):
        m = pattern.match(fname)
        if m:
            d = int(m.group(1))
            if d > highest:
                highest = d
    return highest


def calculate_total_problems(day):
    """Calculates total problems completed up to day N."""
    if day <= 50:
        return day * 2
    else:
        return 100 + (day - 50)


def update_readme(repo_root, day, day_date, filename, topic):
    """Updates README.md with new progress count and adds day entry to table."""
    readme_path = os.path.join(repo_root, "README.md")
    if not os.path.exists(readme_path):
        print(f"Warning: README.md not found at {readme_path}")
        return

    with open(readme_path, "r", encoding="utf-8") as f:
        content = f.read()

    total_problems = calculate_total_problems(day)

    # 1. Update progress line
    progress_pattern = r"(> \*\*Current Progress:\*\* \*\*Day )\d+( / 100\*\* \()\d+( problems completed\))"
    content = re.sub(
        progress_pattern,
        rf"\g<1>{day}\g<2>{total_problems}\g<3>",
        content
    )

    # 2. Add row to schedule table
    date_str = day_date.strftime("%d %b %Y")
    day_str = f"Day {day:02d}"
    new_row = f"| **{day_str}** | {date_str} | `{filename}` | {topic} |"

    # Avoid duplicate table row if already present
    if f"**{day_str}**" not in content:
        # Find where the table ends (before the --- separator following the table)
        # Search for the last table row
        lines = content.splitlines()
        last_table_idx = -1
        for i, line in enumerate(lines):
            if line.strip().startswith("|") and line.strip().endswith("|"):
                last_table_idx = i

        if last_table_idx != -1:
            lines.insert(last_table_idx + 1, new_row)
            content = "\n".join(lines) + "\n"
        else:
            print("Warning: Could not locate table in README.md")

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(content)


def commit_day(repo_root, day, day_date, filename, q_id, dry_run=False):
    """Creates a backdated git commit for the given day."""
    if dry_run:
        print(f"[DRY-RUN] Would commit Day {day} ({filename}, README.md) on {day_date}")
        return

    date_iso = f"{day_date.isoformat()} 09:30:00 +0530"
    commit_msg = f"Add solution for Day {day} (Q{q_id})"

    env = os.environ.copy()
    env["GIT_AUTHOR_NAME"] = GIT_AUTHOR_NAME
    env["GIT_AUTHOR_EMAIL"] = GIT_AUTHOR_EMAIL
    env["GIT_AUTHOR_DATE"] = date_iso
    env["GIT_COMMITTER_NAME"] = GIT_AUTHOR_NAME
    env["GIT_COMMITTER_EMAIL"] = GIT_AUTHOR_EMAIL
    env["GIT_COMMITTER_DATE"] = date_iso

    # Git add
    file_path = os.path.join(repo_root, filename)
    readme_path = os.path.join(repo_root, "README.md")
    subprocess.run(["git", "add", file_path, readme_path], cwd=repo_root, check=True)

    # Git commit
    subprocess.run(
        ["git", "commit", "-m", commit_msg],
        cwd=repo_root,
        env=env,
        check=True
    )
    print(f"Committed Day {day} (Q{q_id}) with timestamp {date_iso}")


def process_days(target_day=None, dry_run=False):
    """Main routine: detects current day, generates missing files, and commits them."""
    current_ist = get_current_ist_date()
    calculated_day = date_to_day(current_ist)

    # Allow environment variable or argument override
    env_target = os.environ.get("TARGET_DAY", "").strip()
    if env_target.isdigit():
        target = int(env_target)
    elif target_day is not None:
        target = target_day
    else:
        target = calculated_day

    target = min(target, 100)
    highest_day = find_highest_day(REPO_ROOT)

    print(f"Current Date (IST): {current_ist}")
    print(f"Calculated Challenge Day: {calculated_day}")
    print(f"Target Day: {target}")
    print(f"Highest Day in Repo: {highest_day}")

    if highest_day >= target:
        print(f"Repository is up to date (Day {highest_day} >= Target Day {target}). Nothing to do.")
        return 0

    committed_count = 0
    for day in range(highest_day + 1, target + 1):
        if day not in SOLUTIONS:
            print(f"Error: Solution for Day {day} not found in database!")
            break

        sol_info = SOLUTIONS[day]
        q_id = sol_info["q_id"]
        filename = sol_info["filename"]
        topic = sol_info["topic"]
        source_code = sol_info["source"]
        day_date = day_to_date(day)

        print(f"--- Processing Day {day} (Q{q_id}) for {day_date} ---")

        # 1. Write C solution file
        out_file = os.path.join(REPO_ROOT, filename)
        if not dry_run:
            with open(out_file, "w", encoding="utf-8") as f:
                f.write(source_code)

        # 2. Update README.md
        if not dry_run:
            update_readme(REPO_ROOT, day, day_date, filename, topic)

        # 3. Create git commit
        commit_day(REPO_ROOT, day, day_date, filename, q_id, dry_run=dry_run)
        committed_count += 1

    print(f"Successfully processed {committed_count} day(s).")
    return committed_count


def main():
    parser = argparse.ArgumentParser(description="UPES 100 Days of Code Daily Solver")
    parser.add_argument("--day", type=int, default=None, help="Force target day number")
    parser.add_argument("--dry-run", action="store_true", help="Simulate without writing or committing")
    args = parser.parse_args()

    process_days(target_day=args.day, dry_run=args.dry_run)


if __name__ == "__main__":
    main()
