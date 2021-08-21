#include <iostream>
#include <stack>
#include <string> 
#include <queue>

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
	bool roundopen, roundclose, curlyopen, curlyclose = false;

	int roundcount = 0;
	int curlycount = 0;

	//one or no chars in string: balanced
	if (length == 0)
		return -1;

	for (int i = 0; i < length; i++){

		roundopen = (str[i] == '(');
		roundclose = (str[i] == ')');

		
		curlyopen = (str[i] == '{');
		curlyclose = (str[i] == '}');

		cout << "i = " << i << endl;
		cout << curlyopen  << roundopen   << roundclose << curlyclose << endl;

		if (roundopen)
		{
			if (length == 1) {
				return length;
			}

			mystack.push(str[i]);
			cout << "round bracket opened at index " << i << endl;
			roundcount++;
			continue;
		}

		if (curlyopen) {
			if (length == 1) {
				return length;
			}

			mystack.push(str[i]);
			cout << "curly bracket opened at index " << i << endl;
			curlycount++;
			continue;
		}

		if (roundclose) {
			if (roundcount < 1
				||
				(mystack.top() != '(')
				) 
			{

				cout << "roudnclose imbalance found at index " << i << endl;
				return i;

				
			}
				
			else 
			{ 
				cout << "curly bracket closed at index" << i << endl;
				mystack.pop();
			}
			continue;
		}

		if (curlyclose) {

			cout << "curlycount= " << curlycount << endl;
			if ( 
				(curlycount < 1)  
				|| 
				(mystack.top() != '{') 
				) 
			{
				cout << "curlyclose imbalance found at index " << i << endl;
				return i;
				
			}
			else
			{
				cout << "curly bracket closed at index" << i << endl;
				mystack.pop();
			}
			continue;
		}


	}

	if (mystack.empty()) {
		cout << "Balance confirmed" << endl;
		return -1;
	}
	else {
		cout << "Unbalanced" << endl;
		return length;
	}

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

void showstack( stack <int> mystack ) {
	while (!mystack.empty()) {
		cout << mystack.top() << endl;
		mystack.pop();
	}
}

