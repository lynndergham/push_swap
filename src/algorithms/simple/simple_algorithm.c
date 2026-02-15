#include "push_swap.h"

// Selection sort

// brings a node to the top based on nb (which is the nb of rotations)
// based on smart choice between ra or rra
void	ra(t_list **a, t_simple_ops *ops, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		rotate(a);
		ops->ra++;
		ft_printf("ra\n");
		i++;
	}
}

void	rra(t_list **a, t_simple_ops *ops, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		reverse_rotate(a);
		ops->rra++;
		ft_printf("rra\n");
		i++;
	}
}

static void	selection_sort_pass(t_list **a, t_list **b, t_simple_ops *ops)
{
	int	min;
	int	dist;
	int	n;

	min = find_min(*a);
	dist = calculate_distance_from_top(*a, min);
	n = ft_lstsize(*a);
	if (dist <= n / 2 && dist != 0)
	{
		ra(a, ops, dist);
	}
	else if (dist > n / 2 && dist != 0)
	{
		rra(a, ops, n - dist);
	}
	push(a, b);
	ops->pb++;
	ft_printf("pb\n");
}

static void	selection_sort(t_list **a, t_simple_ops *ops)
{
	int		n;
	int		i;
	t_list	*b;

	n = ft_lstsize(*a);
	i = 0;
	b = NULL;
	while (i < n)
	{
		selection_sort_pass(a, &b, ops);
		i++;
	}
	i = 0;
	n = ft_lstsize(b);
	while (i < n)
	{
		push(&b, a);
		ft_printf("pa\n");
		ops->pa++;
		i++;
	}
}

/*
Simple selection-sort algorithm using push_swap operations
*/
void	simple_sort(t_list **s, int bench_mode)
{
	t_simple_ops	ops;
	double			disorder;

	if (!s || !*s)
		return ;

	init_ops(&ops);

	/* ---- ADD THIS BLOCK ---- */
	if (ft_lstsize(*s) == 2)
	{
		if (*(int *)(*s)->content > *(int *)(*s)->next->content)
			sa(s, &ops);
		if (bench_mode)
			bench_report(0.0, "Simple / O(n²)", ops);
		return ;
	}
	/* ------------------------ */

	disorder = compute_disorder(*s);

	if (disorder == 0.00 || ft_lstsize(*s) < 2)
	{
		if (bench_mode)
			bench_report(disorder, "Simple / O(n²)", ops);
		return ;
	}
	if (disorder == 1.00)
		worst_order_sort(s, &ops);
	else
		selection_sort(s, &ops);
	if (bench_mode)
		bench_report(disorder, "Simple / O(n²)", ops);
}
