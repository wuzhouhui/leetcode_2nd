int searchInsert(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return(0);

	int	l, u, m;

	l = -1;
	u = numsSize;
	while (l + 1 != u) {
		/*
		 * x[l] <= t < x[u]
		 */
		m = (l + u) >> 1;
		if (nums[m] > target)
			u = m;
		else
			l = m;
	}
	if (l == -1 || nums[l] != target)
		return(l + 1);
	else 
		return(l);
}

#include <stdio.h>

int main(void)
{
	int	x[]  = { 1, 3, 5, 6 };
	printf("%d %d %d %d\n", searchInsert(x, 4, 5), searchInsert(x, 4, 2), searchInsert(x, 4, 7), searchInsert(x, 4, 0));
	return(0);
}
