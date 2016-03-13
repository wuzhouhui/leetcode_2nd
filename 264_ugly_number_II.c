int nthUglyNumber(int n)
{
	int	ugly[n + 1];
	int	i, p1, p2, p3;
	int	u1, u2, u3, next;

	p1 = p2 = p3 = 1;
	i = 1;
	ugly[1] = 1;
	while (i < n) {
		u1 = ugly[p1] * 2;
		u2 = ugly[p2] * 3;
		u3 = ugly[p3] * 5;
		next = u1 < u2 ? u1 : u2;
		next = u3 < next ? u3 : next;
		if (next == u1)
			p1++;
		if (next == u2)
			p2++;
		if (next == u3)
			p3++;
		ugly[++i] = next;
	}
	return(ugly[n]);
}

int main(void)
{
}
