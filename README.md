*This project has been created as part of the 42 curriculum by ekirgin.*

# ft_printf

## Description

`ft_printf` is a 42 project that recreates a simplified version of the standard C `printf()` function.

The goal of this project is to understand variadic functions in C, formatted output, type-specific argument handling, and character counting. The final result is a static library named `libftprintf.a`, which contains the function:

```c
int ft_printf(const char *format, ...);
```

`ft_printf` writes formatted output to standard output and returns the number of characters printed.

This implementation covers the mandatory conversions required by the subject:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This creates the static library:

```text
libftprintf.a
```

### Cleaning object files

```bash
make clean
```

### Full clean

```bash
make fclean
```

### Rebuild

```bash
make re
```

### Example usage

Create a test file, for example `main.c`:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "42");
	ft_printf("Number: %d\n", -42);
	ft_printf("Hex: %x\n", 255);
	return (0);
}
```

Compile it with:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Run it:

```bash
./test
```

## Implementation Overview

The project is split into small helper functions to keep the code readable and easy to test.

### Main parser

The `ft_printf` function loops through the format string character by character.

If the current character is not `%`, it is printed directly with `ft_print_char`.

If the current character is `%`, the next character is treated as a conversion specifier, and the correct helper function is called.

### Conversion dispatcher

The conversion dispatcher receives the character after `%` and calls the matching helper function:

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

## Algorithm and Data Structure Explanation

This project does not require complex data structures. The main data structure used is `va_list`, which allows access to a variable number of arguments.

The algorithm follows these steps:

1. Initialize a `va_list` with `va_start`.
2. Iterate through the format string.
3. Print normal characters directly.
4. When `%` is found, inspect the next character.
5. Retrieve the correct argument type with `va_arg`.
6. Print the value using the correct helper function.
7. Add each helper function's return value to the total character count.
8. Clean up the `va_list` with `va_end`.
9. Return the total number of printed characters.

## Files

| File | Purpose |
|---|---|
| `ft_printf.c` | Main parser and conversion dispatcher |
| `ft_printf.h` | Header file with function prototypes |
| `ft_print_char.c` | Character and string printing |
| `ft_print_number.c` | Signed and unsigned decimal printing |
| `ft_print_hex.c` | Lowercase and uppercase hexadecimal printing |
| `ft_print_pointer.c` | Pointer address printing |
| `Makefile` | Builds the static library |

## Testing

During development, the implementation was tested against the original `printf` using edge cases such as:

- Empty strings
- Null strings
- Null pointers
- `INT_MIN`
- `INT_MAX`
- `UINT_MAX`
- Lowercase and uppercase hexadecimal values
- Multiple conversions in one format string
- Return value comparison with `printf`

## Resources

The following resources were useful for understanding the concepts behind this project:

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- C documentation about variadic functions
- The 42 `ft_printf` subject

## AI Usage

AI was used as a learning assistant during this project.

It helped with:

- Explaining variadic functions and `va_list`
- Suggesting edge cases for testing

AI was not used as a replacement for understanding the code. Each function was written, tested, and reviewed step by step.