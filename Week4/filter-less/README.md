# Filter (Less Comfortable)

## Overview
Implement four image filters for 24-bit BMP files in C by completing the helper functions in `helpers.c`.

## Filters to Implement

### 1. Grayscale (`-g`)
Converts each pixel to a shade of grey by setting the red, green, and blue values to the **average** of the three channels:
$$\text{avg} = \text{round}\left(\frac{R + G + B}{3}\right)$$

### 2. Sepia (`-s`)
Applies a warm, vintage tone using the following formula per pixel:
$$\text{sepiaRed}   = 0.393R + 0.769G + 0.189B$$
$$\text{sepiaGreen} = 0.349R + 0.686G + 0.168B$$
$$\text{sepiaBlue}  = 0.272R + 0.534G + 0.131B$$
Values are capped at 255.

### 3. Reflect (`-r`)
Flips the image **horizontally** (mirror effect) by swapping pixels across the vertical center of each row.

### 4. Blur (`-b`)
Applies a **box blur** by replacing each pixel with the average color of its surrounding 3×3 neighborhood (ignoring pixels outside the image boundary).

## File Structure
| File | Description |
|---|---|
| `filter.c` | Main program — handles CLI, reads/writes BMP |
| `helpers.c` | **Your implementation** — the four filter functions |
| `helpers.h` | Function prototypes |
| `bmp.h` | BMP data structure definitions |
| `Makefile` | Build configuration |
| `images/` | Sample BMP images for testing |

## Usage Example
```bash
make filter
./filter -g images/yard.bmp out.bmp   # grayscale
./filter -s images/yard.bmp out.bmp   # sepia
./filter -r images/yard.bmp out.bmp   # reflect
./filter -b images/yard.bmp out.bmp   # blur
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/filter/less
```
