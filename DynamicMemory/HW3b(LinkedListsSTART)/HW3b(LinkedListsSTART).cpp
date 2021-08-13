#include <iostream>
using namespace std;

struct ListNode {
    int data;         // value stored in each node
    ListNode* next= nullptr;   // pointer to next node in list (nullptr if none)

};

void addNode(ListNode* &head, int num) {
	if (head == nullptr) {							//if list is empty
		head = new ListNode();						//set the new listnode as head
		head->data = num;		
		cout << "Added node with val " << head->data << endl;
	}
		

	else {											//if list is not empty
		ListNode* current = head;					//make new traverse pointer
		while (current != nullptr) {			//while we havent reached the last page
			current = current->next;				//keep traversing
		}
		current = new ListNode();
		current->data = num;
		cout << "Added node with val " << current->data << endl;
	}
}

void showNodes(ListNode* head) {
	ListNode* current = head;
	if (head->next == nullptr) {
		cout << (current->data) << endl;
	}
	else {
		while (current->next != nullptr) {			//while we havent reached the last page
			cout << current->data << endl;
			current = current->next;				//keep traversing
			
		}
	}
	
}

bool isSorted(ListNode* &head) {
    if (head == nullptr)	//empty linked list
        return true;
	else {					//non-empty linked list
		int largest = head->data;
		cout << "\nLargest = " << largest << endl;
		ListNode* current = head;

		while (current != nullptr) {
			current = current->next;
		}

	}
}

void traverseBoth(ListNode* head1, ListNode* head2) {
	if (head1 == nullptr || head2 == nullptr)
	{
	}
	else {
		ListNode* current1 = head1;
		ListNode* current2 = head2;
	}
}

int main()
{
	ListNode* head = nullptr;
	addNode(head, 1);
	addNode(head, 2);
	addNode(head, 3);
	addNode(head, 4);
	addNode(head, 5);

	ListNode* current = head;
	cout << current->data;

	current = current->next;
	cout << current->data;
	




	cout << endl << endl;
	//showNodes(head1);

	ListNode* head2 = nullptr;
	addNode(head2, 6);
	addNode(head2, 7);
	addNode(head2, 8);
	addNode(head2, 9);
	addNode(head2, 10);
	showNodes(head2);








}

