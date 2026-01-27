import sys


def print_arvs() -> None:
    """
    show all argvs
    """
    len_: int = len(sys.argv)
    print(f"Program name: {sys.argv[0]}")
    if len_ < 2:
        print("No args given")
    else:
        print(f"Arguments received: {len_ - 1}")
        i = 1
        while (i < len_):
            print(f"Argument {i}: {sys.argv[i]}")
            i += 1
    print(f"Total args: {len_}")


if __name__ == "__main__":
    print_arvs()
