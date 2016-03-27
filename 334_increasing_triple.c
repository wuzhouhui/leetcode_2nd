#include <limits.h>

#ifndef bool
#define bool int
#endif

bool increasingTriplet(int *nums, int numsSize)
{
	int	a1, a2, i;

	a1 = a2 = INT_MAX;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] <= a1)
			a1 = nums[i];
		else if (nums[i] <= a2)
			a2 = nums[i];
		else
			return(1);
	}
	return(0);
}

int main(void)
{
	return(0);
}
