#include "push_swap.h"

void	sa(t_list **s, t_simple_ops *ops)
{
	swap(s);
	ops->sa++;
	ft_printf("sa\n");
}


int	handle_sort_three_cases(t_list **s, t_simple_ops *ops)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*s)->content;
	b = *(int *)(*s)->next->content;
	c = *(int *)(*s)->next->next->content;
	if (a > b && b > c)
	{
		sa(s, ops);
		rra(s, ops,1);
	}
	else if (a > b && b < c && a > c)
		ra(s, ops,1);
	else if (a > b && b < c && a < c)
		sa(s, ops);
	else if (a < b && b > c && a < c)
	{
		sa(s, ops);
		ra(s, ops,1);
	}
	else if (a < b && b > c && a > c)
		rra(s, ops,1);
	return (1);
}

void	sort_three(t_list **s, int bench_mode)
{
	t_simple_ops	ops;
	int				disorder;
	int				a;
	int				b;
	int				c;

	a = *(int *)(*s)->content;
	b = *(int *)(*s)->next->content;
	c = *(int *)(*s)->next->next->content;
	init_ops(&ops);
	disorder = compute_disorder(*s);
	if (a < b && b < c)
	{
		if (bench_mode)
			bench_report(disorder, "Complex / O(nlogn)", ops);
		return ;
	}
	handle_sort_three_cases(s, &ops);
	if (bench_mode)
		bench_report(disorder, "Complex / O(nlogn)", ops);
}

