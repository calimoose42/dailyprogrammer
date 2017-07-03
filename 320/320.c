#include <stdlib.h>
#include <stdio.h>

void	print_tab(int **tab, int input)
{
	int j = 0;
	int k = 0;

	while (j < input)
	{
		while (k < input && j < input)
		{
			printf("%d", tab[j][k]);
			k++;
			if (k == input)
			{
				printf("\n");
				k = 0;
				j++;
			}
		}
	}
}
			


int	**spiral(int input)
{
	int **tab;
	int j = 0;
	int k = 0;
	int count = 1;
	int kmax = input - 1;
	int jmax = input - 1;
	int kmin = 0;
	int jmin = 0;

	if (input == 1)
	{
		printf("%d\n", input);
		return (0);
	}
	if (input <= 0)
	{
		printf("error: input <= 0");
		return (0);
	}
	if (!(tab = malloc(sizeof(tab) * input)))
		return (NULL);
	while (j < input)
	{
		if (!(tab[j] = malloc(sizeof(*tab) * input)))
			return (NULL);
		j++;
	}
	j = 0;
	while (count <= (input * input))
	{
		while (k <= kmax && count < (input * input))	//right
		{
			tab[j][k] = count;
			k++;
			count++;
		}
		if (k > kmax)
		{
			k--;
			j++;
		}
		while (j <= jmax && count < (input * input))	//down
		{
			tab[j][k] = count;
			j++;
			count++;
		}
		if (j > jmax)
		{
			j--;
			k--;
		}
		while (k >= kmin && count < (input * input))	//left
		{
			tab[j][k] = count;
			k--;
			count++;
		}
		if (k < kmin)
		{
			k++;
			j--;
		}
		jmin++;
		while (j >= jmin && count < (input * input))	//up
		{
			tab[j][k] = count;
			j--;
			count++;
		}
		if (j < jmin)
		{
			j++;
			k++;
		}
		kmax--;
		jmax--;
		kmin++;
		if (count == input * input)
			tab[j][k] = count;
		count++;
	}
	print_tab(tab, input);
	free(tab);
	return (0);
}

int	main(int ac, char **av)
{
	int input = atoi(av[1]);
	
	if (ac != 2)
		return (0);
	spiral(input);
	return (0);
}	
