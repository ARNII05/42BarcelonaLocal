def water_plants(plant_list: list) -> None:
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None:
                raise ValueError("Cannot watter None - invalid plant!")
            print(f"Watering {plant}")
    except ValueError as e:
        print(f"Error: {e}")
    else:
        print("Watering completed successfully!")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system() -> None:
    good_list: list = ["Tomato", "Lettuce", "Carrot"]
    print("=== Garden Watering System ===")
    print("\nTesting normal watering...")
    water_plants(good_list)
    print("\nTesting with error...")
    bad_list: list = ["Tomato", None, "Carrot"]
    water_plants(bad_list)
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
