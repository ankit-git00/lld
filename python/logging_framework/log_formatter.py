from abc import ABC, abstractmethod

from log_message import LogMessage
from log_level import LogLevel


class LogFomatter(ABC):
    @abstractmethod  # used for inheritance, child classes have to implement this method, can't be used directly in this class.
    def format(self, log_message: LogMessage):
        pass


class SimpleTextFormatter(LogFomatter):

    def format(self, log_message : LogMessage) -> str:
        return f"{log_message.get_timestamp()} [{log_message.get_thread_name()}] [{log_message.get_level()}] - {log_message.get_logger_name()} : {log_message.get_message()}"



# completed formatter and log message, need to work on processor next.



# def main():
#     logMessage = LogMessage(LogLevel.DEBUG, "Main", "Testing")

#     print(logMessage.get_message())

# main()



    
