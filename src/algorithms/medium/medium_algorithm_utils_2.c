#include "push_swap.h"

int	compute_rotations_to_top(t_list *s, t_list *node)
{
	int	pos;
	int	n;

	if (!s || !node)
		return (0);
	pos = get_pos(s, node);
	if (pos < 0)
		return (0);
	n = ft_lstsize(s);
	if (pos <= n / 2)
		return (pos);
	return (pos - n);
}

int	compute_rotations_a_for_index(t_list *a, int index)
{
	t_list	*cur;
	t_list	*best;
	int		cur_idx;
	int		next_idx;

	if (!a)
		return (0);
	cur = a;
	best = a;
	while (cur && cur->next)
	{
		cur_idx = *(int *)cur->content;
		next_idx = *(int *)cur->next->content;
		if (cur_idx <= index && index <= next_idx)
			return (compute_rotations_to_top(a, cur->next));
		if (cur_idx < *(int *)best->content)
			best = cur;
		cur = cur->next;
	}
	return (compute_rotations_to_top(a, best));
}

t_list	*find_best_node_in_b(t_list *a, t_list *b, t_cost *best_cost)
{
	t_list	*cur;
	t_list	*best_node;
	t_cost	cost;

	if (!b)
		return (NULL);
	cur = b;
	best_node = b;
	*best_cost = compute_cost(a, b, b);
	cur = cur->next;
	while (cur)
	{
		cost = compute_cost(a, b, cur);
		if (cost.total < best_cost->total)
		{
			*best_cost = cost;
			best_node = cur;
		}
		cur = cur->next;
	}
	return (best_node);
}
