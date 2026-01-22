class Plant:
    def __init__(self, name: str, height: str, age: str) -> None:
        self.name: str = name
        self.height: str = height
        self.age: str = age

    def show_info(self) -> None:
        name: str = self.name.capitalize()
        print(f"{name}: {self.height}cm, {self.age} years old")


def init_plant() -> None:
    plant_1 = Plant("Rose", "25", "30")
    plant_2 = Plant("Sunflower", "80", "45")
    plant_3 = Plant("Cactus", "15", "120")
    plant_1.show_info()
    plant_2.show_info()
    plant_3.show_info()


if __name__ == "__main__":
    init_plant()
