/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:52:28 by abenkrar          #+#    #+#             */
/*   Updated: 2024/11/22 15:07:30 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	operate_mandatory(char **str, va_list arg, t_infos *p_infos, int *p_count)
{
	if (**str == 'c')
		print_char(va_arg(arg, int), p_count);
	else if (**str == 's')
	{
		(*str) ++;
		print_string(arg, p_count);
	}
	printf("%d", p_infos -> width);
	/*else if (*str == 'p')
		print_pointer(str, arg, p_count);
	else if (*str == 'd' || *str == 'i')
		print_number(str, arg, p_count);
	else if (*str == 'u')
		print_unsigned(str, arg, p_count);
	else if (*str == 'x')
		print_lower_hexa(str, arg, p_count);
	else if (*str == 'X')
		print_upper_hexa(str, arg, p_count);*/
}

void	operate_flags(char **str, va_list arg, t_infos *p_infos, int *p_count)
{
	if (ft_isdigit(**str) == 1)
	{
		p_infos -> width = ft_atoi(str);
		operate_flags(str, arg, p_infos, p_count);
		return;
	}
	else if (**str == '.')
		p_infos -> dot = 1;
	else if (**str == '-')
		p_infos -> dash = 1;
	else if (**str == 0)
		p_infos -> zero = 1;
	else if (**str == '#')
		p_infos -> square = 1;
	else if (**str == ' ')
		p_infos -> space = 1;
	else if (**str == '+')
		p_infos -> plus = 1;
	if (is_flag(**str))
	{
		(*str) ++;
	}
	if (is_specif(**str))
		operate_mandatory(str, arg, p_infos, p_count);
	else
		*p_count = -1;
	return;
}

void	operate(char **str, va_list arg, t_infos *p_infos, int *p_count)
{
	if (is_specif(**str) == 1)
	{
		operate_mandatory(str, arg, p_infos, p_count);
		(*str)++;
		return;
	}
	else if (is_flag(**str) == 1)
	{
		operate_flags(str, arg, p_infos, p_count);
		return; 
	}
	*p_count = -1; 
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;
	t_infos	*infos;

	count = 0;
	infos = malloc(sizeof(t_infos));
	if (infos == NULL)
		return (-1);
	va_start(arg, str);
	
	while (*str != '\0')
	{
		if (*str == '%')
		{
			start_infos(infos);
			str++; 
			operate((char **)&str, arg, infos, &count);
			if (count == -1)
				return (-1);
		}
		else
		{
			print_char(*str, &count); 
			str++;
		}
	}
	va_end(arg);
	free(infos);
	return (count);
}

int main()
{
	char x = 'x';
	char *y = "hdhfsh";
	int count = ft_printf("%14s%s", y,y);
	//printf("%d",count);
	return (0);
}
