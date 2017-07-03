#include <stdlib.h>
#include <stdio.h>

void	print_tab(int **tab, int input)
{
	int j = 0;
	int k = 0;

	while (k < input && j < input)
	{
		printf("%d", tab[j][k++]);
		printf(",");
		if (k == input)
		{
			printf("\n");
			k = 0;
			j++;
		}
	}
}

int	**spiral(int input)
{
	int	**tab;
	int	j = 0;
	int	k = 0;
	int	count = 1;
	int	kmax = input;
	int	jmax = input;
	int	kmin = -1;
	int	jmin = 0;

	if (input == 1)
		printf("%d\n", input);
	if (input < 1)
		printf("error: input < 1");
	if (!(tab = malloc(sizeof(tab) * input)))
		return (NULL);
	while (j < input)
	{
		if (!(tab[j++] = malloc(sizeof(*tab) * input)))
			return (NULL);
	}
	j = 0;
	while (count < (input * input))
	{
		if (j == jmin)
			kmax--;
		while (k < kmax)	//right
		{
			tab[j][k] = count;
			k++;
			count++;
		}
		if (k == kmax)
			jmax--;
		while (j < jmax)	//down
		{
			tab[j][k] = count;
			j++;
			count++;
		}
		if (j == jmax)
			kmin++;
		while (k > kmin)	//left
		{
			tab[j][k] = count;
			k--;
			count++;
		}
		if (k == kmin)
			jmin++;
		while (j > jmin)	//up
		{
			tab[j][k] = count;
			j--;
			count++;
		}
		if (count == (input * input))
			tab[j][k] = count;
	}
	print_tab(tab, input);
	free(tab);
	return (0);
}

int	main(int ac, char **av)
{
	int input = atoi(av[1]);

	if (ac == 2)
		spiral(input);
	if (ac != 2)
		printf("error: too many arguments");
	return (0);
}
