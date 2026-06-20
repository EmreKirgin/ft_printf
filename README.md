# ft_printf

*This project was created as part of the 42 curriculum by ekirgin.*

## Overview

`ft_printf` is a custom implementation of a simplified version of the standard C `printf()` function. The project focuses on variadic functions, formatted output, type-specific argument handling, recursion, and accurate character counting.

The final output is a static library:

```text
libftprintf.a
```

The library exposes one main function:

```c
int ft_printf(const char *format, ...);
```

`ft_printf` writes formatted output to standard output and returns the number of characters printed.

## Supported Conversions

This implementation covers the mandatory conversions required by the 42 subject.

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal number in lowercase |
| `%X` | Prints an unsigned hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Project Structure

```text
.
├── .github/
│   └── workflows/
│       └── c-build.yml
├── .gitignore
├── README.md
├── ft_printf/
│   ├── Makefile
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── ft_print_char.c
│   ├── ft_print_hex.c
│   ├── ft_print_number.c
│   └── ft_print_pointer.c
└── ft_printf_test/
    ├── Makefile
    ├── compare_output.c
    └── main.c
```

### Source folder

The `ft_printf/` folder contains the library implementation and the Makefile that builds `libftprintf.a`.

### Test folder

The `ft_printf_test/` folder contains local test programs that compare `ft_printf` with the standard `printf` for the mandatory conversion specifiers and several edge cases.

It contains two kinds of tests:

- `main.c`: checks return values against `printf`
- `compare_output.c`: checks both printed output and return values against `printf`

The test folder is not part of the official 42 submission. It is included to make local verification easier and to document how the function behaves.

## Build Instructions

From the repository root, compile the library with:

```bash
make -C ft_printf
```

This creates:

```text
ft_printf/libftprintf.a
```

You can also build directly from inside the implementation folder:

```bash
cd ft_printf
make
```

## Cleaning

Remove object files:

```bash
make -C ft_printf clean
```

Remove object files and the static library:

```bash
make -C ft_printf fclean
```

Rebuild from scratch:

```bash
make -C ft_printf re
```

## Running the Test Folder

From the repository root:

```bash
make -C ft_printf_test re
make -C ft_printf_test run
make -C ft_printf_test compare
```

Or from inside the test folder:

```bash
cd ft_printf_test
make re
make run
make compare
```

The test programs check return values and output against `printf` for cases such as:

- Basic text
- Empty format string
- Characters, including `\0`
- Strings and null strings
- Signed integers with `INT_MIN` and `INT_MAX`
- Unsigned integers with `UINT_MAX`
- Lowercase and uppercase hexadecimal output
- Pointer output, including null pointers
- Percent signs
- Mixed format strings
- Many conversions in one format string
- A trailing percent sign as a crash-safety test


## Implementation Notes

The implementation is split into small helper functions to keep the code readable and maintainable.

| File | Purpose |
|---|---|
| `ft_printf.c` | Main parser and conversion dispatcher |
| `ft_printf.h` | Header file with function prototypes |
| `ft_print_char.c` | Character and string printing |
| `ft_print_number.c` | Signed and unsigned decimal printing |
| `ft_print_hex.c` | Lowercase and uppercase hexadecimal printing |
| `ft_print_pointer.c` | Pointer address printing |
| `Makefile` | Builds the static library |

### Main parser

`ft_printf` iterates through the format string character by character. Normal characters are printed directly. When a `%` character is found, the next character is interpreted as a conversion specifier and passed to the dispatcher.

### Conversion dispatcher

The dispatcher maps each supported specifier to the correct helper function.

| Specifier | Function used |
|---|---|
| `%c` | `ft_print_char` |
| `%s` | `ft_print_string` |
| `%p` | `ft_print_pointer` |
| `%d` | `ft_print_number` |
| `%i` | `ft_print_number` |
| `%u` | `ft_print_unsigned` |
| `%x` | `ft_print_hex` |
| `%X` | `ft_print_hex` |
| `%%` | `ft_print_char` |

### Variadic arguments

The project uses `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` to access the variable number of arguments passed to `ft_printf`.

### Character counting

Each helper function returns the number of characters it prints. `ft_printf` adds these values and returns the total count, matching the expected behavior of `printf` for the supported conversions.

## Limitations

This project implements the mandatory part of the 42 `ft_printf` subject. It does not implement optional formatting features such as:

- Field width
- Precision
- Flags such as `-`, `0`, `.`, `#`, space, or `+`
- Length modifiers such as `l`, `ll`, `h`, or `hh`
- Floating-point conversions

## Automated Testing

This repository includes a GitHub Actions workflow in `.github/workflows/c-build.yml`.

The workflow runs on every push and pull request. It checks that:

- the `ft_printf` library compiles with `-Wall -Wextra -Werror`
- the local test programs compile
- the return-value tests pass
- the output comparison tests pass

## Verification Status

The project was checked locally with:

```bash
make -C ft_printf re
make -C ft_printf_test re
make -C ft_printf_test run
make -C ft_printf_test compare
```

The library and test programs compiled successfully with:

```text
-Wall -Wextra -Werror
```

The included test programs completed successfully for the tested cases.

## Resources

Useful references for this project:

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- 42 `ft_printf` subject

## AI Usage Note

The core `ft_printf` implementation is my own work and corresponds to the version I passed at 42.

AI assistance was used only for repository improvement tasks, including:

- creating additional local test cases
- adding output-comparison testing
- setting up the GitHub Actions workflow
- improving README structure and documentation

All AI-assisted additions were reviewed, tested, and adapted by me before being included in the repository.
