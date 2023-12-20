//File Name: azby_crypt.cpp
//Author: Chaim Fishman
//ID: 208509349
//Project For: HW 10.1 for Intro to Computer Science course.
//Description: This program will recieve a string up to 80 characters
//long and encrypt it using the abzy method. and read the string back 
//to the user.
#include <iostream>
#include <cstring>
using namespace std;
const int max_size = 81;//81 because hw calls for 80 and we need 1 for \0.

//Crypto will recieve a string and encrypt the letters.
void crypto(char* s);

//encrypt gets a letter and returns an encrypted letter
char encrypt(char& s);

//will get an input from user up to size 80 and store in given array
void input(char* s);

//out the array to the user
void output(char* s);

int main() {
	char st[max_size];
	input(st);//get input from user up to size 80.
	crypto(st);//encrypt the inputed data
	output(st);//output the string in array
	return 0;
}


void crypto(char* s)
{
	
	while (*s)//while the string did not terminate wit \0
	{
		if (*s >= 97 && *s <= 122)//if element in array is a lowercase letter
		{
			*s = encrypt(*s);//encrypt the letter
		}
		s++;//look at next element.
	}
}


char encrypt(char& s)
{
	return (97 + (122 - (int)s));//return an encrypted letter.
}


void input(char* s)
{
	cout << "Enter a string:\n";
	cin.getline(s, 80);//read in innput up to 80 char
}

void output(char* s)
{
	cout << "After crypto:\n";
	cout << s << endl;//will cout the entire string up ot \0
}

/*
Enter a string:
azby&&&&???osnvus12AAA
After crypto:
zayb&&&&???lhmefh12AAA
Enter a string:
000000000
After crypto:
000000000
Enter a string:
sdkjflaksdjfl;sadjflsdjflkdsjlfsdjfjsfjsdlfjlsdjflkdsjflsdjflksjflsdjflksdjfdsjflkdsjflks       asjdflsjfj   asdljflsdjfl
After crypto:
hwpquozphwquo;hzwquohwquopwhqouhwquqhuqhwouqohwquopwhquohwquophquohwquophwquwhq 

will read the first 80 characters and ignore the rest.
*/