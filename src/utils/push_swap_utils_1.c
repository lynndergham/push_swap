#include "push_swap.h"

int	has_in_range(t_list *s, int min, int max)
{
	while (s)
	{
		if (*(int *)s->content >= min && *(int *)s->content <= max)
			return (1);
		s = s->next;
	}
	return (0);
}

int	find_max(t_list *s)
{
	int	max;

	max = *(int *)s->content;
	while (s)
	{
		if (*(int *)s->content > max)
			max = *(int *)s->content;
		s = s->next;
	}
	return (max);
}

static int	find_pos_in_range(t_list *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (*(int *)a->content >= min && *(int *)a->content <= max)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

static void	apply_rotations_a(t_list **a, int pos, int size, t_simple_ops *ops)
{
	int	bottom;

	bottom = size - pos;
	while (pos <= bottom && pos-- > 0)
	{
		rotate(a);
		ft_printf("ra\n");
		ops->ra++;
	}
	while (pos > bottom && bottom-- > 0)
	{
		reverse_rotate(a);
		ft_printf("rra\n");
		ops->rra++;
	}
}

void	rotate_range_to_top(t_list **a, int min, int max, t_simple_ops *ops)
{
	int	pos;
	int	size;

	pos = find_pos_in_range(*a, min, max);
	if (pos < 0)
		return ;
	size = ft_lstsize(*a);
	apply_rotations_a(a, pos, size, ops);
}
