//using dynamic memory allocation, we can store 2000 times more array spaces.
//that's a lot of additional space.

#include <iostream>
using namespace std;

#define log(x) cout << x
#define logline(x) cout << x << endl
#define endline cout << endl

void myswap_address(int* a, int* b) {
	int temp = *a;
	*a = (*b);
	*b = temp;
}

void passbyValue(int*& a) {
	log(a);
	a = new int;
	log(a);
}
void passbyReference(int* a) {
	cout << a << endl;
	a = new int;
	cout << a << endl;
}

void swapAddress(int*& a, int*& b) {
	int* temp = a;
	a = b;
	b = temp;
}

void swapbyreference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void incrementReference(int& value) {	//pass by reference.
	value++;
}
void incrementPointer(int* value) {	//pass by reference
	(*value)++;
}

void hello(int* a) {
	cout << "hello start" << endl;
	cout << "a before changing: " << a << endl;

	int k = 12;
	cout << "int k's address: " << &k << endl;

	a = &k;
	cout << "a after changing: " << a << endl;

	cout << "hello end" << endl;
}

void showArr_pointer( int arr[], int mysize ) {
	int mynum = 5;
	for (int i = 0; i < mysize; i++) {
		*(arr + i) = mynum;
		mynum += 5;
	}

	for (int i = 0; i < mysize; i++) {
		cout << *(arr + i) << endl;
	}
}



//MANGO--------------------
struct mango {
	int price = 0;
	string name = "";
	string color = "";
	float weight = 0;
};
void showmango(mango m) {
	cout << m.name << endl;
	cout << m.price << endl;
	cout << m.color << endl;
	cout << m.weight << endl;
}


//PATIENT-----------------
struct patient {
	string name = "";
	int age = 0;
	int weight = 0;
	string gender = "";
	string bloodgroup = "";
};

void showpatients(patient p[], int size) {
	
	for (int i = 0; i < size; i++)
	{
		cout << p[i].name << " ";
		cout << p[i].weight << " ";
		cout << endl;
	}
}


//RECTANGLE---------------
struct rectangle{
	int length = 0;
	int width = 0;
};
void setLenWid( rectangle r ) {
	r.length = 2;
	r.width = 3;
}
void getArea( rectangle r) {
	cout << (r.length) * (r.width) << endl;
}

struct page {
	string content = "";
	int pagenumber;
	page* nextpage = nullptr;
};

