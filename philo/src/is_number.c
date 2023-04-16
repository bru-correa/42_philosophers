/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:40:33 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/16 05:40:33 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	ft_isdigit(int c)
{
	if (((c >= '0') && (c <= '9')))
		return (1);
	return (0);
}
