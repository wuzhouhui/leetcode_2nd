#include <string.h>
#include <stdlib.h>

int *findOrder(int numCourses, int **prerequisites, int prerequisitesRowSize,
		int prerequisitesColSize, int *returnSize)
{
	int	degree[numCourses], i, left, next;
	int	order[numCourses];
	int	*t;

	memset(degree, 0, sizeof(degree));
	for (i = 0; i < prerequisitesRowSize; i++)
		degree[prerequisites[i][0]]++;
	left = numCourses;
	*returnSize = 0;
	while (left) {
		next = -1;
		for (i = 0; i < numCourses; i++) {
			if (degree[i] == 0) {
				next = i;
				break;
			}
		}
		if (next < 0) {
			*returnSize = 0;
			return(NULL);
		}
		degree[next] = -1;
		order[(*returnSize)++] = next;
		left--;
		for (i = 0; i < prerequisitesRowSize; i++) {
			if (prerequisites[i][1] != next)
				continue;
			degree[prerequisites[i][0]]--;
		}
	}
	t = malloc(sizeof(order));
	memcpy(t, order, sizeof(order));
	return(t);
}

int main(void)
{
}
