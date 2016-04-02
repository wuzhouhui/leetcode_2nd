#ifndef bool
#define bool int
#endif

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
		int target)
{
	int	i, j;
	i = 0;
	j = matrixColSize - 1;
	while (i < matrixRowSize && j >= 0) {
		if (matrix[i][j] == target)
			return(1);
		 else if (matrix[i][j] < target)
			 i++;
		 else
			 j--;
	}
	return(0);
}

int main(void)
{
	int	a[] = { 1, 3, 5, 7, };
	int	b[] = { 10, 11, 16, 20, };
	int	c[] = { 23, 30, 34, 50, };
	int	*d[] = { a, b, c, };
	return(searchMatrix(d, 3, 4, 3));
}
