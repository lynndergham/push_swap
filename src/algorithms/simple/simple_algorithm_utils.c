#include "push_swap.h"

// find the smallest value in a list
int	find_min(t_list *s)
{
	int		min;
	t_list	*cur;

	min = *(int *)s->content;
	if (!s->next)
		return (min);
	cur = s->next;
	while (cur)
	{
		if (*(int *)cur->content < min)
			min = *(int *)cur->content;
		cur = cur->next;
	}
	return (min);
}

// calculate distance of a node from top
int	calculate_distance_from_top(t_list *s, int val)
{
	t_list	*cur;
	int		dist;

	if (!s->next)
		return (0);
	cur = s;
	dist = 0;
	while (cur)
	{
		if (*(int *)cur->content == val)
			break ;
		dist++;
		cur = cur->next;
	}
	return (dist);
}
