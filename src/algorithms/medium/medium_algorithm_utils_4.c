#include "push_swap.h"

static void	apply_common_rotations(t_list **a, t_list **b,
		t_cost *cost, t_simple_ops *ops)
{
	while (cost->ra > 0 && cost->rb > 0)
	{
		rotate(a);
		rotate(b);
		ops->rr++;
		ft_printf("rr\n");
		cost->ra--;
		cost->rb--;
	}
	while (cost->ra < 0 && cost->rb < 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ops->rrr++;
		ft_printf("rrr\n");
		cost->ra++;
		cost->rb++;
	}
}

void	apply_rotations(t_list **a, t_list **b, t_cost cost, t_simple_ops *ops)
{
	apply_common_rotations(a, b, &cost, ops);
	while (cost.ra > 0)
	{
		ra(a, ops, 1);
		cost.ra--;
	}
	while (cost.ra < 0)
	{
		rra(a, ops, 1);
		cost.ra++;
	}
	while (cost.rb > 0)
	{
		rotate(b);
		ops->rb++;
		ft_printf("rb\n");
		cost.rb--;
	}
	while (cost.rb < 0)
	{
		reverse_rotate(b);
		ops->rrb++;
		ft_printf("rrb\n");
		cost.rb++;
	}
}

static void	move_target_to_top(t_list **b, int target, t_simple_ops *ops)
{
	t_list	*curr;
	int		pos;
	int		size;
	int		i;

	curr = *b;
	size = ft_lstsize(*b);
	pos = 0;
	i = 0;
	while (curr && *(int *)curr->content != target)
	{
		curr = curr->next;
		i++;
	}
	pos = i;
	if (pos <= size / 2)
		while (pos-- > 0)
			(rotate(b), ops->rb++, ft_printf("rb\n"));
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			(reverse_rotate(b), ops->rrb++, ft_printf("rrb\n"));
	}
}

void	reinsert_all_from_b(t_list **a, t_list **b, t_simple_ops *ops)
{
	int	target;

	if (!b || !*b)
		return ;
	target = ft_lstsize(*b) - 1;
	while (target >= 0)
	{
		move_target_to_top(b, target, ops);
		push(b, a);
		ops->pa++;
		ft_printf("pa\n");
		target--;
	}
}

void	rotate_a_min_to_top(t_list **a, t_simple_ops *ops)
{
	t_list	*cur;
	t_list	*min_node;
	int		min_idx;
	int		dist;

	if (!a || !*a)
		return ;
	cur = *a;
	min_node = cur;
	min_idx = *(int *)cur->content;
	while (cur)
	{
		if (*(int *)cur->content < min_idx)
		{
			min_idx = *(int *)cur->content;
			min_node = cur;
		}
		cur = cur->next;
	}
	dist = get_pos(*a, min_node);
	if (dist <= ft_lstsize(*a) / 2)
		ra(a, ops, dist);
	else
		rra(a, ops, ft_lstsize(*a) - dist);
}
