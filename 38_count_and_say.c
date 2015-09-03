#include <stdlib.h>
#include <string.h>

#define STEP 8

static char *t;
static int p, maxp;

static void add(char c)
{
	if (!t) {
		maxp = STEP;
		p = 0;
		t = malloc((maxp + 1) * sizeof(char));
	}
	if (p >= maxp) {
		maxp += STEP;
		t = realloc(t, (maxp + 1) * sizeof(char));
	}
	t[p++] = c;
	t[p] = 0;
}

char *countAndSay(int n)
{
	if (n < 1)
		return(strdup(""));

	int	i, j, c;
	char	*orig;

	orig = strdup("1");
	t = 0;

	for (i = 2; i <= n; i++) {
		for (j = 0; orig[j]; ) {
			c = 1;
			j++;
			while (orig[j]) {
				if (orig[j] == orig[j - 1]) {
					c++;
					j++;
				} else {
					break;
				}
			}
			add(c + '0');
			add(orig[j - 1]);
		}
		free(orig);
		orig = t;
		t = 0;
	}
	return(orig);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", countAndSay(atoi(argv[1])));
	return(0);
}
