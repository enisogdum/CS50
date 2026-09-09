# Caesar

## Overview
Implement a program in C that encrypts messages using **Caesar's Cipher**, shifting each letter by $k$ positions in the alphabet.

## Mathematical Formula
For each letter character $p_i$, the ciphertext character $c_i$ is given by:
$$c_i = (p_i + k) \bmod 26$$

## Specification
1. Store your code in `caesar.c`.
2. Accept a single command-line argument, $k$, which represents the non-negative integer key.
3. If executed without command-line arguments, or with more than one command-line argument, or if the argument contains non-digit characters, print usage instructions (`Usage: ./caesar key`) and return exit code `1`.
4. Prompt the user for `plaintext: `.
5. Print `ciphertext: ` followed by the encrypted text and a newline.
6. Preserve case: uppercase letters remain uppercase, lowercase letters remain lowercase.
7. Leave non-alphabetical characters (numbers, punctuation, spaces) unchanged.

## Usage Example
```bash
$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/caesar
```
