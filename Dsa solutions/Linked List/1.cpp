#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = NULL;

    ListNode(int val)
    {
        this->val = val;
    }
};

// 876 Middle of the Linked List
// T: O(n), S: O(1)
ListNode *midNode(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// 206. Reverse Linked List
// T: O(n), S: O(1)
ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        ListNode *forw = curr->next; // backup

        curr->next = prev; // link

        prev = curr; // move
        curr = forw;
    }

    return prev;
}

// 234. Palindrome Linked List
// T: O(n), S: O(1)
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* mid = midNode(head);
        ListNode* nhead = mid->next;
        mid->next = NULL;
        nhead = reverse(nhead);

        bool flag = true;
        ListNode *c1 = head, *c2 = nhead;
        while (c1 != NULL && c2 != NULL) {
            if (c1->val != c2->val) {
                flag = false;
                break;
            }

            c1 = c1->next;
            c2 = c2->next;
        }

        nhead = reverse(nhead);
        mid->next = nhead;

        return flag;
    }

// 143  Reorder List  // fold linked list
// T: O(n), S: O(1)
void fold(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    ListNode *mid = midNode(head);
    ListNode *nhead = mid->next;
    mid->next = NULL;
    nhead = reverse(nhead);

    ListNode *c1 = head, *c2 = nhead;

    while (c2 != NULL)
    {
        ListNode *f1 = c1->next, *f2 = c2->next;

        c1->next = c2;
        c2->next = f1;

        c1 = f1;
        c2 = f2;
    }
}

// Unfold the linked list
// T: O(n), S: O(1)
 void unfold(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode *c1 = head, *c2 = head->next, *nHead = c2;
        while (c2 != NULL && c2->next != NULL) {
            ListNode* f1 = c2->next;

            c1->next = f1;
            c2->next = f1->next;

            c1 = c1->next; // c1 = f1;
            c2 = c2->next; // c2 = c1->next;
        }

        c1->next = NULL;
        nHead = reverse(nHead);
        c1->next = nHead;
    }

// 21. Merge Two Sorted Lists
// T: O(n + m), S: O(1)
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
        return l1 != NULL ? l1 : l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy, *c1 = l1, *c2 = l2;

    while (c1 != NULL && c2 != NULL)
    {
        if (c1->val <= c2->val)
        {
            prev->next = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }

    prev->next = c1 != NULL ? c1 : c2;
    ListNode *head = dummy->next;
    dummy->next = NULL;
    delete dummy;
    return head;
}

//  148. Sort List
//T:O(nlogn)
ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = midNode(head);
        ListNode* nHead = mid->next;
        mid->next = NULL;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(nHead);
        return mergeTwoLists(left,right);
    }

// 23. Merge k Sorted Lists
// TC = O(NK^2)
ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        for (auto i : lists) {
            res = mergeTwoLists(res, i);
        }
        return res;
    }

// 23 Merge k Sorted Lists(2nd approach)  ,, // SC O(log(K))
// TC : O(Nlog(K)),,K = size of array,L = nodes in each linked list ,, N = KL = total nodes in merged list
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
        return l1 != NULL ? l1 : l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy, *c1 = l1, *c2 = l2;

    while (c1 != NULL && c2 != NULL)
    {
        if (c1->val <= c2->val)
        {
            prev->next = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }

    prev->next = c1 != NULL ? c1 : c2;
    ListNode *head = dummy->next;
    dummy->next = NULL;
    delete dummy;
    return head;
}
ListNode *mergeKSortedLists(vector<ListNode*>& lists,int si,int ei){
        if(si < ei)return NULL;
        if(si == ei)return lists[si];
        int mid = (si+ei)/2;
        ListNode *l1 = mergeKSortedLists(lists,si,mid);
        ListNode *l2 = mergeKSortedLists(lists,mid+1,ei);
        return mergeTwoLists(l1,l2);
    }
ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        return mergeKSortedLists(lists,0,lists.size()-1);
    }
    
// Segregate even and odd nodes in a Link List

ListNode *segregateEvenOdd(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *even = new ListNode(-1), *odd = new ListNode(-1);
    ListNode *ep = even, *op = odd, *curr = head;

    while (curr != NULL)
    {
        if (curr->val % 2 != 0)
        {
            op->next = curr;
            op = op->next;
        }
        else
        {
            ep->next = curr;
            ep = ep->next;
        }
        curr = curr->next;
    }

    ep->next = NULL, op->next = NULL;
    ep->next = odd->next;

    return even->next;
}

