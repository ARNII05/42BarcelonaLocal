class Plant:
    def __init__(self, name: str, height: str, age: str) -> None:
        self.name: str = name
        self.height: str = height
        self.age: str = age

    def show_info(self) -> None:
        name: str = self.name.capitalize()
        total_height = int(self.height)
        total_age = int(self.age)
        print(f"Created: {name} ({total_height}cm, {total_age} days)")


def init_plant() -> None:
    plant_1 = Plant("Rose", "25", "30")
    plant_2 = Plant("Oak", "200", "265")
    plant_3 = Plant("Cactus", "5", "90")
    plant_4 = Plant("Sunflower", "80", "45")
    plant_5 = Plant("Fern", "15", "120")
    plant_1.show_info()
    plant_2.show_info()
    plant_3.show_info()
    plant_4.show_info()
    plant_5.show_info()
    print("\nTotal plants created:", 5)


if __name__ == "__main__":
    init_plant()
