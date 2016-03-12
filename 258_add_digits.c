int addDigits(int num)
{
	int	t;

	while (num / 10) {
		t = 0;
		while (num) {
			t += num % 10;
			num /= 10;
		};
		num = t;
	}
	return(num);
}

int main(void)
{
}