int main()
{
	int choice = 1000;

	while (choice != 0) {
		cout << "1: myswap_adress\n";
		cout << "2: adress1\n";
		cout << "3: aliasing\n";
		cout << "4: change addres without changing value\n";
		cout << "2: adress1\n";
		cout << "2: adress1\n";
		cout << "2: adress1\n";
		cout << "2: adress1\n";
		cout << "2: adress1\n";
		cout << "10: intro to structs\n";

		cin >> choice;
		switch (choice) {

			case 1:	//myswap
			{
				int a = 10;
				int b = 20;
				myswap_address(&a, &b);
				cout << a << " " << b << " main swap complete." << endl;

			}break;

			case 2:	//swap address
			{
				int a = 3;
				int* m = &a;

				int b = 5;
				int* n = &b;

				int& p = a;
				int& q = b;

				cout << "before swapping: " << endl;
				cout << a << ""; logline(&a);
				log(b) << " "; logline(&b);
				swapbyreference(a, b);
				cout << "after swapping: " << endl;
				log(a) << " "; logline(&a);
				log(b) << " "; logline(&b);

			}break;

			case 3:	//aliasing
			{
				int a = 10;
				int& ref = a;

				//now, anything you do to a, will also happen to a.
				ref = 2;

				cout << "Before increment a: " << a << endl;
				incrementReference(ref);
				cout << "After aliased increment, a: " << a << endl;
				incrementPointer(&a);
				cout << "After pointer referenced incerement, a: " << a << endl;


			}

			case 4:	//changing address of a variable without changing its value
			{
				int m = 45;
				int* x = &m;

				cout << "Address of m before changing: " << x << endl;

				hello(x);

				cout << "Address of m after changing: " << x << endl;
			}
			case 5:	//swap address 
			{
				int a = 65;
				int* m = &a;

				int b = 65;
				int* n = &b;

				cout << &a << endl;
				cout << &b << endl;
				swapAddress(m,n);
				cout << &a << endl;
				cout << &b << endl;
			}

			case 6:	//dynamic array
			{
				const int N = 5;
				int arr[N] = { 102, 103, 104, 105 };
				int* p = arr;	//points to first array's 1st element.

				for (int i = 0; i < N; i++)
				{
					cout << p << endl;
					cout << *p << endl;
					p = p + 1;
				}
			}
			case 7:	//show array using pointers
			{
				//init
				const int N = 10;
				int mynum = 10;

				//setup
				int* arr = new int(N);

				//call
				showArr_pointer(arr, N);
			}

			case 8: //WRONG way to iterate array using pointers
			{
				int arr[3]= { 1,2,3 };
				int* p = &( arr[0] );
				for (int i = 0; i < 3; i++)
				{
					cout << *(arr) << endl;
					//arr +1;
					//if you really have to do it this way, use an int * p = arr [0] instead.
					//Wrong.
					//This is trying to ASSIGN a different memory address VALUE to an existing memory location VALUE.
					//Can't do this in C++.
				}



			}

			case 9 : // pointer delete
			{
				int* a = new int(8);
				cout << a << endl;
				
				delete[] a; 

				a = new int[3]{ 1,2,3 };
				cout << a << endl;
			}

			case 10: //intro to structs
			{
				//float type was already defined by c++
				float x = 90;
				
				//with struct,
				//we defined mango
				//as a variable TYPE.
				mango m1;
				m1.price = 12;
				m1.name = "Himshagor";
				m1.color = "Green";
				m1.weight = 15;
				cout << m1.price << " " << m1.name << endl;
				showmango(m1);

				mango m2;
				m2.price = 10;
				m2.name = "Fojli";
				m2.color = "Green";
				m2.weight = 10;
				cout << m2.price << " " << m2.name << endl;

			}
			case 11: //patients
			{
				patient p1;
				p1.name = "motiur";
				p1.age = 123;
				p1.weight = 123;
				p1.gender = "male";
				p1.bloodgroup = "A+";

				patient p2;
				p2.name = "motiur";
				p2.age = 123;
				p2.weight = 123;
				p2.gender = "male";
				p2.bloodgroup = "A+";

				patient p[3];
				p[0].name = "";


				const int N = 30;
				for (int i = 0; i < N; i++)
				{
					cout << "Enter your name: ";
					cin >> p[i].name;

					cout << p[i].weight;
					cin >> p[i].weight;


				}		
			}

			case 12:	//heap vs stack
			{

				
				//from stack
				patient p1;
				p1.name = "motiur";
				p1.age = 123;
				p1.weight = 123;
				p1.gender = "male";
				p1.bloodgroup = "A+";
				//here you can use the dot notation.
				//DO NOT rely on autocorrect.
				patient sun[2];
				sun[0].name = "abc";
				sun[0].weight = "123";



				//from heap
				int* y = new int(34);
				patient* q = new patient();
				cout << q->name << " " << q->weight << endl;
				//REMEMBER TO USE -> when accessing var from
				//dynamically allocated heap memory.
				patient* patients = new patient[2];
				q[0].name = "abc";
				q[0].weight = 123;
				q[1].name = "abcd";
				q[1].weight = 131;
				q[2].name = "daed";
				q[2].weight = 231;

				int size = 3;

				showpatients(patients, 3);

				//in the case of arrays, dots are legal for
				//both allocation types, be it from stack or heap.

				

				//dereferencing a struct instance
				q->weight = "123";
				q->name = 125;
			}

			case 13: // static struct
			{
				page p1;
				p1.content = "Sample text on sample page";
				p1.pagenumber = 10;
			}

			case 14: // dynamic struct
			{
				page* p2 = new page;
				p2->content = "Different text from difference page.";

				delete p2;

			}

			case 15: // pointer to pointer
			{
				int* arr = new int[3]{1,12,31};
				int** array = new int* [3];
			}
			case 16: //iterating dynamic array
			{
				int* arr = new int[3]{ 1,12,31 };
				
				for (int i = 0; i < 3; i++)
				{
					cout << *(arr + i) << " ";
				}
			}

			case 17:
			{
				
			}
			

	}



}

















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
