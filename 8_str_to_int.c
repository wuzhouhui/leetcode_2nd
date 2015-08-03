#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int myAtoi(char *str)
{
	if (str == NULL || str[0] == 0)
		return(0);

	long long res;
	int	i, neg;

	for (i = 0; str[i]; i++)
		if (!isblank(str[i]))
			break;
	if (str[i] == 0)
		return(0);
	switch (str[i]) {
	case '-':
		neg = 1;
		i++;
		break;
	case '+':
		neg = 0;
		i++;
		break;
	default:
		neg = 0;
		break;
	}

	res = 0;
	while (isdigit(str[i])) {
		res = res * 10 + str[i] - '0';
		i++;
		if (res > INT_MAX)
			break;
	}
	if (neg) {
		res = -res;
		return(res <= INT_MIN ? INT_MIN : (int)res);
	}
	return(res >= INT_MAX ? INT_MAX : (int)res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", myAtoi(argv[1]));
	return(0);
}
