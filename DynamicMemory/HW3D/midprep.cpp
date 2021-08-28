#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct ListNode {
    int data;         // value stored in each node
    ListNode* next;  // pointer to next node in list (nullptr if none)
};

struct Customer {
    int cnumber;
    int totalcost;
    Customer* next;
    queue <string> itemsbought;
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

void addFront( ListNode* &head , int element ) {
    ListNode* newnode = new ListNode;
    newnode->data = element;

    newnode->next = head;
    head = newnode;
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

void switchPairsOfPairs( ListNode* head ) {
    queue <int> temp1;
    queue <int> temp2;

    ListNode* current = head;

    int i = 0;
    while (current!= nullptr)
    {
        if (i % 4 == 0) {
            //Add 1st element to pair1
            temp1.push(current->data);
            cout << "pushed node of value " << current->data << " into temp1." << endl;
        }
        else if (i % 4 == 1) {
            //Add 2nd element to pair1
            temp1.push(current->data);
            cout << "pushed node of value " << current->data << " into temp1." << endl;
        }
        else if (i % 4 == 2) {
            //Add 1st element to pair2
            temp2.push(current->data);
            cout << "pushed node of value " << current->data << " into temp2." << endl;
        }
        else if (i % 4 == 3) {
            //Add 2nd element to pair2
            temp2.push(current->data);
            cout << "pushed node of value " << current->data << " into temp2." << endl;
        }
        current = current->next;
        deleteFront(head);

        if (temp1.size() == 2 && temp2.size() == 2) {
            cout << "Both temp queues are full. Time to empty them back into the linked list" << endl;
            
            //first temp2
            addNode(head, temp2.front()); temp2.pop(); current = current->next;
            addNode(head, temp2.front()); temp2.pop(); current = current->next;
            
            //then temp1
            addNode(head, temp1.front()); temp1.pop(); current = current->next;
            addNode(head, temp1.front()); temp1.pop(); current = current->next;
        }
        
        i++;
    }
    cout << endl << endl;
}

void swapDataReference(ListNode* &current1, ListNode* &current2 ) {
    int temp = current1->data;
    current1->data = current2->data;
    current2->data = temp;
}

void addN(ListNode*& n, int x)
{
    if (n == nullptr)
        return;

    ListNode* current = n;
    int i = 0;
    
    //init
    ListNode* newnode = new ListNode;
    newnode->data = x;
    newnode->next = current->next;
    current->next = newnode;
    
    current = current->next->next;

    while (current->next != nullptr) {
        ListNode* newnode = new ListNode;
        newnode->data = x;
        newnode->next = current->next;
        current->next = newnode;

        current = current->next->next;
    }
}

void addNTimes(ListNode*& n, int x, int p) {

    if (n == nullptr)
        return;

    ListNode* current = n;
    int i = 0;

    //init
    ListNode* newnode = new ListNode;
    newnode->data = x;
    newnode->next = current->next;
    current->next = newnode;

    current = current->next->next;
    i++;

    while ( current->next != nullptr && i<p ) {
        ListNode* newnode = new ListNode;
        newnode->data = x;
        newnode->next = current->next;
        current->next = newnode;

        current = current->next->next;
        i++; 
    }
}

string listElements(Customer* c) {
    int size = c->itemsbought.size();

    string output = "["; 
    for (int i = 0; i < size; i++)
    {
        
        if (i = size - 1) {
            output += (c->itemsbought.front());
            c->itemsbought.pop();
        }
        else {
            output += (c->itemsbought.front());
            output += ", ";
            c->itemsbought.pop();
        }
        
    }
    output += "]";

    return output;
}

void addNode(Customer *& head) {
    Customer* newnode = new Customer;

    //if list is empty
    if (head == nullptr)
    {
        head = newnode;
        newnode->next = nullptr;
        return;
    }

    // if list is non empty
    Customer* current = head;
    while (current->next != nullptr) {
        current = current->next;
        cout << "Traversed once" << endl;
    }
    current->next = newnode;
    newnode->next = nullptr;
}

void makereceipt( Customer* head) {
    ofstream outfile("outfile.txt");

    outfile << "Customer Total Cost \t Elements brought" << endl;

    Customer* current = head;
    while (current != nullptr) {
        outfile << current->cnumber << "\t\t" << current->totalcost << "\t\t" << listElements(current) << endl;
        current = current->next;
    }
}

void showNodes(Customer* head) {
    if (head == nullptr)
        return;

    Customer* current = head;
    while (current != nullptr) {
        cout << current->totalcost << " ";
        current = current->next;
    }
    cout << endl << endl;
}

void manageStore() {

    //Customer1
    Customer* c1 = new Customer;
    c1->cnumber = 1;
    c1->totalcost = 100;
    c1->itemsbought.push("potato");
    c1->itemsbought.push("tomato");
    c1->itemsbought.push("beans");

    Customer* head = c1;

    //Customer2
    Customer* c2 = new Customer;
    c2->cnumber = 2;
    c2->totalcost = 120;
    c2->itemsbought.push("pineapple");
    c2->itemsbought.push("chocolate");
    c2->itemsbought.push("sugar");

    head->next = c2;

    //Customer3
    Customer* c3 = new Customer;
    c3->cnumber = 3;
    c3->totalcost = 50;
    c3->itemsbought.push("potato");
    c3->itemsbought.push("tomato");
    c3->itemsbought.push("beans");

    head->next->next = c3;
    head->next->next->next = nullptr;

    showNodes(head);

    makereceipt(head);
}

void sortQ(queue <int> &Q) {
    int sortedcount = 0;
    queue <int> R;

    int largest=0;

    for (int k = 0; k < Q.size(); k++)
    {
        for (int i = 0; i < sortedcount; i++) {
            R.push(Q.front());
            Q.pop();
        }

        for (int i = 0; i < Q.size(); i++) {
            if (Q.front() >= largest)
                largest = Q.front();
            R.push(Q.front());
            Q.pop();
        }

        for (int i = 0; i < sortedcount; i++) {

            Q.push(R.front());
            R.pop();
        }

        for (int i = 0; i < Q.size(); i++)
        {
            if (R.front() != largest)
                Q.push(R.front());
            R.pop();
        }

        sortedcount++;
    }

        

    //showQueue 

    for (int i = 0; i < Q.size(); i++)
    {
        cout << Q.front() << " ";
    }


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

            case (2) :
            {
                ListNode* head = nullptr;
                addNode(head, 1);
                addNode(head, 2);
                addNode(head, 3);
                addNode(head, 4);

                switchPairsOfPairs(head);

            }

            case (3):   //switch pairs of pairs using pointer changes
            {
                ListNode* head = nullptr;
                addNode(head, 1);
                addNode(head, 2);
                addNode(head, 3);
                addNode(head, 4);

                int i,j,k = 0;
                ListNode* current = head;
                ListNode* current1 = nullptr;
                ListNode* current2 = nullptr;
                ListNode* current3 = nullptr;
                ListNode* current4 = nullptr;

                current = head;
                current1 = current;

                current = head;
                current = current->next;
                current2 = current;
                
                current = head;
                current = current->next;
                current = current->next;
                current3 = current;

                current = head;
                current = current->next;
                current = current->next;
                current = current->next;
                current4 = current;

                swapDataReference(current1, current3);
                swapDataReference(current2, current4);

                cout << current1->data << endl;
                cout << current2->data << endl;
                cout << current3->data << endl;
                cout << current4->data << endl;
            }
            
            case (4):
            {
                manageStore();
                
                

                
            } break;

            case (5): //add N
            {
                ListNode* n = nullptr;
                addNode(n, 1);
                addNode(n, 2);
                addNode(n, 3);
                addNode(n, 4);
                addNode(n, 5);
                addNode(n, 6);
                addNode(n, 7);

                int x = 500;
                addNTimes(n, x, 2);

                showNodes(n);
            }

            case (6):
            {
                queue <int> Q;
                Q.push(3);
                Q.push(5);
                Q.push(1);
                Q.push(6);
                Q.push(8);
                Q.push(11);
                Q.push(13);

                sortQ(Q);
            }


            default:
                break;
        }
    }

    

}
    

    
    

    
