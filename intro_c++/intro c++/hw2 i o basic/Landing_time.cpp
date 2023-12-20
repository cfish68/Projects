//File name: Landing_time.
//Author: Chaim Fishman
//ID:208509349
//Description: Program will ask for take off time,
//duration time and give back the landing time.
#include <iostream>
using namespace std;
int main()
{
	int takeoff_hours, takeoff_minutes, takeoff_seconds;
	int duration_hours, duration_minutes, duration_seconds;
//if the time goes over alloted time we don't want to lose
//our time so we will use bool to check if we need to add
// and hour or a min.
	cout << "enter flight takeoff:\n";
	cin >> takeoff_hours >> takeoff_minutes >> takeoff_seconds;
	cout << endl;
	cout << "enter flight duration:\n";

//this is assuming the user won't enter numbers that will be greater then 
//24 hours 60 minutes and 60 seconds
//because then we'll be in trouble.
//to fix this 3 simple if statement will 
// (-)24hours,(-)60 minutes(-)60 seconds
	cin >> duration_hours >> duration_minutes >> duration_seconds;
//print out the hours and make sure you dont lose an hour if min
//went over 60 by adding one if you did
//print out the min and make sure you dind't lose a min if 
//seconds went over 60 by adding one if you did.
//hours will stay the same of course because it will
//just go back around to 12.
	cout << "\nflight arrival is:\n" <<
		((takeoff_hours + duration_hours) % 24) + (takeoff_minutes + duration_minutes) / 60 <<
		':' << (takeoff_minutes + duration_minutes) % 60 + (takeoff_seconds + duration_seconds) / 60 <<
		':' << (takeoff_seconds + duration_seconds) % 60 ;
	return 0;
}
/*program works
enter flight takeoff:
21 45 43

enter flight duration:
0 55 10

flight arrival is:
22:40:53*/