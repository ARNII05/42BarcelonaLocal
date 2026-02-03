from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        pass


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        self.nbr: list[int] = []
        self.validation: bool = True
        self.count: int = 0
        print("\nInitializing Numeric Processor...")

    def sum_(self, data) -> int:
        total: int = 0
        for n in data:
            total += n
        return total

    def process(self, data: Any) -> str:
        result: str = "Error processing data"
        try:
            print(f"Procesing data: {data}")
            if self.validate(data):
                sum_n: int = self.sum_(data)
                avg: int = sum_n / self.count
                op: str = f"sum={sum_n}, avg={avg:.1f}"
                result = f"{self.count} numeric values, {op}"
                print("Validation: Numeric data validated")
            else:
                print("Data is not numeric")
        except Exception as e:
            return f"{e}"
        finally:
            return self.format_output(result)

    def validate(self, data: Any) -> bool:
        try:
            for n in data:
                self.nbr.append(n + 0)
                self.count += 1
            return self.count > 0
        except Exception:
            return False

    def format_output(self, result: str) -> str:
        return f"Output: Processed: {result}"


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        self.words: int = 1
        self.chars: int = 0
        print("\nInitializing Text Processor...")

    def process(self, data: Any) -> str:
        result: str = "No text given"
        try:
            print("Processing data: ", end="")
            if self.validate(data):
                print(f"{data}")
                result = f"{self.chars} characters, {self.words} words"
            else:
                print("Data is not a String")
        except Exception as e:
            return f"Error: {e}"
        finally:
            print("Validation: Text data verified")
            return self.format_output(result)

    def validate(self, data: Any) -> bool:
        try:
            for n in data:
                _ = n + '0'
                if n == " ":
                    self.words += 1
                self.chars += 1
            return True
        except Exception:
            return False

    def format_output(self, result: str) -> str:
        return f"Output: Processed text: {result}"


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        print("\nInitializing Log Processor...")

    def process(self, data: Any) -> str:
        result: str = "Data is not a log type"
        try:
            print("Processing data: ", end="")
            if self.validate(data):
                print(f"{data}")
                print("Validation: Log entry verified")
                if "ERROR" in data:
                    result = f"[ALERT] level detected {data}"
                else:
                    result = f"[INFO] level detected {data}"
            else:
                print("Valid data -> [INFO/ERROR]: info")
                print("Validation: Data is not a valid log")
        except Exception as e:
            print(f"ERROR: {e}")
        finally:
            return self.format_output(result)

    def validate(self, data: Any) -> bool:
        if ":" not in data:
            return False
        if "ERROR" not in data and "INFO" not in data:
            return False
        return True

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


def init_classes() -> None:
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
    data: list[int] = [1, 2, 7]
    string: str = "Hello Nexus World"
    log_text: str = "INFO: Connection timeout"
    nbr: NumericProcessor = NumericProcessor()
    print(nbr.process(data))
    text: TextProcessor = TextProcessor()
    print(text.process(string))
    log: LogProcessor = LogProcessor()
    print(log.process(log_text))


if __name__ == "__main__":
    init_classes()
