class Secure_Plant:
    """
    Class to Manage each Plant specs
    """
    def __init__(self, name: str, height: int, age: int) -> None:
        """
        innit Secure_Plant
        """
        self.name: int = name
        self._height: int = height
        self._age: int = age

    def set_height(self, height: int) -> None:
        """
        set height value
        """
        self._height = height

    def set_age(self, age: int) -> None:
        """
        set age value
        """
        self._age = age

    def get_height(self) -> int:
        """
        get height value
        """
        return self._height

    def get_age(self) -> int:
        """
        get age value
        """
        return self._age


def correct_validation(age: int, height: int) -> int:
    """
    Checks if age and height are in range
    """
    if age > 0 and height > 0:
        return 1
    if age < 0:
        print(f"\nInvalid operation: {age}cm [REJECTED]")
        print("Negative age rejected")
    if height < 0:
        print(f"Invalid operation: {height}cm [REJECTED]")
        print("Negative height rejected")
    return 0


def show_info(plant: Secure_Plant) -> None:
    """
    Show plant specs
    """
    age: int = plant.get_age()
    height: int = plant.get_age()
    name: str = plant.name
    print(f"\nPlant created: {name}")
    print(f"Height updated: {height}cm [OK]")
    print(f"Age updated: {age} days [OK]")
    print(f"\nCurrent plant: {name}, ({height}cm {age} days)")


def init_plant() -> None:
    """
    init plants and call correct_validation
    """

    p1: Secure_Plant = Secure_Plant("Rose", -32, 1)
    if correct_validation(p1.get_age(), p1.get_height()):
        show_info(p1)
    p2: Secure_Plant = Secure_Plant("Sunflower", 45, -12)
    if correct_validation(p2.get_age(), p2.get_height()):
        show_info(p2)
    p3: Secure_Plant = Secure_Plant("Cactus", 45, 56)
    if correct_validation(p3.get_age(), p3.get_height()):
        show_info(p3)


if __name__ == "__main__":
    init_plant()
