#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int *q, qnext, qsz;
static char **res;
static int resnext, ressz;

static void enq(int val)
{
	if (q == NULL) {
		qsz = 8;
		qnext = 0;
		q = malloc(qsz * sizeof(*q));
	}
	if (qnext >= qsz) {
		qsz += 8;
		q = realloc(q, qsz * sizeof(*q));
	}
	q[qnext++] = val;
}

static void deq(void)
{
	qnext--;
}

static int digits(int val)
{
	int	i = 0;
	long long v;

	if (val < 0)
		v = -(long long)val;
	else
		v = val;
	do {
		i++;
		v /= 10;
	} while (v);

	if (val < 0)
		return(i + 1);
	else
		return(i);
}

static void add_ans(void)
{
	int	len, i;
	int	flag;
	char	*buf;

	for (len = i = 0; i < qnext; i++)
		len += digits(q[i]);
	buf = malloc(len + 2 * qnext);
	for (len = flag = i = 0; i < qnext; i++) {
		if (flag) {
			len += sprintf(buf + len, "->%d", q[i]);
		} else {
			flag = 1;
			len += sprintf(buf + len, "%d", q[i]);
		}
	}

	if (res == NULL) {
		ressz = 8;
		resnext = 0;
		res = malloc(ressz * sizeof(*res));
	}
	if (resnext >= ressz) {
		ressz += 8;
		res = realloc(res, ressz * sizeof(*res));
	}
	res[resnext++] = buf;
}

static void do_path(struct TreeNode *root)
{
	if (root == NULL)
		return;
	enq(root->val);
	if (!root->left && !root->right)
		add_ans();
	do_path(root->left);
	do_path(root->right);
	deq();
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
	q = NULL;
	res = NULL;
	resnext = 0;
	do_path(root);
	if (q)
		free(q);
	*returnSize = resnext;
	return(res);
}

int main(void)
{
	return(0);
}
