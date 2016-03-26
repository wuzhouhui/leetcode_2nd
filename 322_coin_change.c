static inline int min(int a, int b)
{
	return(a < b ? a : b);
}

int coinChange(int *coins, int coinsSize, int amount)
{
	int	dp[amount + 1];
	int	i, j;

	for (i = 1; i <= amount; i++)
		dp[i] = amount + 1;
	dp[0] = 0;
	for (i = 1; i <= amount; i++) {
		for (j = 0; j < coinsSize; j++) {
			if (i >= coins[j])
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}
	return(dp[amount] > amount ? -1 : dp[amount]);
}

int main(void)
{
}
