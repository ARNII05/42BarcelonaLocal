

def high_scorers(name: list[str], scores: list[int]) -> list[str]:
    high: list[str] = []
    i: int = 0
    while i < len(scores):
        if scores[i] > 2000:
            high.append(name[i])
        i += 1
    return high


def scorers_doubled(scores: list[int]) -> list[int]:
    doubled: list[int] = []
    i: int = 0
    while i < len(scores):
        if scores[i] >= 4000:
            doubled.append(scores[i])
        i += 1
    return doubled


def active(name: list[int], active_p: list[bool]) -> list[str]:
    active: list[str] = []
    i: int = 0
    while i < len(name):
        if active_p[i]:
            active.append(name[i])
        i += 1
    return active


def list_examples() -> int:
    list_name: list[str] = ["Patry", "Ade", "Dylan", "Arnau", "Veri", "Dani"]
    list_scores: list[int] = [1850, 4200, 2500, 1999, 4700, 3100]
    active_players: list[bool] = [True, True, True, True, False, False]
    print("High scorers (>2000): ", end="")
    print(high_scorers(list_name, list_scores))
    print("Scores doubled: ", end="")
    print(scorers_doubled(list_scores))
    print("Active players: ", end="")
    print(active(list_name, active_players))
    return len(list_name)


def dict_scores(my_dict: dict[str, list[int]]) -> dict[str, int]:
    scores: dict[str, int] = {}
    for key in my_dict:
        scores[key] = my_dict[key][0]
    return scores


def dict_category(my_dict: dict[str, list[int]]) -> dict[str, int]:
    cat: dict[str, int] = {
        "High": 0,
        "Medium": 0,
        "Low": 0
    }
    for key in my_dict:
        if my_dict[key][0] >= 4000:
            cat["High"] += 1
        elif my_dict[key][0] >= 2000:
            cat["Medium"] += 1
        if my_dict[key][0] < 2000:
            cat["Low"] += 1
    return cat


def arch_count(my_dict: dict[str, list[int]]) -> dict[str, int]:
    count: dict[str, int] = {}
    for key in my_dict:
        count[key] = my_dict[key][1]
    return count


def dict_examples() -> dict[str, list[int]]:
    my_dict: dict[str, list[int]] = {
        "Patry": [1850, 7],
        "Ade": [4200, 12],
        "Dylan": [2500, 15],
        "Arnau": [1999, 9],
        "Veri": [4700, 18],
        "Dani": [3100, 6]
     }
    print("Player scores: ", end="")
    print(dict_scores(my_dict))
    print("Score categories: ", end="")
    print(dict_category(my_dict))
    print("Achievement counts: ", end="")
    print(arch_count(my_dict))
    return my_dict


def set_examples() -> set[str]:
    p_set: set[str] = {'Patry', 'Ade', 'Dylan', 'Arnau', 'Veri', 'Dani'}
    regions: set[str] = {'north', 'east', 'central'}
    set_1: set[str] = {'first_kill', 'level_10',
                       'treasure_hunter', 'speed_demon'}
    set_2: set[str] = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    set_3: set[str] = {'level_10', 'treasure_hunter', 'boss_slayer',
                       'speed_demon', 'perfectionist'}
    print(f"Unique players: {p_set}")
    print(f"Unique achievements: {set_1.union(set_2, set_3)}")
    print(f"Active regions: {regions}")
    return set_1.union(set_2, set_3)


def best(d: dict[str, list[int]], s: dict[str, int]) -> dict[str, list[int]]:
    my_dict: dict[str, list[int]] = {}
    for key in d:
        if d[key][0] == max(s.values()):
            my_dict[key] = d[key][0]
    return my_dict


def best_name(d: dict[str, list[int]], s: dict[str, int]) -> str:
    key: str = ""
    for keys in d:
        if d[keys][0] == max(s.values()):
            key = keys
    return key


def combined(len_: int, my_set: set[str], d: dict[str, list[int]]) -> None:
    scores: dict[str, int] = dict_scores(d)
    arch: dict[str, int] = arch_count(d)
    best_p: dict[str, list[int]] = best(d, scores)
    name: str = best_name(d, scores)
    print(f"Total players: {len_}")
    print(f"Total unique achievements: {my_set}")
    print(f"Average score: {sum(scores.values()) / len(scores):.1f}")
    print(f"Top performer: {name} ({max(best_p.values())} points, ", end="")
    print(f"{max(arch.values())} archivements)")


def call_functs() -> None:
    print("=== Game Analytics Dashboard ===")
    print("\n=== List Comprehension Examples ===")
    len_: int = list_examples()
    print("\n=== Dict Comprehension Examples ===")
    my_dict: dict[str, list[int]] = dict_examples()
    print("\n=== Set Comprehension Examples ===")
    my_set: set[str] = set_examples()
    print("\n=== Combined Analysis ===")
    combined(len_, my_set, my_dict)


if __name__ == "__main__":
    call_functs()
