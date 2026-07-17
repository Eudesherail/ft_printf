#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	standard;
	int	custom;
	int	value;

	value = 42;
	standard = printf(
			"STD: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "Hello", &value, -42, 42, 42U, 255U, 255U);
	custom = ft_printf(
			"FT : c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "Hello", &value, -42, 42, 42U, 255U, 255U);
	printf("printf return:    %d\n", standard);
	printf("ft_printf return: %d\n", custom);
	return (0);
}