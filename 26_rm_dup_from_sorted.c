int removeDuplicates(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return(numsSize);

	int	i, j;

	for (i = 0, j = 1; j < numsSize; j++) {
		if (nums[i] == nums[j])
			continue;
		nums[++i] = nums[j];
	}

	return(i + 1);
}

int main(void)
{
}
