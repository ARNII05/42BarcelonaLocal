def init_sets() -> None:
    """
    init three sets with info
    """
    print("=== Achievement Tracker System ===")
    set_1: set[str] = {'first_kill', 'level_10',
                       'treasure_hunter', 'speed_demon'}
    set_2: set[str] = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    set_3: set[str] = {'level_10', 'treasure_hunter', 'boss_slayer',
                       'speed_demon', 'perfectionist'}
    print_sets(set_1, set_2, set_3)


def print_sets(set_1: set[str], set_2: set[str], set_3: set[str]) -> None:
    """
    print all sets and call other functions
    """
    print("=== Achievement Analytics ===")
    print(f"\nPlayer alice achievements: {set_1}")
    print(f"Player bob archievements: {set_2}")
    print(f"Player charlie achievements: {set_3}")
    print("\n=== Achievement Analytics ===")
    unique_arch(set_1, set_2, set_3)
    common_rare_arch(set_1, set_2, set_3)
    compare_sets(set_1, set_2)


def compare_sets(set_1: set[str], set_2: set[str]) -> None:
    """
    comparing set 1 and 2
    """
    common: set[str] = set_1.intersection(set_2)
    a_unique: set[str] = set_1.difference(set_2)
    b_unique: set[str] = set_2.difference(set_1)
    print(f"\nAlice vs Bob common: {common}")
    print(f"Alice unique: {a_unique}")
    print(f"Bob unique: {b_unique}")


def count_rare(set_1: set[str], set_2: set[str], set_3: set[str]) -> set[str]:
    """
    checks for the less common archivements
    """
    all_achievements: set[str] = set_1 | set_2 | set_3
    rare: set[str] = set()
    for ach in all_achievements:
        count = 0
        if ach in set_1:
            count += 1
        if ach in set_2:
            count += 1
        if ach in set_3:
            count += 1
        if count == 1:
            rare.add(ach)
    return rare


def common_rare_arch(set_1: set[str], set_2:
                     set[str], set_3: set[str]) -> None:
    """
    prints the common and rarest archeivements
    """
    common: set[str] = set_1.intersection(set_2, set_3)
    rare: set[str] = count_rare(set_1, set_2, set_3)
    print(f"\nCommon to all players: {common}")
    print(f"Rare achievements (1 player): {rare}")


def unique_arch(set_1: set[str], set_2: set[str], set_3: set[str]) -> None:
    """
    Print all achievements across all sets
    """
    unique: set[str] = set_1.union(set_2, set_3)
    print(f"All unique achievements: {unique}")
    print(f"Total unique achievements: {len(unique)}")


if __name__ == "__main__":
    init_sets()
