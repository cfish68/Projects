//File Name: reverse_words.cpp
//Author: Chaim Fishman
//ID: 208509349
//Created For: hw10.2 for Intro to Computer Science.
//Description: This program will recieve a string of up
//to 80 elements long, from the user and reverse the
//words within the string "that" will become "taht." 
//(preserve the spaces) and read it back to the user.
#include <iostream>
#include <cstring>
using namespace std;
void reverse(char* s);
char* fBegining(char* s);
char* fEnd(char* s);
void swap(char* b, char* e);
int main() {
	char sentence[80];
	cout << "enter a string: " << endl;
	cin.getline(sentence, 80);
	reverse(sentence);
	cout << "After reverse:\n";
	cout << sentence << endl;

}
char* fBegining(char* s)
{
	//find the begining
	while (*s == ' ')
		s++;
	return s;

}
char* fEnd(char* s)
{
	//find the last char of given sequence.
	while (*s != ' ' && *s != '\0')
		s++;
	return s;
}
void reverse(char* s)
{
	while (*s!='\0')
	{
		char* begining = fBegining(s);
		char* end = fEnd(begining);
		s = end;
		while (begining < end-1)
		{
			swap(begining++, (end--)-1);
		}
	}
}
void swap(char* b, char* e)
{
	char temp = *b;
	*b = *e;
	*e = temp;
}
/*
enter a string:
this is a silly sentence88
After reverse:
siht si a yllis 88ecnetnes

no input
enter a string:

After reverse:


enter a string:
my name     is a   silly    sen  t ence
After reverse:
ym eman     si a   yllis    nes  t ecne
*/