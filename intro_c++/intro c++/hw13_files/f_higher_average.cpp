//File Name: project1
//Author: Chaim Fishman
//ID: 208509349
//Project For: Intro to Computer Science hw13.1
//Description: This program will read 2 files, grades1.txt and grades2.txt
//and will output which file has the higher average 1 or 2...
#include <fstream>
#include <iostream>
using namespace std;
int main() {
	ifstream input_grades1, input_grades2;
	input_grades1.open("grades1.txt");
	//check if the first one was opened if not we should terminate right away without trying to open the second one
	if (!input_grades1)
	{
		cout << "could not open file:1\n";
		return 1;
	}
	//first file opened now lets try to open the second one.
	input_grades2.open("grades2.txt");
	if (!input_grades2)
	{
		cout << "could not open file:2\n";
		return 1;
	}
	int i = 0, j = 0, read;
	float sum1 = 0, sum2 = 0;
	//calculate the sum and the amount of values that are in grades1
	while (input_grades1 >> read)
	{
		sum1 += read;
		i++;
	}
	sum1 = sum1 / i;//sum1 will now be the average of grades1
	//calculate the sum and the amount of values that in grades 2
	while (input_grades2 >> read)
	{
		sum2 += read;
		j++;
	}
	sum2 = sum2 / j;//sum2 will be the average of the grades 2
	if (sum1 == sum2)
	{
		cout << "Average for both files are equal\n";
	}
	else 
	{
		cout << "highest average found in file ";
		(sum1 > sum2) ? cout << 1 : cout << 2;
	}
	input_grades1.close();
	input_grades2.close();
	return 0;
}
/*
highest average found in file 2*/