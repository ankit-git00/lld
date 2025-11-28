from log_level import LogLevel
from datetime import datetime
import threading

class LogMessage:
    def __init__(self, level : LogLevel, logger_name : str, message : str):
        self.level = level
        self.logger_name= logger_name
        self.message = message
        self.timestamp = datetime.now()
        self.thread_name = threading.current_thread().name


    def get_message(self) -> str:
        return self.message


    def get_level(self) -> LogLevel:
        return self.level


    def get_timestamp(self) -> str:
        return self.timestamp

    def get_logger_name(self) -> str:
        return self.logger_name
    

    def get_thread_name(self) -> str:
        return self.thread_name
    




