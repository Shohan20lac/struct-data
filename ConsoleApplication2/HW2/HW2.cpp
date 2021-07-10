// HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

int fib(int n) {
	if (n <= 1)
		return n;
	
	return fib(n - 2) + fib(n - 1);
}

void myswap( string s1, string s2) {
	string temp;
	temp = s1;
	s1 = s2;
	s2 = temp;

}

void flipLines(string filename) {
	string line;
	ifstream infile(filename);		//initiates an instance of the ifstream class, which opens the file named "filename.txt".

	int nlines = 0;
	int nwords = 0;
	string s1="";
	string s2="";

	if (!infile.is_open()) {
		cout << "File not found" << endl;
		return;
	}

	while (getline(infile, line)) {	//execute this every 
		nlines++;

		if (nlines % 2 != 0) {	//even index
			s1 = line;
		}

		if (nlines % 2 == 0) {	//odd index
			s2 = line;
		}

		if (s2 != "" && s1 != "") {
			cout << s2 << endl;
			s2 = "";
			cout << s1 << endl;
			s1 = "";
		}
		else if (s2 == "")
			cout << s2;
	}

	cout << "\nNumber of lines: " << nlines << endl;
}

void displayLines( string filename) {
	string line;
	ifstream ifile(filename);
	while (getline(ifile, line)) {
		cout << line << endl;
	}


	

}

void hoursWorked(string filename) {
	//input object
	string line;
	ifstream ifile(filename);

	//ID
	string id = "0";
	int id_L, id_R = 0; 
	bool idFound = false;
	
	//Name
	string name = "";
	int name_L, name_R = 0;
	bool nameFound = false;
	
	//Hours
	string hours_string = "";
	float hours_float = 0;
	int hours_L, hours_R = 0; bool hoursFound = false;

	
	while (getline(ifile, line)) {

		
		for (int i = 0; i < line.length(); i++)
		{
			//locating ID
			if (line[i] == ' ' && idFound == false) {//if space(" ") found and we are still looking for the id bounds
				id_R = i - 1;
				id_L = 0;
				idFound = true;
				name_L = i + 1;
				continue;
			}

			//locating name
			if (line[i] == ' ' && nameFound == false) {	//if space(" ") found and we are still looking for the name bounds
				name_R = i - 1;
				idFound = true;	
				continue;
			}
			
			//id and name located. So,
			break;
		}

		for (int i = name_R+2;		//start loop at the first hour char, which is two spaces after the final name char
			i < line.length();		//keep running loop all the way until the end of the line
			i++)
		{
			if (
				(line[i] != ' ') || (i == (line.length() - 1))) //if we still haven't found a space OR reached the end of the line
			{		
				hours_string += line[i];						//then store this string.
			}
			else {
				hours_float += stof(hours_string);	//convert hours into float and add it to a global sum.
				hours_string = "";					//reset the hours_string so we can use it again for the the next pass.
			}
			
		}

		
		//retrieving ID
		for (int i = 0; i <= id_R ; i++)
		{
			id += line[i];

		}
		
		//retrieving name
				//retrieving ID
		for (int i = name_L; i <= name_R; i++)
		{
			name += line[i];
		}

	}


}
void leetSpeak(string infilename, string outfilename) {
	string line;
	ifstream infile(infilename);
	ofstream outfile(outfilename, ofstream::out);
	int linelength;

	while (getline(infile, line)) {
		linelength = line.length();
		for (int i = 0; i < linelength; i++) {
			if (line[i] == 'o')
				line[i] = '0';
			if (line[i] == 'l')
				line[i] = '1';
			if (line[i] == 'e')
				line[i] = '3';
			if (line[i] == 'a')
				line[i] = '4';
			if (line[i] == 't')
				line[i] = '7';
			if (line[i] == 's'
				&&
				(line[i + 1] == ' ' || i == linelength)
				)
				line[i] = 'Z';
		}
		outfile << line << endl;
	}

}

void reverseLines() {

}

void recursionMystery1(int x, int y) {
	if (y <= 0) {
		cout << "0 ";
	}
	else if (x > y) {
		cout << x << " ";
		recursionMystery1(x - y, y);
	}
	else {
		recursionMystery1(x, y - x);
		cout << y << " ";
	}

}

void recursionMystery2(int n) {
	if (n <= 1) {
		cout << ": ";
	}
	else {
		cout << (n % 2) << " ";
		recursionMystery2(n / 2);
		cout << n << " ";
	}
}

void hanoi(int count, int start, int end) {
	cout << "";
}

