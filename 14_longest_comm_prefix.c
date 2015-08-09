#include <string.h>

static int commlen(char *s1, char *s2)
{
	int	n = 0;
	while (*s1 && *s1++ == *s2++)
		n++;
	return(n);
}

static int cmp(void *x, void *y)
{
	char *s1 = *(char **)x;
	char *s2 = *(char **)y;
	return(strcmp(s1, s2));
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	int	i, ind, max, clen;

	if (strsSize == 0)
		return(strdup(""));
	if (strsSize == 1)
		return(strdup(strs[0]));

	max = strlen(strs[0]);
	ind = 0;
	qsort(strs, strsSize, sizeof(char *), cmp);
	for (i = 1; i < strsSize; i++) {
		clen = commlen(strs[i - 1], strs[i]);
		if (clen < max) {
			ind = i;
			max = clen;
		}
	}
	if (max == 0)
		return(strdup(""));
	return(strndup(strs[ind], max));
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", longestCommonPrefix(argv + 1, argc - 1));
	return(0);
}
