int rangeBitwiseAnd(int m, int n)
{
	int	bitm, bitn, i, res;
	int	diff;

	res = 0;
	diff = n - m;
	for (i = 0; i < 32; i++) {
		bitm = m & (1 << i);
		bitn = n & (1 << i);
		if (bitm == 0 || bitn == 0)
			continue;
		bitm -= 1;
		bitm = bitm - (m & bitm);
		if (diff > bitm)
			continue;
		res |= bitn;
	}
	return(res);
}

int main(void)
{
	return(rangeBitwiseAnd(5, 7));
}
