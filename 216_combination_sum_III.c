#include <stdlib.h>
#include <string.h>

#define STEP	8

static int **res, p, maxsz;

static void add_ans(const int *ans, int len)
{
	if (res == NULL) {
		p = 0;
		maxsz = STEP;
		res = malloc(maxsz * sizeof(res[0]));
	}
	if (p >= maxsz) {
		maxsz += STEP;
		res = realloc(res, maxsz * sizeof(res[0]));
	}
	res[p] = malloc(len * sizeof(ans[0]));
	memcpy(res[p], ans, len * sizeof(ans[0]));
	p++;
}

static void do_comb(int *ans, int next, int sum, int k, int n)
{
	int	i;

	if (next == k) {
		if (sum == n)
			add_ans(ans, k);
		return;
	}

	for (i = ans[next - 1] + 1; i <= 9; i++) {
		if (sum + i > n)
			return;
		ans[next] = i;
		do_comb(ans, next + 1, sum + i, k, n);
	}
}

int **combinationSum3(int k, int n, int **columnSizes, int *returnSize)
{
	if (k <= 0 || n <= 0) {
		*columnSizes = NULL;
		*returnSize = 0;
		return(NULL);
	}

	int	i;
	int	ans[k];

	res = NULL;
	p = 0;
	for (i = 1; i <= 9; i++) {
		if (i > n)
			break;
		ans[0] = i;
		do_comb(ans, 1, i, k, n);
	}

	*columnSizes = malloc(p * sizeof(columnSizes[0]));
	for (i = 0; i < p; i++)
		(*columnSizes)[i] = k;
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	**res, n, i, *col;
	res = combinationSum3(3, 9, &col, &n);
	for (i = 0; i < n; i++)
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	return(0);
}
