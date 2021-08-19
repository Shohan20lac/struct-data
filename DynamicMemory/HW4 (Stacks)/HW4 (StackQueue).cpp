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
	tail++;
}

char dequeue(char arr[], int sz, int &head ) {
	head++;
	return arr[head-1];
}

int main()
{
	
	int choice = 1000;

	while (choice != 0) {
		cout << "\nSelect choice: " << endl;
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
				enqueue(arr, sz, 'E', head);

				cout << arr[head]; 
				
			}


			default:
				break;
		}
	}

	

}
