int removeElement(int *nums, int numsSize, int val)
{
	int	i, j;

	for (i = -1, j = 0; j < numsSize; j++) {
		if (nums[j] == val)
			continue;
		nums[++i] = nums[j];
	}
	return(++i);
}

int main(void)
{
}
