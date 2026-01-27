def check_temperature(temp_str: str) -> None:
    """
    check the temperature
    """
    print(f"\nTesting temperature: {temp_str}")
    try:
        converted_nbr: int = int(temp_str)
        if converted_nbr < 0:
            print(f"Error: {converted_nbr} is too cold for plants (min 0ºC)")
        elif converted_nbr > 40:
            print(f"Error: {converted_nbr}°C is too hot for plants (max 40°C)")
        else:
            print(f"Temperature: {converted_nbr} is perfect for plants!")
    except ValueError:
        print(f"Error: {temp_str} is not a valid number")
        return


def test_temperature_input() -> None:
    """
    tests
    """
    check_temperature("25")
    check_temperature("abc")
    check_temperature("100")
    check_temperature("-25")
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature_input()
