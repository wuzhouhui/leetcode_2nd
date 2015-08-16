#include <stdlib.h>
#include <string.h>

struct stack {
	int	val;
	struct stack *next;
} *stack;

static char **res;
static int maxp, p;

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
	int	c = tmp->val;
	free(tmp);
	return(c);
}

static void add_ans(char *s, int l)
{
	if (!res) {
		maxp = 16;
		p = 0;
		res = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += 16;
		res = realloc(res, maxp * sizeof(char *));
	}
	res[p] = malloc((l + 1) * sizeof(char));
	memcpy(res[p], s, l);
	res[p][l] = 0;
	p++;
}

static void do_gen(char *s, int level, int n)
{
	int c;
	if (level >= n) {
		if (!stack)
			add_ans(s, n);
		return;
	}

	s[level] = '(';
	push('(');
	do_gen(s, level + 1, n);
	pop();

	s[level] = ')';
	c = pop();
	if (c == '(')
		do_gen(s, level + 1, n);
	if (c)
		push(c);
	return;
}

char **generateParenthesis(int n, int *returnSize)
{
	char	s[n + n];

	res = NULL;
	p = 0;
	stack = NULL;
	if (n > 0)
		do_gen(s, 0, n + n);

	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	i, n;
	char	**res = generateParenthesis(0, &n);
	for (i = 0; i < n; i++)
		printf("%s\n", res[i]);
	return(0);
}
