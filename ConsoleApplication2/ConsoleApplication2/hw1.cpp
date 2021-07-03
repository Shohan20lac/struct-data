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
    int sum=0;
    int input=0;
    
    while (input != -1) {
        cout << "Type a number: ";
        cin >> input;
        sum += input; 
    }
    cout << "Sum is " << sum;
}

void showArr(int arr[], int size)  {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showArr(string arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void banish( int a1[], int size1, int a2[], int size2) {
    
    cout << "Array1 before banishing:"; showArr(a1, size1); cout << endl;
    cout << "Array2 before banishing:"; showArr(a2, size2); cout << endl;

    for (int i = 0; i < size2; i++){

        for (int j = 0; j < size1; j++)
        {
            if (a2[i] == a1[j]) {   
                //duplicate found. initiate banish protocol.
                for (int k = j; k < size1; k++){
                    a1[k] = a1[k + 1];
                    cout << "a1" << (k + 1) << "] moved to a1[" << (k) << "]\n";
                }
                a1[ (size1 - 1) ] = 0;                
                j--;
            }
        }

    }


    cout << "Array1 after completion:"; showArr(a1, size1); cout << endl;
    cout << "Array2 after completion:"; showArr(a2, size2); cout << endl;

}

int getLength( int arr[]) {
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Entered array length: " << length<<endl;
    return length;
}

void collapsePairs( int a[], int size) {
    
    size -= (size%2);

    for (int i = 0; i < size; i+=2)
    {
        //get sum of pair
        int sum = 0;
        sum = a[i] + a[i+1];


        //put sum value in right location
        if (sum%2==0) { //put in even index
            a[i] = sum; 
            a[i+1] = 0;
        }
        else {
            a[i] = 0;
            a[i+1] = sum; 
        }
            
    }
}

double computeAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return double(sum) / size;
}

float getPercentEven(int arr[], int size) {
    float evencount = 0;
    for (int i = 0; i < size; i++)
    {
        if ( arr[i]!=NULL && arr[i] % 2 == 0 )
            evencount +=1;
    }
    cout << evencount << " even numbers found in this array.";
    if (evencount == 0) 
        return evencount;
    else
        return ((evencount / size) * 100);
}

void swap( int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int* mirror( int arr[], int size) {
    for (int i = 0; i < size/2; i++)
    {
        swap(arr[i], arr[(size - i)]);
    }    
    return arr;
}

/*
bool hasSubstring(int haystack[], int size1, int needle[], int size2) {
    //int haystack[]=   { 1, 2, 3, 4, 0, 0, 0, 3, 4, 6 };
    //int needle[]  =   { 3, 4, 5 };

    for (int i = 0; i < size1-size2; i++)
    {
        int j = 0;
        while (j < size2) {
            if (needle[j] == haystack[i + j]) { //element matched.
                std::cout << "\nmatch number " << j + 1 << " found.";
                j++;
            }
            else
                break;
        }
        if (j == size2) 
            return true;
    }
    return false;
}
*/

bool hasMirrorTwice(int haystack[], int size1, int needle[], int size2) {
    //int haystack[]=   { 1, 2, 5, 4, 3, 0, 0, 3, 4, 6 };
    //int needle[]  =   { 3, 4, 5 };
    int mirrorCount = 0;

    for (int i = 0; i < size1 - size2; i++)
    {
        cout << "\n\nChecking haystack index number: " << i ;

        int j = size2-1;
        int haystackOffset = 0;
        while (j >=0) {
            cout << "\nChecking needle index " << j << " with haystack index " << i + haystackOffset;
                    
            if (needle[j] == haystack[i + haystackOffset]) { //element matched.
                std::cout << "\nmatch number " << j + 1 << " found. ";
                cout << needle[j] << "=" << haystack[i + haystackOffset] << endl;
                j--;
                haystackOffset++;
            }
            else {
                break;
            }
        }
        if (j < 0)
            mirrorCount++;
    }
    if (mirrorCount > 1)
        return true;
    else
        return false;
}

int indexOf(int arr[], int length, int target) {
    bool found = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int longestSortedSequence(int a[], int length) {
    //init

    int count = 0;

    /*
    if (length==0)
        maxcount =0;
    else
        maxcount =1;
    */

    /*
    maxcount = (length==0) ? 0 : 1;
    */

    int maxcount = (length != 0);

    //sliding window approach
    int L = 0;
    int R = 0;

    for (; L < length - 1; L++) {
        R = L + 1;

        bool isNonDescending = (a[R] >= a[(R - 1)]);
        while (isNonDescending && R < length) {
            cout << "While loop entered";

            R++;
            count = R - L;

            cout << "\ncount = " << count;
            isNonDescending = (a[R] >= a[(R - 1)]);
        }

        if (count > maxcount)
            maxcount = count;


    }

    return maxcount;
}

int maxValue(int arr[], int length) {
    int maxval = arr[0];
    for (int i = 0; i < length; i++) {


        if (arr[i] > maxval) {
            maxval = arr[i];
        }
    }

    return maxval;
}

void mystery1( int a1[], int length1, int a2[], int length2) {
    for (int i = 0; i < length1; i++){
        a1[i] += a2[length2 - i - 1];
    }
}

void mystery2( int a[], int length) {
    for (int i = 1; i < length-1; i++) {
        a[i] = a[i - 1] - a[i] + a[i + 1];
    }
}

int numUnique( int arr[], int length) {
    int uValue = arr[0];
    int counter;
    if (uValue == 0 || uValue == NULL)
        counter = 0;
    else
        counter = 1;

    for (int i = 1; i < length; i++)
    {
        if (arr[i] == uValue)
            continue;
        else{
            uValue = arr[i];
            counter++;
        }
    }
    return counter;     
}
string makePalindrome(string a, int length) {
    int last = length - 1;
    int middle = length / 2;
    int mirror;

    for (int i = 0; i < middle; i++) {
        mirror = last - i;
        swap(a[i], a[mirror]);
    }
    return a;
}

void removePalindromes(string a[], int length) {

    cout << "\n Array before removing palindromes:"; showArr(a, length);

    //checking to see if a single word is a palindrome. let's start one word at a time.
    for (int j = 0; j < length; j++)
    {
        
        string word = a[j];
        cout << "\nChecking the word " << word <<"...";
        int wordlength = a[0].length();

        int last = wordlength - 1;
        int middle = wordlength / 2;
        int mirror;

        bool isPalindrome = false;
        bool isMirrorDuplicate = false;
        for (int i = 0; i < middle; i++) {
            mirror = last - i;
            if (word[i] == word[mirror])
                isMirrorDuplicate = true;
            else {
                isMirrorDuplicate = false;
                break;
            }

        }

        if (isMirrorDuplicate) {
            cout << "\nThe word " << a[j] << " is a palindrome. Setting it equal to null.";
            a[0].assign("");
        }
        else
            cout << "\nThe word " << a[j] << " is NOT a palindrome. Leaving it alone.";
    }
  
    cout << "\n Array after removing palindromes:"; showArr(a, length);
}

int secondIndexOf(int a[], int length, int target) {
    bool secondFound = false;
    bool firstFound = false;
    int foundIndex;


    for (int i = 0; i < length; i++) {
        if (firstFound && a[i] == target) {
            foundIndex = i;
            secondFound = true;
            break;
        }
        if (a[i] == target) {
            firstFound = true;
        }

    }

    if (secondFound == true) {
        return foundIndex;
    }
    else {
        return -1;
    }

}
void armstrongNumbers(int n) {
    // this is to find the minimum n digit number
    //int n=3;
    int min = 1;
    for (int i = 0; i < n - 1; i++)
    {
        min = min * 10;
        // cout << min << endl;
    }
    //cout << min<<endl;
    //this is to find the maximum n digit number
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        max = max * 10;
        // cout << max << endl;
    }
    //   max = max - 1;
      // cout << max; 


    for (int i = min; i < max; i++)
    {
        int temp;
        int r;
        int sum = 0;
        temp = i; //temp = 153; //storing i to avoid anomalous values
        int c = i; //storing i because value gets lost later on
        for (int k = 0; k < n; k++)
        {//this loop is to make sure all the digits raised to the power n and added
            //raising digit to the power N
            int toTheN = 1;
            r = c % 10; // r = 3; 
            for (int j = 0; j < n; j++)
            {// this loop is used to raise the power to n
                toTheN = toTheN * r;    //toTheN = 1rrr
            }

            //adding the raised digits
            sum = sum + (toTheN);

            //moving on to the next digit
            c = c / 10;
        }
        if (temp == sum)
            cout << temp << " ";
    }
void floydsTriangle(int k) {
    int num = 1;
    for (int row = 0; row < k; row++) {
        for (int col = 0; col < row + 1; col++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

int quadrant( int x, int y) {
    if (x == 0 || y == 0)
        return 0; 

    if (x > 0) {
        if (y > 0)
            return 1;
        else
            return 4;

    }
    if (x < 0) {
        if (y > 0)
            return 2;
        else
            return 3;
    }
}














//------------MAIN-----------------------------------------------------------------------------------//



int main()
{
    //main menu init
    int choice = 1000;

    //main menu frontend
    while (choice != 0) {
        cout << "\n\n==MAIN MENU==" << endl;
        cout << "1: Fibonacci Sequence Generator\n";
        cout << "2: Mystery Exam 1\n";
        cout << "3: Number Loop 1\n";
        cout << "4: Number Loops 2\n";
        cout << "5: Number Loops 3\n";
        cout << "6: Sentinel Sum\n";
        cout << "7: Banish Protocol\n";
        cout << "8: Collapse Pairs(incomplete)\n";
        cout << "9: Compute Average(incomplete)\n";
        cout << "10: Get Percent Even\n";
        cout << "11: Has Mirror Twice\n";
        cout << "12: IndexOf\n";
        cout << "13: Longest Sorted non-decreasing sequence\n";
        cout << "14: maxValue\n";
        cout << "15: Mystery1\n";
        cout << "16: Mystery2\n";
        cout << "17: Number of unique digits\n";
        cout << "18: Make Palindrome\n";
        cout << "19: Remove Palindrome\n";
        cout << "20: Second Index Of\n";
        cout << "21: Sorted\n";
        cout << "22: Armstrong Numbers\n";
        cout << "23: K-Floyd's Triangle\n";
        cout << "Select exercise number: ";
        cin >> choice;


        //main menu backend-------------------------------------------------------------
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
                int i, j;
                cout << "Enter i: "; cin >> i;
                cout << "\nEnter j: "; cin >> j;
                int returnee = loopMysteryExam1(i, j);
                cout << "Return: " << returnee;
            }
            case 3:
            {
                numberLoops1();
            }
            case 4:
            {
                numberLoops2();
            }
            case 5:
            {
                numberLoops3();
            }
            case 6:
            {//sentinel sum
                int sum = 0;
                int input = 0;



                while (input != -1) {
                    std::cout << "Type a number: ";
                    std::cin >> input;
                    if (input != -1)
                        sum = sum + input;
                    else
                        break;
                }
                cout << "Sum is " << sum;
            }
            case 7:
            {
                int a1[] = { 42,3,9,42,42,0,42,9,42,42,17,8,2222,4,9,0,1 };
                int a2[] = { 42,2222,9 };

                int size1 = sizeof(a1) / sizeof(a1[0]);
                int size2 = sizeof(a2) / sizeof(a2[0]);

                banish(
                    a1, size1,
                    a2, size2
                );
            }
            case 8:
            {
                int a[] = { 7,2,8,9,4,22,7,1,9,10 };
                int size_a = sizeof(a) / sizeof(a[0]);

                cout << "\nInitialized array before collapsing pairs: "; showArr(a, size_a);
                collapsePairs(a, size_a);
                cout << "\nArray after collapsing pairs: "; showArr(a, size_a);
            }
            case 9://computeAverage
            {
                int a[] = { 7,2,8,9,4,22,7,1,9,10 };
                int size_a = sizeof(a) / sizeof(a[0]);
                computeAverage(a, size_a);
            }
            case 10://percentageEven
            {
                int a[] = { 7,2,8,9,4,22,7,1,9,10 };
                int size_a = sizeof(a) / sizeof(a[0]);
                cout << "\nTaking array:"; showArr(a, size_a);
                cout << "\nPercentage of even numbers in this array: " << getPercentEven(a, size_a);
            }
            case 11://hasMirrorTwice
            {
                int haystack[] = { 1, 2, 5, 4, 3, 0, 0, 3, 4, 6 };
                int haystack_size = sizeof(haystack) / sizeof(haystack[0]);

                int needle[] = { 3, 4, 5 };
                int needle_size = sizeof(needle) / sizeof(needle[0]);


                //cout << "\nCheck to see if a1 contains all consecutive elements of a2 twice: ";
                
                cout << endl << boolalpha << hasMirrorTwice(haystack, haystack_size, needle, needle_size);
            }   break;
            case 12://index of
            {
                int a1[] = { 6, 1, 2, 1, 3, 1, 3, 2, 1, 5 };
                int size_a1 = sizeof(a1) / sizeof(a1[0]);
                cout << "\nInitialized array: "; showArr(a1, size_a1);

                int target;
                cout << "\nEnter target value:";
                cin >> target;

                cout << "Index of target value is: " << indexOf(a1, size_a1, target);

            }
            case 13: //longestSortedSequence
            {
                int a1[] = { 6, 1, 2, 1, 3, 1, 3, 2, 1, 5 };
                int size_a1 = sizeof(a1) / sizeof(a1[0]);
                cout << "\nInitialized array: "; showArr(a1, size_a1);
                int result = longestSortedSequence(a1, size_a1);
            }
            case 14: //maxValue
            {
                int a1[] = { 6, 1, 2, 1, 3, 1, 3, 2, 1, 5 };
                int size_a1 = sizeof(a1) / sizeof(a1[0]);

                cout << "Max value: " << maxValue(a1, size_a1);
                
            }
            case 15:    //mystery1
            {
                int a1[] = { 1,3,5,7,9 };
                int size_a1 = sizeof(a1) / sizeof(a1[0]);

                int a2[] = { 1,4,9,16,25 };
                int size_a2 = sizeof(a2) / sizeof(a2[0]);

                mystery1(a1, size_a1, a2, size_a2);

                showArr(a1, size_a1);

            }
            case 16:    //mystery2
            {
                int a1[] = { 42, 42 };
                int size_a1 = sizeof(a1) / sizeof(a1[0]);
                mystery2(a1, 2);
                showArr(a1, size_a1);

                int a2[] = { 6, 2, 4 };
                int size_a2 = sizeof(a2) / sizeof(a2[0]);
                mystery2(a2, 3);
                showArr(a2, size_a2);

                int a3[] = { 7, 7, 3, 8, 2 };
                int size_a3 = sizeof(a3) / sizeof(a3[0]);
                mystery2(a3, 5);
                showArr(a3, size_a3);

                int a4[] = { 4, 2, 3, 1, 2, 5 };
                int size_a4 = sizeof(a4) / sizeof(a4[0]);
                mystery2(a4, 6);
                showArr(a4, size_a4);

                int a5[] = { 6, 0, -1, 3, 5, 0, -3 };
                int size_a5 = sizeof(a5) / sizeof(a5[0]);
                mystery2(a5, 7);
                showArr(a5, size_a5);
            }

            case 17:    //numUnique
            {
                int a5[] = { 6, 0, -1, 3, 5, 0, -3 };
                int size_a5 = sizeof(a5) / sizeof(a5[0]);

                cout << "number of unique digits in this array: " << numUnique(a5, size_a5);
            }

            case 18:  //make palindrome
            {
                string input;
                cout << "\nEnter a string:";
                cin >> input;               
                
                cout <<"\nThe word " << input << "is " << input.length() << " characters long.";
                cout <<"Backwards, it is : " << makePalindrome(input, input.length());
            }

            case 19:    //remove palindromes
            {
                string a[] = { "madam", "raceCAR", "", "hi", "A", "Abba", "banana", "dog God",
                    "STOP otto POTS", "Madame", "C++", "LevEL", "staTS" };
                int size_a = sizeof(a) / sizeof(a[0]);

                removePalindromes(a, size_a);

            }
            case 20:    //secondIndex
            {
                int a[] = { 42, 7, -9, 14, 8, 39, 42, 8, 19, 0, 42 };
                cout << "Index of second occuring index of target value: " << secondIndexOf(a, 11, 42);

            }
            case 21:    //sorted
            {
                //too easy.
            }
            case 22:    //armstrong numbers
            {
                int n;
                cout << "Enter n for generating armstrong numbers: ";
                cin >> n;

                armstrongNumbers(n);
            }
            case 23:    //k-floyd's triangle
            {
                int k;
                cout << "Enter k: ";
                cin >> k;

                floydsTriangle(k);
            }
            case 24:    //Quadrant
            {
                cout << "\nEnter x: ";
                int x; cin >> x; 

                cout << "\nEnter y: ";
                int y; cin >> y;

                cout << quadrant(x, y);

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
