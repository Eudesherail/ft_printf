*This project has been created as part of the 42 curriculum by esevindi.*

# ft_printf

## Description

The goal of this project is to recreate a simplified version of the standard C
library `printf` function.

The mandatory implementation supports the following conversion specifiers:

- `%c` Character
- `%s` String
- `%p` Pointer address
- `%d` Signed decimal integer
- `%i` Signed integer
- `%u` Unsigned decimal integer
- `%x` Lowercase hexadecimal
- `%X` Uppercase hexadecimal
- `%%` Percent sign

The function writes formatted output to the standard output using the `write()`
system call and returns the total number of printed characters.

Only the mandatory part of the project is implemented.

---

## Instructions

Compile the library:

```sh
make
```

This creates the static library:

```text
libftprintf.a
```

Clean object files:

```sh
make clean
```

Remove object files and the library:

```sh
make fclean
```

Rebuild the entire project:

```sh
make re
```

Example compilation:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a
```

---

## Resources

- `man 3 printf`
- `man 2 write`
- ISO C Standard Library (`<stdarg.h>`)
- 42 ft_printf subject (v12.1)

---

## Algorithm and data structure

The implementation follows a modular design.

The format string is parsed from left to right.

Ordinary characters are written directly to the standard output.

Whenever a `%` character is encountered, the parser dispatches execution to the
appropriate conversion function according to the following specifier.

```
%c -> character
%s -> string
%p -> pointer
%d -> signed integer
%i -> signed integer
%u -> unsigned integer
%x -> hexadecimal (lowercase)
%X -> hexadecimal (uppercase)
%% -> percent sign
```

Numeric conversions are implemented recursively.

Unsigned decimal numbers are converted using repeated division by 10.

Hexadecimal values and pointer addresses are converted using repeated division
by 16.

Each helper function returns the number of characters written, allowing
`ft_printf` to maintain the correct total character count.

No dynamic memory allocation is used.

---

## AI Usage

Artificial Intelligence tools were used as a learning and review assistant for:

- understanding variadic functions
- studying parser architecture
- algorithm discussion
- documentation writing
- code review
- test case generation

---

## Project Structure

.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
├── ft_print_char.c
├── ft_print_string.c
├── ft_print_number.c
├── ft_print_unsigned.c
├── ft_print_hex.c
├── ft_print_pointer.c
└── tests
    └── test_main.c


All implementation decisions, testing, debugging, and final validation were
performed manually by the author.