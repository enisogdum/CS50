# Mario (Less Comfortable)

## Overview
Recreate the half-pyramid of blocks from Nintendo's *Super Mario Bros.* using hash symbols (`#`) for blocks.

## Specification
1. Write a C program in `mario.c` that prompts the user for the pyramid's height.
2. The height must be a positive integer between **1 and 8**, inclusive.
3. If the user inputs anything other than an integer from 1 to 8, re-prompt the user until they comply.
4. Generate a right-aligned half-pyramid of height $H$ using hash (`#`) characters.

## Usage Example
```bash
$ ./mario
Height: 4
   #
  ##
 ###
####
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/mario/less
```
