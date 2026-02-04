from typing import Any, List, Dict, Union, Optional
from abc import ABC, abstractmethod

class DataStream(ABC):
    def __init__(self, stream_id: str, stream_type: str):
        self.stream_id: str = stream_id
        self.stream_type: str = stream_type
        self.total_processed: str = 0

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]:
        try:
            if criteria is None:
                return data_batch
            return [item for item in data_batch if criteria in str(item)]
        except Exception as e:
            print(f"ERROR: {e}")

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "stream_id": self.stream_id,
            "type": self.stream_type,
            "total_processed": self.total_processed
        }

class SensorStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id, "Environmental Data")
        print("\nInitializing Sensor Stream...")
        print(f"Stream ID: {self.stream_id}, Type: {self.stream_type}")

    def process_batch(self, data_batch: List[str]) -> str:
        try:
            values: list[int] = []
            for item in data_batch:
                raw: str = item.split(":")[1]
                values.append(float(raw))
            self.total_processed += len(values)
            avg: float = sum(values) / len(values) if values else 0.0
            return f"Sensor analysis: {len(values)} readings processed, avg: {avg:.1f}"
        except Exception as e:
            print(f"ERROR: {e}")

    def filter_data(self, data_batch: List[str], criteria: Optional[str] = None) -> List[str]:
        try:
            if criteria is None:
                return data_batch
            if criteria == "high":
                return [x for x in data_batch if x.startswith("temp:") and float(x.split(":")[1]) > 30]
            return data_batch
        except Exception as e:
            print(f"ERROR: {e}")

class TransactionStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id, "Financial Data")
        print("\nInitializing Transaction Stream...")
        print(f"Stream ID: {self.stream_id}, Type: {self.stream_type}")

    def process_batch(self, data_batch: List[str]) -> str:
        try:
            net: int = 0
            sign: str = "+"
            for item in data_batch:
                kind: str = item.split(":")[0]
                raw: str = item.split(":")[1]
                amt = int(raw)
                net += amt if kind == "buy" else -amt
            self.total_processed += len(data_batch)
            if (net < 0):
                sign = ""
            return f"Transaction analysis: {len(data_batch)} operations, net flow: {sign}{net} units"
        except Exception as e:
            print(f"ERROR: {e}")

    def filter_data(self, data_batch: List[str], criteria: Optional[str] = None) -> List[str]:
        try:
            if criteria is None:
                return data_batch
            if criteria == "large":
                return [x for x in data_batch if int(x.split(":")[1]) >= 100]
            return data_batch
        except Exception as e:
            print(f"ERROR: {e}")

class EventStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id, "System Events")
        print("\nInitializing Event Stream...")
        print(f"Stream ID: {self.stream_id}, Type: {self.stream_type}")

    def process_batch(self, data_batch: List[str]) -> str:
        try:
            errors: list[str] = [x for x in data_batch if x == "error"]
            self.total_processed += len(data_batch)
            return f"Event analysis: {len(data_batch)} events, {len(errors)} error detected"
        except Exception as e:
            print(f"ERROR: {e}")

class StreamProcessor:
    def __init__(self, streams: List[DataStream]):
        self.streams = streams

    def run_batches(self, batches: List[List[str]]) -> None:
        try:
            print("\n=== Polymorphic Stream Processing ===")
            for i, (stream, batch) in enumerate(zip(self.streams, batches), start=1):
                result: str = stream.process_batch(batch)
                print(f"Batch {i} Result: {result}")
        except Exception as e:
            print(f"ERROR: {e}")

if __name__ == "__main__":
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")
    sensor_list: list[str] = ["temp:22.5", "humidity:65", "pressure:1013"]
    trans_list: list[str] = ["buy:100", "sell:150", "buy:75"]
    event_list: list[str] = ["login", "error", "logout"]
    sensor = SensorStream("SENSOR_001")
    print(f"Processing sensor batch: {sensor_list}")
    print(sensor.process_batch(sensor_list))
    trans = TransactionStream("TRANS_001")
    print(f"Processing transaction batch: {trans_list}")
    print(trans.process_batch(trans_list))
    event = EventStream("EVENT_001")
    print(f"Processing event batch: {event_list}")
    print(event.process_batch(event_list))
    processor = StreamProcessor([sensor, trans, event])
    processor.run_batches([
        ["temp:31.2", "temp:28.0"],
        ["buy:100", "buy:200", "sell:50", "buy:75"],
        ["login", "error", "logout"]
    ])
    print("Stream filtering active: High-priority data only")
    print("Filtered results:", sensor.filter_data(["temp:29", "temp:35"], "high"), trans.filter_data(["buy:50", "buy:200"], "large"))
