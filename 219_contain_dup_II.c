#include <stdio.h>

#ifndef bool
#define bool int
#endif

struct valind {
	int	val;
	int	ind;
};

static int cmp(const void *a, const void *b)
{
	const struct valind *ap = a;
	const struct valind *bp = b;
	if (ap->val != bp->val)
		return(ap->val - bp->val);
	else
		return(ap->ind - bp->ind);
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
	struct valind x[numsSize];
	int	i;

	for (i = 0; i < numsSize; i++) {
		x[i].val = nums[i];
		x[i].ind = i;
	}

	qsort(x, numsSize, sizeof(x[0]), cmp);
	for (i = 1; i < numsSize; i++)
		if ((x[i].val == x[i - 1].val)
				&& ((x[i].ind - x[i-1].ind) <= k))
			return(1);
	return(0);
}

int main(void)
{
}
