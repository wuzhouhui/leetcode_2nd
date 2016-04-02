#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct stack {
	struct TreeNode *node;
	struct stack *next;
};

struct queue {
	struct stack *stack;
	struct stack **tail;
};

#define LEFT2RIGHT 0
static inline void initq(struct queue *q)
{
	q->stack = NULL;
	q->tail = &q->stack;
}

static void enq(struct queue *q, struct TreeNode *node)
{
	if (node == NULL)
		return;
	struct stack *t = malloc(sizeof(*t));
	t->node = node;
	t->next = NULL;
	*(q->tail) = t;
	q->tail = &t->next;
}

static int isqempty(struct queue *q)
{
	return(q->stack == NULL);
}

static struct TreeNode *deq(struct queue *q)
{
	if (isqempty(q))
		return(NULL);
	struct stack *t = q->stack;
	struct TreeNode *node = t->node;
	q->stack = t->next;
	free(t);
	return(node);
}

static int *buf, bufmaxsz, bufnextp;

static void add(int val)
{
	if (buf == NULL) {
		bufmaxsz = 8;
		bufnextp = 0;
		buf = malloc(sizeof(*buf) * bufmaxsz);
	}
	if (bufnextp >= bufmaxsz) {
		bufmaxsz += 8;
		buf = realloc(buf, sizeof(*buf) * bufmaxsz);
	}
	buf[bufnextp++] = val;
}

static void revq(struct queue *q)
{
	if (isqempty(q))
		return;
	struct stack *t = q->stack;
	struct stack *t2;
	q->stack = NULL;
	q->tail = &t->next;
	while (t) {
		t2 = t;
		t = t->next;
		t2->next = q->stack;
		q->stack = t2;
	}
}

static int **res, resmaxsz, resnexp;
static int *col;
static void addans(void)
{
	if (res == NULL) {
		resmaxsz = 8;
		resnexp = 0;
		res = malloc(sizeof(*res) * resmaxsz);
		col = malloc(sizeof(*col) * resmaxsz);
	}
	if (resnexp >= resmaxsz) {
		resmaxsz += 8;
		res = realloc(res, sizeof(*res) * resmaxsz);
		col = realloc(col, sizeof(*col) * resmaxsz);
	}
	res[resnexp] = malloc(sizeof(*buf) * bufnextp);
	memcpy(res[resnexp], buf, sizeof(*buf) * bufnextp);
	col[resnexp++] = bufnextp;
}

int **zigzagLevelOrder(struct TreeNode *root, int **columnSizes,
		int *returnSize)
{
	if (root == NULL) {
		*columnSizes = NULL;
		*returnSize = 0;
		return(NULL);
	}
	res = NULL;
	col = NULL;
	buf = NULL;
	struct queue q1, q2;
	struct TreeNode *node;
	int	dir;

	initq(&q1);
	initq(&q2);
	dir = LEFT2RIGHT;
	enq(&q1, root);
	while (!isqempty(&q1)) {
		while (!isqempty(&q1)) {
			node = deq(&q1);
			add(node->val);
			if (dir == LEFT2RIGHT) {
				enq(&q2, node->left);
				enq(&q2, node->right);
			} else {
				enq(&q2, node->right);
				enq(&q2, node->left);
			}
		}
		dir = !dir;
		revq(&q2);
		q1 = q2;
		initq(&q2);
		addans();
		bufnextp = 0;
	}
	*columnSizes = col;
	*returnSize = resnexp;
	return(res);
}

int main(void)
{
	struct TreeNode n9 = { 9, NULL, NULL };
	struct TreeNode n20 = { 20, NULL, NULL };
	struct TreeNode n3 = { 3, &n9, &n20 };
	int	*col, n;
	zigzagLevelOrder(&n3, &col, &n);
	return(0);
}
