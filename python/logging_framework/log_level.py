from enum import Enum
class LogLevel(Enum):
    DEBUG = 1
    INFO = 2
    WARN = 3
    ERROR = 4
    FATAL = 5

    def isGreaterOrEqual(self, other:'LogLevel') ->bool:
        return self.value >= other.value

    
def main():
    LogLevelA = LogLevel(2)
    LogLevelB = LogLevel(2)
    print(LogLevelA.isGreaterOrEqual(LogLevelB))

# main()

    

