def read_files() -> None:
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    try:
        print("\nCRISIS ALERT: Attempting access to 'lost_archive.txt'...")
        with open("lost_archive.txt", "r") as f:
            print(f"{f.read()}")
    except FileNotFoundError:
        print("RESPONSE: RESPONSE: Archive not found in storage matrix")
        print("STATUS: Crisis handled, system stable")
    try:
        print("\nCRISIS ALERT: Attempting access to 'classified_data.txt'...")
        with open("classified_data.txt", "r") as f:
            print(f"{f.read()}")
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
        print("STATUS: Crisis handled, security maintained")
    try:
        print("\nROUTINE ACCESS: Attempting access to ", end="")
        print("'standard_archive.txt'...")
        with open("standard_archive.txt", "r") as f:
            print(f"Archive recovered - ''{f.read()}''")
            print("STATUS: Normal operations resumed")
    except Exception as e:
        print(e)
    print("\nAll crisis scenarios handled successfully. Archives secure.")


if __name__ == "__main__":
    read_files()
