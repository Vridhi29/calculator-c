<div align="center">

![Header](https://capsule-render.vercel.app/api?type=waving&color=0:1a1a2e,50:16213e,100:0f3460&height=200&section=header&text=C%20Menu%20Calculator&fontSize=50&fontColor=e94560&animation=fadeIn&fontAlignY=38&desc=A%20menu-driven%20CLI%20calculator%20built%20in%20C&descAlignY=55&descColor=a8b2d8)

[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build](https://img.shields.io/badge/Build-GCC%20%2B%20Make-informational?style=for-the-badge&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20Mac-blueviolet?style=for-the-badge)](https://github.com/Vridhi29/calculator-c)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)]()
[![Open to Internships](https://img.shields.io/badge/Open%20To-Internships-orange?style=for-the-badge&logo=linkedin)]()

<br/>

> **A clean, modular, menu-driven calculator written in C — built from scratch as part of my systems programming journey.**

</div>

---

## 👩‍💻 About This Project

This is one of my early projects as I learn **C programming** from the ground up. I wanted to go beyond a single-file script and build something that reflects how real software is structured — with separate files for logic, UI, and headers.

The goal wasn't just to make a calculator. It was to learn:
- How to split C code across multiple files
- How to use a `Makefile` to automate builds
- How to handle errors properly instead of letting the program crash
- How to use Git and push a project to GitHub

---

## ✨ Features

| Feature | Details |
|--------|---------|
| ➕ Addition | `a + b` |
| ➖ Subtraction | `a - b` |
| ✖️ Multiplication | `a * b` |
| ➗ Division | `a / b` with divide-by-zero protection |
| **%** Modulus | `a % b` |
| **^** Power | `a ^ b` using `pow()` |
| **√** Square Root | `sqrt(a)` with negative number check |
| **\|x\|** Absolute Value | `fabs(a)` |

---

## 🗂️ Project Structure

```
calculator-c/
│
├── 📁 include/
│   └── calculator.h       ← types, constants & function declarations
│
├── 📁 src/
│   ├── main.c             ← main loop & menu dispatcher
│   ├── operations.c       ← all 8 arithmetic functions
│   └── ui.c               ← display, input handling, colours
│
├── 📄 Makefile            ← build automation
├── 📄 README.md           ← you are here!
└── 📄 LICENSE             ← MIT
```

---

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make (Linux/Mac) or GCC directly (Windows)

### Clone & Run

```bash
# Clone the repo
git clone https://github.com/Vridhi29/calculator-c.git
cd calculator-c

# Linux / Mac
make
./calculator

# Windows (Git Bash)
gcc -Wall -Iinclude main.c operations.c ui.c -o calculator -lm
./calculator
```

---

## 🖥️ How It Looks

```
  +==============================+
  |   C M E N U  CALCULATOR     |
  +==============================+
  ------------------------------
  [1]  Addition         (a + b)
  [2]  Subtraction      (a - b)
  [3]  Multiplication   (a * b)
  [4]  Division         (a / b)
  [5]  Modulus          (a % b)
  [6]  Power            (a ^ b)
  [7]  Square Root      (sqrt a)
  [8]  Absolute Value   (|a|)
  ------------------------------
  [0]  Exit
  ------------------------------
  Enter choice: 4
  Enter operand A: 22
  Enter operand B: 7

  [=] Result = 3.14286
```

---

## 🛡️ Error Handling

The program never crashes — every edge case is handled gracefully:

```
  Enter operand A: 10
  Enter operand B: 0

  [!] Error: Division by zero
```

| Scenario | Response |
|----------|----------|
| Division by zero | `Error: Division by zero` |
| Modulus by zero | `Error: Modulus by zero` |
| Square root of negative | `Error: Square root of negative number` |
| 0 raised to negative power | `Error: 0 raised to negative exponent` |
| Non-numeric input | Flushes buffer and re-prompts |

---

## 🧠 What I Learned

- **Multi-file C projects** — separating concerns into `main.c`, `operations.c`, and `ui.c`
- **Header files** — declaring types and functions in `.h` files so all source files can share them
- **Enums & Structs** — using `typedef enum` for operations and `typedef struct` for returning results cleanly
- **Error propagation** — returning a `CalcResult` struct with a status code + message instead of just a number
- **Makefile basics** — automating compilation with targets like `make`, `make debug`, `make clean`
- **Git workflow** — `init → add → commit → push` to publish code on GitHub

---

## 📌 Concepts Used

![C](https://img.shields.io/badge/C-Programming-blue?style=flat-square&logo=c)
![GCC](https://img.shields.io/badge/GCC-Compiler-lightgrey?style=flat-square&logo=gnu)
![Make](https://img.shields.io/badge/Make-Build%20Tool-informational?style=flat-square)
![Git](https://img.shields.io/badge/Git-Version%20Control-orange?style=flat-square&logo=git)
![CLI](https://img.shields.io/badge/CLI-Terminal%20App-black?style=flat-square&logo=windowsterminal)

---

## 🙋‍♀️ About Me

I'm **Vridhi**, a student currently learning C programming and systems concepts. This project is part of my journey to build a strong foundation in computer science fundamentals.

- 🎓 Currently learning: C, Data Structures, Git
- 📫 Reach me: [GitHub](https://github.com/Vridhi29)

---

## 📄 License

This project is licensed under the **MIT License** — feel free to use, modify, and share it.

---

<div align="center">

![Footer](https://capsule-render.vercel.app/api?type=waving&color=0:0f3460,50:16213e,100:1a1a2e&height=120&section=footer)

⭐ **If you found this helpful, consider giving it a star!** ⭐

</div>
