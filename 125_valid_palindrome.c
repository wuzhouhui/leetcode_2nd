#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef bool
#define bool int
#endif

bool isPalindrome(char *s)
{
	int	i, j, l, r;
	char	*str;

	l = strlen(s);
	str = malloc(l);
	for (i = -1, j = 0; s[j]; j++) {
		if (!isalnum(s[j]))
			continue;
		str[++i] = s[j];
		if (isalpha(str[i]))
			str[i] = tolower(str[i]);
	}
	l = i + 1;
	r = 1;
	for (i = 0; i < l / 2 ; i++) {
		if (str[i] != str[l - i - 1]) {
			r = 0;
			break;
		}
	}
	if (str)
		free(str);
	return(r);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", isPalindrome(argv[1]));
	return(0);
}
