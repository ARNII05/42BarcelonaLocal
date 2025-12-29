#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int main (int argc, char **argv)
{
	int *nums;
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (1);
	while (i < argc)
	{
		nums[i - 1] = ft_atoi(argv[i]);
		if (any_errors(nums[i - 1]))
			ft_printf("Error\n");
		i++;
	}
	push_swap(nums);
	free(nums);
	return (0);
}