void collapse(stack <int>& mystack) {
	int size = mystack.size();
	int* arr = new int[size];

	int last;

	for (int i = 0; i < size; i++)
	{
		arr[i] = mystack.top();
		mystack.pop();
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "linebreak" << endl;

	for (int i = size - 1; i >= 0; i -= 2) {
		mystack.push(arr[i] + arr[i - 1]);
	}

}

bool isPalindrome(queue <int> q) {
	stack <int> mystack;
	int size = q.size();
	if (size <= 2)
		return true;

	bool sizeEven = (size % 2 == 0);

	if (!sizeEven)	//if odd number of elements
	{
		for (int i = 0; i < size / 2; i++)
		{
			mystack.push(q.front());
			q.pop();
		}

		//middle element. Do nothing and...
		q.pop();

		for (int i = ((size / 2) + 1); i < size; i++)
		{
			if (q.front() == mystack.top()) {
				q.pop();
				mystack.pop();
			}
			else {
				return false;
			}
		}
		//if came this far, then...
		return true;
	}

	else           //if even number of elements
	{

		for (int i = 0; i <= size / 2; i++) {
			mystack.push(q.front());
			q.pop();
		}

		for (int i = (size / 2) + 1; i < size; i++) {
			if (mystack.top() == q.front()) {
				mystack.pop();
				q.pop();
			}
		}
		//if came this far, then...
		return true;



	}



}

void collectionMystery6( stack <int> &s) {
	queue <int> q;
	stack <int> s2;

	while (!s.empty()) {
		if (s.top() % 2 == 0) {
			q.push( s.top() );
			s.pop();
		}
		else
		{
			s2.push(s.top());
			s.pop();
		}
	}

	while (!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	while (!s2.empty())
	{
		s.push(s2.top());
		s2.pop();
	}
	cout << "Output: " << endl;
	showstack(s);
}


void qStackPush ( queue <int> &q , int element ) {
	int newsize = q.size() + 1;
	int* arr = new int[newsize];

	for (int i = 0; i < q.size(); i++){
		arr[i] = q.front();
		q.pop();
	}

	arr[q.size()] = element;

	for (int i = 0; i < newsize; i++){
		q.push(arr[i]);
	}

}

int qStackPop (queue <int> q) {
	queue <int> p = q;
	q.pop();
	return(p.back());
}

void reorder(queue <int>& q) {
	int size = q.size();
	if (size <= 1)
		return;

	stack <int> negstack;
	queue <int> posQ;

	while (!q.empty()) {

		if (q.front() < 0) {
			negstack.push(q.front());
			q.pop();
		}
		else {
			posQ.push(q.front());
			q.pop();
		}
	}

	while (!negstack.empty()) {
		//keep getting all elements from it
		q.push(negstack.top());
		negstack.pop();
	}

	while (!posQ.empty()) {
		q.push(posQ.front());
		posQ.pop();
	}


}

void shift ( stack <int> &mystack , int n ){    
    int m = mystack.size();
    if (m<=1)
        return;
    
    int diff = m-n;
    
    stack <int> unchangedStack;
    for (int i = 0; i< diff; i++){
        unchangedStack.push( mystack.top() );
        mystack.pop();
    }
    
    queue <int> shiftedQ;
    for ( int i=0; i<n; i++ ){
        shiftedQ.push ( mystack.top() );
        mystack.pop();
    }
    
    while (!unchangedStack.empty()){
        mystack.push ( unchangedStack.top() );
        unchangedStack.pop();
    }
    
    while (!shiftedQ.empty()){
        mystack.push ( shiftedQ.front() );
        shiftedQ.pop();
    }
}

void stutter ( queue <int> &q){
    queue <int> temp;
    while (!q.empty()){
        temp.push ( q.front() );
        q.pop();
    }
    
    while (!temp.empty()){
        q.push( temp.front() );
        q.push( temp.front() );
        temp.pop();
    }
    
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
				string str1 = "{{{{this is a string.}";
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

			}break;
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
			}break;

			case(5) :	//collapse 
			{
				stack <int> mystack;
				mystack.push(1);
				mystack.push(2);
				mystack.push(3);
				mystack.push(4);
				mystack.push(5);

				collapse(mystack);
			}break;
			case (6):	// isPalindrome
			{
				queue <int> q;
				q.push(1);
				q.push(2);
				q.push(3);
				q.push(2);
				q.push(1);

				cout << "Is palindrome? Ans:" << isPalindrome(q);

			}
			case (7):	// collectionMystery6
			{
				stack <int> mystack1;
				mystack1.push(1);
				mystack1.push(2);
				mystack1.push(3);
				mystack1.push(4);
				mystack1.push(5);
				mystack1.push(6);

				stack <int> mystack2;
				mystack2.push(43);
				mystack2.push(3);
				mystack2.push(12);
				mystack2.push(15);
				mystack2.push(9);
				mystack2.push(71);
				mystack2.push(88);

				collectionMystery6(mystack2);

				stack <int> mystack3;
				mystack3.push(65);
				mystack3.push(30);
				mystack3.push(10);
				mystack3.push(20);
				mystack3.push(45);
				mystack3.push(55);
				mystack3.push(6);
				mystack3.push(1);

				




			}
			case(8): // isPalindrome
			{
				queue <int> q;
				q.push(3);
				q.push(8);
				q.push(17);
				q.push(9);
				q.push(4);
				q.push(17);
				q.push(8);
				q.push(3);

				cout << "is palindrome: " << isPalindrome(q);
			}
			case(9):	//stack using queue
			{
				queue <int> q;
				q.push(30);
				q.push(10);
				q.push(50);
				q.push(20);
				q.push(40);
				q.push(60);

				qStackPush( q,80 );

				qStackPop( q );
			}
		}
	}

	
	return 0;
}
