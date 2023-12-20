//File Name: lexgraphical_order.cpp
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Description: This program will have user enter 10 words with 
//5 letters each. A function will arrange them in 
//lexi-graphical order and read them back to the user.
//Created: 12/3/2020
//Last modified: 12/5/2020
#include <iostream>
using namespace std;
const int word_length = 5;
void lexi_sort(char arr[][word_length], int size);//arrange in lexigraphical order words of size 5
//Precondition: takes in an array with words sized word length and the amount of words
//post: the array that was enterd was sorted to be in lexi-graphical oreder.
void swap_word(char arr[][word_length], int row, int row2);
//Precondition: takes in a 2d array and two rows(words that should be changed)
//Post-condition: swapped the two words that were requested to be swapped
void user_input(char arr[][word_length], int size);
//Precondition: takes in a 2d array and size(how many words).
//post condition: will request from user to enter (size) words.
void output(char arr[][word_length], int size);
//Precondition: takes in a 2d array and size
//postconditon: the words of the array were read out to the user
int main() {
	const int size = 10;
	char ten_words[size][5];
	user_input(ten_words, size);
	lexi_sort(ten_words, size);
	cout << "after sorting:\n";
	output(ten_words, size);
	return 0;
}
void user_input(char arr[][word_length], int size) {
	cout << "enter " << size <<  " words:\n";
	for(int i = 0; i < size; i++)//start new row
		for(int j = 0; j < word_length; j++)//enter words to fit into column
		{
			cin >> arr[i][j];
		}
	return;
}
void lexi_sort(char arr[][word_length], int size) {
//bubble sort the all the words
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {//Each time i was incremetnted we had  
//placed the largest word left in the last possible j.
			int letter = 0;
//if the first, second or third letter are equal we want to keep looking to see if the word needs to be swapped.
			while (arr[j][letter] == arr[j+1][letter] && letter < word_length)
				letter++;
			if (arr[j][letter] > arr[j + 1][letter])
				swap_word(arr, j, j + 1);
		}
	}
}

void swap_word(char arr[][word_length], int row, int row2) {
	char temp[word_length];
	for (int i = 0; i < word_length; i++)//save word
		temp[i] = arr[row2][i];
	for (int i = 0; i < word_length; i++)//ovewrite that was previously saved
		arr[row2][i] = arr[row][i];
	for (int i = 0; i < word_length; i++)//write saved word into copied word
		arr[row][i] = temp[i];
}
void output(char arr[][word_length], int size) {
	for (int i = 0; i < size; i++)//start new row
	{
		for (int j = 0; j < word_length; j++)//enter words to fit into column
		{
			cout << arr[i][j];
		}
		cout << ' ';
	}
	cout << endl;
	return;
}
/*
enter 10 words:
house apple teach array teach books point float apply begin
after sorting:
apple apply array begin books float house point teach teach

enter 10 words:
 champ jelly print sheet throw beach helps break phone sheep
after sorting:
beach break champ helps jelly phone print sheep sheet throw

Note: A flag can be set to see if the prgram is sorted already 
I chose not to do this for this program.*/