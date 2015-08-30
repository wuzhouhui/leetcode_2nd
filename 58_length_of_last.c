#include <string.h>

int lengthOfLastWord(char *s)
{
	int	l, r, i;

	l = strlen(s);
	r = 0;
	l--;
	for (; l >= 0; l--) {
		if (s[l] == ' ')
			continue;
		for (i = l; i >= 0; i--) {
			if (s[i] != ' ')
				r++;
			else
				break;
		}
		break;
	}
	return(r);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", lengthOfLastWord(argv[1]));
	return(0);
}
