
#include <iostream>
using namespace std;

struct page {
	int content;
	page* nextpage = nullptr;

	page(int pn) {
		content = pn;
	}
};

void push(page*& top, int num) { 
	if (top == nullptr)
		top = new page(num);

	else {
		page* current = top;
		while (current->nextpage != nullptr) {			//while we havent reached the last page
			current = current->nextpage;				//keep traversing
		}
		current->nextpage = new page(num);
	}
}

void pop(page*& top) {

	page* current = top;
	while (current->nextpage != nullptr) {
		current = current->nextpage;
	}
	cout << "Deleting node form back with content " << (current->content) << endl;
	current = nullptr;
	delete current;
}

int main()
{
	page* top = nullptr;
	push(top, 100);
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
