//File Name: project2
//Author: Chaim Fishman
//ID: 208509349
//Project For: Intro to Computer Science hw13.2
//Description. this program will open a file (name enterd by user)
//read the amount of each digit that is in the file and save that into
//another file called frequencyDigits.txt and print it out onto the console.
#include <fstream>
#include <iostream>
using namespace std;
enum digit { ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
void digitCounter(ifstream& ifile, ofstream& ofile);
int main() {
	char file_name[20];
	char c;
	cout << "enter file name\n";
	cin >> file_name;
	ifstream infile;
	infile.open(file_name);
	if (infile.fail())
	{
		cout << "could not open file\n";
		return 1;
	}
	ofstream oufile("frequencyDigits.txt");
	//oufile.open("frequencyDigits.txt");
	if (oufile.fail())
	{
		cout << "could not open file1\n";
		return 1;
	}
	digitCounter(infile, oufile);
	infile.close();
	oufile.close();
	return 0;
}
void digitCounter(ifstream& ifile, ofstream& ofile)
{
	int zero = 0, one = 0, two = 0, three = 0, four = 0,
		five = 0, six = 0, seven = 0, eight = 0, nine = 0;
	char input;
	while (ifile >> input)
	{ 
		switch (input)
		{
		case ZERO: zero++;
			break;
		case ONE: one++;
			break;
		case TWO: two++;
			break;
		case THREE: three++;
			break;
		case FOUR: four++;
			break;
		case FIVE: five++;
			break;
		case SIX: six++;
			break;
		case SEVEN: seven++;
			break;
		case EIGHT: eight++;
			break;
		case NINE: nine++;
		default: break;
		}
	}
	cout << "digit frequency\n";
	ofile << "digit frequency\n";
	cout << 0 << '\t' << zero << endl;
	ofile << 0 << '\t' << zero << endl;
	cout << 1 << '\t' << one << endl;
	ofile << 1 << '\t' << one << endl;
	cout << 2 << '\t' << two << endl;
	ofile << 2 << '\t' << two << endl;
	cout << 3 << '\t' << three << endl;
	ofile << 3 << '\t' << three << endl;
	cout << 4 << '\t' << four << endl;
	ofile << 4 << '\t' << four << endl;
	cout << 5 << '\t' << five << endl;
	ofile << 5 << '\t' << five << endl;
	cout << 6 << '\t' << six << endl;
	ofile << 6 << '\t' << six << endl;
	cout << 7 << '\t' << seven << endl;
	ofile << 7 << '\t' << seven << endl;
	cout << 8 << '\t' << eight << endl;
	ofile << 8 << '\t' << eight << endl;
	cout << 9 << '\t' << nine << endl;
	ofile << 9 << '\t' << nine << endl;

}