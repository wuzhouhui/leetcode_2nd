#include <stdlib.h>

struct val_cnt {
	int val;
	int cnt;
};

static int **res, *col, maxp, p;

static void add_ans(int size, struct val_cnt *val_cnt)
{
	int	i, j, k;

	if (!res) {
		maxp = 16;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 16;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	for (col[p] = i = 0; i < size; i++)
		col[p] += val_cnt[i].cnt;
	res[p] = malloc(col[p] * sizeof(int));
	for (k = i = 0; i < size; i++)
		for (j = 0; j < val_cnt[i].cnt; j++)
			res[p][k++] = val_cnt[i].val;
	p++;
}

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void do_comb(int *candidates, int candidatesSize,
		struct val_cnt *val_cnt, int target, int sum, int start)
{
	int	i, j;

	if (start >= candidatesSize)
		return;

	for (i = 0; ; i++) {
		val_cnt[start].cnt++;
		sum += candidates[start];
		if (sum > target)
			break;
		if (sum == target) {
			add_ans(candidatesSize, val_cnt);
			break;
		}
		for (j = start + 1; j < candidatesSize; j++)
		do_comb(candidates, candidatesSize, val_cnt, target,
				sum, j);
	}
	val_cnt[start].cnt = 0;
	return;
}
int **combinationSum(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	struct val_cnt val_cnt[candidatesSize];
	int	i;

	res = 0;
	col = 0;
	p = 0;
	qsort(candidates, candidatesSize, sizeof(int), intcmp);
	for (i = 0; i < candidatesSize; i++) {
		val_cnt[i].val = candidates[i];
		val_cnt[i].cnt = 0;
	}

	for (i = 0; i < candidatesSize; i++) {
		if (i && candidates[i] == candidates[i - i])
			continue;
		do_comb(candidates, candidatesSize, val_cnt,
				target, 0, i);
	}

	*columnSizes = col;
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 2, 3, 5 };
	int	**res, *col, size, i, j;

	res = combinationSum(x, 3, 7, &col, &size);
	for (i = 0; i < size; i++) {
		for (j = 0; j < col[i]; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return(0);
}
