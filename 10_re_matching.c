#ifndef bool
#define bool int 
#endif

bool isMatch(char *s, char *p)
{
	int i;

	switch (*p) {
	case 0:
		return(*s == 0);
	case '.':
		if (*(p + 1) != '*') {
			if (*s == 0)
				return(0);
			else
				return(isMatch(s + 1, p + 1));
		} else {
			if (isMatch(s, p + 2))
				return(1);
			for (i = 1; s[i - 1]; i++)
				if (isMatch(s + i, p + 2))
					return(1);
			return(0);
		}

	case '*':
		if (isMatch(s, p + 1))
			return(1);

		for (i = 1; s[i - 1] &&
				(s[i - 1] == p[-1] || p[-1] == '.'); i++)
			if (isMatch(s + i, p + 1))
				return(1);
		return(0);
	default:
		if (p[1] == '*') {
			if (isMatch(s, p + 2))
				return(1);
			for (i = 1; s[i - 1] == *p; i++)
				if (isMatch(s + i, p + 2))
					return(1);
			return(0);
		} else {
			if (*s == *p)
				return(isMatch(s + 1, p + 1));
			else
				return(0);
		}
	}
	return(0);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", isMatch(argv[1], argv[2]));
	return(0);
}
