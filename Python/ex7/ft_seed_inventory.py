def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
	if unit != "packets" and unit != "area" and unit != "grams":
		print("Unknown unit type")
		return
	if unit == "packets":
		print(seed_type.capitalize(), "seeds:", quantity, "packets available")
	elif unit == "grams":
		print(seed_type.capitalize(), "seeds:", quantity, "grams total")
	else:
		print(seed_type.capitalize(), "seeds: covers", quantity, "square meters")
