#ifndef bool
#define bool int
#endif

bool isPowerOfThree(int n)
{
	if (n > 0)
		while (n % 3 == 0)
			n /= 3;
	return(n == 1);
}

int main(void)
{
}
