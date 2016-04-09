#include <stdlib.h>

struct _stack {
	union {
		int	val;
		struct _stack *node;
	} unionval;
	struct _stack *next;
};

typedef struct {
	struct _stack *head;
	struct _stack *min;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize)
{
	stack->head = stack->min = NULL;
}

void minStackPush(MinStack *stack, int element)
{
	struct _stack *t = malloc(sizeof(*t));
	t->unionval.val = element;
	t->next = stack->head;
	stack->head = t;

	if (stack->min == NULL ||
			element < stack->min->unionval.node->unionval.val) {
		t = malloc(sizeof(*t));
		t->unionval.node = stack->head;
		t->next = stack->min;
		stack->min = t;
	}
}

void minStackPop(MinStack *stack)
{
	if (stack->head == NULL)
		return;

	struct _stack *t = stack->head;
	stack->head = t->next;
	if (t == stack->min->unionval.node) {
		free(t);
		t = stack->min;
		stack->min = t->next;
		free(t);
	} else
		free(t);
}

int minStackTop(MinStack *stack)
{
	return(stack->head->unionval.val);
}

int minStackGetMin(MinStack *stack)
{
	return(stack->min->unionval.node->unionval.val);
}

void minStackDestroy(MinStack *stack)
{
	struct _stack *t;
	while (stack->head) {
		t = stack->head;
		stack->head = t->next;
		free(t);
	}
	while (stack->min) {
		t = stack->min;
		stack->min = t->next;
		free(t);
	}
}
