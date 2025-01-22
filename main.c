/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/22 20:59:44 by kkoujan          ###   ########.fr       */
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

int	is_dup(t_list	*head)
{
	t_list	*node;

	node = head->next;
	while (head)
	{
		while (node)
		{
			if (head->content == node->content)
				return (1);
			node = node->next;
		}
		head = head->next;
		if (head)
		{
		node = head->next;			
		}
	}
	return (0);
}

int	check_nums(char *str, t_list **head)
{
	char		**nums;
	int			i;
	int			nb;

	i = 0;
	nums = ft_split(str, ' ');
	while (nums[i])
	{
		if (!is_number(nums[i]))
			return (0);
		nb = ft_atoi(nums[i]);
		if ((nb == 0 || nb == -1) && ft_strlen(nums[i]) > 2)
			return (0);
		if (i == 0)
			*head = ft_lstnew(nb);
		else
			ft_lstadd_back(head, ft_lstnew(nb));
		i++;
		free(nums[i]);
	}
	free(nums);
	return (1);
}

char	*arr_strjoin(char **str, size_t size)
{
	size_t	i;
	char	*arr;
	char	*prev;
	char	*tmp;

	arr = NULL;
	i = 0;
	prev = ft_strdup(str[0]);
	while (++i < size)
	{
		free(prev);
		prev = ft_strjoin(prev, " ");
		free(arr);
		tmp = prev;
		arr = ft_strjoin(prev, str[i]);
		free(tmp);
		prev = arr;
	}
	free(prev);
	return (arr);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%i ", head->content);
		head = head->next;
	}
}

void	f(){system("leaks push_swap");}

int	main(int ac, char **av)
{
	t_list	*head;
	atexit(f);
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!check_nums(av[1], &head) && printf("Error\n"))
			return (1);
	}
	if (!check_nums(arr_strjoin(av + 1, ac - 1), &head) && printf("Error\n"))
		return (1);
	print_list(head);
	if (is_dup(head) && printf("Error\n"))
		return (ft_lstclear(&head, free),1);
}
