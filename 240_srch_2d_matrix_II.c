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
		if (target == matrix[i][j])
			return(1);
		else if (target < matrix[i][j])
			j--;
		else
			i++;
	}
	return(0);
}

int main(void)
{
}
