from custom_log_manager import LogManager
from log_level import LogLevel
from log_appender import ConsoleAppender
import time

def main():

    log_manager = LogManager.get_instance()
    root_logger = log_manager.get_logger('root')
    root_logger.set_level(LogLevel.INFO)
    root_logger.add_appender(ConsoleAppender())

    print("------Initial Logging Demo------")
    main_logger = log_manager.get_logger("com.example.Main")
    main_logger.info("Info Test")
    main_logger.debug("Warn Tesst")


    service_logger = log_manager.get_logger("com.example.service.UserService")
    service_logger.set_level(LogLevel.DEBUG)  # More verbose logging for this specific service
    service_logger.info("User service starting.")
    service_logger.debug("This debug message SHOULD now appear for the service logger.")

    print("\n--- Dynamic Configuration Demo ---")
    print("Changing root log level to DEBUG...")
    root_logger.set_level(LogLevel.DEBUG)
    main_logger.debug("This debug message should now be visible.")

    try:
            time.sleep(0.5)
            log_manager.shutdown()
    except Exception as e:
            print(f"Caught exception : {e}")

main()


# what did I learn from the low level design of logging framework : 
#     1. singleton Pattern , only one instance of log manager is created.
#     2. multithreading and thread lock, fileAppender is using a thread lock , since multiple append call can be made to the same file
#     3. abstract class , define the methods that need to be implemented, concrete implementation of that class should implement these methods.