#define bool int

bool isBadVersion(int version);

int firstBadVersion(int n)
{
	int	left, right, mid;

	if (n < 2)
		return(n);
	left = 1;
	right = n;
	if (isBadVersion(1))
		return(1);
	while (left + 1 != right) {
		mid = left + (right - left) / 2; /* avoid overflow */
		if (isBadVersion(mid))
			right = mid;
		else
			left = mid;
	}
	return(right);
}
