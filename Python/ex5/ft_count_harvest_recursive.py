def ft_count_harvest_recursive():
	day = 0
	total_days = int(input("Days until harvest: "))
	main_recursion(day, total_days)

def main_recursion(day : int, total_days: int):
	if total_days == day:
		print("Harvest time!")
		return 
	print("Day", day + 1)
	main_recursion(day + 1, total_days)
