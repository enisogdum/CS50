# Runoff

## Overview
Implement a program in C that simulates an **instant-runoff election**, where voters rank candidates by preference and elimination rounds are held until one candidate secures a majority.

## How It Works
1. Candidates are passed as command-line arguments (up to 9).
2. Each voter ranks **all** candidates from most to least preferred.
3. Rounds are repeated until a winner is found:
   - **Tabulate**: Count each voter's top-ranked non-eliminated candidate.
   - **Check for majority**: If any candidate has > 50% of votes, they win.
   - **Check for tie**: If all remaining candidates are tied, all are declared winners.
   - **Eliminate**: Remove the candidate(s) with the fewest votes and repeat.

## Key Functions
| Function | Description |
|---|---|
| `vote(voter, rank, name)` | Records a voter's ranked preference |
| `tabulate()` | Counts current-round votes for non-eliminated candidates |
| `print_winner()` | Prints winner if majority reached; returns `true` |
| `find_min()` | Returns the lowest vote count among remaining candidates |
| `is_tie(min)` | Returns `true` if all remaining candidates are tied |
| `eliminate(min)` | Marks last-place candidates as eliminated |

## Usage Example
```bash
$ ./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/runoff
```
