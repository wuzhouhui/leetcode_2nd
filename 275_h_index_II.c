int hIndex(int *citations, int citationsSize)
{
	if (citationsSize <= 0)
		return(0);

	int	left, right, mid;

	left = 0;
	right = citationsSize - 1;
	while (left < right) {
		mid = (left + right) >> 1;
		if (citations[mid] < (citationsSize - mid))
			left = mid + 1;
		else
			right = mid;
	}
	if (citations[right] < (citationsSize - right))
		return(0);
	else
		return(citationsSize - right);
}

int main(void)
{
}
