
#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    
    /*/page(int pn) {
        content = pn;
    }
    */
};

void addNode(ListNode*& head, int num) {
    if (head == nullptr)
        //head = new page(num);
    {
        head = new ListNode;
        head->data = num;
        head->next = nullptr;
    }
        
    else {
        ListNode* current = head;
        while (current->next != nullptr) {			//while we havent reached the last page
            current = current->next;				//keep traversing
        }
        current->next = new ListNode;
        current->next->data = num;
        current->next->next = nullptr;
    }
}

void showNodes(ListNode* &head) {
    ListNode* current = head;
    cout << (head->data) << endl;
    while (current->next != nullptr) {			//while we havent reached the last page
        current = current->next;				//keep traversing
        cout << current->data << endl;
 
    
    }
}

void showEvenIndexes(ListNode*& head) {
    int index = 0;
    ListNode* current = head;
    
    if (index % 2 == 0) {   //if index is even
        cout << (head->data) << endl;
    }

    while (current->next != nullptr) {			//while we havent reached the last page
        index++;
        current = current->next;				//keep traversing
        
        if (index % 2 == 0) {   //if index is even
            cout << current->data << endl;
        }
    }
}

void showPairs(ListNode* head1, ListNode*head2) {
    ListNode* current1 = head1;
    ListNode* current2 = head2;

    //case1 : One or more list is empty
    if (current1 == nullptr || current2 == nullptr) {
        cout << "One or more list is empty!" << endl;
    }

    //case2 : One more lists contains only one element
    else if (current1->next == nullptr || current2->next == nullptr) {
        cout << "One more lists contains only one element" << endl;
        cout << current1->data << " , " << current2->data << endl;
    }

    //case3 : Both lists contain more than one element
    else {
        cout << head1->data << " , " << head2->data << endl;
        while ( current1->next != nullptr || current2->next !=nullptr ) {
            current1 = current1->next;
            current2 = current2->next;
            cout << current1->data << " , " << current2->data << endl;
        }

    }
}

bool hasDataAtIndex(ListNode*& head, int val, int index) {      //returns whether a linked list node contains data=val at index # index.
    int i = 0;
    ListNode* current = head;
    if (head == nullptr)                        //zero elements
        return false;

    if (head->data == val && i ==index )                      //first elements 
        return true;

    while (current->next != nullptr) {			//while we havent reached the last page
        i++;
        current = current->next;				//keep traversing
        if (current->data == val && i == index) {
            cout << "value " << val << " found at index " << i << endl;
            return true;
        }

    }
    if (current->next == nullptr)
        return false;
}

bool hasDataAtEvenIndex(ListNode*& head, int val, int index) {      
    int i = 0;
    ListNode* current = head;
    if (head == nullptr)                        //zero elements
        return false;

    if (head->data == val && i == index)                      //first elements 
        return true;

    while (current->next != nullptr) {			//while we havent reached the last page
        i++;
        current = current->next;				//keep traversing
        if (current->data == val && i == index) {
            cout << "value " << val << " found at index " << i << endl;
            return true;
        }

    }
    if (current->next == nullptr)
        return false;
}

bool hasData (ListNode*& head, int num ) {
    ListNode* current = head;

    if (current->data == num)
        return true;

    while (current->next != nullptr) {			//while we havent reached the last page
        current = current->next;
        //keep traversing
        if (current->data == num)
            return true;
    }
    return false;
}

bool hasDataArray (ListNode*& head, int numbers[], int size) {
    ListNode* current = head;

    //check with head
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == current->data)
            return true;
    }

    while (current->next != nullptr) {			//while we havent reached the last page
        current = current->next;

        //check with rest of nodes
        for (int j = 0; j < size; j++)
        {
            if (numbers[j] == current->data)
                return true;
        }
    }
    return false;
}

bool arrayHasValue(int arr[], int val) {
    int k = 0;
    while (arr[k] != '0') {
        if (arr[k] == val)
            return true;
        else
            k++;
    }
    return false;
}

