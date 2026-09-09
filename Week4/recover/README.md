# Recover

## Overview
Implement a program in C that **recovers deleted JPEG images** from a forensic memory card image (`.raw` file) by scanning for JPEG file signatures in 512-byte blocks.

## How It Works
1. Accepts a single command-line argument — the raw memory card file (e.g., `card.raw`).
2. Reads the file **512 bytes at a time** (the size of one sector).
3. Detects the start of a JPEG by checking if the first four bytes of a block match the JPEG signature:
   ```
   0xff 0xd8 0xff 0xe?  (where the 4th byte has its top nibble = 0xe)
   ```
4. When a new JPEG is found:
   - Closes the previously open output file (if any).
   - Opens a new file named `###.jpg` (e.g., `000.jpg`, `001.jpg`, …).
5. Writes each 512-byte block to the currently open JPEG file.
6. At end-of-file, closes the last open JPEG file.

## JPEG Signature
```c
buffer[0] == 0xff &&
buffer[1] == 0xd8 &&
buffer[2] == 0xff &&
(buffer[3] & 0xf0) == 0xe0
```

## Output
Recovered files are written to the **current working directory** as:
```
000.jpg
001.jpg
002.jpg
...
```

## Usage Example
```bash
$ ./recover card.raw
```
After running, you should see 50 JPEG files (`000.jpg` through `049.jpg`) in your working directory.

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/recover
```
