#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct node {
	string name;
	int age;
	node* next;
	node* previous;

	
	node(string n, int a) {
		name = n;
		age = a;
		next = nullptr;
		previous = nullptr;
		
	}
};

struct page {
	int content;
	page* nextpage = nullptr;

	page(int pn) {
		content = pn;
	}
};

void addNode( page* &head, int num) {
	if (head == nullptr)
		head = new page(num);

	else {
		page* current = head;
		while (current->nextpage != nullptr) {			//while we havent reached the last page
			current = current->nextpage;				//keep traversing
		}
		current->nextpage = new page(num);
	}
}

void showNodes( page* &head) {
	page* current = head;
	cout << (head->content) << endl;
	while (current->nextpage != nullptr) {			//while we havent reached the last page
		current = current->nextpage;				//keep traversing
		cout << current->content << endl;
	}
}

void editAtIndex(page* head, int i, int newcontent) {		//goes to the ith element in the linked list and changes the content to str
	page* current = head;
	while (i != 0) {									//until we haven't traversed the list i number of times
		current = current->nextpage;					//keep traversing
		i--;
	}
	current->content = newcontent;

}

void addNode2(page* &head, int mycontent) {
	for (int i = 0; i < 5; i++)
	{
		editAtIndex(head, i, i * mycontent);
	}
	cout << "\nNode(s) added." << endl;
}

void deleteNode(page* &head, int mycontent) {		//deletes ALL nodes that contain the value mycontent.
	
	if (head->content == mycontent) {
		page* trash = head;
		head = head->nextpage;
		cout << "Deleting page containing the value " << mycontent << endl;
		delete trash;
	}
	else {
		page* current = head;
		while (current->nextpage != nullptr) {			//while we havent reached the last page
			if ((current->nextpage->content) == mycontent) {
				page* trash = current->nextpage;
				current->nextpage = (current->nextpage->nextpage);
				cout << "Deleting page containing the value " << mycontent << endl;
				delete trash;
			}
			else {
				current = current->nextpage;
			}
		}
	}
		
}

void addFront(page* &head, int mycontent) {
	page* current = new page(mycontent);
	current->nextpage = head;
	head = current;
}

void removeFront(page*& head) {
	if (head == nullptr)
		cout << "Nothing to remove: List is already empty." << endl;

	page* trash = head;
	head = head->nextpage;
	cout << "Node with content " << trash->content << " removed from front." << endl;
	delete trash;
}

void removeBack(page* &head) {
	if (head == nullptr) {
		cout << "Nothing to remove: List is already empty." << endl;
		return;
	}
		
	page* current = head;
	while (current->nextpage != nullptr) {
		current = current->nextpage;
	}
	cout << "Deleting node form back with content " << (current->content) << endl;
	current = nullptr;
	delete current;
}

void removeBack2(page* &p) {
	//Remove the last element fo the list
	if (p->nextpage == nullptr) {
		page* trash = p;
		p = p->nextpage;
		delete p;
	}
	else {
		page* current = p;
		while (current->nextpage->nextpage != nullptr) {
			current = current->nextpage;
		}
		page* trash = current->nextpage;
		current->nextpage = current->nextpage->nextpage;
		delete trash;
	}
}


int main()
{
	int choice = 1000;

	//MAIN MENU 
	while (choice != 0) 
	{
		//FRONTEND
		cout << "\nEnter choice: ";
		cin >> choice;
		cin.ignore();

		//BACKEND
		switch (choice) {

			/*
			case 40:
			{
				string juicename = "";
				juicename = getString();
				cout << juicename;
			} break;
			*/

			case 1://helloworld
			{
				cout << "hello world!";
			}

			case 2: //dynamic 2D array
			{
				const int nStudents = 3;
				int* students[nStudents];

				for (int k = 0; k < nStudents; ++k)
				{
					int courseTaken = 0;
					
					cout << "enter number of courses taken:" << endl;
					cin >> courseTaken;
					int* nCourses = new int[courseTaken];

					for (int i = 0; i < courseTaken; ++i)
					{
						nCourses[i] = rand() % 100;
					}
					students[k] = nCourses;
				}

			}

			/*
			case 3 :	//setting up and displaying the dimensions of a rectangle
			{
				const int rectcount = 4;
				cout << "\n Number of rectangles? " << endl;

				
				Rectangle* rects[rectcount];

				for (int i = 0; i < rectcount; i++)
				{
					rects[i] = new Rectangle(rand() % 100, rand() % 100);
					cout << "\n New random rectangle created " << i << endl;
				}

				showTriangles(rects, rectcount);



				cout  << endl;

			}break; 
			*/

			case 4:	//linked list START
			{
				page* head = nullptr;
				
				addNode(head, 1);
				addNode(head, 2);
				addNode(head, 3);
				addNode(head, 3);
				addNode(head, 5);
				showNodes(head);
				
				removeFront(head); removeFront(head);

				removeBack2(head);
				cout << endl;
				showNodes(head);













				
				

			}break;











		}
	}




}