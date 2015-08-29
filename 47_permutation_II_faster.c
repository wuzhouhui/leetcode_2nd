#include <stdlib.h>
#include <string.h>

static int **perms, maxp, p;
static int *aperm;
static char *occupy;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void add_perm(int numsSize)
{
	if (!perms) {
		maxp = 8;
		perms = malloc(maxp * sizeof(int *));
	}
	if (p >= maxp) {
		maxp += 8;
		perms = realloc(perms, maxp * sizeof(int *));
	}
	perms[p] = calloc(numsSize, sizeof(int));
	memcpy(perms[p], aperm, numsSize * sizeof(int));
	p++;
}

static void do_perm(int *nums, int numsSize, int start)
{
	int	i;
	int	prev, first;

	if (start >= numsSize) {
		add_perm(numsSize);
		return;
	}
	first = 1;
	for (i = 0; i < numsSize; i++) {
		if (occupy[i])
			continue;
		if (!first && nums[i] == prev)
			continue;
		first = 0;
		prev = nums[i];
		occupy[i] = 1;
		aperm[start] = nums[i];
		do_perm(nums, numsSize, start + 1);
		occupy[i] = 0;
	}
	return;
}

int **permuteUnique(int *nums, int numsSize, int *returnSize)
{
	perms = 0;
	p = 0;
	aperm = calloc(numsSize, sizeof(int));
	occupy = calloc(numsSize, sizeof(char));
	qsort(nums, numsSize, sizeof(int), intcmp);
	do_perm(nums, numsSize, 0);
	*returnSize = p;
	if (aperm)
		free(aperm);
	if (occupy)
		free(occupy);
	return(perms);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 1, 2 };
	int	**res, n, i;
	res = permuteUnique(x, 3, &n);
	for (i = 0; i < n; i++)
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	return(0);
}