float averageValueInFile(string infilename) {
	ifstream infile(infilename);
	string line;

	string num_string = " ";
	int num_L;
	int num_R;
	float num_float = 0;

	int numcount = 0;

	while (getline(infile, line)) { //do this everyline

		for (int i = 0; i < line.length(); i++) {

			if ((i == 0) && (line[i] != ' ')) {
				//first char of line
				num_L = line[i + 1];
				continue;
			}

			if ((line.length()>1) && (line[i] = ' ') && (line[i + 1] != ' '))

				//empty before line containing at least two chars
			{
				num_L = line[i + 1];
				continue;
			}


			if ((line[i] = ' ') && (line[i - 1] != ' '))
				//empty after line: get, convert, add
			{
				numcount++;
				num_R = line[i - 1];
				for (int j = num_L;
					j <= num_R;
					j++)
				{
					num_string += line[j];
				}
				cout << "Debug num_string: " << num_string << endl;
				//num_float += stof(num_string);
				num_string = " ";
				continue;
			}

		}

	}

	return (num_float / numcount);

}

void fileOut() {
	ifstream myFile("E:/dev/datastructPractice_1/ConsoleApplication2/HW2/word2.txt");
	//ifstream because we are inputting something from the file INto our system.

	if (!myFile.is_open()) {
		cout << "File not found" << endl;
		return;
	}

	string line = ""; int nlines = 0;

	while (getline(myFile, line)) {
		nlines += 1;
		cout << line << endl;
	}
	cout << "Number of lines: " << nlines << endl;

	
}

void fileOut2() {
	ifstream myFile("E:/dev/datastructPractice_1/ConsoleApplication2/HW2/word2.txt");
	//ifstream because we are inputting something from the file INto our system.

	if (!myFile.is_open()) {
		cout << "File not found" << endl;
		return;
	}

	string line = ""; int nlines = 0; int nWords=0;
	string word = "";


	int nwords = 0;
	for (string line, word; getline(myFile, line); )
	{
		cout << "\nLine " << nlines << endl;
		nlines++;

		stringstream iss(line);
		while (iss >> word)
		{
			cout << word << endl;
			bool alpha = true;

			for (char c : word)
				if (!isalpha(c)) alpha = false;

			if (alpha)
				nwords++;
		}
		std::cout << "Number of words on this line: " << nwords << endl;
	}

	cout << "\nNumber of lines: " << nlines << endl;
	cout << "\nNumber of words: " << nwords << endl;
}

int largestDigit(int n) {
	if (n == 0);
		return 0;

	int r_lastCall = largestDigit(n/10);
	return max (n%10, r_lastCall);
}

int getMax(int a, int b) {
	return max(a, b);
}

void vowelStats(string filename) {
	ifstream infile(filename);
	string line;

	int nlines = 0;
	int charcount = 0;
	int vowelcount = 0;
	char vowels[5] = { 'a','e','i','o','u' };


	while (getline(infile, line)) {
		nlines++;
		for (int i = 0; i < line.length(); i++)		//execute this for every char in the line string
		{
			charcount++;
			if (line[i] == ' ') {	//empty space. reduce count by 1.
				charcount--;

				for (int j = 0; j < 5; j++) {	//compare this char with each vowel
					if (line[i] == vowels[j]) {
						cout << "Vowel found!" << endl;
						vowelcount++;
						break;
					}
				}

			}
			cout << "Line "<< nlines << "has " << charcount << " chars and " << vowelcount << " vowels" << endl;
			charcount = 0; vowelcount = 0;
		}

	}
}

int parameterMystery1(int a, int b, int* c) {
	b++;
	a += *c;
	cout << b << " " << *c << " " << a << " " << c << endl;
	c = &a;
	return a - b;
}

int parameterMystery4(int& a, int* b, int c){
	a--;
	c = c * 2;
	cout << c << " " << a << " " << *b << endl;
	(*b)++;
	return a + c;
}

int parameterMystery9(int* b, int& c, int a) {
	(*b)++;
	c += 3;
	a += 5;
	cout << c << " " << a << " " << *b << " " << endl;
	return a;
}

string* parameterMystery2X(string& s1, string s2) {
	s1 += "1";
	s2 += "2";
	cout << s2 << " -- " << s1 << endl;
	s1 += "!!!";
	return &s1;
}

int mystery(int* a, int b, int& c) {
	c++;
	b--;
	*a = (c + b);
	cout << *a << " " << b << " " << c << endl;
	return b;
}

float fileSum(string filename) {
	float sum=0;
	int linenum = 0;
	string line;
	string word;

	ifstream infile(filename);

	while (getline(infile, line)) {

		linenum++;
		cout << "Reading line " << linenum << endl;

		stringstream ss(line);

		while (ss >> word) {
			float addition = stof(word);
			sum = sum + addition;
			cout << sum << endl;
		}
	}
	return sum;
}

void reverseLines( ifstream infile ) {
	
}

