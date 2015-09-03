#include <stdlib.h>
#include <string.h>

#define MAXN	32
#define STEP	8

static char layout[MAXN][MAXN];
static char occupy[MAXN];
static int	res;

static int avail(int n, int level)
{
	int	i, j;
	int	k, l;

	for (i = 0; i < level; i++) {
		for (j = 0; j < n; j++) {
			if (!layout[i][j])
				continue;
			break;
		}
		for (k = i + 1, l = j - 1; k <= level && l >= 0;
				k++, l--)
			if (layout[k][l])
				return(0);
		for (k = i + 1, l = j + 1; k <= level && l < n;
				k++, l++)
			if (layout[k][l])
				return(0);
	}
	return(1);
}

static void do_nqueen(int n, int level)
{
	int	i;

	if (level >= n) {
		res++;
		return;
	}

	for (i = 0; i < n; i++) {
		if (occupy[i])
			continue;
		occupy[i] = 1;
		layout[level][i] = 1;
		if (avail(n, level))
			do_nqueen(n, level + 1);
		occupy[i] = 0;
		layout[level][i] = 0;
	}
	return;
}

int totalNQueens(int n)
{
	if (n < 1) {
		return(0);
	}
	memset(layout, 0, sizeof(layout));
	memset(occupy, 0, sizeof(occupy));
	res = 0;
	do_nqueen(n, 0);
	return(res);
}

#include <stdio.h>

int main(void)
{
	int res = totalNQueens(4);
	printf("%d\n", res);
}
