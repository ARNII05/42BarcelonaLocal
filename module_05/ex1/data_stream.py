from typing import Any, List, Dict, Union, Optional
from abc import ABC, abstractmethod

class DataStream(ABC):
    def __init__(self):
        super().__init__()

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] 
                    = None) -> List[Any]:
        pass

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        pass


class SensorStream(DataStream):
    def __init__(self, stream_id: int):
        super().__init__()
        self.strem_id: int = stream_id

    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] 
                    = None) -> List[Any]:
        pass

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        pass


class TransactionStream(DataStream):
    def __init__(self, stream_id: int):
        super().__init__()
        self.strem_id: int = stream_id

    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] 
                    = None) -> List[Any]:
        pass

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        pass


class EventStream(DataStream):
    def __init__(self, stream_id: int):
        super().__init__()
        self.strem_id: int = stream_id

    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] 
                    = None) -> List[Any]:
        pass

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        pass


class StreamProcessor():
    def __init__(self, stream: DataStream):
        super().__init__()
        self.stream: DataStream = stream