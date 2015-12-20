static void rev(char *s, int start, int end)
{
	int	t, i;

	for (i = start; i <= (start + end) / 2; i++) {
		t = s[start + end - i];
		s[start + end - i] = s[i];
		s[i] = t;
	}
}
void reverseWords(char *s)
{
	int	i, j, prev;

	prev = ' ';
	for (i = 0, j = -1; s[i]; i++) {
		if (s[i] == ' ') {
			if (prev == ' ')
				continue;
			else {
				s[++j] = s[i];
				prev = ' ';
			}
		} else {
			s[++j] = s[i];
			prev = s[i];
		}
	}
	if (j < 0) {
		s[0] = 0;
		return;
	}
	if (s[j] == ' ')
		s[j] = 0;
	else
		s[++j] = 0;

	for (i = 0; i < j / 2; i++) {
		prev = s[j - i - 1];
		s[j - i - 1] = s[i];
		s[i] = prev;
	}

	j = 0;
	for (i = 0; ; i++) {
		if (s[i] == ' ' || s[i] == 0) {
			rev(s, j, i - 1);
			j = i + 1;
			if (s[i] == 0)
				break;
		}
	}
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	reverseWords(argv[1]);
	printf("%s\n", argv[1]);
	return(0);
}
