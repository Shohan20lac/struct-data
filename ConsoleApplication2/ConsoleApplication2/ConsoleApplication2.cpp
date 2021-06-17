// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void fibonacci(int limit) {
    cout << "Fibonacci sequence up to " << limit << ":" << endl;

    int previous = 0;
    int current = 1;

    cout << previous << endl;

    while (current < limit) {
        cout << current << endl;

        int temp = current;
        current = current + previous;
        previous = temp;
    }
}

int loopMysteryExam1(int i, int j) {
    while (i != 0 && j != 0) {
        i = i / j;
        j = (j - 1) / 2;
        
        cout << i << " " << j << " ";
    }
    cout << i << endl;
    return i + j;
}
void numberLoops1() {
    for (int i = 1; i <= 5; i++)
    {
        int n = i ;
        for (int j = 0; j < i; j++){
            cout << n;
        }   
        cout << endl;
    }
}

void numberLoops2(){
    int max_dots = 4;
    int max_rows = 5;
    int max_cols = 5;

    int dotCount;
    int digitCount;
    int digitValue;

    for (int rowNum = 0; rowNum < max_rows; rowNum++)    //this loop executes as many times as the number of dots
    {   
        //in row 0, dotNum = 4.     That's 4-0. That's max_dots(4) - rowNum(0). 
        //in row 1, dotCount = 3.   That's 4-1. That's max_dots(4) - rowNum(1).
        //in row 2, dotCount = 2.   That's 4-2. That's max_dots(4) - rowNum(2).

        dotCount = max_dots - rowNum;
        for (int i = 0; i < dotCount; i++){
            cout << ".";
        }   


        digitCount = max_cols - dotCount;
        digitValue = rowNum + 1;

        for (int i = 0; i < digitCount; i++){
            cout << digitValue;
        }
        cout << endl;

    }
}

void numberLoops3() {
    int max_rows = 5;
    int max_cols = 5;

    int gridX;
    int gridY;

    int numPos;
    int numValue;
    int dotPos;

    //in gridY = 0, numPos = 4. So, in this row, numPos = max_rows - gridY - 1.
    //in gridY = 1, numPos = 3  So, numPos = max_rows - gridY - 1.
    //in gridY = 2, numPos = 2  So, numPos = max_rows - gridY - 1.
    //in gridY = 3, numPos = 1  So, numPos = max_rows - gridY - 1.
    //in gridY = 4, numPos = 0  So, numPos = max_rows - gridY - 1.

    for (int gridY = 0; gridY < max_rows; gridY++)
    {
        numPos = max_rows - gridY - 1;
        numValue = gridY + 1;
        //cout << "We're at row" << gridY << ". numPos at this row is " << numPos << endl;

        
        for (int i = 0; i < max_cols; i++)
        {
            if (i == numPos)
                cout << numValue;
            else
                cout << ".";
        }
        cout << endl;
    }
}

void sentinelSum() {
    
}

int main()
{

    int choice = 1000;

    while (choice != 0) {
        cout << "\n==MAIN MENU==" << endl;
        cout << "1: Fibonacci Sequence Generator\n";
        cout << "2: Mystery Exam 1\n";  
        cout << "3: Number Loop 1\n";  
        cout << "4: Number Loops 2\n";  
        cout << "5: Number Loops 3\n";  
        cout << "6: Sentinel Sum\n";  
        cout << "Select exercise number: ";
        cin >> choice;

        switch (choice) {

            case 1: 
            { //fibonacci
                int limit;
                cout << "Enter limit for fibonacci series:";
                cin >> limit;
                fibonacci(limit);
                cout << "\nFunction completed successfully. Returning to main menu.\n\n";
            }break;
            
            case 2: 
            {//loopMysterExam1
                int i,j;
                cout << "Enter i: "; cin >> i;
                cout << "\nEnter j: "; cin >> j;
                int returnee = loopMysteryExam1(i, j);
                cout << "Return: " << returnee;
            }

            case 3:
            {//rough work
                numberLoops1();
            }

            case 4:
            {//rough work
                numberLoops2();
            }
            case 5:
            {//rough work
                numberLoops3();
            }
            case 6:
            {//rough work
                sentinelSum();
            }
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
