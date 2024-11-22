/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:59:57 by abenkrar          #+#    #+#             */
/*   Updated: 2024/11/22 10:36:57 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char **str)
{
	int	sign;
	int	resultat;

	sign = 1;
	resultat = 0;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str) ++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
		{
			sign = -1;
		}
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		resultat = resultat * 10;
		resultat = resultat + **str - '0';
		(*str)++;
	}
	resultat *= sign;
	return (resultat);
}
