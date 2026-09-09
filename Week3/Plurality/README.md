# Plurality

## Overview
Implement a program in C that simulates a **plurality vote** (first-past-the-post) election, printing the candidate(s) with the most votes.

## How It Works
1. Candidates are passed as command-line arguments (up to 9).
2. The program prompts for the number of voters, then collects one vote per voter.
3. Invalid votes (names that don't match any candidate) are rejected with an error message.
4. After all votes are cast, the candidate(s) with the highest vote count are printed.
5. **Ties** are handled — all candidates sharing the highest vote total are printed.

## Specification
- `vote(string name)` — increments the vote count of the matching candidate; returns `true` on success, `false` if the name is not found.
- `print_winner()` — prints the name(s) of the candidate(s) with the maximum votes.

## Usage Example
```bash
$ ./plurality Alice Bob Charlie
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/plurality
```
