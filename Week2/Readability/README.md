# Readability

## Overview
Implement a program in C that calculates the approximate grade level needed to comprehend a text using the **Coleman-Liau Index**.

## The Coleman-Liau Index Formula
$$\text{index} = 0.0588 \times L - 0.296 \times S - 15.8$$

Where:
- $L$ = Average number of letters per 100 words.
- $S$ = Average number of sentences per 100 words.

## Rules for Counting
- **Letters**: Any uppercase or lowercase alphabetical character (`a` through `z`, `A` through `Z`).
- **Words**: Any sequence of characters separated by spaces.
- **Sentences**: Any sequence of characters ending with a period (`.`), exclamation mark (`!`), or question mark (`?`).

## Specification
1. Write a program in `readability.c` that prompts the user for a string of text.
2. Calculate and round the Coleman-Liau index to the nearest integer.
3. Output the grade level:
   - If index $\ge 16$, print `Grade 16+`.
   - If index $< 1$, print `Before Grade 1`.
   - Otherwise, print `Grade X` (where $X$ is the rounded grade level).

## Usage Example
```bash
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/readability
```
