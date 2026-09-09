# Cash

## Overview
Implement a program in C that calculates the minimum number of coins required to give a user change using a **Greedy Algorithm**.

## Specification
1. Write a program in `cash.c` that prompts the user for the amount of change owed in cents (or dollars/cents depending on the prompt version).
2. If the user enters a negative value, re-prompt until a non-negative value is provided.
3. Calculate the minimum number of coins needed to make change using available denominations:
   - **Quarters**: 25¢
   - **Dimes**: 10¢
   - **Nickels**: 5¢
   - **Pennies**: 1¢
4. Print the total minimum number of coins.

## Greedy Algorithm Strategy
At each step, take the largest coin denomination possible:
$$\text{Coins} = \lfloor \frac{\text{Cents}}{25} \rfloor + \lfloor \frac{\text{Remaining}}{10} \rfloor + \lfloor \frac{\text{Remaining}}{5} \rfloor + \text{Remaining Pennies}$$

## Usage Example
```bash
$ ./cash
Change owed: 41
4
```
*(Explanation: 1 quarter (25¢) + 1 dime (10¢) + 1 nickel (5¢) + 1 penny (1¢) = 4 coins)*

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/cash
```
