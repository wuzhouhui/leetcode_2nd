#include <stdlib.h>

static struct stack {
	int	val;
	struct stack *next;
} *stack;

static void push(int val)
{
	struct stack *t = malloc(sizeof(struct stack));
	t->val = val;
	t->next = stack;
	stack = t;
	return;
}

static int top(void)
{
	return(stack->val);
}

static int pop(void)
{
	int	val = stack->val;
	struct stack *t = stack;
	stack = stack->next;
	free(t);
	return(val);
}

int largestRectangleArea(int *height, int heightSize)
{
	int	i, max, t, tmp;

	stack = 0;
	max = 0;
	i = 0;
	while (i < heightSize) {
		if (!stack || height[i] >= height[top()]) {
			push(i++);
			continue;
		}

		t = pop();
		tmp = (!stack ? i : i - 1 - top()) * height[t];
		if (tmp > max)
			max = tmp;
	}
	while (stack) {
		t = pop();
		tmp = (!stack ? i : i - 1 - top()) * height[t];
		if (tmp > max)
			max = tmp;
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 2, 1, 5, 6, 2, 3};
	printf("%d\n", largestRectangleArea(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
