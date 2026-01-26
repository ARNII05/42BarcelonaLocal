class Plant:
    """
    Class to Manage each Plant specs
    """
    def __init__(self, name: str, height: str, age: str):
        """
        init Plant
        """
        self.name: str = name
        self.height: str = height
        self.age: str = age

    def show_info(self, type: str) -> None:
        """
        Show plant info
        """
        name: str = self.name.capitalize()
        type = type.capitalize()
        print(f"\n{name} ({type}): {self.height}cm, {self.age} days", end="")


class Flower(Plant):
    """
    Class to Manage each Flower specs (Plant's child)
    """
    def __init__(self, name: str, height: str, age: str, color: str):
        """
        init Flower
        """
        self.name: str = name
        self.height: str = height
        self.age: str = age
        self.color: str = color
        super().__init__(name, height, age)

    def bloom(self) -> None:
        """
        Personalized msg for Flower class
        """
        print(f"{self.name} is blooming beautifully!")

    def show_info(self) -> None:
        """
        Show Flower info
        """
        super().show_info("Flower")
        print(f", {self.color} color")


class Tree(Plant):
    """
    Class to Manage each Tree specs (Plant's child)
    """
    def __init__(self, name: str, height: str, age: str, td: str):
        """
        init Tree
        """
        self.name: str = name
        self.height: str = height
        self.age: str = age
        self.td: str = td
        super().__init__(name, height, age)

    def produce_shade(self) -> None:
        """
        Personalized msg for Tree class
        """
        print(f"{self.name} provides {self.td} square meters of shade")

    def show_info(self) -> None:
        """
        Show Tree info
        """
        super().show_info("Tree")
        print(f", {self.td}cm diameter")
        self.produce_shade()


class Vegetable(Plant):
    """
    Class to Manage each Vegetable specs (Plant's child)
    """
    def __init__(self, name: str, height: str, age: str, hs: str, nv: str):
        """
        init Vegetable
        """
        self.name: str = name
        self.height: str = height
        self.age: str = age
        self.hs: str = hs
        self.nv: str = nv
        super().__init__(name, height, age)

    def show_info(self) -> None:
        """
        Show Vegetable info
        """
        super().show_info("Tree")
        print(f", {self.hs} harvest")
        print(f"{self.name} is rich in vitamin {self.nv}")


def init_plant() -> None:
    """
    init all Plant types and show its info
    """
    p1: Plant = Flower("Rose", 25, 30, "red")
    p1.show_info()
    p2: Plant = Flower("Sunflower", 50, 67, "yellow")
    p2.show_info()
    p3: Plant = Tree("Oak", 500, 1825, "50")
    p3.show_info()
    p4: Plant = Tree("Pine", 765, 2956, "100")
    p4.show_info()
    p5: Plant = Vegetable("Tomato", 25, 30, "summer", "C")
    p5.show_info()
    p6: Plant = Vegetable("Carrot", 25, 30, "fall", "A")
    p6.show_info()


if __name__ == "__main__":
    init_plant()
