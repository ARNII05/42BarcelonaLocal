def read_file() -> None:
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print("\nAccessing Storage Vault: ancient_fragment.txt")
    try:
        with open("ancient_fragment.txt") as f:
            print("Connection established...")
            print(f"\n{f.read()}")
        print("\nData recovery complete. Storage unit disconnected.")
    except Exception:
        print("ERROR: Storage vault not found")


if __name__ == "__main__":
    read_file()
