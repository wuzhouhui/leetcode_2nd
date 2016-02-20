#include <string.h>

int titleToNumber(char *s)
{
	int	res, len, pow;

	res = 0;
	len = strlen(s);
	pow = 1;
	while (len--) {
		res += (s[len] - 'A' + 1) * pow;
		pow *= 26;
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", titleToNumber(argv[1]));
	return(0);
}
