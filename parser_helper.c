/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:06:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/26 15:08:20 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*remove_leading_zeros(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (ft_strdup("0"));
	result = ft_strdup(str + i);
	return (result);
}

int	trim(char *str)
{
	char	*tr;

	tr = ft_strtrim(str, " ");
	if (!tr || !str[0] || ft_strlen(tr) == 0)
		return (free(tr), 0);
	return (free(tr), 1);
}
