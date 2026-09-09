# CS50x — Introduction to Computer Science

> Harvard University's introduction to the intellectual enterprises of computer science and the art of programming.

This repository contains my personal solutions and notes for **CS50x**, organized by week. Each problem set folder includes a `README.md` explaining the task, algorithm, and how to run it.

---

## 📚 Course Structure

### Week 0 — Scratch
> **Topic**: Visual programming fundamentals

| Task | Description |
|---|---|
| [Problem Set 0](./Week0/) | Build an interactive project in Scratch using sprites, loops, conditionals, and variables |

---

### Week 1 — C
> **Topic**: Compiled languages, variables, conditionals, loops, functions

| Task | Description |
|---|---|
| [Hello World](./Week1/HelloWorld/) | First C program — print a greeting |
| [Mario (Less)](./Week1/Mario-Less/) | Print a right-aligned half-pyramid using `#` characters |
| [Mario (More)](./Week1/Mario-More/) | Print a double pyramid (left + right) using `#` characters |
| [Cash](./Week1/Cash/) | Calculate minimum coins for change using a greedy algorithm |
| [Credit](./Week1/Credit/) | Validate credit card numbers using Luhn's algorithm |

---

### Week 2 — Arrays
> **Topic**: Arrays, strings, command-line arguments, cryptography

| Task | Description |
|---|---|
| [Scrabble](./Week2/Scrabble/) | Determine which player has the higher-scoring Scrabble word |
| [Readability](./Week2/Readability/) | Compute reading grade level using the Coleman-Liau Index |
| [Caesar](./Week2/Caesar/) | Encrypt a message using a Caesar cipher with a numeric key |
| [Substitution](./Week2/Substitution/) | Encrypt a message using a full 26-character substitution key |

---

### Week 3 — Algorithms
> **Topic**: Searching, sorting, recursion, voting algorithms

| Task | Description |
|---|---|
| [Plurality](./Week3/Plurality/) | Simulate a first-past-the-post election |
| [Runoff](./Week3/Runoff/) | Simulate an instant-runoff election with ranked voting |
| [Tideman](./Week3/Tideman/) | Implement the Tideman (ranked-pairs) voting method |
| [Sort](./Week3/Sort/) | Identify sorting algorithms (bubble, selection, merge) from binary behavior |

---

### Week 4 — Memory
> **Topic**: Pointers, memory allocation, file I/O, BMP/WAV formats

| Task | Description |
|---|---|
| [Volume](./Week4/Volume/) | Scale the volume of a WAV audio file by a given factor |
| [Filter (Less)](./Week4/filter-less/) | Apply grayscale, sepia, reflect, and blur filters to BMP images |
| [Filter (More)](./Week4/filter-more/) | All four filters above + edge detection via the Sobel operator |
| [Recover](./Week4/recover/) | Recover deleted JPEG images from a raw memory card image |

---

## 🛠 Languages & Tools

- **C** (primary language from Week 1 onward)
- **Scratch** (Week 0)
- **CS50 Library** (`cs50.h`) — provides helpers like `get_string`, `get_int`
- Compiled with `gcc` / `clang` via `make`

## 🚀 Getting Started

1. **Clone the repo**
   ```bash
   git clone <repo-url>
   cd CS50
   ```

2. **Install the CS50 library** (if not already installed)
   ```bash
   # On Linux/macOS via apt or brew, or from:
   # https://cs50.readthedocs.io/libraries/cs50/c/
   ```

3. **Navigate to any task and compile**
   ```bash
   cd Week1/Cash
   make cash
   ./cash
   ```

4. **Test with check50**
   ```bash
   check50 cs50/problems/2024/x/<task-name>
   ```

---

## 📄 License

Solutions are for educational reference only. Please follow the [CS50 Academic Honesty Policy](https://cs50.harvard.edu/x/honesty/) and do not submit these as your own work.
