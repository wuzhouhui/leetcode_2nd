#include <string.h>

int strStr(char *haystack, char *needle)
{
	int	i, j, l1, l2;

	l1 = strlen(haystack);
	l2 = strlen(needle);
	for (i = 0; (l1 - i) >= l2; i++) {
		for (j = 0; needle[j]; j++)
			if (haystack[i + j] != needle[j])
				break;
		if (!needle[j])
			return(i);
	}
	return(-1);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", strStr(argv[1], argv[2]));
	return(0);
}
