/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:07:05 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/31 21:48:53 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*lb;
	char	*inst;
	// atexit(f);
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!parse_nums(ft_strdup(av[1]), &head) && write(2, "Error\n", 6))
			return (ft_lstclear(&head, free), 1);
	}
	else if (!parse_nums(arr_strjoin(av + 1, ac - 1), &head) \
	&& write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	if (is_dup(head) && write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	lb = NULL;
	inst = get_next_line(0);
	while (inst)
	{
		if (ft_strncmp(inst, "sa", 2) == 0)
			swap(&head, 's');
		else if (ft_strncmp(inst, "sb", 2) == 0)
			swap(&lb, 's');
		else if (ft_strncmp(inst, "ss", 2) == 0)
			checker_ss(&head, &lb);
		else if (ft_strncmp(inst, "pa", 2) == 0)
			push(&head, &lb, 's');
		else if (ft_strncmp(inst, "pb", 2) == 0)
			push(&lb, &head, 's');
		else if (ft_strncmp(inst, "ra", 2) == 0)
			rotation(&head, 's');
		else if (ft_strncmp(inst, "rb", 2) == 0)
			rotation(&lb, 's');
		else if (ft_strncmp(inst, "rr", 2) == 0 && ft_strlen(inst) - 1 == 2)
			checker_rr(&head, &lb);
		else if (ft_strncmp(inst, "rra", 3) == 0)
			rrotation(&head, 's');
		else if (ft_strncmp(inst, "rrb", 3) == 0)
			rrotation(&lb, 's');
		else if (ft_strncmp(inst, "rrr", 3) == 0)
			checker_rrr(&head, &lb);
		free(inst);
		inst = get_next_line(0);
	}
	free(inst);
	if (check_sorted(&head, &lb))
		printf("OK\n");
	else
		printf("KO\n");
	ft_lstclear(&head, free);
}
