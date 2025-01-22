/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/22 18:58:35 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_number(char *str)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (i > 1)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
		nums++;
	}
	if (nums == 0)
		return (0);
	return (1);
}

int	is_dup(char	**nums)
{
	int	i;
	int	j;

	i = -1;
	while (nums[++i])
	{
		j = i;
		while (nums[++j])
		{
			if (ft_atoi(nums[i]) == ft_atoi(nums[j]))
				return (1);
		}
	}
	return (0);
}

int	check_nums(int ac, char **str)
{
	char		**nums;
	int			i;
	int			nb;

	i = 0;
	if (ac == 2)
		nums = ft_split(str[1], ' ');
	else
	{
		i = 1;
		nums = str;
	}
	while (nums[i])
	{
		if (ft_strchr(nums[i], ' ') != 0)
		{
			if (!check_nums(2, nums + i - 1))
				return (0);
			i++;
			continue ;
		}
		if (!is_number(nums[i]))
			return (0);
		nb = ft_atoi(nums[i]);
		if ((nb == 0 || nb == -1) && ft_strlen(nums[i]) > 2)
			return (0);
		i++;
	}
	return (1);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%i ", head->content);
		head = head->next;
	}
}

int	main(int ac, char **av)
{

	if (ac == 1)
		return (1);

	if(!check_nums(ac, av) && printf("Error\n"))
			return (1);

}

