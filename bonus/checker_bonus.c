/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:07:05 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/16 10:18:04 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*prev;
	t_list	*la;

	if (*stack_b)
		return (0);
	la = *stack_a;
	prev = la;
	while (la)
	{
		if (la->content < prev->content)
			return (0);
		prev = la;
		la = la->next;
	}
	return (1);
}

void	free_list(t_list **head, t_list **lb)
{
	ft_lstclear(head, free);
	ft_lstclear(lb, free);
}

void	perform_sorting(char *inst, t_list **head, t_list **lb)
{
	if (ft_strncmp(inst, "sa", ft_strlen(inst) - 1) == 0)
		swap(head, 's');
	else if (ft_strncmp(inst, "sb", ft_strlen(inst) - 1) == 0)
		swap(lb, 's');
	else if (ft_strncmp(inst, "ss", ft_strlen(inst) - 1) == 0)
		checker_ss(head, lb);
	else if (ft_strncmp(inst, "pa", ft_strlen(inst) - 1) == 0)
		push(head, lb, 's');
	else if (ft_strncmp(inst, "pb", ft_strlen(inst) - 1) == 0)
		push(lb, head, 's');
	else if (ft_strncmp(inst, "ra", ft_strlen(inst) - 1) == 0)
		rotation(head, 's');
	else if (ft_strncmp(inst, "rb", ft_strlen(inst) - 1) == 0)
		rotation(lb, 's');
	else if (ft_strncmp(inst, "rr", ft_strlen(inst) - 1) == 0)
		checker_rr(head, lb);
	else if (ft_strncmp(inst, "rra", ft_strlen(inst) - 1) == 0)
		rrotation(head, 's');
	else if (ft_strncmp(inst, "rrb", ft_strlen(inst) - 1) == 0)
		rrotation(lb, 's');
	else if (ft_strncmp(inst, "rrr", ft_strlen(inst) - 1) == 0)
		checker_rrr(head, lb);
}

void	read_instructions(t_list **head, t_list **lb)
{
	char	*inst;
	char	*inst_arr;
	char	*tmp;

	inst = get_next_line(0);
	inst_arr = NULL;
	tmp = NULL;
	while (inst)
	{
		if (ft_strlen(inst) > 4 || ft_strlen(inst) <= 2 || !is_valid(inst))
			return (write(2, "Error\n", 6), free(inst), free(inst_arr), \
			free_list(head, lb), exit(1));
		tmp = ft_strjoin(inst_arr, inst);
		free(inst_arr);
		inst_arr = ft_strjoin(tmp, " ");
		if (!tmp || !inst_arr)
			return (free(tmp), free(inst_arr));
		free(inst);
		free(tmp);
		inst = get_next_line(0);
	}
	return (execute_instructions(inst_arr, head, lb), free(inst_arr));
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*lb;

	head = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!parse_nums(ft_strdup(av[1]), &head) && write(2, "Error\n", 6))
			return (ft_lstclear(&head, free), 1);
	}
	else if (!parse_nums(arr_strjoin(av + 1, ac - 1), &head))
		return (write(2, "Error\n", 6), ft_lstclear(&head, free), 1);
	if (is_dup(head) && write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	lb = NULL;
	read_instructions(&head, &lb);
	if (check_sorted(&head, &lb))
		return (ft_printf("OK\n"), free_list(&head, &lb), 0);
	return (ft_printf("KO\n"), free_list(&head, &lb), 0);
}
