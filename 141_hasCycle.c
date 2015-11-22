
struct ListNode {
	int	val;
	struct ListNode *next;
};

#ifndef bool
#define bool int
#endif

bool hasCycle(struct ListNode *head)
{
	if (!head || !head->next)
		return(0);

	struct ListNode *p1, *p2;

	p1 = head;
	p2 = head->next;
	while (p2 && p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
		if (p2)
			p2 = p2->next;
		else
			return(0);
	}
	if (!p2)
		return(0);
	else
		return(1);
}

int main(void)
{
	return(0);
}
