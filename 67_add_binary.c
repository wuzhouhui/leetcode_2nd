#include <stdlib.h>
#include <string.h>

static void reverse(char *s, int n)
{
	int	i, t;

	for (i = 0; i < n / 2; i++) {
		t = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = t;
	}
}

char *addBinary(char *a, char *b)
{
	int	l1, l2, c, t, i;
	char	*sum;

	l1 = strlen(a);
	l2 = strlen(b);
	reverse(a, l1);
	reverse(b, l2);
	sum = calloc(l1 + l2 + 1, sizeof(char *));
	c = 0;
	for (i = 0; i < l1 || i < l2; i++) {
		t = c;
		c = 0;
		if (i < l1)
			t += a[i] - '0';
		if (i < l2)
			t += b[i] - '0';
		if (t > 1) {
			t -= 2;
			c = 1;
		}
		sum[i] = t + '0';
	}
	if (c)
		sum[i++] = '1';
	reverse(sum, i);
	return(sum);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", addBinary(argv[1], argv[2]));
	return(0);
}
