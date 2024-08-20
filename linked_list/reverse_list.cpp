#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList( vector<int>& values) {
    if(values.size() == 0) return NULL;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for(int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* nextNode = NULL;

    while(current!= NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
};

void printList(ListNode* head) {
    ListNode* current = head;

    while(current!= NULL) {
        cout << current->val;
        current = current->next;
        if(current != NULL) cout << "->";
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }

    ListNode* head = createLinkedList(values);
    // cout << "Original List: ";
    // printList(head);
    // cout << endl;
    ListNode* reverseNode = reverseList(head);
    // cout << "Reversed List: ";
    printList(reverseNode);
    

    return 0;
}