// 328. Odd Even Linked List
ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *even = new ListNode(-1), *odd = new ListNode(-1);
    ListNode *ep = even, *op = odd, *curr = head;
    int count = 0;

    while (curr != NULL){
        count++;

        if (count % 2 != 0)
        {
            op->next = curr;
            op = op->next;
        }
        else
        {
            ep->next = curr;
            ep = ep->next;
        }
        curr = curr->next;
    }

    ep->next = NULL, op->next = NULL;
    op->next = even->next;

    return odd->next;
    }

// finding length of linkedlist
int length(ListNode *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

ListNode *th = NULL, *tt = NULL;

void addFirstNode(ListNode *node)
{
    if (th == NULL)
        th = tt = node;
    else
    {
        node->next = th;
        th = node;
    }
}

ListNode *reverseInKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k <= 1)
        return head;

    int len = length(head);
    ListNode *curr = head, *oh = NULL, *ot = NULL;
    while (curr != NULL && len >= k)
    {
        int tempK = k;
        while (tempK-- > 0)
        {
            ListNode *forw = curr->next;
            curr->next = NULL;
            addFirstNode(curr);
            curr = forw;
        }

        if (oh == NULL)
        {
            oh = th;
            ot = tt;
        }
        else
        {
            ot->next = th;
            ot = tt;
        }

        th = tt = NULL;
        len -= k;
    }

    ot->next = curr;

    return oh;
}

// 25. Reverse Nodes in k-Group
// finding length of linkedlist(when remaining nodes to be leave as it is)
    int length(ListNode *head){
    int len = 0;
    while (head != NULL){
        head = head->next;
        len++;
    }
    return len;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
       if(head == NULL){
           return head;
       }
       // step 1 reverse first k nodes
       ListNode* curr=head,*prev=NULL,*forw=NULL;
       int cnt=0;
       while(curr != NULL && cnt < k){
           forw = curr->next;
           curr->next=prev;
           prev=curr;
           curr=forw;
           cnt++;
       }
       // recursive part
       int len = length(forw);
       if(forw != NULL ){
           if(len >= k){
               head->next = reverseKGroup(forw,k);
           }else{
               head->next = forw;
           }
       }
       
       // step 3 return head of reversed list 
        return prev;
    }

// Reverse a Linked List in groups of given size(GFG)
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
       if(head == NULL){
           return head;
       }
       // step 1 reverse first k nodes
       ListNode* curr=head,*prev=NULL,*forw=NULL;
       int cnt=0;
       while(curr != NULL && cnt < k){
           forw = curr->next;
           curr->next=prev;
           prev=curr;
           curr=forw;
           cnt++;
       }
       // step 2 recursive part
       if(forw != NULL ){
            head->next = reverseKGroup(forw,k);
       }
       
       // step 3 return head of reversed list 
        return prev;
    }

ListNode *multiplyDigitWithLL(ListNode *list, int digit)
{
    ListNode *dummy = new ListNode(-1), *prev = dummy, *c = list;
    int carry = 0;
    while (c != NULL || carry != 0)
    {
        int prod = carry + (c != NULL ? c->val : 0) * digit;
        carry = prod / 10;
        int num = prod % 10;

        prev->next = new ListNode(num);
        prev = prev->next;

        if (c != NULL)
            c = c->next;
    }

    return dummy->next;
}

void addTwoLL(ListNode *curr, ListNode *prev)
{
    int carry = 0;
    while (curr != NULL || carry != 0)
    {
        int sum = carry + (curr != NULL ? curr->val : 0) + (prev->next != NULL ? prev->next->val : 0);
        carry = sum / 10;

        if (prev->next == NULL)
            prev->next = new ListNode(0);
        prev = prev->next;
        prev->val = sum % 10;

        if (curr != NULL)
            curr = curr->next;
    }
}

ListNode *multiplyTwoLL(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode *dummy = new ListNode(-1), *prev = dummy, *l2_itr = l2;

    while (l2_itr != NULL)
    {
        ListNode *smallAnsList = multiplyDigitWithLL(l1, l2_itr->val);
        addTwoLL(smallAnsList, prev);

        prev = prev->next;
        l2_itr = l2_itr->next;
    }

    return reverse(dummy->next);
}

// multiply k list
ListNode *multiplyKList(vector<ListNode *> &list)
{
}
