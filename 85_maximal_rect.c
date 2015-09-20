#include <stdlib.h>
#include <string.h>

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

static int largestRectangleArea(int *height, int heightSize)
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

int maximalRectangle(char **matrix, int matrixRowSize, int matrixColSize)
{
	int	h[matrixColSize];
	int	i, j, max, t;

	max = 0;
	memset(h, 0, sizeof(h));
	for (i = 0; i < matrixRowSize; i++) {
		for (j = 0; j < matrixColSize; j++)
			if (matrix[i][j] == '1')
				h[j]++;
			else
				h[j] = 0;
		t = largestRectangleArea(h, matrixColSize);
		if (t > max)
			max = t;
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
}
