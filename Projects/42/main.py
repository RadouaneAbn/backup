#!/bin/env python3

from engine.logtime import LogTime
from dotenv import load_dotenv
from utils.json_op import load, save

load_dotenv()

if __name__ == "__main__":
    logtime = LogTime()
    data = logtime.get_log_time()
    print(data)