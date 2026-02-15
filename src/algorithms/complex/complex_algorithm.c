#include "push_swap.h"
#include <stdlib.h>

static void	radix_sort(t_list **stack_a, t_list **stack_b, t_simple_ops **ops,
		int i)
{
	if ((*(int *)(*stack_a)->content >> i) & 1)
	{
		rotate(stack_a);
		ft_printf("ra\n");
		(*ops)->ra++;
	}
	else
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
		(*ops)->pb++;
	}
}

static void	complex_sort_stack(t_list **stack_a, t_simple_ops *ops)
{
	t_list	*stack_b;
	int		i;
	int		max;
	int		size;

	stack_b = NULL;
	i = 0;
	size = ft_lstsize(*stack_a);
	max = binary_digit_count(size - 1);
	while (max--)
	{
		while (size--)
			radix_sort(stack_a, &stack_b, &ops, i);
		size = ft_lstsize(stack_b);
		while (size--)
		{
			push(&stack_b, stack_a);
			ft_printf("pa\n");
			ops->pa++;
		}
		size = ft_lstsize(*stack_a);
		i++;
	}
}

void	complex_sort(t_list **s, int bench_mode)
{
	t_list			*stack_a;
	t_simple_ops	ops;
	double			disorder;

	if (!s || !*s)
		return ;
	stack_a = indexing(s);
	init_ops(&ops);
	disorder = compute_disorder(stack_a);
	if (disorder == 0.00)
	{
		ft_lstclear(&stack_a, free);
		if (bench_mode)
			bench_report(disorder, "Complex / O(nlogn)", ops);
		return ;
	}
	if (disorder == 1.00)
		worst_order_sort(s, &ops);
	else
		complex_sort_stack(&stack_a, &ops);
	ft_lstclear(&stack_a, free);
	if (bench_mode)
		bench_report(disorder, "Complex / O(nlogn)", ops);
}
