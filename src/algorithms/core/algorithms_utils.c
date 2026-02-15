#include "push_swap.h"

/*
	Initializes all operations count to 0
*/
void	init_ops(t_simple_ops *ops)
{
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
}

/*
	O(n) best-case for perfectly reversed order
*/
void	worst_order_sort(t_list **s, t_simple_ops *ops)
{
	t_list	*b;
	int		size;
	int		i;

	b = NULL;
	size = ft_lstsize(*s);
	i = 0;
	while (i < size - 1)
	{
		reverse_rotate(s);
		ops->rra++;
		ft_printf("rra\n");
		push(s, &b);
		ops->pb++;
		ft_printf("pb\n");
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		push(&b, s);
		ops->pa++;
		ft_printf("pa\n");
		i++;
	}
}
/*
Choose a sorting strategy based on computed disorder
*/

void	adaptive_sort(t_list **s, int bench_mode)
{
	double	disorder;

	disorder = compute_disorder(*s);


	if (ft_lstsize(*s) <= 2)
	{
		simple_sort(s, bench_mode);
		return;
	}

	if (disorder < 0.20)
		simple_sort(s, bench_mode);
	else if (disorder < 0.50)
		medium_sort(s, bench_mode);
	else
		complex_sort(s, bench_mode);
}



static void	print_ops_count(t_simple_ops ops)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ops.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops.rrr, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops.pb, 2);
	ft_putstr_fd("\n", 2);
}

/*
	report template
*/
void	bench_report(double disorder, char *strategy, t_simple_ops ops)
{
	int	total_ops;

	total_ops = ops.pa + ops.pb + ops.ra + ops.rb + ops.rr + ops.rra + ops.rrb
		+ ops.rrr + ops.sa + ops.sb + ops.ss;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdouble_fd(disorder * 100, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_ops_count(ops);
}
