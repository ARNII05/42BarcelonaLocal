from typing import Any, List, Dict, Union, Optional
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
        print("\nInitializing Numeric Processor..")

    @abstractmethod
    def process(self, data: Any) -> str:
       if self.validate(data):
        return f"Procesing data: {data}"

    @abstractmethod
    def validate(self, data: Any) -> bool:
        print("Validation: Numeric data verified")
        return True

    def format_output(self, result: str) -> str:
        return result


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        print("\nInitializing Text Processor..")

    @abstractmethod
    def process(self, data: Any) -> str:
        return f"Procesing data: {data}"

    @abstractmethod
    def validate(self, data: Any) -> bool:
        print("Validation: Text data verified")
        return True

    def format_output(self, result: str) -> str:
        return result


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        print("\nInitializing Log Processor..")

    @abstractmethod
    def process(self, data: Any) -> str:
        print()

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return result