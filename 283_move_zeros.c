void moveZeroes(int *nums, int numsSize)
{
	int	i, j;

	for (i = -1, j = 0; j < numsSize; j++) {
		if (nums[j] == 0)
			continue;
		nums[++i] = nums[j];
		if (i != j)
			nums[j] = 0;
	}
}

int main(void)
{
}
