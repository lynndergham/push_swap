#include "push_swap.h"
#include <stdlib.h>

// count how many digits in binary
int	binary_digit_count(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 2;
		i++;
	}
	return (i);
}

// from stack to array
int	*to_array(t_list **s)
{
	t_list	*node;
	int		size;
	int		*array;
	int		i;

	size = ft_lstsize(*s);
	array = (int *)malloc(sizeof(int) * size);
	i = 0;
	node = *s;
	while (i < size)
	{
		array[i] = *(int *)node->content;
		i++;
		node = node->next;
	}
	return (array);
}

// simple array sort
int	*sort(int *arr, int size)
{
	int	i;
	int	temp;
	int	*new;

	i = -1;
	temp = 0;
	new = (int *)malloc(sizeof(int) * size);
	if (!new)
		return (NULL);
	while (++i < size)
		new[i] = arr[i];
	i = 0;
	while (i < size)
	{
		temp = new[i++];
		if (i < size && temp > new[i])
		{
			new[i - 1] = new[i];
			new[i] = temp;
			i = 0;
		}
	}
	return (new);
}
