int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize <= 1)
		return(0);

	int	left[pricesSize];
	int	i, t;

	t = prices[0];
	for (i = 0; i < pricesSize; i++) {
		left[i] = t;
		if (prices[i] < t)
			t = prices[i];
	}
	t = 0;
	for (i = 0; i < pricesSize; i++) {
		prices[i] -= left[i];
		if (prices[i] > t)
			t = prices[i];
	}
	return(t);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 3, 2, 6, 5, 0, 3 };
	printf("%d\n", maxProfit(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
