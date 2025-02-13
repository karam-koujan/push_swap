/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:03:29 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/13 20:52:04 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_nums(char *str)
{
	int		nb;
	char	*str_copy;

	if (!is_number(str))
		return (0);
	nb = ft_atoi(str);
	str_copy = remove_leading_zeros(str);
	if (!str_copy)
		return (0);
	if ((nb == 0 || nb == -1) && ft_strlen(str_copy) > 2)
		return (free(str_copy), 0);
	return (free(str_copy), 1);
}

char	*arr_strjoin(char **str, size_t size)
{
	size_t	i;
	char	*result;
	char	*temp;

	if (size == 0 || !trim(str[0]))
		return (NULL);
	i = 0;
	temp = NULL;
	result = ft_strdup(str[0]);
	if (!result)
		return (NULL);
	while (++i < size)
	{
		if (!trim(str[i]))
			return (free(result), NULL);
		temp = ft_strjoin(result, " ");
		if (!temp)
			return (free(result), NULL);
		free(result);
		result = ft_strjoin(temp, str[i]);
		if (!result)
			return (free(temp), NULL);
		free(temp);
	}
	return (result);
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

int	parse_nums(char *str, t_list **head)
{
	char	**nums;
	int		i;

	i = -1;
	if (str == NULL || !*str)
		return (free(str), 0);
	nums = ft_split(str, ' ');
	if (!nums)
		return (free(str), 0);
	while (nums[++i])
	{
		if (!check_nums(nums[i]))
			return (free_arr(nums), free(str), 0);
		if (i == 0)
		{
			*head = ft_lstnew(ft_atoi(nums[i]));
			if (!head)
				return (free_arr(nums), free(str), 0);
		}
		else
			ft_lstadd_back(head, ft_lstnew(ft_atoi(nums[i])));
	}
	if (i == 0)
		return (free_arr(nums), free(str), 0);
	return (free_arr(nums), free(str), 1);
}
