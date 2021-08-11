#include <iostream>
#include <string>
#include <sstream>

using namespace std;


struct Rectangle {
	int L = 0;
	int W = 0;

	int area = 0;

	Rectangle( int l, int w) {
		L = l;
		W = w;
		area = L * W;
	}
};

void setLW( Rectangle r [] , int size ) {	//randomly initiates a rectangle.
	for (int i = 0; i < size; i++)
	{
		r[i].L = rand() % 100;
		r[i].W = rand() % 100;
		cout << "Triangle # " << i << " random L and W set." << endl;
	}
}

void setArea(Rectangle r[], int size)
{
	for (int i = 0; i < size; i++)
	{
		r[i].area = r[i].L * r[i].W;
		cout << "Triangle # " << i << " area set." << endl;
	}
}

void showTriangles(Rectangle* r[], int size){
	for (int i = 0; i < size; i++)
	{
		cout << "Triangle # " << i << endl;
		cout << " area = " << r[i]->area << endl;

	}
}

void makeJuice() {
	string juice = "";
	cout << "juice name: ";

	getline(cin, juice);
	cout << juice;
}

string getString () {
	string str = "";
	getline(cin, str);
	return str;
}

int getInteger() {
	int i = 0;

	stringstream ss;
	string str = getString();
	ss << str;
	
	ss >> i;
	return i;
}

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
	int pagenum;
	page* nextpage = nullptr;

	page(int pn) {
		pagenum = pn;
	}
};



node* initNode(string name, int age) {
	node* head = new node(name, age);
	return head;
}

void traverseAll(node* thisnode) {
	int count = 0;
	while (thisnode->next != nullptr) {
		thisnode = thisnode->next;
		cout << "\nTraversed a node " << count++ << " times." << endl;
	}
		

}

void addNode( node* n, string name, int age) {
	node* newnode = new node(name, age);
	n->next = newnode;

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

			case 40:
			{
				string juicename = "";
				juicename = getString();
				cout << juicename;
			} break;


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



				cout << "\end" << endl;

			}break; 

			case 4:	//linked list START
			{
				page* ptr;
				int pagecount = 1;

				//first node
				page* p1 = new page(pagecount); pagecount++;
				page* head = p1;
				ptr = head;
				cout << "Page pumber " << ptr->pagenum << " created." << endl;

				//second node
				page* p2 = new page(pagecount); pagecount++;
				ptr = head;
				ptr->nextpage = p2;
				ptr = p2;
				cout << "Page pumber " << ptr->pagenum << " created." << endl;

				//third node
				page* p3 = new page(pagecount); pagecount++;
				ptr = head;
				ptr = ptr->nextpage;	//traverse once to get to second node
				ptr->nextpage = p3;		//from second node, assign p3 as the third node and link it.
				ptr = p3;
				cout << "Page pumber " << ptr->pagenum << " created." << endl;
				






				
				

			}break;











		}
	}




}