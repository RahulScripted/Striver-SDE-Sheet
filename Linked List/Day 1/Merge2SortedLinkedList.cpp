// You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.




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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(list1 && list2){
            if(list1 -> val > list2 -> val) {
                tail -> next = list2;
                list2 = list2 -> next;
            } else {
                tail -> next = list1;
                list1 = list1 -> next;
            }
            tail = tail -> next;
        }

        tail -> next = list1 ? list1 : list2;
        return dummy -> next;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    cout<<"First Linkedlist: ";
    printList(list1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    cout<<"Second Linkedlist: ";
    printList(list2);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);
    cout<<"Merged List: ";
    printList(mergedList);

    return 0;
}