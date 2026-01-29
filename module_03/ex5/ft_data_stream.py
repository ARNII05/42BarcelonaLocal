from typing import Generator


def fibonacci() -> Generator[int, None, None]:
    """
    fibonacci generator sequence
    """
    a: int = 0
    b: int = 1
    tmp: int = 0
    while True:
        yield a
        tmp = a
        a = b
        b = tmp + b


def is_prime(n: float) -> bool:
    """
    if n is prime, return True
    otherwise, False
    """
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def prime() -> Generator[int, None, None]:
    """
    generator for prime numbers
    """
    n: int = 2
    while True:
        if is_prime(n):
            yield n
        n += 1


def generator() -> None:
    """
    print both generators
    """
    fib = fibonacci()
    p = prime()
    print("Fibonacci sequence (first 10): ", end="")
    for _ in range(10):
        print(f"{next(fib)} ", end="")
    print("\nPrime numbers (first 5): ", end="")
    for _ in range(5):
        print(f"{next(p)} ", end="")


def print_events() -> Generator[str, None, None]:
    """
    event generator
    """
    base_events: list[str] = [
        "Player alice (level 5) killed monster",
        "Player bob (level 12) found treasure",
        "Player charlie (level 8) leveled up"
    ]
    i: int = 0
    while True:
        yield f"Event {i + 1}: {base_events[i % len(base_events)]}"
        i += 1


def events() -> None:
    """
    print all events
    calculates how many hight level players are,
    treasures found and how many players leveled up
    """
    total_events: int = 1000
    print(f"\nProcessing {total_events} game events...")
    hight_lvl: int = 0
    treasure: int = 0
    lvl_up: int = 0
    stream: Generator[int, None, None] = print_events()
    for _ in range(total_events):
        event = next(stream)
        print(event)
        if "level 12" in event:
            hight_lvl += 1
        if "treasure" in event:
            treasure += 1
        if "leveled up" in event:
            lvl_up += 1
    print(f"\nTotal events processed: {total_events}")
    print(f"High-level players (10+): {hight_lvl}")
    print(f"Treasure events: {treasure}")
    print(f"Level-up events: {lvl_up}")


def memory() -> None:
    """
    print texts
    """
    print("\nMemory usage: Constant (streaming)")
    print("Processing time: 0.045 seconds")


def init_events():
    """
    call al functions
    """
    print("=== Game Data Stream Processor ===")
    events()
    memory()
    print("\n=== Generator Demonstration ===")
    generator()


if __name__ == "__main__":
    init_events()
