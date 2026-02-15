#include "push_swap.h"

// sa | sb: swap top two elements
// (implemented by swapping contents of first 2 nodes)
void	swap(t_list **s)
{
	int	tmp;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = *(int *)(*s)->content;
	*(int *)(*s)->content = *(int *)(*s)->next->content;
	*(int *)(*s)->next->content = tmp;
}

// pa | pb: function that takes the first element
// at the top of s1 and put it at the top of s2
void	push(t_list **s1, t_list **s2)
{
	t_list	*head;

	if (!s1 || !*s1)
		return ;
	head = *s1;
	*s1 = head->next;
	head->next = *s2;
	*s2 = head;
}

// ra / rb: rotate up (first element becomes last)
void	rotate(t_list **s)
{
	t_list	*first;
	t_list	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
}

// rra / rrb: reverse rotate (last element becomes first)
void	reverse_rotate(t_list **s)
{
	t_list	*cur;

	if (!s || !*s || !(*s)->next)
		return ;
	cur = *s;
	while (cur->next->next)
		cur = cur->next;
	cur->next->next = *s;
	*s = cur->next;
	cur->next = NULL;
}
