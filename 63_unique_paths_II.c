int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize,
		int obstacleGridColSize)
{
	static int paths[100][100];
	int	i, j;

	if (!obstacleGridRowSize || !obstacleGridColSize)
		return(0);
	for (i = 0; i < obstacleGridRowSize; i++) {
		for (j = 0; j < obstacleGridColSize; j++) {
			if (obstacleGrid[i][j]) {
				paths[i][j] = 0;
				continue;
			}
			if (i && j) {
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
				continue;
			}
			if (!i && !j)
				paths[0][0] = 1;
			else if (!i)
				paths[0][j] = paths[0][j - 1];
			else
				paths[i][0] = paths[i - 1][0];
		}
	}
	return(paths[obstacleGridRowSize - 1][obstacleGridColSize - 1]);
}

#include <stdio.h>

int main(void)
{
	int	a1[] = { 0, 0, 0};
	int	a2[] = { 0, 1, 0};
	int	a3[] = { 0, 0, 0};
	int	*b[] = { a1, a2, a3 };
	printf("%d\n", uniquePathsWithObstacles(b, 3, 3));
	return(0);
}
