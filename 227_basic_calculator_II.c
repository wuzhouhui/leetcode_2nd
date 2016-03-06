int calculate(char *s)
{
	long	term, res, op;
	int	preop, sign;

	res = 0;
	preop = 0;
	term = 0;
	sign = 0;
	while (*s) {
		switch (*s) {
		case ' ':
			s++;
			break;
		case '+':
			res += term;
			preop = 0;
			s++;
			term = 0;
			sign = 0;
			break;
		case '-':
			res += term;
			preop = 0;
			s++;
			term = 0;
			sign = 1;
			break;
		case '*':
		case '/':
			preop = *s;
			s++;
			break;
		default:
			op = 0;
			while (isdigit(*s)) {
				op = op * 10 + *s - '0';
				s++;
			}
			if (preop == 0) {
				term = op;
				if (sign)
					term = -term;
			} else if (preop == '*')
				term *= op;
			else if (preop == '/')
				term /= op;
		}
	}
	res += term;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
