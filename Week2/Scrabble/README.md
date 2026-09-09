# Scrabble

## Overview
Implement a program in C that determines the winner of a two-player Scrabble-like game based on score calculations.

## Points Breakdown
Letters are assigned point values matching standard Scrabble:

| Letter | Points |
| :--- | :--- |
| A, E, I, L, N, O, R, S, T, U | 1 |
| D, G | 2 |
| B, C, M, P | 3 |
| F, H, V, W, Y | 4 |
| K | 5 |
| J, X | 8 |
| Q, Z | 10 |

- Characters that are not letters receive `0` points.
- Letter scoring is **case-insensitive** (`a` and `A` earn equal points).

## Specification
1. Write a program in `scrabble.c`.
2. Prompt Player 1 for a word and Player 2 for a word.
3. Compute each word's score.
4. Output:
   - `Player 1 wins!` if Player 1's score is higher.
   - `Player 2 wins!` if Player 2's score is higher.
   - `Tie!` if both scores are equal.

## Usage Example
```bash
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/scrabble
```
