/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/23 20:57:11 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	while (str[i] == ' ')
		i++;
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
void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_nums(char *str, t_list **head)
{
	char	**nums;
	int		i;
	int		nb;
	char	*c_nums;

	i = -1;
	if (str == NULL || !*str)
		return (free(str), 0);
	nums = ft_split(str, ' ');
	c_nums = NULL;
	while (nums[++i])
	{
		if (!is_number(nums[i]))
			return (free_arr(nums),free(str), 0);
		nb = ft_atoi(nums[i]);
		c_nums = remove_leading_zeros(nums[i]);
		if ((nb == 0 || nb == -1) && ft_strlen(c_nums) > 2)
			return (free_arr(nums), free(c_nums), free(str), 0);
		if (i == 0)
			*head = ft_lstnew(nb);
		else
			ft_lstadd_back(head, ft_lstnew(nb));
		free(c_nums);
	}
	if (i == 0)
		return (free(str), 0);
	return (free_arr(nums), free(str), 1);
}

char	*arr_strjoin(char **str, size_t size)
{
	size_t	i;
	char	*result;
	char	*temp;
	char	*tr;

	if (size == 0)
		return (NULL);
	i = 0;
	temp = NULL;
	tr = ft_strtrim(str[0], " ");
	if (!str[0][0] || ft_strlen(tr) == 0)
		return (free(tr), NULL);
	result = ft_strdup(str[0]);
	free(tr);
	while (++i < size)
	{
		tr = ft_strtrim(str[i], " ");
		if (!str[i][0] || ft_strlen(tr) == 0)
			return (free(tr), free(result), NULL);
		free(tr);
		temp = ft_strjoin(result, " ");
		free(result);
		result = ft_strjoin(temp, str[i]);
		free(temp);
		tr = NULL;
	}
	return (result);
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
		if (!check_nums(ft_strdup(av[1]), &head) && printf("Error\n"))
			return (ft_lstclear(&head, free),1);
	}
	else if(!check_nums(arr_strjoin(av + 1, ac - 1), &head) && printf("Error\n"))
		return (ft_lstclear(&head, free),1);
	print_list(head);
	if (is_dup(head) && printf("Error\n"))
		return (ft_lstclear(&head, free),1);
	ft_lstclear(&head, free);
	//free(head);
}
