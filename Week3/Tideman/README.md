# Tideman

## Overview
Implement a program in C that runs a **Tideman (ranked-pairs)** election — a voting method that produces a winner consistent with the majority preference of voters while avoiding the problems of plurality and runoff voting.

## How It Works
The algorithm follows four steps after collecting ranked votes:

1. **Record Preferences** — Build a `preferences[i][j]` matrix where the value is the number of voters who prefer candidate `i` over candidate `j`.
2. **Add Pairs** — For each pair of candidates, if one is strictly preferred over the other, add it as a directed pair (winner → loser). Skip tied pairs.
3. **Sort Pairs** — Sort all pairs in descending order by victory margin (strength of win).
4. **Lock Pairs** — Lock each pair into a directed graph (candidate graph), skipping any pair that would create a **cycle**.
5. **Print Winner** — The winner is the candidate with **no incoming locked edges** (the source of the graph).

## Key Functions
| Function | Description |
|---|---|
| `vote(rank, name, ranks[])` | Records a voter's ranked preference |
| `record_preferences(ranks[])` | Updates the pairwise preference matrix |
| `add_pairs()` | Identifies winning pairs from the preference matrix |
| `sort_pairs()` | Sorts pairs by victory strength (bubble sort) |
| `lock_pairs()` | Locks pairs into the graph, skipping cycle-creating pairs |
| `find_lock(winner, loser)` | Recursive cycle detection helper |
| `print_winner()` | Prints the candidate with no incoming locked edges |

## Usage Example
```bash
$ ./tideman Alice Bob Charlie
Number of voters: 3
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/tideman
```
