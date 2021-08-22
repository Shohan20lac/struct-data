#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

bool listEmpty( ListNode* head ) {
    if (head == nullptr)
        return true;
    else
        return false;
}

bool oneElement(ListNode* head) {
    if (head->next == nullptr)
        return true;
    else
        return false;
}

void addNode( ListNode* &head , int element ) {
    ListNode* newnode = new ListNode;
    newnode->data = element;
    
    //if list is empty
    if (head == nullptr)    
    {
        head = newnode;
        head->data = element;
        newnode->next = nullptr;
        return;
    }

    // if list is non empty
    ListNode* current = head;
    while (current -> next != nullptr) {
        current = current->next;
        cout << "Traversed once" << endl;
    }
    current->next = newnode;
    newnode->next = nullptr;
    cout << "Added node of value " << element << " to back of lineked list." << endl;
}



void addAtIndex( ListNode* &head, int element, int index ) {
    cout << "Adding element " << element << " at index " << index << "..." << endl;

    ListNode* newnode = new ListNode;
    newnode->data = element;

    if (head == nullptr) {
        cout << "List is empty. Adding at front without iteration... " << endl;
        head = newnode;
        head->data = element;
        newnode->next = nullptr;
        
        cout << "Added node of value " << element << " to front of lineked list." << endl;
        return;
    }

    
    ListNode* current = head;
    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
        cout << "iterated and traversed to next index" << endl;
    }
    
    newnode->next = current->next;
    current->next = newnode;
    cout << "Added element " << element << " after index " << index << endl;
}

void showNodes(ListNode* head) {
    if (listEmpty(head))
        return;

    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl << endl;
}

void showAtIndex(ListNode* head, int index) {
    if (head == nullptr) {
        cout << "list is empty!" << endl;
        return;
    }

    ListNode* current = head;
    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
        cout << "iterated and traversed to next index" << endl;
    }

    cout << "Showing element at index " << i << ": ";
    cout << (current->data);

    cout << endl << endl;
}

void showEvenIndexes( ListNode* head ) {
    if (listEmpty(head))
        return;

    ListNode* current = head;
    int i = 0;
    while (current != nullptr ) {
        if (i % 2 == 0)
            cout << (current->data) << endl;
        current = current->next;
        i++;
    }
}

void deleteFront( ListNode* &head ) {
    if (listEmpty(head))
        return;

    ListNode* trash = head;
    head = head->next;
    cout << "deleting head node of value " << trash->data << "..." << endl;
    delete trash;
    cout << "done" << endl;
}

void deleteBack( ListNode*& head ) {
    if (listEmpty(head))
        return;

    //if only one element
    if (head->next == nullptr)
    {
        ListNode* trash = head;
        head = head->next;
        cout << "deleting head node of value " << trash->data << "..." << endl;
        delete trash;
        cout << "done" << endl;
    }

    ListNode* current = head;
    while ( current->next->next != nullptr ) {
        current = current->next;
        cout << "Traversed once" << endl;
    }
    cout << "Second last node reached. value: " << current->data << ". Initiating delete protocol..." << endl;
    ListNode* trash = current->next;
    current->next = current->next->next;
    delete trash;   
}

void deleteAtIndex(ListNode*& head, int index) {
    cout << "deleting node at index " << index << "..." << endl;
    if (listEmpty(head))
        return;

    if (oneElement(head) || index == 0) {
        deleteFront(head);
        return;
    }
    
    int i = 0;
    ListNode* current = head;
    while ( i < (index - 1) ) {
        current = current->next;
        i++;
        cout << "iterated and traversed to next index" << endl;
    }
    cout << "(n-1) th node reached. Value: " << current->data << ". Initiating delete protocol..." << endl;
    ListNode* trash = current->next;
    current->next = current->next->next;
    delete trash;
}

void deleteOddIndexes( ListNode* &head ) {
    if ( listEmpty(head) )
        return;

    if ( oneElement(head) ) {
        deleteFront(head);
        return;
    }

    //else, if the list has more than one element...

    int i = 0;
    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr) {
        if (i % 2 != 0) {
            //initiate delete protocol
            prev->next = current->next;
            ListNode* trash = current;
            current = current->next;
            delete trash;
        }
        else {
            prev = current;
            current = current->next;
        }
        i++;
    }
}



int main()
{
    ListNode* head = nullptr;
    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);
    addNode(head, 40);
    addNode(head, 50);
    addNode(head, 60);
    addNode(head, 70);
    cout << endl;

    deleteOddIndexes(head);
    
    showNodes(head);


}
