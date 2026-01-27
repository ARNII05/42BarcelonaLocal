def check_plant_health(
        plant_name: str,
        water_level: int,
        sunlight_hours: int
        ) -> None:
    """
    check differents errors
    """
    sun: str = sunlight_hours
    try:
        if plant_name == "":
            raise ValueError("Plant name cannot be empty!")
        elif water_level > 10:
            raise ValueError(f"Water level {water_level} is too high (max 10)")
        elif water_level < 1:
            raise ValueError(f"Water level {water_level} is too low (min 1)")
        elif sun > 12:
            raise ValueError(f"Sunlight hours {sun} is too high (max 12)")
        elif sun < 2:
            raise ValueError(f"Sunlight hours {sun} is too low (min 2)")
    except ValueError as e:
        print(f"Error: {e}")
    else:
        print(f"Plant '{plant_name}' is healthy!")


def test_plant_checks() -> None:
    """
    create examples
    """
    print("\nTesting good values")
    check_plant_health("Rose", 3, 5)
    print("\nTesting empty plant name")
    check_plant_health("", 3, 3)
    print("\nTesting bad water level...")
    check_plant_health("Rose", 17, 5)
    print("\nTesting bad sunlight hours...")
    check_plant_health("Rose", 3, 24)
    print("\nAll error raising tests completed!")


if __name__ == "__main__":
    test_plant_checks()
