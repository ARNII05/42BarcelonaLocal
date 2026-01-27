import sys


def procesed_list(argv: list[str], my_list: list[int]) -> None:
    """
    convert all list to ints
    """
    try:
        for s in argv:
            n: int = int(s)
            my_list.append(n)
    except ValueError as e:
        print(f"Error: {e}")


def print_scores() -> None:
    """
    print all math operations
    """
    print("=== Player Score Analytics ===")
    if len(sys.argv) < 2:
        print("No scores provided. Usage: python3 ", end="")
        print("ft_score_analytics.py <score1> <score2> ...")
        return
    my_list: list[int] = []
    procesed_list(sys.argv[1:], my_list)
    len_: int = len(my_list)
    sum_: int = sum(my_list)
    avg: int = sum_ / len_
    max_: int = max(my_list)
    min_: int = min(my_list)
    range: int = max_ - min_
    print(f"Scores processed: {my_list}")
    print(f"Total players {len_}")
    print(f"Total score: {sum_}")
    print(f"Average score: {avg}")
    print(f"High score: {max_}")
    print(f"Low score: {min_}")
    print(f"Score range: {range}")


if __name__ == "__main__":
    print_scores()
