import threading
from typing import Dict
from async_log_processor import AsyncLogProcessor

class LogManager:
    _instance = None
    _lock = threading.Lock()
    
    def __init__(self):
        if LogManager._instance is not None:
            raise Exception("This class is singleton")

        from logger import Logger  # Lazy import
        self.loggers: Dict[str, Logger] = {}
        self.root_logger = Logger("root", None)
        self.loggers['root'] = self.root_logger
        self.processor = AsyncLogProcessor()
    
    @staticmethod
    def get_instance():
        if LogManager._instance is None:
            with LogManager._lock:
                    LogManager._instance = LogManager()
        
        return LogManager._instance
    
    def get_logger(self, name):
        if self.loggers.get(name) is not None:
            return self.loggers[name]
        
        return self.create_logger(name)
    
    def create_logger(self, name: str):
        from logger import Logger  # Lazy import
        if name == 'root':
            return self.root_logger
        
        last_dot = name.rfind('.')
        parent_name = 'root' if last_dot == -1 else name[:last_dot]
        parent = self.get_logger(parent_name)

        self.loggers[name] = Logger(name, parent)
        print(f"Created logger {name}")
        return self.loggers[name]
    
    def get_processor(self) -> AsyncLogProcessor:
        return self.processor

    def shutdown(self):
        self.processor.shutDown()

        for logger in self.loggers.values():
            for appender in logger.appenders:
                appender.close()
            
        print("Logger Framework shutdown gracefully")


        
    # each logger has own appenders and there is only one processor created by log manager, 

    #implement shut_down method, complete small fucntions in logger, and move to demo, try to complete by next session
    # I should try the chunk the solution and key learnings like singleton pattern, multithreading,etc

# def main():
#     instance = LogManager.get_instance()
#     print(instance.get_logger("aisehi").parent.name)


# main()


