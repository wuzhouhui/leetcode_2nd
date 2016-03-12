int missingNumber(int *nums, int numsSize)
{
	int	s;
	int	i;

	s = 0;
	for (i = 0; i < numsSize; i++)
		s += nums[i];
	return(numsSize * (numsSize + 1) / 2- s);
}

int main(void)
{
	return(0);
}
