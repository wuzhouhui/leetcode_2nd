#include <stdlib.h>
#include <string.h>

char *convertToTitle(int n)
{
	if (n <= 0)
		return(strdup(""));
	char	*res;
	int	r, sz, p;

	res = malloc(sizeof(*res));
	sz = 1;
	p = 0;
	while (n) {
		res = realloc(res, ++sz);
		r = n % 26;
		if (r == 0) {
			res[p++] = 'Z';
			n--;
		} else
			res[p++] = 'A' + r - 1;
		n = n / 26;
	}
	res[p] = 0;
	for (r = 0; r < p / 2; r++) {
		sz = res[r];
		res[r] = res[p - r - 1];
		res[p - r - 1] = sz;
	}
	return(res);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("%s\n", convertToTitle(atoi(argv[1])));
	return(0);
}
