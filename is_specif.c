#include "ft_printf.h"

int is_specif(char c)
{
	char *specif;

	specif = "cspdiuxX%";
	if (ft_strchr(specif, c) != NULL)
	{
		return (1);
	}
	return (0);
}
