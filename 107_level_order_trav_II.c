#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct queue {
	struct TreeNode *node;
	struct queue *next;
};

static int **res, *col, p, maxp;

static void enq(struct queue **head, struct queue **tail,
		struct TreeNode *node, int *len)
{
	if (!node)
		return;
	struct queue *t = malloc(sizeof(struct queue));
	t->node = node;
	t->next = 0;
	if (!*head) {
		*head = *tail = t;
	} else {
		(*tail)->next = t;
		*tail = t;
	}
	(*len)++;
}

static struct TreeNode *deq(struct queue **head)
{
	struct queue *t = *head;
	struct TreeNode *node = t->node;
	*head = (*head)->next;
	free(t);
	return(node);
}

static void add(int *tmpbuf, int len)
{
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = tmpbuf;
	col[p] = len;
	p++;
}

int **levelOrderBottom(struct TreeNode *root, int **columnSizes,
		int *returnSize)
{
	struct queue *q1head, *q1tail, *q2head, *q2tail;
	int	qlen, i, *tmpbuf, len;
	struct TreeNode *node;

	res = 0;
	col = 0;
	p = 0;
	q1head = q2head = 0;
	qlen = 0;

	enq(&q1head, &q1tail, root, &qlen);
	while (qlen) {
		tmpbuf = malloc(qlen * sizeof(int));
		len = qlen;
		qlen = 0;
		i = 0;
		while (q1head) {
			node = deq(&q1head);
			enq(&q2head, &q2tail, node->left, &qlen);
			enq(&q2head, &q2tail, node->right, &qlen);
			tmpbuf[i++] = node->val;
		}
		add(tmpbuf, len);
		tmpbuf = 0;
		q1head = q2head;
		q1tail = q2tail;
		q2head = 0;
	}
	for (i = 0; i < p / 2; i++) {
		tmpbuf = res[i];
		len = col[i];
		res[i] = res[p - i - 1];
		col[i] = col[p - i - 1];
		res[p - i - 1] = tmpbuf;
		col[p - i - 1] = len;
	}
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

int main(void)
{
}
