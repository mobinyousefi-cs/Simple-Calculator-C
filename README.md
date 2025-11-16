# Simple Calculator in C

A small but well-structured **command-line calculator** written in C. It supports basic arithmetic operations (addition, subtraction, multiplication, and division) with simple, robust input handling.

The project is organized like a professional C repository, using separate header/source files, a `Makefile`, and a minimal test file.

---

## Features

- ✅ Basic arithmetic: `+`, `-`, `*`, `/`
- ✅ Safe division with **division-by-zero protection**
- ✅ Clean separation of concerns:
  - `calculator.c` / `calculator.h` implement the core logic
  - `main.c` handles user interaction and parsing
- ✅ Simple unit-style tests in `tests/test_calculator.c`
- ✅ `Makefile` for building, cleaning, and (optionally) formatting
- ✅ MIT licensed

---

## Project Structure

```text
simple-calculator-c/
├─ include/
│  └─ calculator.h          # Public API for calculator operations
├─ src/
│  ├─ main.c                # CLI entry point
│  └─ calculator.c          # Core arithmetic logic and helpers
├─ tests/
│  └─ test_calculator.c     # Lightweight tests using <assert.h>
├─ bin/
│  └─ simple_calculator     # (created by the build; not in Git)
├─ build/                   # Object files (generated; not in Git)
├─ Makefile                 # Build configuration
├─ .gitignore               # Ignore build artifacts, IDE files, etc.
├─ .editorconfig            # Editor settings for consistent style
├─ LICENSE                  # MIT License
└─ README.md                # Project documentation (this file)
```

---

## Requirements

- C compiler supporting C11 (e.g., `gcc`, `clang`)
- `make` (for using the provided `Makefile`)

> Tested with GCC using `-std=c11 -Wall -Wextra -Wpedantic`.

---

## Building the Project

From the project root directory, run:

```bash
make
```

This will:

- Compile all sources in `src/`
- Place object files in `build/`
- Generate the final executable in `bin/simple_calculator`

To clean build artifacts:

```bash
make clean
```

> Optional: If you use `clang-format` and want to auto-format the C sources, you can run:
>
> ```bash
> make format
> ```

---

## Running the Calculator

After building, run:

```bash
./bin/simple_calculator
```

Example session:

```text
=============================
  Simple Calculator (C11)
  Author: Mobin Yousefi
=============================

Enter an expression (e.g., 3 + 4) or 'q' to quit.

> 3 + 4
Result: 7

> 10 / 0
Error: Division by zero is not allowed.

> 5 * 8.5
Result: 42.5

> q
Goodbye!
```

---

## Usage Details

- Input format: `number operator number`
  - Example: `12.5 * 3`
- Supported operators:
  - `+` (addition)
  - `-` (subtraction)
  - `*` (multiplication)
  - `/` (division)
- You can use integer or floating-point numbers.
- Type `q` or `Q` at the beginning of the line to exit.

If the input cannot be parsed (e.g., `abc + 3`), the program prints a helpful error message and asks again.

---

## Tests

A very small set of unit-style tests is provided using `<assert.h>`:

```bash
# Build the test binary
make tests

# Run the tests
./bin/test_calculator
```

If all assertions pass, you will see:

```text
All calculator tests passed successfully.
```

---

## Code Style & Conventions

- Standard: **C11**
- Warnings: `-Wall -Wextra -Wpedantic`
- Public functions and types are declared in `include/calculator.h`.
- Implementation details are in `src/calculator.c`.
- `main.c` is intentionally thin and delegates logic to the calculator module.

An `.editorconfig` file is included to help keep formatting consistent across editors.

---

## Extending the Project

Some ideas for future improvements:

- Add more operations: modulo, power, square root, etc.
- Add support for parentheses and operator precedence (expression parser)
- Add a history of previous calculations
- Add a non-interactive mode that reads expressions from command-line arguments or a file
- Add colorized output for errors and results

---

## License

This project is licensed under the **MIT License**. See the `LICENSE` file for details.

---

## Author

**Mobin Yousefi**  
GitHub: [github.com/mobinyousefi-cs](https://github.com/mobinyousefi-cs)

