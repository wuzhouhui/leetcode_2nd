int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize <= 1)
		return(0);

	int	buy, sell, profit, i;

	buy = sell = profit = 0;
	for (i = 1; i < pricesSize; i++) {
		if (prices[i] > prices[sell]) {
			sell = i;
		} else {
			profit += prices[sell] - prices[buy];
			buy = sell = i;
		}
	}
	profit += prices[sell] - prices[buy];
	return(profit);
}

int main(void)
{
}
