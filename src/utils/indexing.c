#include "push_swap.h"

static int	*indexing_helper(int *arr, int *sorted, int size)
{
	int	*indexed;
	int	i;
	int	j;

	i = 0;
	j = 0;
	indexed = (int *)malloc(sizeof(int) * size);
	if (!indexed)
		return (NULL);
	while (i < size)
	{
		if (arr[i] == sorted[j])
		{
			indexed[i] = j;
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (indexed);
}

t_list	*indexing(t_list **s)
{
	t_list	*stack_a;
	int		*arr;
	int		*sorted;
	int		*indexed;
	int		size;

	size = ft_lstsize(*s);
	arr = to_array(s);
	sorted = sort(arr, size);
	indexed = indexing_helper(arr, sorted, size);
	free(sorted);
	free(arr);
	stack_a = push_values(indexed, size);
	free(indexed);
	return (stack_a);
}
