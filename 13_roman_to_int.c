#include <string.h>

struct roman_int {
	char	*roman;
	int	val;
};

static char *roman[] = {
	"M",
	"CM", "D", "CD", "C",
	"XC", "L", "XL", "X",
	"IX", "V", "IV", "I",
};

static int val[] = {
	1000,
	900, 500, 400, 100,
	90, 50, 40, 10,
	9, 5, 4, 1,
};

int romanToInt(char *s)
{
	int	res;
	int	i, p, l;
	
	res = p = 0;
	while (s[p]) {
		for (i = 0; i < 13; i++) {
			l = strlen(roman[i]);
			if (strncmp(s + p, roman[i], l))
				continue;
			res +=val[i];
			p += l;
		}
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", romanToInt(argv[1]));
	return(0);
}
