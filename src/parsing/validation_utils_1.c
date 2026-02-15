#include "push_swap.h"

int	is_bench_mode(char *s)
{
	return (s && ft_strncmp(s, "--bench", 7) == 0);
}

int	is_strategy_selector(char *s)
{
	if (!s)
		return (0);
	return (ft_strncmp(s, "--simple", 8) == 0 || ft_strncmp(s, "--medium",
			8) == 0 || ft_strncmp(s, "--complex", 9) == 0 || ft_strncmp(s,
			"--adaptive", 10) == 0);
}

int	is_numeric_string(char *s)
{
	int	i;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	skip_whitespace_and_sign(const char *s, int *i, int *sign)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n'))
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}
//convert a string to a long long integer
long long	ft_strtoll(const char *s, int *overflow)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	*overflow = 0;
	skip_whitespace_and_sign(s, &i, &sign);
	while (s[i] && ft_isdigit(s[i]))
	{
		if (result > LLONG_MAX / 10)
			*overflow = 1;
		result = result * 10 + (s[i] - '0');
		if (result < 0)
			*overflow = 1;
		i++;
	}
	return (result * sign);
}
