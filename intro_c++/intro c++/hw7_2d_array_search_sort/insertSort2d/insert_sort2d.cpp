//File Name: inser_sort2d.cpp
//For: HW #7 q#3
//Author: Chaim Fishman
//ID: 208509349
//Email: csfwny@gmail.com
//Description: this program will have a 2 dimensional array with 10 rows and 10 columns
//the user will input 100 elemnts. and the program will print them out as a table.
//the program will then use insert sort to sort rows and column together, though it will not sort 
//all the columns of given rows. It will sort 1 less then the coulumn number. 
//once it's done sorting this part it will then start from the first column again and 
//will sort all rows(except for last one) but each row it will start the line from one
//more column then the last one(meaning sort one less coulumn each row.) Finally
//the program will read out the sorted 2d array as a table to the user.
//Created: 12/1/2020
#include <iostream>
using namespace std;
const int max_num = 10;
void input_array(int arr[][max_num], int size);
void output_array(int arr[][max_num], int size);
void ins_sort_bottom(int arr[][max_num], int size);
void ins_sort_top(int arr[][max_num], int size);
void swap(int& i, int& j);
int main() {
	int input_output[max_num][max_num];//set 2d array to be 10*10
	input_array(input_output, max_num);//get input from user to fill up 100 spaces in array
	cout << "before sorted:\n";
	output_array(input_output, max_num);//out put users input in 10*10 table
	ins_sort_bottom(input_output,  max_num);//sort the bottom half of array
	ins_sort_top(input_output, max_num);//sort the top half of array
	cout << "sorted matrix:\n";
	output_array(input_output, max_num);//output the sorted array
	return 0;
}
void input_array(int arr[][max_num], int size)
{
	cout << "enter the values:\n";
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] < 0)
			{
				cout << "ERROR\n";
				i = -1;//i will immidiately be incrementd to be 0 so we can start over
				break;
			}
		}
}
void output_array(int arr[][max_num], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void ins_sort_bottom(int arr[][max_num], int size)
{
	for (int i = 0; i < size; i++)//iterate through rows
	{
		for (int j = 0; j < i; j++)//iterate through columns
		{
			for (int column = j, row = i; row > 0; column--)//insert sort bottom triangle
			{
				if (column == 0)//if we finished compring column we need to compare to last column
				{
					if (arr[row][column] < arr[row - 1][row - 2])
					{
						swap(arr[row][column], arr[row - 1][row - 2]);
						row--;
						column = row;//column will be imidiately decremented to start at apprpriate spot on triangle
					}//if (arr[row][column] < arr[row - 1][row - 2])
					else break;//last number was smaller
				}//if (column == 0)
				else if (arr[row][column] < arr[row][column - 1])
				{
					swap(arr[row][column], arr[row][column - 1]);
				}//else if (arr[row][column] < arr[row][column - 1])
				else break;//lsat number was smaller
			}//for (int column = j, int row = i; row > 0; column--)
		}//for (int j = 0; j < i; j++)
	}//for (int i = 1; i < size; i++)
}//end function
void swap(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}void ins_sort_top(int arr[][max_num], int size)
{
	for (int i = 0; i < size; i++)//iterate through rows
	{
		for (int j = i+1; j < size; j++)//iterate through columns
		{
			for (int column = j, row = i; row >= 0 ; column--)//insert sort top triangle
			{
				if (column == row+1)//if we finished compring column we need to compare to last column
				{
					if (arr[row][column] < arr[row - 1][size-1])
					{
						swap(arr[row][column], arr[row - 1][size-1]);
						row--;
						column = size;//column will be imidiately decremented to start at apprpriate spot on triangle
					}//if (arr[row][column] < arr[row - 1][row - 2])
					else break;//last number was smaller
				}//if (column == 0)
				else if (arr[row][column] < arr[row][column - 1])
				{
					swap(arr[row][column], arr[row][column - 1]);
				}//else if (arr[row][column] < arr[row][column - 1])
				else break;//lsat number was smaller
			}//for (int column = j, int row = i; row > 0; column--)
		}//for (int j = 0; j < i; j++)
	}//for (int i = 1; i < size; i++)
}//end function
/*program works beautifully!!
enter the values:
1 11 21 31 41 51 61 71 81 91 2 12 22 32 42 52 62 72 82 92 3 13 23 33 43 53 63 73 83 93 4 14 24 34 44 54 64 74 84 94 5 15 25 35 45 55 65 75 85 95 6 16 26 36 46 56 66 76 86 96 7 17 27 37 47 57 67 77 87 97 8 18 28 38 48 58 68 78 88 98 9 19 29 39 49 59 69 79 89 99 10 20 30 40 50 60 70 80 90 100
before sorted:
1 11 21 31 41 51 61 71 81 91
2 12 22 32 42 52 62 72 82 92
3 13 23 33 43 53 63 73 83 93
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
sorted matrix:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 4 23 63 64 65 66 71 72 73
5 6 7 34 74 75 76 77 81 82
8 9 10 13 45 83 84 85 86 87
14 15 16 17 18 56 88 91 92 93
19 20 24 25 26 27 67 94 95 96
28 29 30 35 36 37 38 78 97 98
39 40 46 47 48 49 50 57 89 99
58 59 60 68 69 70 79 80 90 100
enter the values:
1 11 21 31 41 51 61 71 81 91 2 12 22 32 42 52 62 72 82 92 3 13 23 33 43 53 63 73 83 93 4 14 24 34 44 54 64 74 84 94 5 15 25 35 45 55 65 75 85 95 6 16 26 36 46 56 66 76 86 96 7 17 27 37 47 57 67 77 87 97 8 18 28 38 48 58 68 78 88 98 9 19 29 39 49 59 69 79 89 99 10 20 30 40 50 60 70 -1 90 100
ERROR
1 11 21 31 41 51 61 71 81 91 2 12 22 32 42 52 62 72 82 92 3 13 23 33 43 53 63 73 83 93 4 14 24 34 44 54 64 74 84 94 5 15 25 35 45 55 65 75 85 95 6 16 26 36 46 56 66 76 86 96 7 17 27 37 47 57 67 77 87 97 8 18 28 38 48 58 68 78 88 98 9 19 29 39 49 59 69 79 89 99 10 20 30 40 50 60 70 80 90 100
before sorted:
90 100 1 11 21 31 41 51 61 71
81 91 2 12 22 32 42 52 62 72
82 92 3 13 23 33 43 53 63 73
83 93 4 14 24 34 44 54 64 74
84 94 5 15 25 35 45 55 65 75
85 95 6 16 26 36 46 56 66 76
86 96 7 17 27 37 47 57 67 77
87 97 8 18 28 38 48 58 68 78
88 98 9 19 29 39 49 59 69 79
89 99 10 20 30 40 50 60 70 80
sorted matrix:
90 1 2 11 12 13 21 22 23 24
4 91 31 32 33 34 35 41 42 43
5 6 3 44 45 46 51 52 53 54
7 8 9 14 55 56 57 61 62 63
10 15 16 17 25 64 65 66 67 68
18 19 20 26 27 36 71 72 73 74
28 29 30 37 38 39 47 75 76 77
40 48 49 50 59 60 70 58 78 79
81 82 83 84 85 86 87 88 69 100
89 92 93 94 95 96 97 98 99 80*/