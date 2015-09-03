#include <stdlib.h>
#include <string.h>

#define MAXN	32
#define STEP	8

static char ***res;
static int p, maxp;
static char layout[MAXN][MAXN];
static char occupy[MAXN];

static void add_ans(int n)
{
	int	i, j;

	if (!res) {
		maxp = STEP;
		res = malloc(maxp * sizeof(char **));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(char **));
	}
	res[p] = malloc(n * sizeof(char *));
	for (i = 0; i < n; i++) {
		res[p][i] = malloc((n + 1) * sizeof(char));
		for (j = 0; j < n; j++)
			if (layout[i][j])
				res[p][i][j] = 'Q';
			else
				res[p][i][j] = '.';
		res[p][i][j] = 0;
	}
	p++;
}

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
		add_ans(n);
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

char ***solveNQueens(int n, int *returnSize)
{
	if (n < 1) {
		*returnSize = 0;
		return(0);
	}
	memset(layout, 0, sizeof(layout));
	memset(occupy, 0, sizeof(occupy));
	res = 0;
	p = 0;
	do_nqueen(n, 0);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	char ***res;
	int	n, i, j;
	res = solveNQueens(4, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 4; j++)
			printf("%s\n", res[i][j]);
	}
}
