/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:16:24 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/08 09:28:50 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_strtoint(const char *str, int sign)
{
	int	result;
	int	max;

	max = 0;
	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result < max && result != -2147483648)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		max = result;
		str++;
	}
	if (result * sign > 0 && sign == -1)
		return (0);
	if (result * sign < 0 && sign == 1)
		return (-1);
	return ((int)result * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (ft_strtoint(str, sign));
}
