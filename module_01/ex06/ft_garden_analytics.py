class Plant:
    def __init__(self, name: str, cm: float):
        self.name = name
        self.cm = cm

class Flowering_Plant(Plant):
    def __init__(self, name: str, cm: float, color: str):
        self.color = color
        super().__init__(name, cm)

class Prize_Flower(Plant):
    def __init__(self, name: str, cm: float, color: str, cost: float):
        self.color = color
        self.cost = cost
        super().__init__(name, cm)

class Garden:
    def __init__(self, name: str, plants: Plant):
        self.plants = plants
        self.name = name

class Garden_Manager:
    def __init__(self):
        self.garden_1 = None
        self.garden_2 = None

    def plants_msg(self) -> None:
        garden_1 = self.garden_1
        print("Added {}")

    def add_garden(self, garden: Garden) -> None:
        if self.garden_1 is None:
            self.garden_1 = garden
        if self.garden_2 is None:
            self.garden_2 = garden
        

    class GardenStats:
        def __init__(self):
            self.total_gardens = 2
            self.total_plants = 3
            self.total_points = 25 * 3

        def get_total_gardens(self) -> int:
            return self.total_gardens

        def get_total_plants(self) -> int:
            return self.total_plants

        def get_total_points(self) -> int:
            return self.total_points


def init_plants() -> None:
    plants_g1 = Plant("Oak tree", 12)
    flowering_g1 = Flowering_Plant("Rose", 12, "red")