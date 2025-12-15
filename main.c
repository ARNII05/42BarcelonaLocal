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
	if (argc < 2)
	{
		printf("No args given");
		return (0);
	}

	int *nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (1);

	for (int i = 1; i < argc; i++)
		nums[i - 1] = ft_atoi(argv[i]); 

	push_swap(nums);

	free(nums);
	return (0);
}