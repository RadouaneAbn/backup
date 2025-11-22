def ensure_valid_token(func):
    def wrapper(self, *args, **kwargs):
        if not self.check_token_state():
            self.logger.info("creating new token")
            self.get_credentional()
        return func(self, *args, **kwargs)
    return wrapper