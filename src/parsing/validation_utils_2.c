#include "push_swap.h"

static int	check_bench_flag(char **args, int *bench_mode, int *i)
{
	if (is_bench_mode(args[*i]))
	{
		if (*bench_mode == 1)
			return (0);
		*bench_mode = 1;
		(*i)++;
		return (1);
	}
	return (0);
}

static int	check_strategy_flag(char **args, char **strategy, int *i)
{
	if (is_strategy_selector(args[*i]))
	{
		*strategy = args[*i];
		(*i)++;
		return (1);
	}
	return (0);
}

int	check_flags(char **args, char **strategy, int *bench_mode, int *start)
{
	int	strategy_changed;
	int	i;

	strategy_changed = 0;
	i = *start;
	while (i <= 2 && args[i])
	{
		if (check_bench_flag(args, bench_mode, &i))
			continue ;
		if (check_strategy_flag(args, strategy, &i))
		{
			if (strategy_changed == 1)
				return (0);
			strategy_changed = 1;
		}
		else
			break ;
	}
	*start = i;
	return (1);
}

int	validate_numbers(char **args, int i)
{
	int			overflow;
	long long	val;

	while (args[i])
	{
		if (!is_numeric_string(args[i]))
			return (0);
		val = ft_strtoll(args[i], &overflow);
		if (overflow || val < INT_MIN || val > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(char **args, char **strategy, int *bench, int *start)
{
	int			i;

	i = 1;
	*strategy = "--adaptive";
	*bench = 0;
	if (!(check_flags(args, strategy, bench, &i)))
		return (0);
	*start = i;
	if (!validate_numbers(args, i))
		return (0);
	return (1);
}
