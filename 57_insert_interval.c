#include <stdlib.h>

struct Interval {
	int start;
	int end;
};

static struct Interval *res;
static int p, maxp;

static void add(struct Interval *i)
{
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(struct Interval));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(struct Interval));
	}
	res[p].start = i->start;
	res[p].end = i->end;
	p++;
}

struct Interval *insert(struct Interval *intervals, int intervalsSize,
		struct Interval newInterval, int *returnSize)
{
	res = 0;
	p = 0;
	struct Interval *intvptr;
	int	i, flag;

	flag = 0;
	for (i = 0; i < intervalsSize;) {
		if (!flag) {
			if (intervals[i].start < newInterval.start) {
				intvptr = &intervals[i];
				i++;
			} else {
				intvptr = &newInterval;
				flag = 1;
			}
		} else {
			intvptr = &intervals[i];
			i++;
		}
		while (1) {
			if (!flag) {
				if (newInterval.start <= intvptr->end) {
					if (newInterval.end > intvptr->end)
						intvptr->end = newInterval.end;
					flag = 1;
				}
			}
			if (i < intervalsSize && intervals[i].start <= intvptr->end) {
				if (intervals[i].end > intvptr->end)
					intvptr->end = intervals[i].end;
				i++;
			} else {
				if (flag || newInterval.start > intvptr->end)
					break;
			}
		} 
		add(intvptr);
	}
	if (!flag)
		add(&newInterval);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	struct Interval is[] = {
		{ 1, 5 },
		{ 6, 8},
	};
	struct Interval newint = { 5, 6};
	int	n, i;
	struct Interval *res;

	res = insert(is, 2, newint, &n);
	for (i = 0; i < n; i++) 
		printf("%d %d\n", res[i].start, res[i].end);
	return(0);
}
