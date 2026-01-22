"""
Print plant info
"""


def print_plant_specs() -> None:
    name: str = "Rose"
    height: str = "25cm"
    age: str = "30 days"
    print("=== Welcome to My Garden ===")
    print("Plant:", name)
    print("Height:", height)
    print("Age:", age)
    print("\n=== End of Program ===")


if __name__ == "__main__":
    print_plant_specs()
