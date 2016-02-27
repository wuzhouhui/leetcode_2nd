#include <string.h>

#ifndef bool
#define bool int
#endif

bool canFinish(int numCourses, int **prerequisites, int prerequisitesRowSize,
		int prerequisitesColSize)
{
	int	degree[numCourses], i, left, next;

	memset(degree, 0, sizeof(degree));
	for (i = 0; i < prerequisitesRowSize; i++)
		degree[prerequisites[i][0]]++;
	left = numCourses;
	while (left) {
		next = -1;
		for (i = 0; i < numCourses; i++) {
			if (degree[i] == 0) {
				next = i;
				break;
			}
		}
		if (next < 0)
			return(0);
		degree[next] = -1;
		left--;
		for (i = 0; i < prerequisitesRowSize; i++) {
			if (prerequisites[i][1] != next)
				continue;
			degree[prerequisites[i][0]]--;
		}
	}
	return(1);
}

int main(void)
{
}
