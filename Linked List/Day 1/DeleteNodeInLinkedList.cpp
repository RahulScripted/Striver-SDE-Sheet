// There is a singly-linked list head and we want to delete a node node in it. You are given the node to be deleted node. You will not be given access to the first node of head. All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.




#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        if(curr -> next != nullptr)  cout << curr -> val << " -> ";
        else cout << curr-> val;
        curr = curr->next;
    }
}

int main (){
    Solution sol;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout<<"Original List: ";
    printList(head);

    sol.deleteNode(head->next);
    cout<<"\nList after deletion: ";
    printList(head);
}