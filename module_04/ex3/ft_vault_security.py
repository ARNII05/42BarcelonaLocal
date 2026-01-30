def read_files() -> None:
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
    try:
        print("\nInitiating secure vault access...")
        print("Vault connection established with failsafe protocols")
        print("\nSECURE EXTRACTION:")
        with open("classified_data.txt", "r") as f:
            print(f"{f.read()}")
        print("\nSECURE PRESERVATION:")
        with open("security_protocols.txt", "r") as f2:
            print(f"{f2.read()}")
        print("Vault automatically sealed upon completion")
        print("\nAll vault operations completed with maximum security.")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    read_files()
