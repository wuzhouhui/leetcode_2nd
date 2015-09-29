#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static int **res, *col;
static int maxp, p;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void add(int *t, int k)
{
	int	i, j;

	qsort(t, k, sizeof(int), intcmp);
	for (i = 0; i < p; i++) {
		if (col[i] != k)
			continue;
		for (j = 0; j < col[i]; j++)
			if (res[i][j] != t[j])
				break;
		if (j == col[i])
			return;
	}

	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = malloc(k * sizeof(int));
	col[p] = k;
	memcpy(res[p], t, k * sizeof(int));
	p++;
}

int **subsetsWithDup(int *nums, int numsSize, int **columnSizes,
		int *returnSize)
{
	uint64_t n, i, j;
	int	*tmp = 0, k;

	res = 0;
	col = 0;
	p = 0;

	n = (uint64_t)1 << numsSize;
	tmp = malloc(numsSize * sizeof(int));
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = 0; j < numsSize; j++) {
			if (i & ((uint64_t)1 << j))
				tmp[k++] = nums[j];
		}
		add(tmp, k);
	}

	*columnSizes = col;
	*returnSize = p;
	if (tmp)
		free(tmp);
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	i, n, **res, *col;
	int	j;
	int	x[] = { 1, 2, 2 };

	res = subsetsWithDup(x, 3, &col, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < col[i]; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return(0);
}
