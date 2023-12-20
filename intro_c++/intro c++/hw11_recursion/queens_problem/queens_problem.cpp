//File Name: queens_problem.cpp
//Author: Chaim Fishman 
//ID: 208509349
//project: Intro to Computer Science hw11.5 optional hw problem
//Description: this program will take a number and tell 
//the user if in n squared chess board you could fit n queens
//and perhaps if we are lucky it will also print out the chess board.
#include <iostream>
using namespace std;
//find a spot for queen on column, find for next column if 
//recursion gets stuck before it reaches will return back false to last call.
//last call will try again..untill it can't try anymore 
//and return false and keep doing that until it test all possible 
//placements and if its still false it is impossible
//inroder to be able to print the chessboard after
//placements were found function will need to input
//queen into every spot that it tries and remove it if it fails.
bool n_queens(int* chessboard, int n, int placement)
{
	
	if(placement < n)
		n_queens(chessboard, n, placement-1);
}
//find where in the column queen can be placed if at any point
int queen_placement(int* chessboard, int n, int placement)


int main()
{

	return 0;
}