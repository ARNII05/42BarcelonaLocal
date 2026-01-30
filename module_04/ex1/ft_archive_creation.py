def read_file() -> None:
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print("\nInitializing new storage unit: new_discovery.txt")
    try:
        with open("new_discovery.txt", "w") as f:
            print("Storage unit created successfully...")
            print("\nInscribing preservation data...")
            f.write("[ENTRY 001] New quantum algorithm discovered\n")
            f.write("[ENTRY 002] Efficiency increased by 347%\n")
            f.write("[ENTRY 003] Archived by Data Archivist trainee\n")
        with open("new_discovery.txt", "r") as e:
            print(f"\n{e.read()}") 
        print("Data inscription complete. Storage unit sealed")
        print("Archive 'new_discovery.txt' ready for long-term preservation.")
    except Exception:
        print("ERROR: Cannot read or create file")

if __name__ == "__main__":
    read_file()