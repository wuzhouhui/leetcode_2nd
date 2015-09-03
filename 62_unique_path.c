int uniquePaths(int m, int n)
{
	static int paths[100][100];
	int	i, j;

	if (!m || !n)
		return(0);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (!i || !j)
				paths[i][j] = 1;
			else
				paths[i][j] = paths[i - 1][j] +
					paths[i][j - 1];
		}
	}
	return(paths[m - 1][n - 1]);
}

int main(void)
{
}
