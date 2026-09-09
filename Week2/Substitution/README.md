# Substitution

## Overview
Implement a program in C that encrypts messages using a **Substitution Cipher**, replacing each letter in plaintext with a corresponding letter from a 26-character key string.

## Specification
1. Store your code in `substitution.c`.
2. Accept a single command-line argument: a key of **26 unique alphabetic characters**.
3. Validate the command-line argument:
   - If missing, or if extra arguments are provided, print usage (`Usage: ./substitution key`) and return `1`.
   - If key length is not exactly 26 characters, print error and return `1`.
   - If key contains non-alphabetic characters, print error and return `1`.
   - If key contains duplicate characters (case-insensitive), print error and return `1`.
4. Prompt the user for `plaintext: `.
5. Output `ciphertext: ` followed by the encrypted text and a newline.
6. Case mapping rules:
   - If the plaintext character is uppercase, output the key's corresponding character in uppercase.
   - If the plaintext character is lowercase, output the key's corresponding character in lowercase.
   - Non-alphabetic characters remain unchanged.

## Usage Example
```bash
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jsssb, cywsp
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/substitution
```
