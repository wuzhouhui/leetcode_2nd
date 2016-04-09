#include <string.h>

int minDistance(char *word1, char *word2)
{
	static int dist[512][512];
	int	l1, l2, i, j;
	int	ins, rep, del;

	l1 = strlen(word1);
	l2 = strlen(word2);
	if (!l1 || !l2)
		return(l1 ? l1 : l2);
	for (i = 0; i < l1; i++)
		dist[i][0] = i;
	for (j = 0; j < l2; j++)
		dist[0][j] = j;
	for (i = 0; i < l1; i++) {
		for (j = 0; j < l2; j++) {
			if (word1[i] == word2[j]) {
				dist[i + 1][j + 1] = dist[i][j];
				continue;
			}
			ins = dist[i][j + 1] + 1;
			del = dist[i + 1][j] + 1;
			rep = dist[i][j] + 1;
			if (del < ins)
				ins = del;
			if (rep < ins)
				ins = rep;
			dist[i + 1][j + 1] = ins;
		}
	}
	return(dist[l1][l2]);
}

int main(void)
{
}
