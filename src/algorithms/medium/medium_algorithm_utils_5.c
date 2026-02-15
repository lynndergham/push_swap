#include "push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_cost	compute_cost(t_list *a, t_list *b, t_list *node)
{
	t_cost	cost;

	cost.ra = compute_rotations_a_for_index(a, *(int *)node->content);
	cost.rb = compute_rotations_to_top(b, node);
	if (cost.ra >= 0 && cost.rb >= 0)
		cost.total = ft_max(cost.ra, cost.rb);
	else if (cost.ra <= 0 && cost.rb <= 0)
		cost.total = ft_max(ft_abs(cost.ra), ft_abs(cost.rb));
	else
		cost.total = ft_abs(cost.ra) + ft_abs(cost.rb);
	return (cost);
}
