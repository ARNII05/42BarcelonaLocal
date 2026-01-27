import math
import sys


def procesed_list(string: str) -> list[int]:
    """
    convert string to int
    return the list or error for non int values
    """
    result: list[int] = []
    new_argv: list[str] = string.split(",")
    try:
        for s in new_argv:
            result.append(int(s))
    except ValueError as e:
        print(f"Error parsing coordinates: {e}")
        print("Error details - Type: ValueError, Args: ", end="")
        print(f"({e})")
        return []
    return result


def do_math(string: str) -> None:
    """
    do all operations and print them
    """
    coords: list[int] = procesed_list(string)
    if not coords:
        return
    pos: tuple[int, ...] = tuple(coords)
    x: int = pos[0]
    y: int = pos[1]
    z: int = pos[2]
    dist: float = math.sqrt(x ** 2 + y ** 2 + z ** 2)
    print(f"\nPosition created: {pos}")
    print(f"Distance between (0, 0, 0) and {pos}: {dist}")
    print("\nUnpacking demostration:")
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, Z={z}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    do_math(sys.argv[1])
