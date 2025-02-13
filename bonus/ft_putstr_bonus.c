/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:49:27 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/08 09:29:55 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(char *s)
{
	if (s != NULL)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	write(1, "(null)", ft_strlen("(null)"));
	return (ft_strlen("(null)"));
}
