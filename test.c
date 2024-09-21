#include <stdio.h>
#include <stdlib.h>

void	allocate_float(float **tab, int size)
{
	*tab = (float*)malloc(sizeof(float) * size);
    for (int i = 0; i < size; i++)
	{
		(*tab)[i] = (0.0 + i);
		printf("count:%i\nvalue:%1.1f\n", i, (*tab)[i]);
	}
}

int	main()
{
	float *array_of_float;
	int size = 8;

	allocate_float(&array_of_float, size);
	int i = 0;
	free(array_of_float);
	return 0;
}