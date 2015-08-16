#include <stdlib.h>

#define STET 16

static int **res, p, maxp;

static void add_ans(int a, int b, int c, int d)
{
	int	i, *ans;

	for (i = 0; i < p; i++) {
		if (res[i][0] == a && res[i][1] == b &&
				res[i][2] == c && res[i][3] == d)
			return;
	}

	ans = malloc(4 * sizeof(int));
	ans[0] = a;
	ans[1] = b;
	ans[2] = c;
	ans[3] = d;

	if (res == NULL) {
		maxp = STET;
		p = 0;
		res = malloc(maxp * sizeof(int *));
	}
	if (p >= maxp) {
		maxp += STET;
		res = realloc(res, maxp * sizeof(int *));
	}
	res[p++] = ans;
	return;
}

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
	int	a, b, c, d, s;

	res = NULL;
	p = 0;

	qsort(nums, numsSize, sizeof(*nums), cmp);
	for (a = 0; a < (numsSize - 3); a++) {
		for (b = a + 1; b < (numsSize - 2); b++) {
			c = b + 1;
			d = numsSize - 1;
			while (c < d) {
				s = nums[a] + nums[b] + nums[c] + nums[d];
				if (s == target) {
					add_ans(nums[a], nums[b], nums[c],
							nums[d]);
					c++;
				} else if (s > target)
					d--;
				else
					c++;
			}
		}
	}

	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { -4, -4, -2, -1, 0, 0, 1, 2, 3, 4 };
	int	**res, n, i;
	res = fourSum(x, 10, 0, &n);
	for (i = 0; i < n; i++)
		printf("%d %d %d %d\n", res[i][0], res[i][1], res[i][2],
				res[i][3]);
	return(0);
}
