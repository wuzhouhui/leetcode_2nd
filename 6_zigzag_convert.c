#include <string.h>

char *convert(char *s, int numRows)
{
	char	*res = strdup(s);
	int	left, right, step;
	int	p, i, j, l;

	if (numRows <= 1)
		return(res);
	
	step = (numRows - 1) * 2;
	left = step;
	right = 0;
	l = strlen(s);
	p = 0;
	for (i = 0; i < numRows; i++) {
		if (i == 0 || i == numRows - 1) {
			for (j = i; j < l; j += step)
				res[p++] = s[j];
			continue;
		}

		left -= 2;
		right += 2;
		j = i;
		if (j < l)
			res[p++] = s[j];
		else
			break;

		while (1) {
			if ((j += left) < l)
				res[p++] = s[j];
			else
				break;
			if ((j += right) < l)
				res[p++] = s[j];
			else
				break;
		}
	}
	return(res);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i = atoi(argv[2]);
	printf("%s\n", convert(argv[1], i));
			;
	return(0);
}
