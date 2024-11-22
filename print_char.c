#include "ft_printf.h"
void	print_char(char c, int *p_count)
{
	write(1, &c, 1);
	(*p_count) ++;
}
