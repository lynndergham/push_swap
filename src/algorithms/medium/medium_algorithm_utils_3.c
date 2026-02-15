#include "push_swap.h"

t_chunk	*init_chunk(int n)
{
	int		chunks_nb;
	int		chunk_size;
	t_chunk	*chunk;

	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (n <= 0)
	{
		chunk->n = 0;
		chunk->chunks = 0;
		chunk->chunk_size = 0;
		return (chunk);
	}
	chunks_nb = ft_sqrt(n);
	if (chunks_nb <= 0)
		chunks_nb = 1;
	chunk_size = (n + chunks_nb - 1) / chunks_nb;
	chunk->n = n;
	chunk->chunks = chunks_nb;
	chunk->chunk_size = chunk_size;
	return (chunk);
}

int	get_pos(t_list *s, t_list *node)
{
	int		i;
	t_list	*cur;

	if (!s || !node)
		return (-1);
	i = 0;
	cur = s;
	while (cur)
	{
		if (cur == node)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

static void	swap_int(int *tab, int i, int j)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				swap_int(tab, i, j);
			j++;
		}
		i++;
	}
}

int	*build_array(t_list *s, int n)
{
	int		*arr;
	int		i;
	t_list	*cur;

	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	cur = s;
	i = 0;
	while (cur)
	{
		arr[i++] = *(int *)cur->content;
		cur = cur->next;
	}
	ft_sort_int_tab(arr, n);
	return (arr);
}
