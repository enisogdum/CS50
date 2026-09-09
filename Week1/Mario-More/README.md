# Mario (More Comfortable)

## Overview
Recreate the double half-pyramids from Nintendo's *Super Mario Bros.* using hash symbols (`#`) for blocks separated by two spaces.

## Specification
1. Write a C program in `mario.c` that prompts the user for the pyramid's height.
2. The height must be a positive integer between **1 and 8**, inclusive.
3. Re-prompt the user if they input a height less than 1 or greater than 8, or a non-integer.
4. Print two half-pyramids of height $H$ separated by a gap of two spaces:
   - Left half-pyramid (right-aligned).
   - Two spaces.
   - Right half-pyramid (left-aligned).

## Usage Example
```bash
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/mario/more
```
