from engine.base import Base
from utils.decorators.ensure_valid_token import ensure_valid_token
import requests
from utils.calculate_log_time import calculate_duration, total_duration

class LogTime(Base):
    user_url = "https://api.intra.42.fr/v2/users/"
    locations_url = "https://api.intra.42.fr/v2/locations/"

    def __init__(self):
        super().__init__()
    
    @ensure_valid_token
    def get_user(self):
        url = f"{self.user_url}/rabounou"
        res = requests.get(
            url=url,
            headers={
                "Authorization": "{} {}".format(self.token_type, self.access_token)
            }
        )
        if res.status_code == 200:
            return res.json()
        else:
            self.logger.error(f"GET {url} [{res.status_code}]")
            return None

    @ensure_valid_token
    def get_locations(self):
        res = requests.get(
            url=self.locations_url,
            headers={
                "Authorization": "{} {}".format(self.token_type, self.access_token)
            },
            params={
                "user_id": "rabounou",
                "sort": "-begin_at",
                "range[begin_at]": "2025-06-27,2025-07-27"
            }
        )
        if res.status_code == 200:
            return res.json()
        else:
            self.logger.error(f"GET {self.locations_url} [{res.status_code}]")
            return None

    def get_log_time(self):
        data = self.get_locations()
        if data is None:
            return 
        return total_duration(data)
    
# def logtime_check(token, user_id):
#     current = timedelta()
#     time_format = "%Y-%m-%dT%H:%M:%S.%fZ"
#     scholar_ship_start_at = datetime.strptime("2025-02-24T00:00:00.000Z", time_format)
#     date = load_date()
#     print(date)
#     date = datetime.strptime(date, "%Y-%m-%dT%H:%M:%S.%fZ")
#     location_resp = requests.get(
#         f"https://api.intra.42.fr/v2/users/{user_id}/locations?page[number]=1&page[size]=100",
#         headers={"Authorization": f"Bearer {token}"}
#     )
#     location_list = location_resp.json()
#     for loc in location_list:
#         if loc['end_at'] == None:
#             continue
#         end_at = datetime.strptime(loc['end_at'], time_format)
#         begin_at = datetime.strptime(loc['begin_at'], time_format)
#         if (begin_at <= date):#scholar_ship_start_at):
#             break
#         current += end_at - begin_at
#     logtime = current.total_seconds() / 3600
#     logtime_rounded = round(logtime, 2)
#     print(round(logtime, 2))
#     return logtime_rounded