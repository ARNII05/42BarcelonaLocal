class Plant:
    def __init__(self, name: str, cm: float):
        self.name = name
        self.cm = cm

    def get_name(self) -> str:
        return self.plants

    def get_cm(self) -> str:
        return self.cm

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

    def get_name(self) -> str:
        return self.name

    def get_plants(self) -> Plant:
        return self.plants

class Garden_Manager:
    def __init__(self):
        self.garden_1 = None
        self.garden_2 = None

    def plants_msg(self, garden: Garden) -> None:
        plant_name = garden.get_plants().get_name()
        garden_name = garden.get_name()
        print(f"Added {plant_name} to {garden_name}'s garden")

    def validation(self, garden: Garden) -> int:
        cm = garden.plants.get_cm()
        if cm > 0 and garden is None:
            self.plants_msg(garden)
            return 1
        print(f"Invalid height{cm} [REJECTED]")
        return 1

    def add_garden(self, garden: Garden) -> None:
        if self.validation(self.garden_1):
            self.garden_1 = garden
        elif self.validation(self.garden_2):
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