class Plant:
    """
    Plant class
    """
    def __init__(self, name: str, water_lvl: int, sunlight_lvl: int):
        """
        init Plant
        """
        self.name = name
        self.water_lvl = water_lvl
        self.sunlight_lvl = sunlight_lvl

    def get_name(self) -> str:
        """
        get Name
        """
        return self.name

    def get_wl(self) -> int:
        """
        get water level
        """
        return self.water_lvl

    def get_sl(self) -> int:
        """
        sunlight level
        """
        return self.sunlight_lvl


class GardenError(Exception):
    """
    my own error
    """
    pass


class GardenManager:
    """
    Manage all plants
    """
    def __init__(self):
        """
        init GardenManager
        """
        self.plants: Plant = []
        self.water_tank: int = 100

    def add_plant(self, name: str, water_lv: int, sunlight_lvl: int) -> None:
        """
        func to add plant and check ValueErrors
        """
        try:
            water_lv = int(water_lv)
            sunlight_lvl = int(sunlight_lvl)
        except ValueError as e:
            print(f"Error: Water and sunlight levels must be integers {e}")
            return
        try:
            if name is None or name == "":
                raise ValueError("Name cannot be None or Empty")
        except ValueError as e:
            print(f"Error: {e}")
            return
        self.plants.append(Plant(name, water_lv, sunlight_lvl))
        print(f"Added {name} successfully")

    def water_plants(self) -> None:
        """
        func to water the plants
        """
        try:
            for p in self.plants:
                print(f"Watering {p.get_name()} ", end="")
                if self.water_tank <= 0:
                    raise ValueError()
                print("- success")
                self.water_tank -= 50
        except ValueError:
            print("- failed")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self) -> None:
        """
        check plant specs
        """
        try:
            for p in self.plants:
                msg: str = self.validate_values(p)
                water: int = p.get_wl()
                sun: int = p.get_sl()
                name: str = p.get_name()
                if msg != "":
                    raise ValueError(msg)
                print(f"{name}: healthy (water: {water}, sun: {sun})")
        except ValueError as e:
            print(f"Error checking {name}: {e}")

    def error_recovery(self) -> None:
        """
        show all errors
        """
        try:
            if self.water_tank <= 0:
                raise GardenError("Not enough water in tank")
        except GardenError:
            print("Caught GardenError: Not enough water in tank")
        else:
            print("No errors detected")
        finally:
            print("\nGarden management system test complete!")

    def validate_values(self, plant: Plant) -> str:
        """
        validate plant values
        """
        water_lv = plant.get_wl()
        sunlight_lvl = plant.get_sl()
        if water_lv > 10:
            return f"Water level {water_lv} is too high (max 10)"
        elif water_lv < 1:
            return f"Water level {water_lv} is too low (min 1)"
        elif sunlight_lvl > 12:
            return f"Sunlight hours {sunlight_lvl} is too high (max 12)"
        elif sunlight_lvl < 2:
            return f"Sunlight hours {sunlight_lvl} is too low (min 2)"
        return ""


def test_garden_management() -> None:
    """
    init all tests and call functions
    """
    print("=== Garden Management System ===")
    gm = GardenManager()
    print("\nAdding plants to garden...")
    gm.add_plant("Rose", 5, 8)
    gm.add_plant("Letuce", 9, 9)
    gm.add_plant("Sunflower", 9, 9)
    gm.add_plant("Idk", 9, 9)
    gm.add_plant("Test", 9, 12)
    print("\nWatering plants...")
    print("Opening watering system")
    gm.water_plants()
    print("\nChecking plant health...")
    gm.check_plant_health()
    print("\nTesting error recovery...")
    gm.error_recovery()


if __name__ == "__main__":
    test_garden_management()
