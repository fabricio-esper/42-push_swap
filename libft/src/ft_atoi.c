/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:08:03 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/14 12:52:43 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
		if (*nptr == '-' || *nptr == '+')
			return (0);
	}
	while (ft_isdigit(*nptr))
		nbr = (nbr * 10) + *nptr++ - 48;
	nbr *= sign;
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (nbr);
}
