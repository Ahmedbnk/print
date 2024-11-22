#include "ft_printf.h"

void print_string(va_list arg, int *p_count)
{
	 char *content= va_arg(arg, char*);
	while (*content != '\0')
	{
		print_char(*content, p_count);
		content ++;
	}
}
