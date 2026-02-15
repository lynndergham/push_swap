#include "push_swap.h"

int	has_index_in_range(t_list *a, int low, int high)
{
	t_list	*cur;
	int		idx;

	if (!a || low < 0 || high < 0 || high < low)
		return (0);
	cur = a;
	while (cur)
	{
		idx = *(int *)cur->content;
		if (idx >= low && idx <= high)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static t_list	*rotate_helper(t_list **a, int low, int high)
{
	t_list	*cur;
	int		idx;
	int		rot;
	int		min_rot;
	t_list	*best_node;

	cur = *a;
	min_rot = INT_MAX;
	best_node = NULL;
	while (cur)
	{
		idx = *(int *)cur->content;
		if (idx >= low && idx <= high)
		{
			rot = compute_rotations_to_top(*a, cur);
			if (abs(rot) < min_rot)
			{
				min_rot = abs(rot);
				best_node = cur;
			}
		}
		cur = cur->next;
	}
	return (best_node);
}

void	rotate_to_range_top(t_list **a, int low, int high, t_simple_ops *ops)
{
	t_list	*best_node;
	int		rot;

	if (!a || !*a || low < 0 || high < 0 || high < low
		|| !has_index_in_range(*a, low, high))
		return ;
	best_node = rotate_helper(a, low, high);
	if (!best_node)
		return ;
	rot = compute_rotations_to_top(*a, best_node);
	if (rot > 0)
{
    while (rot-- > 0)
        ra(a, ops,1);
}
else if (rot < 0)
{
    while (rot++ < 0)
        rra(a, ops,1);
}
}

void	push_current(t_list **a, t_list **b, int mid_index, t_simple_ops *ops)
{
	if (!a || !b || !*a || mid_index < 0)
		return ;
	push(a, b);
	if (ops)
	{
		ops->pb++;
		ft_printf("pb\n");
	}
	else
		ft_printf("pb\n");
}

void	push_chunks(t_list **a, t_list **b, t_chunk c, t_simple_ops *ops)
{
	int	i;
	int	low;
	int	high;
	int	mid_idx;

	if (!a || !*a || !b)
		return ;
	mid_idx = c.n / 2;
	i = 0;
	while (i < c.chunks)
	{
		low = i * c.chunk_size;
		high = low + c.chunk_size - 1;
		if (high >= c.n)
			high = c.n - 1;
		while (has_index_in_range(*a, low, high))
		{
			rotate_to_range_top(a, low, high, ops);
			push_current(a, b, mid_idx, ops);
		}
		i++;
	}
}
