// Given the head of a linked list, remove the nth node from the end of the list and return its head.





#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++) fast = fast -> next;
        if(!fast) return head -> next;

        while(fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }

        slow -> next = slow -> next -> next;
        return head;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        if(temp->next != nullptr) cout << temp->val << " -> ";
        else cout << temp->val;
        temp = temp->next;
    }
}

int main () {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int n = 2;

    cout<<"Original List: ";
    printList(head);

    sol.removeNthFromEnd(head, n);
    cout<<"\nAfter removing "<< n <<"nd node from end: ";
    printList(head);
}