# C Menu Calculator

A menu-driven command-line calculator written in C, demonstrating clean project structure, modular design, and proper error handling.

---

## Features

- **8 operations** — addition, subtraction, multiplication, division, modulus, power, square root, absolute value
- **Robust error handling** — division by zero, invalid domain (e.g. √ of negative), bad input
- **Coloured terminal output** via ANSI escape codes
- **Modular architecture** — operations, UI, and entry point are separated into distinct source files
- **Makefile** with release and debug targets (includes AddressSanitizer support)

---

## Project Structure

```
calculator-c/
├── include/
│   └── calculator.h      # Public API — types, constants, function declarations
├── src/
│   ├── main.c            # Entry point and main loop
│   ├── operations.c      # Arithmetic implementations
│   └── ui.c              # Menu, input handling, result display
├── Makefile
└── README.md
```

---

## Getting Started

### Prerequisites

| Tool | Version |
|------|---------|
| GCC  | ≥ 7.0   |
| Make | any     |

On Debian/Ubuntu:
```bash
sudo apt install build-essential
```

On macOS (Homebrew):
```bash
xcode-select --install
```

### Build & Run

```bash
# Clone the repository
git clone https://github.com/<your-username>/calculator-c.git
cd calculator-c

# Build
make

# Run
./calculator
```

### Debug Build

```bash
make debug
./calculator
```

Enables `-g`, `-DDEBUG`, and GCC's AddressSanitizer (`-fsanitize=address`) to catch memory issues.

---

## Usage

```
  ╔══════════════════════════════╗
  ║   C M E N U  CALCULATOR     ║
  ╚══════════════════════════════╝
  ──────────────────────────────
  [1]  Addition         (a + b)
  [2]  Subtraction      (a - b)
  [3]  Multiplication   (a * b)
  [4]  Division         (a / b)
  [5]  Modulus          (a % b)
  [6]  Power            (a ^ b)
  [7]  Square Root      (√a)
  [8]  Absolute Value   (|a|)
  ──────────────────────────────
  [0]  Exit

  Enter choice: 4
  Enter operand A: 22
  Enter operand B: 7

  ✔  Result = 3.14286
```

---

## Error Handling

| Scenario | Response |
|----------|----------|
| Division by zero | `Error: Division by zero` |
| Modulus by zero  | `Error: Modulus by zero` |
| √ of negative    | `Error: Square root of negative number` |
| 0 ^ (negative)   | `Error: 0 raised to negative exponent` |
| Non-numeric input | Flushes buffer, reprompts |

---

## Implementation Notes

- All operations return a `CalcResult` struct containing the value, a status code (`CALC_OK`, `CALC_ERR_DIVZERO`, `CALC_ERR_DOMAIN`), and a human-readable message — a lightweight pattern similar to result types in modern languages.
- `fmod()` is used for floating-point modulus (from `<math.h>`), consistent with C standard library behaviour.
- Input is read with `scanf` and guarded against non-numeric characters by flushing `stdin` on failure.

---

## License

MIT — see [LICENSE](LICENSE) for details.
