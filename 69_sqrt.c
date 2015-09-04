int mySqrt(int x)
{
	if (x <= 0)
		return(0);
	long long int	t, l, u, m;

	l = 0;
	u = x / 2 + 1;
	while (l <= u) {
		m = (l + u) / 2;
		t = m * m;
		if (t == x)
			return((int)m);
		else if (t < x)
			l = m + 1;
		else
			u = m - 1;
	}
	return((int)u);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int	n = atoi(argv[1]);
	printf("%d\n", mySqrt(n));
	return(0);
}
