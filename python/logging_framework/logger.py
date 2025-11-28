from typing import TYPE_CHECKING, List
from typing import Optional

from log_appender import ConsoleAppender, FileAppender, LogAppender
from log_level import LogLevel
from log_message import LogMessage


# if TYPE_CHECKING:
#     from log_manager_local import LogManager



class Logger:

    def __init__(self, name : str, parent : Optional['Logger']):
        self.name = name
        self.level = None
        self.parent= parent
        self.appenders: List[LogAppender] = []
        self.additivity = True

    
    def add_appender(self, appender: LogAppender):
        self.appenders.append(appender)

    def get_appenders(self) -> List[LogAppender]:
        return self.appenders

    def get_effective_level(self):
        logger = self
        while logger is not None:
            if logger.level is not None:
                return logger.level
            logger = logger.parent
        
        return LogLevel.DEBUG #default level

    def log(self, messageLevel : LogLevel, message : str):
        if messageLevel.isGreaterOrEqual(self.get_effective_level()):
            logMessage = LogMessage(messageLevel, self.name, message)
            self._call_appenders(logMessage)


    def _call_appenders(self, logMessage : LogMessage):
        if self.appenders:
            from custom_log_manager import LogManager
            LogManager.get_instance().get_processor().process(logMessage,self.appenders)

    
    def debug(self,message:str):
        self.log(LogLevel.DEBUG, message)

    def warn(self, message:str):
        self.log(LogLevel.WARN, message)

    def info(self, message:str):
        self.log(LogLevel.INFO, message)
    
    def error(self, message:str):
        self.log(LogLevel.ERROR, message)
    
    def fatal(self, message:str):
        self.log(LogLevel.FATAL, message)



    
def main():
    logger = Logger(name = 'main', parent=None)
    logger.add_appender(ConsoleAppender())
    logger.add_appender(FileAppender(file_path='/Users/ankit/repo/lld/python/logging_framework/logFile.txt'))
    logger.debug("Hello")
    logger.error("New")

if __name__ == "__main__":
    main()


#check why _lock is not working, and impelement demo file.
# it is acquiring the lock and never releasing it.



#implement _callAppender, then move on to logMaanger and demo , it should take 2 sessions at max.

# diagnose abstract format method error.
