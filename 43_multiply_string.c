/*
 * runtime error while 999 * 999
 */
#include <stdlib.h>
#include <string.h>

static void reverse(char *s)
{
	int	l = strlen(s);
	int	i, t;

	for (i = 0; i < l / 2; i++) {
		t = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = t;
	}
	return;
}

char *multiply(char *num1, char *num2)
{
	int	l1, l2, t, c, i, j;
	char	*res;
	int	len;

	l1 = strlen(num1);
	l2 = strlen(num2);
	if (!l1 || !l2)
		return(strdup("0"));
	res = calloc(l1 + l2 + 2, sizeof(char));

	reverse(num1);
	reverse(num2);
	c = 0;
	for (i = 0; num1[i]; i++) {
		for (j = 0; num2[j]; j++) {
			t = (num1[i] - '0') * (num2[j] - '0');
			res[i + j] += t + c;
			c = res[i + j] / 10;
			res[i + j] %= 10;
		}
		if (c) {
			res[i + j] = c;
			c = 0;
			len = i + j + 1;
		} else {
			len = i + j;
		}
	}
	for (i = 0; i < len; i++)
		res[i] += '0';
	reverse(res);
	if (res[0] == '0')
		res[1] = 0;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	char *res = multiply(argv[1], argv[2]);
	printf("%s\n", res);
	return(0);
}
