import requests
import os
import logging
# curl -H "Authorization: Bearer YOUR_ACCESS_TOKEN" https://api.intra.42.fr/oauth/token/info




class Base:
    URL: str = "https://api.intra.42.fr/oauth/token"
    URL_DATA: str = "grant_type=client_credentials&client_id={}&client_secret={}"
    user_uid = os.getenv("USER_UID")
    user_sec = os.getenv("USER_SEC")
    
    access_token: str = None
    token_type: str = None

    def check_token_state(self) -> bool:
        if not all([self.user_uid, self.user_sec, self.access_token, self.token_type]):
            return False
        res = requests.get(
            url="{}/info".format(self.URL),
            headers={
                "Authorization": "{} {}".format(self.token_type, self.access_token)
            }
        )
        if res.status_code == 200:
            print("token is valid")
            return True
        else:
            print("Token not valid")
            return False


    def __init__(self):
        self.logger = logging.getLogger(self.__class__.__name__)
        self.logger.setLevel(logging.DEBUG)

        # Create file handler which logs messages to a file
        file_handler = logging.FileHandler('42.log')
        file_handler.setLevel(logging.DEBUG)

        # Create a formatter and set it for the handler
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        file_handler.setFormatter(formatter)

        # Add the handler to the logger
        self.logger.addHandler(file_handler)

        self.user_uid = os.getenv("USER_UID")
        self.user_sec = os.getenv("USER_SEC")
        # self.get_credentional()

    def get_credentional(self) -> None:
        res = requests.post(
            url=self.URL,
            data=self.URL_DATA.format(self.user_uid, self.user_sec))
        if res.status_code == 200:
            res_json = res.json()
            self.access_token = res_json["access_token"]
            self.token_type = res_json["token_type"]
            self.logger.info("POST {} [{}]".format(self.URL, res.status_code))
            return True
        else:
            self.logger.error("POST {} [{}]".format(self.URL, res.status_code))
            return False
