#include <stdlib.h>

#ifndef bool 
#define bool int
#endif

struct stack {
	int	val;
	struct stack *next;
};

struct stack *stack;

static void push(int c)
{
	struct stack *tmp = malloc(sizeof(struct stack));
	tmp->val = c;
	tmp->next = stack;
	stack = tmp;
	return;
}

static int pop(void)
{
	if (!stack)
		return(0);
	struct stack *tmp = stack;
	stack = stack->next;
	int	val = tmp->val;
	free(tmp);
	return(val);
}

bool isValid(char *s)
{
	int	i, valid;

	stack = NULL;
	valid = 1;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '(':
		case '[':
		case '{':
			push(s[i]);
			break;
		case ')':
			if (pop() != '(')
				valid = 0;
			break;
		case ']':
			if (pop() != '[')
				valid = 0;
			break;
		case '}':
			if (pop() != '{')
				valid = 0;
			break;
		}
		if (!valid)
			break;
	}
	
	while (stack) {
		pop();
		valid = 0;
	}
	return(valid);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", isValid(argv[1]));
	return(0);
}
