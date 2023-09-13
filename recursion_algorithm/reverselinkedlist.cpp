#include "bits/stdc++.h"

using namespace std;

struct Node {
    int data;
    Node * next;
    Node () {
        this->next = nullptr;
    }
};

void print(Node * list) {
    Node *temp = list;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node * reverse (Node * node, Node *& head) {
    if (node->next == nullptr) {
        head = node;
        return node;
    }

    Node * temp = reverse(node->next, head);
    temp->next = node;
    node->next = nullptr;
    return node;
}

int main() {
    Node * list = new Node();
    list->data = 0;
    Node * tempHead = list;
    int len = 5;
    for (int i = 1; i < len; i++) {
        Node * tempNode = new Node();
        tempNode->data = i;
        tempHead->next = tempNode;
        tempHead = tempHead->next;
    }
    tempHead->next = nullptr;

    // Node * next = nullptr;
    // Node * cur = list;
    // Node * pre = nullptr;

    // while (cur != nullptr) {
    //     next = cur->next;
    //     cur->next = pre;
    //     pre = cur;
    //     cur = next;
    // }
    // Node * newlist = cur;
    // print(newlist);

    Node * temp_list = list;
    Node * nnlist = reverse(list, temp_list);

    print(temp_list);
    return 0;
}