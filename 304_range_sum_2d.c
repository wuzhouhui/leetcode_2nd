#include <stdlib.h>

struct NumMatrix {
	int	**summat;
};

static int region(int **mat, int i, int j)
{
	if (i < 0 || j < 0)
		return(0);
	return(mat[i][j]);
}

struct NumMatrix *NumMatrixCreate(int **matrix, int matrixRowSize,
		int matrixColSize)
{
	struct NumMatrix *nummat;
	int	i, j;

	nummat = malloc(sizeof(*nummat));
	if (!matrixRowSize || !matrixColSize) {
		nummat->summat = NULL;
		return(nummat);
	}

	nummat->summat = malloc(matrixRowSize * sizeof(int *));
	for (i = 0; i < matrixRowSize; i++) {
		nummat->summat[i] = malloc(matrixColSize * sizeof(int));
		nummat->summat[i][0] = matrix[i][0];
		for (j = 1; j < matrixColSize; j++)
			nummat->summat[i][j] = matrix[i][j] +
				nummat->summat[i][j - 1];
	}
	for (j = 0; j < matrixColSize; j++) {
		for (i = 1; i < matrixRowSize; i++)
			nummat->summat[i][j] = nummat->summat[i][j] +
				nummat->summat[i - 1][j];
	}
	return(nummat);
}

int sumRegion(struct NumMatrix *numMatrix, int row1, int col1, int row2,
		int col2)
{
	return(region(numMatrix->summat, row2, col2)
			- region(numMatrix->summat, row1 - 1, col2)
			- region(numMatrix->summat, row2, col1 - 1)
			+ region(numMatrix->summat, row1 - 1, col1 - 1));
}

void NumMatrixFree(struct NumMatrix *numMatrix)
{
	if (numMatrix->summat)
		free(numMatrix->summat);
	free(numMatrix);
}

#include <stdio.h>

int main(void)
{
	int	r0[] = { 3, 0, 1, 4, 2, };
	int	r1[] = { 5, 6, 3, 2, 1, };
	int	r2[] = { 1, 2, 0, 1, 5, };
	int	r3[] = { 4, 1, 0, 1, 7, };
	int	r4[] = { 1, 0, 3, 0, 5, };
	int	*m[] = { r0, r1, r2, r3, r4, };
	struct NumMatrix *p = NumMatrixCreate(m, 5, 5);
	printf("%d %d %d\n", sumRegion(p, 2, 1, 4, 3),
			sumRegion(p, 1, 1, 2, 2),
			sumRegion(p, 1, 2, 2, 4));
	NumMatrixFree(p);
	return(0);
}
