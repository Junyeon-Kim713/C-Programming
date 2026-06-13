#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void print_dlist_reverse(DListNode* phead)
{
	DListNode* p;
	for (p = phead->llink; p != phead; p = p->llink)
	{
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = data;
	node->rlink = before->rlink;
	node->rlink->llink = node;
	node->llink = before;
	before->rlink = node;
}
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->rlink->llink = removed->llink;
	removed->llink->rlink = removed->rlink;
	free(removed);
}
DListNode* search(DListNode* L, element data)
{
	DListNode* p = NULL;
	if (L->rlink == L)
	{
		printf("리스트가 비어있음. NULL 리턴 \n");
		return NULL;
	}
	for (p = L->rlink; p != L; p = p->rlink)
	{
		if (p->data == data)
			return p;
	}
	printf("데이터가 존재하지 않음. NULL 리턴 \n");
	return NULL;
}
int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	int num, i =0;
	init(head);

	printf("데이터의 개수를 입력하시오: ");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		int data;
		printf("노드 #%d의 데이터를 입력하시오: ", i +1);
		scanf("%d", &data);
		dinsert(head, data);
	}

}
