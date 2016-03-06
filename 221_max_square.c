int maximalSquare(char **matrix, int matrixRowSize, int matrixColSize)
{
	if (matrixRowSize < 1 || matrixColSize < 1)
		return(0);

	int	area[matrixRowSize][matrixColSize];
	int	i, j, t, max;

	max = 0;
	for (i = 0; i < matrixRowSize; i++) {
		for (j = 0; j < matrixColSize; j++) {
			if (!i || !j)
				area[i][j] = matrix[i][j] == '1' ? 1 : 0;
			else if (matrix[i][j] == '0')
				area[i][j] = 0;
			else if (matrix[i - 1][j] == '0' ||
					matrix[i][j - 1] == '0')
				area[i][j] = 1;
			else {
				t = area[i - 1][j - 1];
				if (area[i - 1][j] < t)
					t = area[i - 1][j];
				if (area[i][j - 1] < t)
					t = area[i][j - 1];
				area[i][j] = t + 1;
			}
			t = area[i][j] * area[i][j];
			if (t > max)
				max = t;
		}
	}
	return(max);
}

int main(void)
{
}
