struct ListNode* merge(struct ListNode* a,
                       struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    tail->next = (a != NULL) ? a : b;

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second = slow->next;
    slow->next = NULL;

    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(second);

    return merge(left, right);
}