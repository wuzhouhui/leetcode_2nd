#include <stdlib.h>
#include <ctype.h>

struct stack {
	int	val;
	struct stack *next;
};

static void push(struct stack **s, int val)
{
	struct stack *t = malloc(sizeof(struct stack));
	t->val = val;
	t->next = *s;
	*s = t;
}

static int pop(struct stack **s)
{
	struct stack *t = *s;
	int	val = t->val;
	*s = (*s)->next;
	free(t);
	return(val);
}

int evalRPN(char **tokens, int tokensSize)
{
	struct stack *oprand;
	int	i, t;

	for (i = 0; i < tokensSize; i++) {
		if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' &&
					isdigit(tokens[i][1]))) {
			push(&oprand, atoi(tokens[i]));
			continue;
		}

		switch (tokens[i][0]) {
		case '+':
			push(&oprand, pop(&oprand) + pop(&oprand));
			break;
		case '-':
			t = pop(&oprand);
			push(&oprand, pop(&oprand) - t);
			break;
		case '*':
			push(&oprand, pop(&oprand) * pop(&oprand));
			break;
		case '/':
			t = pop(&oprand);
			push(&oprand, pop(&oprand) / t);
			break;
		}
	}
	t = pop(&oprand);
	return(t);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", evalRPN(&argv[1], argc - 1));
	return(0);
}
