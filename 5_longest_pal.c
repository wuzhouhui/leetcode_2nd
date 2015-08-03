#include <string.h>

char *longestPalindrome(char *s)
{
	int	slen, left, right, t;
	int	i, maxlen, start, len;

	if (s == NULL)
		return(strdup(""));
	if ((slen = strlen(s)) < 2)
		return(strdup(s));

	maxlen = 0;
	for (i = 0; i < slen; i++) {
		/* case 1 */
		len = 1;
		t = i;
		for (left = i - 1, right = i + 1; left >= 0 && right < slen;
				left--, right++)
			if (s[left] == s[right]) {
				t = left;
				len += 2;
			} else {
				break;
			}
		if (len > maxlen) {
			maxlen = len;
			start = t;
		}

		/* case 2 */
		len = 0;
		for (left = i, right = i + 1; left >= 0 && right < slen;
				left--, right++)
			if (s[left] == s[right]) {
				t = left;
				len += 2;
			} else {
				break;
			}
		if (len > maxlen) {
			maxlen = len;
			start = t;
		}
	}
	return(strndup(s + start, maxlen));
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", longestPalindrome(argv[1]));
	return(0);
}
