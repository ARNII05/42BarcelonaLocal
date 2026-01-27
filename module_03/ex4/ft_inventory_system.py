class Item:
    def __init__(self, name: str, type: str, values: int, quantity: int):
        self.name = name
        self.type = type
        self.values = values
        self.quantity = quantity

    def get_name(self) -> str:
        return self.name