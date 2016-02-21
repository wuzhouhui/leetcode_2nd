#include <stdint.h>

static char tb[] = {
	0, 8, 4, 12,
	2, 10, 6, 14,
	1, 9, 5, 13,
	3, 11, 7, 15,
};


uint32_t reverseBits(uint32_t n)
{
	uint32_t rn;
	int	i;

	rn = 0;
	for (i = 0; i < 8; i++) {
		rn = (rn << 4) + tb[n & 0xf];
		n >>= 4;
	}
	return(rn);
}

#include <stdio.h>

int main(void)
{
	printf("%u\n", reverseBits(43261596));
	return(0);
}
