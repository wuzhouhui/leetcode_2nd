/*
 * accepted, but too slow
 */
#include <stdlib.h>
#include <string.h>

static int **perms, maxp, p;
static int *aperm;
static char *occupy;

static void add_perm(int numsSize)
{
	int	i;

	for (i = 0; i < p; i++)
		if (!memcmp(perms[i], aperm, numsSize * sizeof(int)))
			return;

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
	if (start >= numsSize) {
		add_perm(numsSize);
		return;
	}
	for (i = 0; i < numsSize; i++) {
		if (occupy[i])
			continue;
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
