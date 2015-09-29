#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STEP 8

static char **res;
static int maxp, p, ips[4];

static void add_ans(int level)
{
	if (level != 4)
		return;
	if (!res) {
		maxp = STEP;
		res = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(char *));
	}
	res[p] = malloc(16 * sizeof(char));
	snprintf(res[p], 16, "%d.%d.%d.%d", ips[0], ips[1], ips[2], ips[3]);
	p++;
}

static void do_restore(char *s, int level)
{
	if (!*s) {
		add_ans(level);
		return;
	}
	if (level > 3)
		return;

	int	i, ip;
	char	t[4];

	memset(t, 0, sizeof(t));
	for (i = 0; s[i] && i < 3; i++) {
		strncpy(t, s, i + 1);
		ip = atoi(t);
		if (ip < 256) {
			ips[level] = ip;
			do_restore(s + i + 1, level + 1);
			if (!ip)
				break;
		} else {
			break;
		}
	}
}

char **restoreIpAddresses(char *s, int *returnSize)
{
	res = 0;
	p = 0;
	do_restore(s, 0);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int	i, n;
	char	**res;

	res = restoreIpAddresses(argv[1], &n);
	for (i = 0; i < n; i++)
		printf("%s\n", res[i]);
	return(0);
}
