import os
import time
import re
import subprocess
import sys
from datetime import datetime, timedelta

def get_folder_commit_date(base_path, folder):
    folder_path = os.path.join(base_path, folder)
    try:
        result = subprocess.run(
            ["git", "log", "--diff-filter=A", "--follow", "--format=%aI", "--", folder_path],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        date_str = result.stdout.strip().splitlines()
        if date_str:
            return datetime.fromisoformat(date_str[0])
    except Exception as e:
        pass
    return None

def get_question_folders(base_path):
    pattern = re.compile(r'^\d+')  # Folder name starts with a number
    folders = []
    for entry in os.scandir(base_path):
        if entry.is_dir() and pattern.match(entry.name) and entry.name != ".git":
            commit_date = get_folder_commit_date(base_path, entry.name)
            if commit_date:
                folders.append((entry.name, commit_date))
    return folders

def format_reminder(folder, revisit_date, period):
    return f"Reminder: Revisit '{folder}' in {period} on {revisit_date.strftime('%Y-%m-%d')}"

def main():
    # Allow optional base path argument for local runs
    if len(sys.argv) > 1:
        base_path = os.path.abspath(sys.argv[1])
    else:
        base_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../"))
    folders = get_question_folders(base_path)
    if not folders:
        print("No folders found.")
        return

    reminders_with_dates = []
    for folder, created_date in folders:
        week_later = created_date + timedelta(weeks=1)
        month_later = created_date + timedelta(days=30)
        two_months_later = created_date + timedelta(days=60)
        reminders_with_dates.append((week_later, folder, "1st review"))
        reminders_with_dates.append((month_later, folder, "2nd review"))
        reminders_with_dates.append((two_months_later, folder, "3rd review"))

    today = datetime.today().date()
    upcoming_reminders = []
    completed_reminders = []
    for revisit_date, folder, review_label in reminders_with_dates:
        days_left = (revisit_date.date() - today).days
        if days_left < 0:
            completed_reminders.append((revisit_date, folder, review_label))
        else:
            upcoming_reminders.append((revisit_date, folder, review_label, days_left))

    upcoming_reminders.sort(key=lambda x: x[0])
    completed_reminders.sort(key=lambda x: x[0])

    # Helper to get files inside a folder (relative to base_path)
    def get_files_in_folder(folder):
        folder_path = os.path.join(base_path, folder)
        files = []
        for entry in os.scandir(folder_path):
            if entry.is_file():
                files.append(entry.name)
        return files

    reminder_file = os.path.join(base_path, "reminders.md")
    with open(reminder_file, "w") as f:
        f.write("# 📅 **DSA Question Revisit Reminders**\n\n")
        f.write("> _Stay sharp! Here are your upcoming revisit reminders._\n\n")
        f.write("| Date | Folder | Files | Review | Days Left |\n")
        f.write("|------|--------|-------|--------|-----------|\n")
        for revisit_date, folder, review_label, days_left in upcoming_reminders:
            date_str = revisit_date.strftime('%Y-%m-%d')
            if days_left == 0:
                days_left_str = "**Today**"
            elif days_left == 1:
                days_left_str = "**Tomorrow**"
            else:
                days_left_str = f"**{days_left} days**"
            folder_path = os.path.join(".", folder)
            files = get_files_in_folder(folder)
            if files:
                files_md = "<br>".join(f"[`{file}`]({os.path.join(folder_path, file)})" for file in files)
            else:
                files_md = "_No files_"
            f.write(f"| {date_str} | [`{folder}`]({folder_path}) | {files_md} | {review_label} | {days_left_str} |\n")

        if completed_reminders:
            f.write("\n## ✅ Completed Reviews\n\n")
            f.write("| Date | Folder | Files | Review |\n")
            f.write("|------|--------|-------|--------|\n")
            for revisit_date, folder, review_label in completed_reminders:
                date_str = revisit_date.strftime('%Y-%m-%d')
                folder_path = os.path.join(".", folder)
                files = get_files_in_folder(folder)
                if files:
                    files_md = "<br>".join(f"[`{file}`]({os.path.join(folder_path, file)})" for file in files)
                else:
                    files_md = "_No files_"
                f.write(f"| {date_str} | [`{folder}`]({folder_path}) | {files_md} | {review_label} |\n")

    print(f"Reminders written to {reminder_file}")

if __name__ == "__main__":
    main()