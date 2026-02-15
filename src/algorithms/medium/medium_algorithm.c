#include "push_swap.h"

void	chunk_based_sort(t_list **s, t_list *indexed_stack, t_simple_ops *ops)
{
	t_list			*b;
	t_chunk			*chunk;

	b = NULL;
	chunk = init_chunk(ft_lstsize(*s));
	push_chunks(&indexed_stack, &b, *chunk, ops);
	reinsert_all_from_b(&indexed_stack, &b, ops);
	rotate_a_min_to_top(&indexed_stack, ops);
	free(chunk);
	ft_lstclear(&indexed_stack, free);
	if (b != NULL)
		ft_lstclear(&b, free);
}

void	medium_sort(t_list **s, int bench_mode)
{
	t_simple_ops	ops;
	double			disorder;
	t_list			*indexed_stack;

	if (!s || !*s)
		return ;
	init_ops(&ops);
	indexed_stack = indexing(s);
	disorder = compute_disorder(indexed_stack);
	if (disorder == 0.0)
	{
		ft_lstclear(&indexed_stack, free);
		if (bench_mode)
			bench_report(disorder, "Medium / O(n√n)", ops);
		return ;
	}
	if (disorder == 1.0)
		worst_order_sort(s, &ops);
	else
		chunk_based_sort(s, indexed_stack, &ops);
	if (bench_mode)
		bench_report(disorder, "Medium / O(n√n)", ops);
}
