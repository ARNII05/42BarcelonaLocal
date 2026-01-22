def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed = seed_type.capitalize()
    if unit != "packets" and unit != "area" and unit != "grams":
        print("Unknown unit type")
        return
    if unit == "packets":
        print(seed, "seeds:", quantity, "packets available")
    elif unit == "grams":
        print(seed, "seeds:", quantity, "grams total")
    else:
        print(seed, "seeds: covers", quantity, "square meters")
