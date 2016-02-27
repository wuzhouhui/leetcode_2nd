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
	struct stack *head;
	struct stack *tail;
};

static int isempty(struct queue *q)
{
	return(q->head == NULL);
}

static void enq(struct queue *q, struct TreeNode *node)
{
	struct stack *stack = malloc(sizeof(*stack));
	stack->node = node;
	stack->next = NULL;
	if (q->head == NULL) {
		q->head = q->tail = stack;
	} else {
		q->tail->next = stack;
		q->tail = stack;
	}
}

static struct TreeNode *deq(struct queue *q)
{
	struct stack *t;
	struct TreeNode *node;
	t = q->head;
	q->head = q->head->next;
	node = t->node;
	free(t);
	return(node);
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
	if (root == NULL) {
		*returnSize = 0;
		return(NULL);
	}

	struct queue q1, q2;
	struct TreeNode *rmost;
	int	*res, max;

	res = NULL;
	memset(&q1, 0, sizeof(q1));
	memset(&q2, 0, sizeof(q2));
	enq(&q1, root);
	while (!isempty(&q1)) {
		rmost = NULL;
		while (!isempty(&q1)) {
			rmost = deq(&q1);
			if (rmost->left)
				enq(&q2, rmost->left);
			if (rmost->right)
				enq(&q2, rmost->right);
		}
		if (rmost) {
			if (res == NULL) {
				max = 8;
				res = malloc(max * sizeof(res[0]));
				*returnSize = 0;
			}
			if (*returnSize >= max) {
				max += 8;
				res = realloc(res, max * sizeof(res[0]));
			}
			res[(*returnSize)++] = rmost->val;
		}
		q1 = q2;
		q2.head = q2.tail = NULL;
	}
	return(res);
}

int main(void)
{
}
