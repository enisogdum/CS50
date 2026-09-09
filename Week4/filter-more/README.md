# Filter (More Comfortable)

## Overview
Implement five image filters for 24-bit BMP files in C by completing the helper functions in `helpers.c`. This version adds **edge detection** on top of the four filters from the less-comfortable version.

## Filters to Implement

### 1. Grayscale (`-g`)
Converts each pixel to a shade of grey by setting R, G, B to the **rounded average** of the three channels.

### 2. Sepia (`-s`)
Applies a warm vintage tone using fixed coefficients per channel (values capped at 255):
$$\text{sepiaRed} = 0.393R + 0.769G + 0.189B$$
$$\text{sepiaGreen} = 0.349R + 0.686G + 0.168B$$
$$\text{sepiaBlue} = 0.272R + 0.534G + 0.131B$$

### 3. Reflect (`-r`)
Flips the image **horizontally** by swapping pixels across the vertical center of each row.

### 4. Blur (`-b`)
Applies a **box blur** using the average color of each pixel's 3×3 neighborhood (boundary pixels use only valid neighbors).

### 5. Edges (`-e`) ⭐ More Comfortable Only
Detects edges using the **Sobel operator**, which computes the gradient magnitude across two 3×3 kernels:

$$G_x = \begin{bmatrix} -1 & 0 & 1 \\ -2 & 0 & 2 \\ -1 & 0 & 1 \end{bmatrix}, \quad G_y = \begin{bmatrix} -1 & -2 & -1 \\ 0 & 0 & 0 \\ 1 & 2 & 1 \end{bmatrix}$$

For each channel: $G = \text{round}(\sqrt{G_x^2 + G_y^2})$, capped at 255. Pixels outside the image are treated as black (0).

## File Structure
| File | Description |
|---|---|
| `filter.c` | Main program — handles CLI, reads/writes BMP |
| `helpers.c` | **Your implementation** — the five filter functions |
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
./filter -e images/yard.bmp out.bmp   # edges (Sobel)
```

## Testing
Run `check50` to test your implementation:
```bash
check50 cs50/problems/2024/x/filter/more
```
