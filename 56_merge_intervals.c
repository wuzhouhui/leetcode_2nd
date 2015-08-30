#include <stdlib.h>

struct Interval {
	int start;
	int end;
};

static struct Interval *res;
static int p, maxp;

static void add_inter(const struct Interval *inter)
{
	if (!res) {
		maxp = 8;
		res = malloc(8 * sizeof(struct Interval));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(struct Interval));
	}
	res[p].start = inter->start;
	res[p].end = inter->end;
	p++;
}

static int cmp(const void *a, const void *b)
{
	struct Interval *x = (struct Interval *)a;
	struct Interval *y = (struct Interval *)b;
	if (x->start != y->start)
		return(x->start - y->start);
	else
		return(x->end - y->end);
}

struct Interval *merge(struct Interval *intervals, int intervalsSize,
		int *returnSize)
{
	int	i;
	struct Interval inter;

	qsort(intervals, intervalsSize, sizeof(struct Interval), cmp);
	res = 0;
	p = 0;
	for (i = 0; i < intervalsSize; ) {
		inter.start = intervals[i].start;
		inter.end = intervals[i].end;
		i++;
		while (i < intervalsSize && intervals[i].start <=
				inter.end) {
			if (intervals[i].end > inter.end)
				inter.end = intervals[i].end;
			i++;
		}
		add_inter(&inter);
	}
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(voidj)
{
	struct Interval x[] = {
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18},
	};
	struct Interval *res;
	int	i, n;

	res = merge(x, 4, &n);
	for (i = 0; i < n; i++)
		printf("%d %d\n", res[i].start, res[i].end);
	return(0);
}
