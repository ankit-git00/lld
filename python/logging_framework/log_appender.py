from log_message import LogMessage
from abc import ABC
from log_formatter import SimpleTextFormatter
from log_formatter import LogFomatter
import threading


class LogAppender(ABC):
    def append(self, message: LogMessage):
        pass

    def set_formatter(self, formatter : LogFomatter):
        pass

    def close(self):
        pass


class ConsoleAppender(LogAppender):

    def __init__(self):
        self.formatter = SimpleTextFormatter()

    def append(self, message: LogMessage):
        print(self.formatter.format(message), end = '')
    
    def close():
        pass

    def set_formatter(self, formatter):
        self.formatter = formatter


class FileAppender(LogFomatter):

    def __init__(self, file_path : str):
        self.formatter = SimpleTextFormatter()
        self._lock = threading.Lock()

        try:
            self.writer = open(file_path, 'a')
        except Exception as e:
            print(f"Unable to create file to append logs, file_path : {file_path}",e)

    def append(self, message : LogMessage):
        with self._lock:
            if self.writer:
                try:
                    self.writer.write(self.formatter.format(message) + "\n")
                    self.writer.flush()
                except Exception as e:
                    print("Unable to write to the file", e)
    
    def close(self):
        if self.writer:
            try:
                self.writer.close()
            except Exception as e:
                print("Unable to close file", e)
    
    def set_formatter(self,formatter):
        self.formatter = formatter


