import os
import subprocess
from datetime import datetime, timedelta, timezone

# Assumes each .cpp file is in a folder representing the question.
# Update logic if your repo structure changes.

def get_first_commit_date(filepath):
    try:
        result = subprocess.run(
            ["git", "log", "--diff-filter=A", "--follow", "--format=%cI", "--", filepath],
            stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=True
        )
        date_str = result.stdout.strip().split('\n')[0]
        return datetime.strptime(date_str[:10], "%Y-%m-%d").date() if date_str else None
    except Exception:
        return None

questions = []
for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".cpp"):
            rel_path = os.path.relpath(os.path.join(root, file), ".")
            folder = os.path.basename(os.path.dirname(rel_path))
            question_name = folder
            commit_date = get_first_commit_date(rel_path)
            if commit_date:
                questions.append((question_name, commit_date))

today = datetime.now(timezone.utc).date()

# Use a range to avoid missing questions if workflow timing is off
week_range = [today - timedelta(days=d) for d in range(6, 9)]    # 6, 7, 8 days ago
month_range = [today - timedelta(days=d) for d in range(27, 30)] # 27, 28, 29 days ago

week_review = [q for q, d in questions if d in week_range]
month_review = [q for q, d in questions if d in month_range]

with open("reminder.md", "w") as f:
    f.write("# DSA Questions Review Reminder\n\n")
    f.write(f"## Questions to review (about 1 week ago):\n\n")
    if week_review:
        f.write("| Question |\n|---|\n")
        for q in week_review:
            f.write(f"| {q} |\n")
    else:
        f.write("_No questions to review for 1 week interval._\n")

    f.write(f"\n## Questions to review (about 1 month ago):\n\n")
    if month_review:
        f.write("| Question |\n|---|\n")
        for q in month_review:
            f.write(f"| {q} |\n")
    else:
        f.write("_No questions to review for 1 month interval._\n")
