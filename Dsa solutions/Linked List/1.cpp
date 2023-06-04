#include<bits/stdc++.h>
using namespace std;

// 876. Middle of the Linked List
ListNode* middleNode(ListNode* head) {
        if(head == NULL && head->next == NULL)return head;
        ListNode *fast=head,*slow=head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}