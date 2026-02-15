#include "push_swap.h"

int	contains_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	if (!nums || size <= 1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// function that prints a double to a file descriptor
void	ft_putdouble_fd(double num, int fd)
{
	long long	int_part;
	long long	dec_part;

	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	int_part = (long long)num;
	ft_putnbr_fd(int_part, fd);
	write(fd, ".", 1);
	dec_part = (long long)((num - int_part) * 100.0 + 0.5);
	if (dec_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(dec_part, fd);
}

int	ft_sqrt(int n)
{
	long	x;
	long	nx;

	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	x = n;
	while (1)
	{
		nx = (x + n / x) / 2;
		if (nx >= x)
			break ;
		x = nx;
	}
	return ((int)x);
}

// a function that fills the array with the numbers entered in the cli
int	*fill_array(char **args, int start, int size)
{
	int	i;
	int	overflow;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (0);
	while (i < size)
	{
		array[i] = ft_strtoll(args[start], &overflow);
		i++;
		start++;
	}
	return (array);
}
