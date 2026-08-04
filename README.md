*This project has been created as part of the 42 curriculum by emsevind.*

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
- `man stdarg`
- 42 ft_printf subject (v12.1)

### AI usage

I used AI while learning how variadic functions work and while planning the
parser and helper functions. It also gave me example implementations for parts
of the parser, number conversions and pointer conversion. I used those examples
as a starting point, tested the code myself and went through every function so I
could understand what it does. AI was also used to suggest test cases, review
edge cases and help write this README.

---

## Algorithm and data structure

The format string is read from left to right with an integer index. I chose this
because only the character after `%` needs special handling in the mandatory
part. Normal characters can be printed immediately.

When `%` is found, a dispatcher sends the next character to the matching helper
function. Keeping the conversions in separate helpers makes `ft_printf` easier
to read and lets every helper return its own printed character count.

The main data structure is `va_list`. It is used to read each argument with the
correct type. Apart from `va_list`, the project only needs counters and temporary
integer values, so I did not need a list, array or allocated buffer.

Numbers are printed recursively. The recursive call first handles the higher
digits and the current call prints the last digit. This lets the number appear in
the correct order without creating a string or using dynamic memory.

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

Unsigned decimal numbers use division and modulo by 10. Hexadecimal numbers and
pointer addresses use division and modulo by 16. A `long` is used while printing
a signed number so that `INT_MIN` can be made positive safely. `uintptr_t` is used
for pointers because it can hold an address value for hexadecimal conversion.

Each helper function returns the number of characters written, allowing
`ft_printf` to maintain the correct total character count.

No dynamic memory allocation is used because every character can be written as
soon as it is ready.

---

## Project Structure

```text
.
|-- Makefile
|-- README.md
|-- ft_printf.h
|-- ft_printf.c
|-- ft_print_char.c
|-- ft_print_string.c
|-- ft_print_number.c
|-- ft_print_unsigned.c
|-- ft_print_hex.c
|-- ft_print_pointer.c
`-- tests
    `-- test_main.c
```
