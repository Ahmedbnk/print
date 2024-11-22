#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
typedef	struct s_infos{
	int width;
	int dash;
	int zero;
	int dot;
	int square;
	int space;
	int plus;
}t_infos;

void	start_infos(t_infos *infos);
char    *ft_strchr(const char *s, int c);
void    print_char(char c, int *p_count);
int	is_specif(char c);
int	is_flag(char c);
void	print_string(va_list arg, int *p_count);
int	ft_isdigit(int c);
int     ft_atoi(char **str);

#endif
