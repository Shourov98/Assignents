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

ListNode* margeSortedList(ListNode* head1, ListNode* head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    ListNode* newHead = NULL;
    if(head1->val <= head2->val) {
        newHead = head1;
        newHead->next = margeSortedList(head1->next, head2);
    } else {
        newHead = head2;
        newHead->next = margeSortedList(head1, head2->next);
    }

    return newHead;
};

void printLinkedList(ListNode* head) {
    while(head!= NULL) {
        cout << head->val;
        head = head->next;
        if(head!= NULL) cout << " -> ";
    }
    cout << endl;
    return;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> values1(n);
    for(int i = 0; i < n; i++) {
        cin >> values1[i];
    }
    ListNode* head1 = createLinkedList(values1);

    vector<int> values2(m);
    for(int i = 0; i < m; i++) {
        cin >> values2[i];
    }
    ListNode* head2 = createLinkedList(values2);

    ListNode* newHead = margeSortedList(head1, head2);
    printLinkedList(newHead);

    return 0;
}