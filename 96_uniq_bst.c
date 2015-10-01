int numTrees(int n)
{
	if (n <= 0)
		return(1);
	int	nums[n + 1];
	int	i, j;

	nums[0] = 1;
	for (i = 1; i <= n; i++) {
		nums[i] = 0;
		for (j = 0; j < i; j++)
			nums[i] += nums[j] * nums[i - 1 - j];
	}

	return(nums[n]);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", numTrees(1));
	return(0);
}
