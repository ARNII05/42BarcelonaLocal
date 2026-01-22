class Plant:
    def __init__(self, name: str, height: str, age: str) -> None:
        self.name: str = name
        self.height: str = height
        self.age: str = age

    def show_info(self, days: int) -> None:
        name: str = self.name.capitalize()
        total_height = int(self.height) + days
        total_age = int(self.age) + days
        print(f"{name}: {total_height}cm, {total_age} years old")


def init_plant() -> None:
    plant_1: Plant = Plant("Lirio", "10", "200")
    print("=== Day 1 ===")
    plant_1.show_info(1)
    print("=== Day 7 ===")
    plant_1.show_info(7)


if __name__ == "__main__":
    init_plant()
