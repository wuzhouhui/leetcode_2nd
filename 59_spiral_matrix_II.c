#include <stdlib.h>

int **generateMatrix(int n)
{
	if (n < 1)
		return(0);
	int	**m;
	int	i, k;
	int	start, end;

	m = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		m[i] = malloc(n * sizeof(int));
	start = 0;
	end = n - 1;

	k = 1;
	while (start < end) {
		for (i = start; i < end; i++)
			m[start][i] = k++;
		for (i = start; i < end; i++)
			m[i][end] = k++;
		for (i = end; i > start; i--)
			m[end][i] = k++;
		for (i = end; i > start; i--)
			m[i][start] = k++;
		start++;
		end--;
	}
	if (start == end)
		m[start][start] = k++;
	return(m);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int	n = atoi(argv[1]);
	int	i, j;
	int	**res;

	res = generateMatrix(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return(0);
}
