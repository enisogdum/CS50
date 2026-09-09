# Sort

## Overview
Analyze three pre-compiled sorting binaries (`sort1`, `sort2`, `sort3`) and identify which **sorting algorithm** each one implements by measuring their performance on different input types.

## Algorithms to Identify
- **Bubble Sort** — O(n²) average/worst; O(n) best (already sorted).
- **Selection Sort** — O(n²) in all cases; not sensitive to input order.
- **Merge Sort** — O(n log n) in all cases; consistently fast regardless of input order.

## Provided Input Files
| File | Description |
|---|---|
| `sorted5000.txt` / `sorted10000.txt` / `sorted50000.txt` | Already sorted |
| `reversed5000.txt` / `reversed10000.txt` / `reversed50000.txt` | Reverse sorted |
| `random5000.txt` / `random10000.txt` / `random50000.txt` | Randomly ordered |

## How to Run Timing Experiments
Use the `time` command to measure how long each binary takes on each input type:
```bash
time ./sort1 random50000.txt
time ./sort2 reversed50000.txt
time ./sort3 sorted50000.txt
```

## Methodology
1. Run each binary against sorted, reversed, and random inputs.
2. Compare how runtime changes with input type and size.
3. Record your conclusions in `answers.txt`.

## Answers File
Fill in `answers.txt` with which algorithm each binary uses and your reasoning:
```
sort1 uses: <algorithm>
How do you know?: <explanation>
...
```

## Testing
Run `check50` to verify your `answers.txt`:
```bash
check50 cs50/problems/2024/x/sort
```
