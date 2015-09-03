#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixRowSize, int matrixColSize)
{
	if (!matrixRowSize || !matrixColSize)
		return(0);

	int	*res, p;
	int	rowstart, rowend, colstart, colend, i;

	res = malloc(matrixRowSize * matrixColSize * sizeof(int));
	rowstart = colstart = 0;
	rowend = matrixRowSize - 1;
	colend = matrixColSize - 1;
	p = 0;
	while (rowstart < rowend && colstart < colend) {
		for (i = colstart; i < colend; i++)
			res[p++] = matrix[rowstart][i];
		for (i = rowstart; i < rowend; i++)
			res[p++] = matrix[i][colend];
		for (i = colend; i > colstart; i--)
			res[p++] = matrix[rowend][i];
		for (i = rowend; i > rowstart; i--)
			res[p++] = matrix[i][colstart];
		rowstart++;
		colstart++;
		rowend--;
		colend--;
	}
	if (rowstart == rowend && colstart == colend)
		res[p++] = matrix[rowstart][colstart];
	else if (rowstart < rowend && colstart == colend)
		for (i = rowstart; i <= rowend; i++)
			res[p++] = matrix[i][colstart];
	else if (rowstart == rowend && colstart < colend)
		for (i = colstart; i <= colend; i++)
			res[p++] = matrix[rowstart][i];

	return(res);
}

#include <stdio.h>

int main(void)
{
	int	a1[] = { 1, 2, 3 };
	int	a2[] = { 4, 5, 6 };
	int	a3[] = { 7, 8, 9 };
	int	*b[] = { a1, a2, a3 };
	int	i;

	int	*res = spiralOrder(b, 3, 2);
	for (i = 0; i < 9; i++)
		printf("%d  ", res[i]);
	printf("\n");
	return(0);
}
