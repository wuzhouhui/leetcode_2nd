#include <string.h>
#include <stdlib.h>

static char *romans[] = {
	/* 1000 */
	"M",
	/* 100, 400, 500, 900 */
	"CM", "D", "CD", "C",
	/* 10, 40, 50, 90 */
	"XC", "L", "XL", "X",
	/* 1, 4, 5, 9 */
	"IX", "V", "IV", "I",
};

static int r[] = {
	1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
};

char *intToRoman(int num)
{
	char	*res = malloc(32);
	int	i, p;

	for (p = i = 0; i < 13; i++) {
		while (num >= r[i]) {
			memcpy(res + p, romans[i], strlen(romans[i]));
			num -= r[i];
			p += strlen(romans[i]);
		}
	}
	res[p] = 0;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", intToRoman(atoi(argv[1])));
	return(0);
}