void linkedListMystery11(ListNode* &front1, ListNode* &front2) {		//! MOST IMPORTANT SIDE QUEST (1/3)
    ListNode* curr1 = front1;

    while (front2 != nullptr) {
        if ( curr1 -> next == nullptr) {
            curr1->next = front2;
            front2 = nullptr;
        }
        else if (front2->data < curr1->next->data) {
            ListNode* temp2 = front2;
            front2 = front2->next;
            temp2->next = curr1->next;
            curr1->next = temp2;
        }
        else {
            curr1 = curr1->next;
        }
    }
}


int countDuplicates(ListNode* head) {

    if (head == nullptr)
        return 0;

    //SET of numbers
    int numset[500];
    for (int i = 0; i < 500; i++)
        numset[i] = '0';
    int j = 0;
    int dupcount = 0;

    ListNode* current = head;

    //BASE CASE
    cout << (head->data) << endl;
    bool arrayHasValue;
    for (int k = 0; k < 500; k++)
    {
        if (numset[k] == head->data) {
            arrayHasValue = true;
            break;
        }
        else {
            arrayHasValue = false;
        }
    }


    if (!arrayHasValue) {
        numset[j] = head->data;
        j++;
    }
    else {
        cout << "duplicate found!" << endl;
        dupcount++;
    }
        
    //INDUCTIVE CASE
    while (current->next != nullptr) {			//while we havent reached the last page
        current = current->next;				//keep traversing
        
        cout << current->data << endl;
        for (int k = 0; k < 500; k++)
        {
            if (numset[k] == head->data) {
                arrayHasValue = true;
                break;
            }
            else {
                arrayHasValue = false;
            }
        }
        if (!arrayHasValue) {
            numset[j] = current->data;
            j++;
        }
        else {
            cout << "duplicate found!" << endl;
            dupcount++;
        }
    }

    return dupcount;
}

void switchPairs(ListNode* head1, ListNode* head2) {
    ListNode* current1;
    ListNode* current2;
    current1 = head1;
    current2 = head2;

    //base (front) case
    if (((head1->data) % 2 == 0) || ((head2->data) % 2 == 0))
    {
        head1 = current2; head2 = current1;
        ListNode* temp = head1->next;
        head1->next = head2->next;
        head2->next = temp;

        //resetting for the next iteration
        current2 = head2;
        current1 = head1;
    }
    //otherwise, move on to loop case


    //loop case
    ListNode* prev1; ListNode* prev2;

    ListNode* temp;
    while (((current1->next) != nullptr) || ((current1->next) != nullptr)) {
        prev1 = current1;
        prev2 = current2;

        current1 = current1->next;
        current2 = current2->next;

        if (((current1->data) % 2 == 0) || ((current2->data) % 2 == 0)) {
            //initiate swap protocol
            prev1->next = current2; prev2->next = current1;
            temp = current1->next;
            current1->next = current2->next;
            current2->next = temp;

            current1 = prev1->next;
            current2 = prev2->next;

        }
    }

}

void removeBack ( ListNode* &head) {
    if (head == nullptr)
        return;

    else if (head->next == nullptr) {
        ListNode* trash = head;
        delete trash;
        return;
    }

    else {
        ListNode* current = head;
        while (current->next != nullptr)
            current = current->next;

        ListNode* trash = current;
        delete trash;
    }

}

void showNodes2 (ListNode*& head) {
    ListNode* current = head;

    if (head == nullptr) {
        cout << "list empty!" << endl;
        return;
    }

    while (current != nullptr) {			
        cout << current->data << endl;
        current = current->next;
    }
}

void printIndex( ListNode* head, int index ) {
    if (head == nullptr) {
        cout << "list empty!" << endl;
        return;
    }

    if (head->next = nullptr) {
        cout << "value of node at index" << index << ": " << (head->data) << endl;
    }
}

