#include <stdlib.h>

#define  STEP	16

static int **ans, p, maxp;

static void add_ans(int x, int y, int z)
{
	int	*new;
	int	i;

	for (i = 0; i < p; i++) {
		if (ans[i][0] == x && ans[i][1] == y && ans[i][2] == z)
			return;
	}

	if (ans == NULL) {
		maxp = STEP;
		p = 0;
		ans = malloc(maxp * sizeof(int *));
	}
	if (p >= maxp) {
		maxp += STEP;
		ans = realloc(ans, maxp * sizeof(int *));
	}
	new = malloc(3 * sizeof(int));
	new[0] = x;
	new[1] = y;
	new[2] = z;
	ans[p++] = new;
}

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	int	start, end, mid, tmp, sum;
	if (numsSize < 3) {
		*returnSize = 0;
		return(NULL);
	}

	qsort(nums, numsSize, sizeof(int), cmp);
	ans = NULL;
	p = 0;
	start = 0;
	end = numsSize - 1;
	while ((start + 1) < end) {
		for (mid = start + 1; mid < end;) {
			tmp = nums[start] + nums[mid] + nums[end];
			if (tmp > 0) {
				end--;
			} else if (tmp < 0) {
				mid++;
			} else {
				add_ans(nums[start], nums[mid], nums[end]);
				mid++;
			}
		}
		start++;
		end = numsSize - 1;
	}
	*returnSize = p;
	return(ans);
}

#include <stdio.h>

int main(void)
{
	int	i, n;
	int	s[] = { -1, 0, 1, 2, -1, -4 };
	int	**res;

	res = threeSum(s, 6, &n);
	for (i = 0; i < n; i++)
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	return(0);
}
