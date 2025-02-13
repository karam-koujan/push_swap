/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:11:11 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/13 22:07:32 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

void	free_arr(char **arr);
char	*remove_leading_zeros(char *str);
int		trim(char *str);
int		check_nums(char *str);
char	*arr_strjoin(char **str, size_t size);
int		is_dup(t_list	*head);
int		is_number(char *str);
int		parse_nums(char *str, t_list **head);
void	swap(t_list **head, char stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b, char stack);
void	rotation(t_list **head, char stack);
void	rr(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstrev(t_list *lst);
void	rrotation(t_list **head, char stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	insertion_sort(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_two(t_list **stack_a);
void	sort_chunk(t_list **stack_a, t_list **stack_b, int *arr, int chunk);
void	sort(t_list **stack_a, t_list **stack_b);
int		*list_to_arr(t_list *stack_a);
int		calculate_idx(int *arr, int size, int nb);
void	move_num(t_list **stack_a, t_list **stack_b, int max, char stack);
void	sort(t_list **stack_a, t_list **stack_b);
int		find_limit_idx(int	*arr, int size, char type);
int		is_decreasing(t_list **stack_a, int *arr, int size);

#endif