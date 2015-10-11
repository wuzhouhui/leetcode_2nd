#include <stdlib.h>

static int **res, *col, p, maxp;

static void add(int *tmp, int n)
{

	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = tmp;
	col[p] = n;
	p++;
}

int **generate(int numRows, int **columnSizes, int *returnSize)
{
	int	i, j, *tmp;

	res = 0;
	p = 0;
	col = 0;
	for (i = 1; i <= numRows; i++) {
		tmp = malloc(i * sizeof(int));
		for (j = 0; j < i; j++) {
			if (j == 0 || j == i - 1)
				tmp[j] = 1;
			else
				tmp[j] = res[p - 1][j - 1] +
					res[p - 1][j];
		}
		add(tmp, i);
	}
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	**res, *col;
	int i, j, n;

	res = generate(4, &col, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < col[i]; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return(0);
}
