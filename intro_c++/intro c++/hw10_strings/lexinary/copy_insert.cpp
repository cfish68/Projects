/*#include <iostream>
#include <cstring>
using namespace std;
void copy_insert(char** from, char** to, int sizefrom, char* input)
{
	int i = 0, j = 0;
	for (; strcmp(*(from + i), input) < 1; i++)//copy everything belonging b4 input
	{
			*(to + j) = new char[sizeof(*(from + i))];
			*(to + j) = *from + i;
			j++;	
	}
	*(to + j) = new char[sizeof(input)];
	*(to + j) = input;
	j++;
	for (; i< sizefrom; i++)//copy everything belonging after input
	{
		*(to + j) = new char[sizeof(*(from + i))];
		*(to + j) = *from + i;
		j++;
	}
}*/