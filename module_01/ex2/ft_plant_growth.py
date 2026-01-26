class Plant:
    """
    Class to Manage each Plant specs
    """

    def __init__(self, name: str, height: str, age: str) -> None:
        """
        innit Plant
        """
        self.name: str = name
        self.height: str = height
        self.age: str = age

    def show_info(self, days: int) -> None:
        """
        show info and simulate a week of growth
        """

        name: str = self.name.capitalize()
        total_height: int = int(self.height) + days
        total_age: int = int(self.age) + days
        print(f"{name}: {total_height}cm, {total_age} years old")


def init_plant() -> None:
    """
    Init all plants
    """
    plant_1: Plant = Plant("Lirio", "10", "200")
    print("=== Day 1 ===")
    plant_1.show_info(1)
    print("=== Day 7 ===")
    plant_1.show_info(7)


if __name__ == "__main__":
    init_plant()
