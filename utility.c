/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:31:27 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/13 10:50:38 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

int	ft_isspace(char str)
{
	if ((str > 8 && str < 14) || str == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	final;

	final = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (ft_isdigit(*str))
		final = (final * 10) + (*str++ - 48);
	return (final * sign);
}

uint64_t	ft_modulus(uint64_t a, uint64_t b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}