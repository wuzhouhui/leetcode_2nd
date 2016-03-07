#include <string.h>

#ifndef bool
#define bool int
#endif

bool isAnagram(char *s, char *t)
{
	static int t1[26], t2[26];

	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	while (*s)
		t1[*s++ - 'a']++;
	while (*t)
		t2[*t++ - 'a']++;
	return(!memcmp(t1, t2, sizeof(t1)));
}

int main(void)
{
}
