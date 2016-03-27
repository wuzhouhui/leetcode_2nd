int minPatches(int *nums, int numsSize, int n)
{
	long long	miss;
	int	added, i;

	added = i = 0;
	miss = 1;
	while (miss <= n) {
		if (i < numsSize && nums[i] <= miss) {
			miss += nums[i++];
		} else {
			miss += miss;
			added++;
		}
	}
	return(added);
}

int main(void)
{
	return(0);
}