void showNodesIndex(ListNode*& head, int index) {
    ListNode* current = head;

    if (head == nullptr) {
        cout << "list empty!" << endl;
        return;
    }

    for (int i = 0; i < index; i++)
    {
        if (current == nullptr)
            break;
        cout << current->data << endl;
        current = current->next;
    }
}

void deleteIndex(ListNode*& head, int index) {
    cout << "\nDeleting node at index" << index << endl;

    if (head == nullptr) {  //no elements
        cout << "list empty!" << endl;
        return;
    }

    if (head->next == nullptr && index == 0)  //only one element
    {
        cout << "list has only one element!" << endl;
        cout << "index:" << index << endl;
        head = head->next;
        delete head;
        return;
    }

    if (head->next != nullptr && index == 0) {  //more than one pointer, index==0 (removeFront)
        cout << "List has more than one element, index= " << index <<". ";
        cout << "Initiating removeFront..." << endl;

        ListNode* trash = head;
        head = head->next;
        cout << "Node with content " << trash->data << " removed from front." << endl;
        delete trash;
        return;
    }

    else if ( head->next != nullptr && index>0 ) {
        cout << "List has more than one element and index>0. Initiating iterative approach..." << endl;
        
        ListNode* current = head;
        for (int i = 0; i < index; i++)
        {
            if (current == nullptr) {
                cout << "End of list reached" << endl;
                break;
            }

            if (i == (index - 1)) {
                //end of list reached. Initiate removeBack...
                ListNode* trash = current->next;
                current->next = current->next->next;
                delete trash;
            }

            current = current->next;
        }
    }

    
}

void linkedListMystery1(ListNode* &front) {
    ListNode* curr = front;
    while (curr != nullptr) {
        if (curr->next != nullptr && curr->data > curr->next->data) {
            curr->data++;
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = curr;
        }
        curr = curr->next;
    }
}

void removeBack3(ListNode* &head) {
	//Remove the last element fo the list
    if (head == nullptr)
    {
        cout << "list empty!" << endl;
        return;
    }
    
    if (head->next == nullptr ) {   //only one element
        ListNode* trash = head;
        head = head->next;
		delete head;
        return;
	}

    {
        ListNode* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}
        //end of list reached. Initiate removeBack...
        ListNode* trash = current->next;
		current->next = current->next->next;
		delete trash;
	}
}

void reverse(ListNode* &head) {
    if (head == nullptr)
        return;

    if (head->next == nullptr) { //one node only
        return;
    }

    if (head->next->next == nullptr) //two nodes only
    {
        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = nullptr;
        curr->next = prev;
        head = curr;
        return;
    }

    if (head->next->next->next == nullptr) //three nodes only
    {
        ListNode* prev = head;
        ListNode* current = prev->next;
        ListNode* after = current->next;
        prev->next = nullptr;

        current->next = prev;
        after->next = current;
        head = after;
        return;
    }
    else {  //more than three nodes
        ListNode* prev = head;
        ListNode* current = prev->next;
        ListNode* after = current->next;
        prev->next = nullptr;

        while (after != nullptr) {

            if (after->next == nullptr)    //last three nodes reached; time to pack up and finish
            {
                current->next = prev;
                after->next = current;
                head = after;
                after = nullptr;
            }
            else {
                current->next = prev;
                prev = current;
                current = after;
                after = after->next;
            }
        }
    }
    
}

void addFront( ListNode* head, int element ) {
    ListNode* newnode = new ListNode;
    newnode->next = head;
    head = newnode;
}

void addtoindex( ListNode* &head, int element, int index ) {
    ListNode* newnode = new ListNode;
    ListNode* current = head;
    
    if (head = nullptr)   //emptylist. index irrelevant.
    {
        head = newnode;
        return;
    }

    if (index == 0) {       
        addFront(head, element);
        return;
    }

    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }
    
    newnode->next = current->next;
    current->next = newnode;


        



}

int main()
{
    cout << "hello world!" << endl;


}
