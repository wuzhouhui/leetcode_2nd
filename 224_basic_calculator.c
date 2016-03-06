#include <stdlib.h>
#include <ctype.h>

struct stack {
	long val;
	struct stack *next;
};

static long pop(struct stack **stk)
{
	struct stack *t = *stk;
	long val = t->val;
	*stk = (*stk)->next;
	free(t);
	return(val);
}

static void push(struct stack **stk, long val)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = val;
	t->next = *stk;
	*stk = t;
}

static long top(struct stack **stk)
{
	return((*stk)->val);
}

static int isempty(struct stack **stk)
{
	return(*stk == NULL);
}

int calculate(char *s)
{
	struct stack *operator, *oprand;
	long op1, op2, op;

	oprand = operator = NULL;
	while (*s) {
		switch (*s) {
		case ' ':
			s++;
			continue;
		case '+':
		case '-':
		case '(':
			push(&operator, *s);
			s++;
			continue;
		case ')':
			while (top(&operator) != '(') {
				op = pop(&operator);
				op2 = pop(&oprand);
				op1 = pop(&oprand);
				if (op == '+')
					op1 += op2;
				else
					op1 -= op2;
				push(&oprand, op1);
			}
			pop(&operator);
			while (!isempty(&operator) && top(&operator) == '-') {
				op2 = pop(&oprand);
				op1 = pop(&oprand);
				pop(&operator);
				push(&oprand, op1 - op2);
			}
			s++;
			continue;
		default:
			op = 0;
			while (isdigit(*s)) {
				op = 10 * op + *s - '0';
				s++;
			}
			push(&oprand, op);
			while (!isempty(&operator) && top(&operator) == '-') {
				op2 = pop(&oprand);
				op1 = pop(&oprand);
				pop(&operator);
				push(&oprand, op1 - op2);
			}
		}
	}
	while (!isempty(&operator)) {
		op2 = pop(&oprand);
		op1 = pop(&oprand);
		if (pop(&operator) == '+')
			push(&oprand, op1 + op2);
		else
			push(&oprand, op1 - op2);
	}
	if (isempty(&oprand))
		return(0);
	else
		return(pop(&oprand));
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
