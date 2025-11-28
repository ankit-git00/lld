from log_appender import LogAppender   
from log_message import LogMessage
from concurrent.futures import ThreadPoolExecutor
from typing import List


class AsyncLogProcessor:
    def __init__(self):
        self.executors = ThreadPoolExecutor(max_workers=1, thread_name_prefix='async_log_processor')
        self.shutdown_flag = False

    def process(self, logMessage : LogMessage, appenders : List[LogAppender]):
        if(self.shutdown_flag):
            print("Processor is shut down, cannot process message")
            return
        
        def process_task():
            for appender in appenders:
                appender.append(logMessage)
            
        self.executors.submit(process_task)

    def shutDown(self):
        self.shutdown_flag = False
        self.executors.shutdown(wait=True)

        if not self.executors._shutdown:
            print("Unable to shut down processor")
        


# need to work on log processer and logger class
