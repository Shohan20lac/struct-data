#include <iostream>
#include <stack>
#include <string> 

using namespace std;

void showStack( stack <char> mystack ) {
	while (!mystack.empty()) {
		cout << mystack.top() << endl;
		mystack.pop();
	}
}

int checkBalance( string str ) {
	stack <char> mystack;
	int length = str.length();

	for (int i = 0; i < length; i++){
		mystack.push(str[i]);
		cout << "Loaded str["<<i<<"] to the stack" << endl;
	}
	cout << "String {" << str << "} pushed to the stack." << endl;
	cout << "Stack: " << endl;
	showStack(mystack);

	//one or no chars in string: balanced
	if (length <= 1)
		return -1;

	//





	return 0;
}

void push( char arr[], int sz, char ch, int &count ) {
	if (count >= sz) {
		cout << "Stack overflow!" << endl;
		return;
	}
	arr[count] = ch;
	count++;
}

char pop(char arr[], int sz, int &count) {
	if (count <= 0) {
		return ' ';
	}
	count = count - 1;
	return arr[count];
}

void enqueue( char arr[] , int sz, char ch , int &tail ) {
	if (tail > sz) {
		cout << "Queue overflow!" << endl;
		return;
	}
	arr[tail] = ch;
	cout << "enqueued " << arr[tail] << endl;
	tail++;
}

char dequeue(char arr[], int sz, int &head ) {
	head++;
	return arr[head-1];
}





struct myStack {
	int counter = 0;
	int size = 0;

	char* arr = nullptr;
	
	myStack(int s) {
		size = s;
		arr = new char[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = ' ';
		}
	}
};

void enlarge(myStack* s){
	s->size = (s->size * 2);

	char* newArr = new char(s->size);
	for (int i = 0; i < (s->size) ; ++i)
	{
		newArr[i] = ' ';

	}
	cout << "enlarged" << endl;
	for (int  i = 0;	i < (s->size / 2);	++i)
	{
		newArr[i] = s->arr[i];
	}
	s->arr = newArr;
}

void myPush(myStack* s, char ch) {
	if (s->counter >= s->size) {
		cout << "stack overflow! enlarging..." << endl;
		enlarge(s);
	}

	s->arr[s->counter] = ch;
	s->counter++;
}

char myPop(myStack* s) {
	s->counter--;
	return ( s-> arr[s->counter] );
}



// MAIN ======================================


int main()
{
	
	int choice = 1000;

	while (choice != 0) {
		cout << "\n\n\nSelect choice: " << endl;
		cin >> choice;

		switch (choice)
		{
			case(1):	
			{
				string str1 = "this is a string.";
				cout << checkBalance(str1);
			}
			break;

			case(2):	// basic stack with array
			{
				const int sz = 5; int count = 0;
				char arr[sz] = { ' ',' ',' ',' ',' ' };
				push(arr, sz, 'A', count);
				push(arr, sz, 'B', count);
				push(arr, sz, 'C', count);
				push(arr, sz, 'D', count);
				cout << pop(arr, sz, count) << endl;

			}
			break;

			case (3):	//basis queue with array
			{
				int head = 0;
				int tail = 0;

				const int sz = 5;
				char arr[sz] = { ' ',' ',' ',' ',' ' };
				enqueue(arr, sz, 'A', tail);
				enqueue(arr, sz, 'B', tail);
				enqueue(arr, sz, 'C', tail);
				enqueue(arr, sz, 'D', tail);
				enqueue(arr, sz, 'E', tail);

				cout << dequeue(arr, sz, head);
				cout << dequeue(arr, sz, head);
				cout << dequeue(arr, sz, head);
				cout << dequeue(arr, sz, head);
				cout << dequeue(arr, sz, head);
			}break;

			case (4):	//myStack
			{
				
				myStack* s = new myStack(5);
				int counter = s->counter;

				myPush(s, 'A');
				myPush(s, 'B');
				myPush(s, 'C');
				myPush(s, 'D');
				myPush(s, 'E');
				myPush(s, 'F');



			}
		}
	}

	

}
