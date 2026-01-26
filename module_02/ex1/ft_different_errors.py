def garden_operations() -> None:
    try:
        print("\nTesting ValueError")
        int("abc")
    except ValueError as e:
        print(f"Caught ValueError: {e}")
    try:
        print("\nTesting ZeroDivisionError")
        0 / 0
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")
    try:
        print("\nTesting FileNotFoundError")
        f = open("file.txt")
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {e}")
    else:
        f.close()
    try:
        print("\nTesting KeyError")
        p: dict = {"Arnau": 5, "Joel": 7}
        p["Guadalajara"]
    except KeyError as e:
        print(f"Caught KeyError: {e}")


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    garden_operations()
    print("\nTesting multiple errors together...")
    try:
        int("abc")
        open("file.txt")
    except Exception:
        print("Caught an error, but program continues!")
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
