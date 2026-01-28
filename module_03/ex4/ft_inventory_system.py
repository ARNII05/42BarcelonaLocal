import sys


class Item:
    def __init__(self, name: str, values: int):
        self.name: str = name
        self.type: str = name
        self.values: int = values
        self.quantity: int = 0

    def get_name(self) -> str:
        return self.name

    def get_type(self) -> int:
        return self.type

    def get_values(self) -> int:
        return self.values

    def get_quantity(self) -> int:
        return self.quantity

    def set_quantity(self, add: int) -> None:
        self.quantity += add

    def set_values(self, add: int) -> None:
        self.values += add


class Inventory:
    def __init__(self):
        self.inventory: dict[str, Item] = {}
        self.total_items: int = 0
        self.unique_types: int = 0

    def add_item(self, item: Item):
        actual_name: str = item.get_name()
        actual_item: Item = self.inventory.get(actual_name)
        if actual_item is None:
            self.inventory.update({actual_name: item})
            self.unique_types += 1
        else:
            actual_item.set_values(item.get_values())

    def get_total_items(self) -> int:
        self.total_items = 0
        for item in self.inventory.values():
            self.total_items += item.get_values()
        return self.total_items

    def get_unique(self) -> int:
        return self.unique_types

    def most_value(self) -> Item:
        new_item: Item = None
        max: int = 0
        for item in self.inventory.values():
            if item.get_values() > max:
                new_item = item
                max = item.get_values()
        return new_item

    def least_value(self, max: int) -> Item:
        new_item: Item = None
        min: int = max
        for item in self.inventory.values():
            if item.get_values() < min:
                new_item = item
                min = item.get_values()
        return new_item

    def statistics(self) -> None:
        print("\n=== Inventory Statistics ===")
        most_item: Item = self.most_value()
        least_item: Item = self.least_value(most_item.get_values())
        print("Most abundant: ", end="")
        print(f"{most_item.get_name()} ({most_item.get_values()})")
        print("Least abundant: ", end="")
        print(f"{least_item.get_name()} ({least_item.get_values()})")

    def item_percert(self, value: int) -> float:
        total: int = self.get_total_items()
        percent_w_total: float = total / value
        return 100 / percent_w_total

    def print_inventory(self) -> None:
        print("\n=== Current Inventory ===")
        for name, item in self.inventory.items():
            values: int = item.get_values()
            percent: float = self.item_percert(values)
            print(f"{name}: {values} units ({percent:.1f}%)")

    def check_values(self) -> None:
        moderate: dict[str, Item] = {}
        scare: dict[str, Item] = {}
        print("\n=== Item Categories ===")
        for item in self.inventory.values():
            if self.item_percert(item.get_values()) >= 30:
                moderate[item.get_name()] = item.get_values()
            else:
                scare[item.get_name()] = item.get_values()
        print(f"Moderate: {moderate}")
        print(f"Scare: {scare}")

    def suggestions(self) -> None:
        print("\n=== Management Suggestions ===")
        restock: list[str] = []
        for name in self.inventory.keys():
            item: Item = self.inventory.get(name)
            if item.get_values() <= 1:
                restock.append(name)
        print(f"Restock needed: {restock}")

    def analysis(self) -> None:
        print("=== Inventory System Analysis ===")
        print(f"Total items in inventory: {self.get_total_items()}")
        print(f"Unique item types: {self.get_unique()}")

    def propierties(self, name_check: str) -> None:
        print("\n=== Dictionary Properties Demo ===")
        keys: list[str] = []
        values: list[int] = []
        item_check: Item = self.inventory.get(name_check)
        for name in self.inventory.keys():
            keys.append(name)
        for value in self.inventory.values():
            values.append(value.get_values())
        print(f"Dictionary keys: {keys}")
        print(f"Dictionary values: {values}")
        print(f"Sample lookup - '{name_check}' in inventory: ", end="")
        if item_check is None:
            print("False")
        else:
            print("True")


def get_point_index(argv: str) -> int:
    i: int = 0
    while i < len(argv):
        if argv[i] == ':':
            return i
        i += 1
    return -1


def add_items(argv: list[str], items: Inventory) -> bool:
    i: int = 0
    point_index: int = 0
    try:
        while i < len(argv):
            point_index = get_point_index(argv[i])
            name: str = argv[i][0:point_index]
            value: int = int(argv[i][point_index + 1:])
            if point_index == -1:
                raise ValueError("Incorrect format of argv")
            items.add_item(Item(name, value))
            i += 1
    except ValueError as e:
        print(f"Error: {e}")
        print("Correct format for each argv: item_name:value")
        return False
    return True


def init_items() -> None:
    items: Inventory = Inventory()
    if len(sys.argv) < 2:
        print("Error: No arguments given")
        return
    if add_items(sys.argv[1:], items):
        items.analysis()
        items.print_inventory()
        items.statistics()
        items.check_values()
        items.suggestions()
        items.propierties("sword")


if __name__ == "__main__":
    init_items()
