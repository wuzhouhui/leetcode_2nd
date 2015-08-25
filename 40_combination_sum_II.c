#include <stdlib.h>
#include <string.h>

static int **res, resmaxp, resp, *col;
static int *ans, ansmaxp;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void add_ans(int n)
{
	int	i;

	for (i = 0; i < resp; i++) {
		if (col[i] != n)
			continue;
		if (!memcmp(res[i], ans, n * sizeof(int)))
			return;
	}

	if (!res) {
		resmaxp = 8;
		resp = 0;
		res = malloc(resmaxp * sizeof(int *));
		col = malloc(resmaxp * sizeof(int));
	}
	if (resp >= resmaxp) {
		resmaxp += 8;
		res = realloc(res, resmaxp * sizeof(int *));
		col = realloc(col, resmaxp * sizeof(int));
	}
	col[resp] = n;
	res[resp] = malloc(n * sizeof(int));
	memcpy(res[resp], ans, n * sizeof(int));
	resp++;
}

static void do_comb(int *candidates, int candidatesSize, int target,
		int sum, int start, int level)
{
	int	i;

	if (start >= candidatesSize)
		return;
	sum += candidates[start];
	if (sum > target)
		return;

	if (!ans) {
		ansmaxp = 8;
		ans = malloc(ansmaxp * sizeof(int));
	}
	if (level >= ansmaxp) {
		ansmaxp += 8;
		ans = realloc(ans, ansmaxp * sizeof(int));
	}
	ans[level] = candidates[start];
	if (sum == target) {
		add_ans(level + 1);
		return;
	}

	/* sum < target */
	for (i = start + 1; i < candidatesSize; i++) {
		if (sum + candidates[i] > target)
			break;
		do_comb(candidates, candidatesSize, target, sum, i, level + 1);
	}
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	int	i;

	res = 0;
	resp = 0;
	resmaxp = 0;
	ans = 0;
	col = 0;
	ansmaxp = 0;

	qsort(candidates, candidatesSize, sizeof(int), intcmp);
	for (i = 0; i < candidatesSize; i++)
		do_comb(candidates, candidatesSize, target, 0, i, 0);
	*columnSizes = col;
	*returnSize = resp;
	if (ans)
		free(ans);
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 10, 1, 2, 7, 6, 1, 5 };
	int	**res, *col, n, i, j;
	res = combinationSum2(x, 7, 8, &col, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < col[i]; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return(0);
}
