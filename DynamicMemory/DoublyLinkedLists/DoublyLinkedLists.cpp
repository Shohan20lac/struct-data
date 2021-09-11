#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct dllnode {
    int* scores = nullptr;
    int subjectcount;
    int data;
    dllnode* next = nullptr;
    dllnode* previous = nullptr;
};

int* setscores ( int count ) {
    
    int* randscores = new int[count];
    for (int i = 0; i < count; i++)
    {
        randscores[i] = rand() % 100;
    }
    return randscores;
}

void addNode(dllnode*& head, int count ) {
    int i = 0;
    dllnode* newnode = new dllnode;
    newnode->scores = setscores( count );
    
    //if list is empty
    if (head == nullptr) {
        cout << "list is empty. Adding to front..." << endl;
        head = newnode;
        head->subjectcount = count;
        head->next = nullptr;
        cout << "DONE: Added " << count << " scores to node number " << i << endl << endl;
        return;
    }

    //else, init for iteration

    dllnode* current = head;
    dllnode* temp = nullptr;

    //first, traverse all the way to the last node of the list.
    while (current->next != nullptr) {
        current = current->next;
        i++;
    }
    cout << "traversed to final node number" << i << endl;

    //once reached the back of the list,
    current->next = newnode;
    temp = current;
    current = current->next;
    current->previous = temp;
    current->next = nullptr; 
    current->scores = setscores( count );
    current->subjectcount = count ;
    
    cout << "DONE: Added " << count << " scores to node number " << i << endl << endl;

}

void showArr(int arr[], int size ) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showNodes(dllnode* head) {
    //if list empty
    if (head == nullptr) {
        cout << "No nodes in list!" << endl;
        return;
    }
    
    //else, init while loop parameters
    dllnode* current = head;
    int i = 0;    
    while (current != nullptr) {
    
        //show entire scores[] array of current node.
        cout << "Showing node # "<< i << "'s scores array: "; 
        for (int j = 0; j < current->subjectcount; j++)
        {
            cout << current->scores[j] << " ";
        }
        cout << endl;
        
        //iterate to next node
        current = current->next;
        i++;
    }

}

int main()
{
    srand(time(0));

    dllnode* head = nullptr;
    addNode(head, 5);
    addNode(head, 5);
    addNode(head, 5);

    showNodes(head);
    
    cout << head->scores[0]; 
    cout << endl;
    cout << head->scores[1];
}