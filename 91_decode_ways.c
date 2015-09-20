#include <string.h>

int numDecodings(char *s)
{
	int	n[strlen(s)];
	int	i;

	if (!s || !s[0])
		return(0);

	for (i = 0; s[i]; i++) {
		if (i == 0) {
			if (s[0] == '0')
				return(0);
			else
				n[0] = 1;
			continue;
		}

		if (i == 1) {
			if (s[1] == '0') {
				if (s[0] != '1' && s[0] != '2')
					return(0);
				else
					n[1] = 1;
				continue;
			}
			n[1] = n[0];
			if (s[1] >= '7' && s[1] <= '9' && s[0] == '1')
				n[1]++;
			if (s[1] >= '1' && s[1] <= '6' && (s[0] == '1'
						|| s[0] == '2'))
				n[1]++;
			continue;
		}

		if (s[i] == '0') {
			if (s[i - 1] == '0' || (s[i - 1] != '1' &&
						s[i - 1] != '2'))
				return(0);
			else
				n[i] = n[i - 2];
		} else {
			n[i] = n[i - 1];
			if (s[i] >= '7' && s[i] <= '9' && s[i - 1] == '1')
				n[i] += n[i - 2];
			if (s[i] >= '1' && s[i] <= '6' && (s[i - 1] == '1'
						|| s[i - 1] == '2'))
				n[i] += n[i - 2];
		}
	}
	return(n[i - 1]);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", numDecodings(argv[1]));
	return(0);
}
