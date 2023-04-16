/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:16 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/16 12:58:16 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isspace(const char c);
static int	get_decimals(const char *str);

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	result = get_decimals(str);
	return (result * sign);
}

static int	ft_isspace(const char c)
{
	if ((c >= '\t' && c <= '\r') || (c == ' '))
		return (1);
	return (0);
}

static int	get_decimals(const char *str)
{
	int	decimals;

	decimals = 0;
	while (ft_isdigit(*str))
		decimals = (decimals * 10) + (int)(*str++ - '0');
	return (decimals);
}
