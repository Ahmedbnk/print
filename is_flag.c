#include "ft_printf.h"

int is_flag(char c)
{
	char *flags;

	flags = "123456789 .-0+#";
	if (ft_strchr(flags, c) != NULL)
	{
		return (1);
	}
	return (0);
}
