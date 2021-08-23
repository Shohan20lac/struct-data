#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

struct Page {
    string content;
    Page* nextpage;
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
void showNodes(Page* head) {
    if (head == nullptr)
        return;

    Page* current = head;
    while (current != nullptr) {
        cout << current->content << " ";
        current = current->nextpage;
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

void openfile( string filename ) {
    ifstream infile (filename);
    if (!infile.is_open()) {
        cout << "file not found" << endl;
        return;
    }
}
void printLines(string filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "file not found" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
}

void addPagesFromFile( Page*& head1 , string filename ) {
    cout << "Adding all pages from file " << filename << endl;

    ifstream infile(filename);
    string line;

    if (head1 == nullptr) {
        getline(infile, line);
        Page* newpage = new Page;
        head1 = newpage;
        head1->content = line;
        head1->nextpage = nullptr;
    }

    Page* current = head1;

    while (getline(infile, line)) {
        Page* newpage = new Page;
        newpage->content = line;

        current->nextpage = newpage;
        current = current->nextpage;

        newpage->nextpage = nullptr;
    }
}

bool hasMoreVowels(string s, int length, int vowelcount, int consonantcount) {
    cout << "String length:" << length << endl;

    if (length < 0) { 
        //time to wrap it up and send it back down the stack.
        if (vowelcount > consonantcount) {
            cout << "vowelcount " << vowelcount << " is greater than consonantcount " << consonantcount << endl;
            return true;
        }
        else{
            cout << "consonantcount " << consonantcount << " is greater than vowelcount " << vowelcount << endl;
            return false;
        }    
    }

    //else, keep recursin'.
    if (s[length] == 'a' || s[length] == 'e' || s[length] == 'i' || s[length] == 'o' || s[length] == 'u')
        return true && hasMoreVowels(s, length - 1, vowelcount + 1, consonantcount);
    else 
        return true && hasMoreVowels(s, length - 1, vowelcount, consonantcount + 1);
}

int main()
{
    int choice = 1000;

    while (choice != 0) {
        cout << "Enter choice:" << endl;
        cin >> choice;

        switch (choice)
        {
            case (1):   //hasmorevowels
            {
                //test string
                string s = "stieaour";
                cout << hasMoreVowels( s , s.length()-1 , 0 , 0 ) << endl;
            }break;

            default:
                break;
        }
    }
    /*Page* head1 = nullptr;
    string filename = "input.txt";
    string line;
    addPagesFromFile(head1, filename);
    showNodes(head1); */

    

}
    

    
    

    
