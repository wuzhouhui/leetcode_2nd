#ifndef bool
#define bool int
#endif

bool isPowerOfTwo(int n)
{
	int	i, j;

	j = sizeof(n) * 8 - 1;
	for (i = 0; i < j; i++)
		if (n == (1 << i))
			return(1);
	return(0);
}

int main(void)
{
}
