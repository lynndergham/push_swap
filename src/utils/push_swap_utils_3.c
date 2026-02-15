#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*cur;

	cur = stack;
	while (cur)
	{
		ft_printf("%i ", *(int *)cur->content);
		cur = cur->next;
	}
	ft_printf("\n");
}

static int	stack_push_values(t_list **stack, int *a, int size)
{
	t_list	*node;
	int		*i;
	int		idx;

	if (!stack)
		return (0);
	idx = 0;
	while (idx < size)
	{
		i = malloc(sizeof(int));
		if (!i)
			return (0);
		*i = a[idx];
		node = ft_lstnew(i);
		if (!node)
		{
			free(i);
			return (0);
		}
		ft_lstadd_back(stack, node);
		idx++;
	}
	return (1);
}

t_list	*push_values(int *a, int size)
{
	t_list	*stack;

	stack = NULL;
	if (!stack_push_values(&stack, a, size))
	{
		ft_lstclear(&stack, free);
		return (NULL);
	}
	return (stack);
}

double	round_to_two_decimals(double num)
{
	double		scaled;
	long long	rounded;

	scaled = num * 100.0;
	if (scaled >= 0.0)
		rounded = (long long)(scaled + 0.5);
	else
		rounded = (long long)(scaled - 0.5);
	return ((double)rounded / 100.0);
}

double	compute_disorder(t_list *s)
{
	long	mistakes;
	long	total_pairs;
	double	disorder;
	t_list	*i;
	t_list	*j;

	if (!s || !s->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = s;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (*(int *)i->content > *(int *)j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	disorder = round_to_two_decimals((double)mistakes / total_pairs);
	return (disorder);
}
