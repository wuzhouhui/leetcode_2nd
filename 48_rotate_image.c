void rotate(int **matrix, int matrixRowSize, int matrixColSize)
{
	int	t, i, start, len;

	start = 0;
	len = matrixColSize;
	while (len > 0) {
		for (i = 0; i < (len - 1); i++) {
			t = matrix[start][start + i];
			matrix[start][start + i] = matrix[matrixRowSize - start - 1 - i][start];
			matrix[matrixRowSize - start - 1 - i][start] =
				matrix[matrixRowSize - start - 1][matrixRowSize - start - 1 - i];
			matrix[matrixRowSize - start - 1][matrixRowSize - start - 1 - i] =
				matrix[start + i][matrixRowSize - start - 1];
			matrix[start + i][matrixRowSize - start - 1] = t;
		}
		start++;
		len -= 2;
	}
	return;
}

#include <stdio.h>

int main(void)
{
	int	i, j;

	int	a[] = { 1, 1, 1, 1, };
	int	b[] = { 2, 2, 2, 2, };
	int	c[] = { 3, 3, 3, 3, };
	int	d[] = { 4, 4, 4, 4, };
	int	*m[] = { a, b, c, d, };
	rotate(m, 3, 3);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	return(0);
}
