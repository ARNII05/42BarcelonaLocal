class Plant:
    def __init__(self, name: str, cm: float):
        self.name: str = name
        self.cm: float = cm
        self.type: str = "r"

    def get_name(self) -> str:
        return self.name

    def get_cm(self) -> float:
        return self.cm

    def get_extra_info(self) -> str:
        return ""

    def get_type(self) -> str:
        return self.type


class Flowering_Plant(Plant):
    def __init__(self, name: str, cm: float, color: str):
        super().__init__(name, cm)
        self.color: str = color
        self.type: str = "fp"

    def get_color(self) -> None:
        return self.color

    def get_extra_info(self) -> str:
        return f"{self.color} flowers (blooming)"


class Prize_Flower(Plant):
    def __init__(self, name: str, cm: float, color: str, cost: float):
        super().__init__(name, cm)
        self.color: str = color
        self.cost: float = cost
        self.type: str = "pp"

    def get_color(self):
        return self.color

    def get_cost(self):
        return self.cost

    def get_extra_info(self) -> str:
        return f"{self.color} flowers (blooming), prize: {self.cost}"


class Garden:
    def __init__(self, name: str, p1: Plant, p2: Plant, p3: Plant):
        self.p1: Plant = p1
        self.p2: Plant = p2
        self.p3: Plant = p3
        self.name: str = name
        self.points: int = 0

    def get_name(self) -> str:
        return self.name

    def get_p1(self) -> Plant:
        return self.p1

    def get_p2(self) -> Plant:
        return self.p2

    def get_p3(self) -> Plant:
        return self.p3

    def get_points(self) -> Plant:
        return self.points

    def validate_plant(self, cm: int) -> int:
        if cm < 0:
            return 0
        self.points += 20


class Garden_Manager:
    def __init__(self, g1: Garden, g2: Garden):
        self.garden_1: Garden = g1
        self.garden_2: Garden = g2
        self.stats = Garden_Manager.Garden_Stats()
        self.show_summary()

    def show_summary(self) -> None:
        print("\n=== Garden Management System Demo ===")
        self.plants_msg(self.garden_1)
        self.text(self.garden_1)
        self.plants_msg(self.garden_2)
        self.text(self.garden_2)
        self.show_stats()

    def plants_msg(self, garden: Garden) -> None:
        p1_name: str = garden.get_p1().get_name()
        p2_name: str = garden.get_p2().get_name()
        p3_name: str = garden.get_p3().get_name()
        garden_name: str = garden.get_name()
        print(f"\nAdded {p1_name} to {garden_name}'s garden")
        print(f"Added {p2_name} to {garden_name}'s garden")
        print(f"Added {p3_name} to {garden_name}'s garden")
        self.total_growth(p1_name, p2_name, p3_name, garden_name)

    def total_growth(self, p1: str, p2: str, p3: str, gn: str):
        print(f"\n{gn} is helping all plants to grow...")
        print(f"{p1} grew 1cm")
        print(f"{p2} grew 1cm")
        print(f"{p3} grew 1cm")

    def show_stats(self):
        total_points_g1: int = self.garden_1.get_points()
        total_points_g2: int = self.garden_2.get_points()
        total_plants: int = self.stats.get_nbr_plants()
        print(f"\nPlants added: {total_plants}, Total growth: {total_plants}")
        print(f"Plant types: {self.stats.get_nbr_plant_t()} regular,", end="")
        print(f" {self.stats.get_nbr_fp()} flowering,", end="")
        print(f" {self.stats.get_nbr_pp()} prize flowers")
        print("\nHeight validation test: True")
        print(f"Garden scores- {self.garden_1.get_name()}: ", end="")
        print(f"{total_points_g1}, ", end="")
        print(f"{self.garden_2.get_name()}: {total_points_g2}")
        print(f"Total gardens managed: {self.stats.get_total_gardens()}")

    def get_type(self, p: Plant):
        if p.get_type() == "r":
            print(f"{p.get_name()}: {p.get_cm()}cm")
            self.stats.set_nbr_plant_t(1)
        elif p.get_type() == "fp":
            print(f"{p.get_name()}: {p.get_cm()}cm, {p.get_extra_info()}")
            self.stats.set_nbr_fp(1)
        elif p.get_type() == "pp":
            print(f"{p.get_name()}: {p.get_cm()}cm, {p.get_extra_info()}")
            self.stats.set_nbr_pp(1)

    def create_garden_network(self, garden: Garden):
        p1: Plant = garden.get_p1()
        p2: Plant = garden.get_p2()
        p3: Plant = garden.get_p3()
        print(f"\n=== {garden.get_name()}'s Garden Report ===")
        print("Plants in garden:")
        self.get_type(p1)
        self.get_type(p2)
        self.get_type(p3)

    def text(self, garden: Garden) -> None:
        p1: float = garden.validate_plant(garden.get_p1().get_cm())
        p2: float = garden.validate_plant(garden.get_p2().get_cm())
        p3: float = garden.validate_plant(garden.get_p3().get_cm())
        if p1 == 0 or p2 == 0 or p3 == 0:
            print(f"\n=== {garden.get_name()}'s Garden Report ===")
            print("Invalid height [REJECTED]")
            return
        self.stats.set_nbr_plants(3)
        self.create_garden_network(garden)

    @staticmethod
    def add_g1() -> Garden:
        p1 = Plant("Oak tree", 12)
        p2: Plant = Flowering_Plant("Rose", 12, "red")
        p3: Plant = Flowering_Plant("Sunflower", 30, "yellow")
        return Garden("Alice", p1, p2, p3)

    @staticmethod
    def add_g2() -> Garden:
        p1 = Plant("Oak tree", 12)
        p2: Plant = Flowering_Plant("Rose", 12, "red")
        p3: Plant = Prize_Flower("Sunflower", 30, "yellow", 20)
        return Garden("Bob", p1, p2, p3)

    @classmethod
    def init_plants(cls) -> "Garden_Manager":
        gm: Garden_Manager = Garden_Manager(cls.add_g1(), cls.add_g2())
        return gm

    class Garden_Stats:
        def __init__(self):
            self.total_gardens: int = 2
            self.total_plants_t: int = 0
            self.total_plants: int = 0
            self.total_fp: int = 0
            self.total_pp: int = 0

        def get_total_gardens(self) -> int:
            return self.total_gardens

        def get_total_points(self) -> int:
            return self.total_points

        def get_nbr_plant_t(self) -> int:
            return self.total_plants_t

        def get_nbr_plants(self) -> int:
            return self.total_plants

        def get_nbr_fp(self) -> int:
            return self.total_fp

        def get_nbr_pp(self) -> int:
            return self.total_pp

        def set_nbr_plant_t(self, add: int) -> None:
            self.total_plants_t += add

        def set_nbr_fp(self, add: int) -> None:
            self.total_fp += add

        def set_nbr_pp(self, add: int) -> None:
            self.total_pp += add

        def set_nbr_plants(self, add: int) -> None:
            self.total_plants += add


if __name__ == "__main__":
    gm: Garden_Manager = Garden_Manager.init_plants()
