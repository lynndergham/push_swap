#include "push_swap.h"
// Free 2D array
static void	free_3d_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static char	**handle_arg(char **argv, int *start, int argc)
{
	char	**args;

	args = ft_split(argv[*start], ' ');
	if (!validate_numbers(args, 0) || *start != argc - 1)
	{
		free_3d_array(args);
		args = NULL;
	}
	*start = 0;
	return (args);
}
static void	call_strategy(t_list **s, char *strategy, int bench_mode)
{
	int	size;

	if (!s || !*s)
		return ;

	size = ft_lstsize(*s);

	if (size == 3)
		sort_three(s, bench_mode);
	else if (!strategy || ft_strncmp(strategy, "--adaptive", 10) == 0)
		adaptive_sort(s, bench_mode);
	else if (ft_strncmp(strategy, "--simple", 8) == 0)
		simple_sort(s, bench_mode);
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
		medium_sort(s, bench_mode);
	else if (ft_strncmp(strategy, "--complex", 9) == 0)
		complex_sort(s, bench_mode);
}

static int	validate_and_parse(char **args, t_list **l, int argc)
{
	int		start;
	int		size;
	int		*array;
	char	*strategy;
	int		bench_mode;

	if (!validate_args(args, &strategy, &bench_mode, &start))
	{
		args = handle_arg(args, &start, argc);
		if (!args)
			return (0);
	}
	size = 0;
	while (args[start + size])
		size++;
	array = fill_array(args, start, size);
	if (!array || contains_duplicates(array, size))
		return (free(array), 0);
	*l = push_values(array, size);
	call_strategy(l, strategy, bench_mode);
	free(array);
	if (start == 0)
		free_3d_array(args);
	return (*l != NULL);
}

int	main(int argc, char **argv)
{
	t_list	*l;

	if (argc < 2)
		return (0);
	if (!validate_and_parse(argv, &l, argc))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_lstclear(&l, free);
	return (0);
}
