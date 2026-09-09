# Volume

## Overview
Implement a program in C that **scales the volume** of a WAV audio file by a given factor, writing the result to a new output file.

## How It Works
1. Accepts three command-line arguments: `input.wav`, `output.wav`, and a float `factor`.
2. Copies the **44-byte WAV header** from input to output unchanged (preserving audio metadata).
3. Reads each **16-bit audio sample** (`int16_t`) one at a time from the input file.
4. Multiplies each sample by `factor` to scale the volume.
5. Writes the modified sample to the output file.

## WAV File Structure
```
[ 44-byte header ][ 16-bit sample ][ 16-bit sample ][ ... ]
```
- The header contains metadata (sample rate, bit depth, channels, etc.) and must **not** be modified.
- Audio data begins immediately after the header.

## Usage Example
```bash
$ ./volume input.wav output.wav 2.0
```
This doubles the volume of `input.wav` and writes the result to `output.wav`.

```bash
$ ./volume input.wav output.wav 0.5
```
This halves the volume.

## Usage / Compilation
```bash
gcc -o volume volume.c
./volume input.wav output.wav <factor>
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/volume
```
