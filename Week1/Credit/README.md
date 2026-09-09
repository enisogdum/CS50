# Credit

## Overview
Implement a program in C that checks the validity of a credit card number using **Luhn's Algorithm** and identifies the card's issuing company.

## Credit Card Validation (Luhn's Algorithm)
1. Multiply every second digit by 2, starting from the number's second-to-last digit, and add those products' digits together.
2. Add the sum to the total of the digits that were not multiplied by 2.
3. If the total's last digit is `0` (i.e., $\text{total} \pmod{10} == 0$), the number is valid!

## Brand Identification Rules
- **American Express (AMEX)**: 15 digits, starts with `34` or `37`.
- **MasterCard**: 16 digits, starts with `51`, `52`, `53`, `54`, or `55`.
- **Visa**: 13 or 16 digits, starts with `4`.

## Specification
1. Write a program in `credit.c` that prompts the user for a credit card number.
2. Output `AMEX\n`, `MASTERCARD\n`, `VISA\n`, or `INVALID\n`.

## Usage Example
```bash
$ ./credit
Number: 378282246310005
AMEX
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/credit
```
