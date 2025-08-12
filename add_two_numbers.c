#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* ret = calloc(1, sizeof(struct ListNode));
	ret->next = l1;
	int c = 0;

	struct ListNode* cur = ret;
	while(l1 != NULL && l2 != NULL) {
		c += l1->val + l2->val;
		cur->next->val = c % 10;
		c /= 10;

		cur = cur->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	cur->next = (l1 == NULL)? l2: l1;
	while(cur->next != NULL) {
		c += cur->next->val;
		cur->next->val = c % 10;
		c /= 10;

		cur = cur->next;
	}

	if(c > 0) {
		cur->next = calloc(1, sizeof(struct ListNode));
		cur->next->val = c;
	}

	return ret->next;
}
