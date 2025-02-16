/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:29:01 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/16 10:04:15 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_instructions(char *inst_arr, t_list **head, t_list **lb)
{
	int		i;
	char	**instructions;

	i = 0;
	instructions = ft_split(inst_arr, ' ');
	if (!instructions)
		return (free_arr(instructions));
	while (instructions[i])
	{
		perform_sorting(instructions[i], head, lb);
		i++;
	}
	free_arr(instructions);
}

int	is_valid(char *inst)
{
	if (ft_strncmp(inst, "sa", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "sb", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "ss", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "pa", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "pb", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "ra", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "rb", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "rr", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "rra", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "rrb", ft_strlen(inst) - 1) == 0)
		return (1);
	else if (ft_strncmp(inst, "rrr", ft_strlen(inst) - 1) == 0)
		return (1);
	else
		return (0);
}
