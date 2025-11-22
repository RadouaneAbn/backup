from datetime import datetime, timezone, timedelta

def calculate_duration(begin_at: str, end_at: str) -> timedelta:
    fmt = "%Y-%m-%dT%H:%M:%S.%fZ"
    begin_dt = datetime.strptime(begin_at, fmt).replace(tzinfo=timezone.utc)
    end_dt = datetime.strptime(end_at, fmt).replace(tzinfo=timezone.utc)
    return end_dt - begin_dt  # returns timedelta

def total_duration(intervals: list) -> timedelta:
    total = timedelta()  # zero duration
    for interval in intervals:
        duration = calculate_duration(interval["begin_at"], interval["end_at"])
        total += duration
    return total