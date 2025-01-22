/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/22 12:25:56 by kkoujan          ###   ########.fr       */
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

int main(int ac, char **av)
{
	char	**nums;
	int		i;
	int		nb;
	t_list	*head;

	i = 0;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		while (nums[i])
		{
			if (!is_number(nums[i]))
				return (printf("Error\n"), 1);
			nb = ft_atoi(nums[i]);
			if ((nb == 0 || nb == -1) && ft_strlen(nums[i]) > 2)
				return (printf("Error\n"), 1);
			if (i == 0)
				head = ft_lstnew(nb);
			else
				ft_lstadd_back(&head, ft_lstnew(nb));
			i++;
		}
		while (head)
		{
		printf("%i ", head->content);
		head = head->next;
		}
	}
}