int main()
{

	//main menu frontend
	//main menu init
	int choice = 1000;

	//main menu frontend
	while (choice != 0) {
		cout << "\n\n==MAIN MENU==" << endl;
		cout << "1: FlipLInes\n";
		cout << "2: Hours Worked\n";
		cout << "3: Linestats (Correction pending)\n";
		cout << "4: Leetspeak\n";
		cout << "5: Recursion Mystery1\n";
		cout << "6: Recursion Mystery2\n";
		cout << "7: Recursion Mystery3\n";
		cout << "8: printBinary\n";
		cout << "9: reverse lines\n";
		cout << "10: reverse\n";
		cout << "11: printRange\n";
		cout << "12: parameterMystery1\n";
		cout << "13: parameterMystery4\n";
		cout << "14: parameterMystery9\n";
		cout << "15: parameterMystery9\n";
		cout << "16: hanoi\n";
		cout << "17: average value in file\n";
		cout << "18: file demo\n";
		cout << "19: word getter\n";
		cout << "19: file out\n";
		cout << "20: vowel stats\n";
		cout << "21: parameter mystery 2X\n";
		cout << "22: parameter mystery 12\n";
		cout << "26: filesum\n";
		cout << "Choose an option: ";
		cin >> choice;

		switch (choice)
		{
		default:
			break;
		case 1:
		{
			string filename = "fruits.txt";
			flipLines(filename);

			//read from a textfile
			//need an object from the ifstream class.

		}break;
		case 2:
		{
			string filename = "hours.txt";
			hoursWorked(filename);
		}
		case 3:
		{

		}
		case 4:
		{
			string infilename = "word.txt";
			string outfilename = "word2.txt";

			leetSpeak(infilename, outfilename);

		}
		case 5:
		{
			int x, y;
			cout << "Enter x:" << endl;
			cin >> x;
			cout << "Enter y:" << endl;
			cin >> y;

			recursionMystery1(x, y);
		}
		case 6:
		{
			int n;
			cout << "Enter n:" << endl;
			cin >> n;
			recursionMystery2(n);
		}

		case 7:
		{

		}
		case 8:
		{

		}
		case 9:	//reverseLines
		{

		}
		case 10:
		{

		}
		case 11:
		{

		}
		case 12:	//parameterMystery1
		{
			int a = 4; 
			int b = 8;
			int c = -3;
			int d;

			d = parameterMystery1(a,b,&c);
			parameterMystery1(c, d, &b);
			parameterMystery1(b, a, &d);
			cout << a << " " << b << " " << c << " " << d << endl;
			
			return 0;
		}
		case 13:	//parameterMystery4
		{
			int a = 2;
			int b = 5;
			int c = -3;
			int d;

			parameterMystery4(a, &b, c);
			d = parameterMystery4(c, &a, b);
			parameterMystery4(b, &d, a);

			cout << a << " " << b << " " << c << " " << d << endl;
			return 0;
		}
		case 14:
		{

		}
		case 15:	//parameterMystery9
		{
			int a = 10;
			int b = 200;
			int c = 3000;

			parameterMystery9(&a, b, c);
			int d = parameterMystery9(&b, c, a);
			cout << a << " " << b << " " << c << " " << d << endl;
			return 0;
		}
		case 16: //hanoi
		{
			hanoi(3, 1, 3);
		}
		case 17:
		{
			averageValueInFile("averagevalueinfile.txt");
		}
		case 18: //fileread
		{
			//read from text. Count number of lines, number of words in each line.
			//display each line.

		}
		case 19: //fileOut 
		{
			cout << endl;
			fileOut2();

		}
		case 20: //vowelstats
		{
			vowelStats("vowelStats.txt");
		}
		case 21:
		{
			string s1 = "hi";
			string s2 = "bye";
			string s3 = "yo";

			string* s4 = new string(s3);
			string* s5 = nullptr;

			parameterMystery2X(s1, s3);
			s5 = parameterMystery2X(*s4, s2);
			parameterMystery2X(s2, *s5);

			cout << s1 << " " << s2 << " " << s3 << endl;
			cout << s4 << " " << *s4 << " " << s5 << " " <<*s5 << endl;

		}
		case 22:
		{

		}
		case 23:
		{
			int a = 1;
			int b = 30;
			int c = 500;
			int* d = new int;

			*d = a;
			int* e = &b;

			mystery(d, c, b);
			b = mystery(&c, a, *e);

			cout << a << " " << b << " " << c << " " << d << " " << e << endl;
			cout << &a << " " << &b << " " << &c << " " << *d << " " << *e << endl;
		
			return 0;
		}
		
		case 26:	//fileSum
		{
			cout << fileSum("integers.txt");
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
