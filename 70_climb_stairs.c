int climbStairs(int n)
{
	if (n <= 0)
		return(0);

	int	steps[n];
	int	i;
	for (i = 0; i < n; i++) {
		if (i == 0)
			steps[0] = 1;
		else if (i == 1)
			steps[1] = 2;
		else
			steps[i] = steps[i - 1] + steps[i - 2];
	}
	return(steps[n - 1]);
}

int main(void)
{
}
