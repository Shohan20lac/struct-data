// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void ageCount() {
    int age = 0;

    cout << "age:" << endl;
    cin >> age;

    if (age < 30)
        cout << "Young" << endl;
    else if (age < 60)
        cout << "Middle Aged" << endl;

    if (age < 100)
        cout << "Old people";
    else
        cout << "Very old People" << endl;
}

void ageCount1() {
    int age = 0;

    cout << "age:" << endl;
    cin >> age;

    if (age < 30)
        cout << "Young" << endl;
    else if (age < 60)
        cout << "Middle Aged" << endl;

    else if (age < 100)
        cout << "Old people";
    else
        cout << "Very old People" << endl;
}

void reverseNum( int x) {
    x = 456;

    while (x != 0) {
        cout << x % 10 << endl; //displays the last element of the int
        x = x / 10;
    }

}

int main()
{
    
    
    //where there's else, there is exclusive conditioning.
    



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
