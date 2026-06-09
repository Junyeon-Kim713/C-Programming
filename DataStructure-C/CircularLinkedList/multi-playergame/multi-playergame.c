ListNode*  delete_first(ListNode* head)
{
	if (head == NULL)
		return;

	ListNode* p = head->link;
	// 예외 처리 2: 리스트에 노드가 딱 '1개'만 있었던 경우
	if (head == p) {
		free(p);             // 유일한 노드 메모리 해제
		return NULL;         // 이제 비어있으므로 NULL을 리턴!
	}

	head->link = p->link;
	free(p);

	return head; // head값이 바뀔 수 있으므로 head 반환 해줘야함
}
