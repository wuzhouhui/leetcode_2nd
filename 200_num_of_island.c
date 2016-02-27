#include <string.h>

static char acce[512][512];

static void do_srch(char **grid, int row, int col, int r, int c)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (grid[r][c] == '0')
		return;
	if (acce[r][c])
		return;
	acce[r][c] = 1;
	do_srch(grid, row, col, r - 1, c);
	do_srch(grid, row, col, r + 1, c);
	do_srch(grid, row, col, r, c + 1);
	do_srch(grid, row, col, r, c - 1);
}

int numIslands(char **grid, int gridRowSize, int gridColSize)
{
	int	i, j, res;

	memset(acce, 0, sizeof(acce));
	res = 0;
	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] == '0')
				continue;
			if (acce[i][j])
				continue;
			res++;
			do_srch(grid, gridRowSize, gridColSize, i, j);
		}
	}
	return(res);
}

int main(void)
{
	char	*s0 = "11000";
	char	*s1 = "11000";
	char	*s2 = "00100";
	char	*s3 = "00011";
	char	*grid[] = { s0, s1, s2, s3, };
	return(numIslands(grid, 5, 5));
}
