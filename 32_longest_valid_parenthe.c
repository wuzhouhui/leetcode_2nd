#include <stdlib.h>

struct stack {
	int	val;
	int	pos;
	struct stack *next;
};

struct stack *stack;

static void push(int c, int pos)
{
	struct stack *s = malloc(sizeof(struct stack));
	s->val = c;
	s->pos = pos;
	s->next = stack;
	stack = s;
}

static void pop(struct stack *e)
{
	struct stack *t = stack;
	stack = stack->next;
	e->val = t->val;
	e->pos = t->pos;
	free(t);
}

static void peek(struct stack *e)
{
	if (!stack)
		return;
	e->val = stack->val;
	e->pos = stack->pos;
}

int longestValidParentheses(char *s)
{
	int	len, maxlen, i;
	struct stack e;
	
	stack = 0;
	maxlen = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '(') {
			push('(', i);
			continue;
		}

		/* s[i] == ')' */
		peek(&e);
		if (!stack || e.val == ')') {
			push(')', i);
		} else {
			pop(&e);
			if (!stack) {
				len = i + 1;
			} else {
				peek(&e);
				len = i - e.pos;
			}
			if (len > maxlen)
				maxlen = len;
		}
	}
	while (stack)
		pop(&e);
	return(maxlen);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", longestValidParentheses(argv[1]));
	return(0);
}
