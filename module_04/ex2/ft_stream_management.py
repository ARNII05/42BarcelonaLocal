import sys


def read_stdin() -> None:
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    try:
        print("\nInput Stream active. Enter archivist ID: ", end="")
        id: str = sys.stdin.readline().strip()
        print("\nInput Stream active. Enter status report: ", end="")
        status: str = sys.stdin.readline()
        sys.stdout.write("\n[STANDARD] Archive status from ")
        sys.stdout.write(f"{id}: {status}")
        print("[ALERT] System diagnostic: ", file=sys.stderr, end="")
        print("Communication channels verified", file=sys.stderr)
        print("[STANDARD] Data transmission complete")
        print("\nThree-channel communication test successful.")
    except Exception as e:
        print(f"ERROR: {e}", file=sys.stderr)


if __name__ == "__main__":
    read_stdin()
