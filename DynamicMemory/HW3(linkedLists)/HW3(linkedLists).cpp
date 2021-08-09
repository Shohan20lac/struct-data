#include <iostream>
#include <string>
using namespace std;

struct page {
	int pageNum;
	string content;
	page* nextpage;
};


int main()
{
	int choice = 1000;

	while (choice != 0) 
	{
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice) {
			case 1://helloworld
			{
				cout << "hello world!";
			}

			case 2: //dynamic 2D array
			{
				int coursecount = 0; cin >> coursecount;
				int* s1 = new int[3]{ 1,2,3 };

				for (int i = 0; i < coursecount; i++)
				{
					s1[i] = rand()
				}
				
				int* b = new int[2]{ 4,6 };
				int* c = new int[4]{ 7,8,9, 10 };
				int x[3] = { 3,2,4 };

				int* students[3];
				students[0] = a;
				students[1] = b;
				students[2] = c;


				int* row = a;

				for (int k = 0; k < 3; k++)
				{
					for (int i = 0; i < x[k]; i++)
					{
						cout << *(students[k]++) << " ";
					}
				}
			}

			case 3 :
			{

			}











		}
	}




}