// Problem 1.cpp : Defines the entry point for the console application.
// Test of Josmar Augusto Fonseca Barbosa

#include "stdafx.h"


#include <iostream>
#include <fstream>

using namespace std;

string hours[12] = { "zero", "one","two", "tree",
                          "four","five","six","seven",
	                      "eight","nine","ten","eleven"};

string mins[30] = { "zero", "one","two", "tree","four","five","six","seven","eight","nine","ten",
        "eleven", "twelve", "thirteen","fourteen", "fiveteen","sixteen","seventeen","eighteen","nineteen","twenty",
	    "twenty one","twenty two","twenty three","twenty four", "twenty five",
	    "twenty six", "twenty seven","twenty eight","twenty nine"};

// Complete the timeInWords function below.
string timeInWords(int h, int m) {

	string sreturn = "";

	if (m == 0) sreturn = hours[h] + " o'clock";
	else if (m == 30) sreturn = "half past " + hours[h];
	else if (m == 15)  sreturn = "quarter past " + hours[h];
	else if (m == 45) {		
		string nextHour = (h < 11) ? hours[h + 1] : " zero";		
		sreturn = "quarter to " + nextHour;
	}
	else {
		if (m > 30) {
			string nextHour = (h < 11) ? hours[h + 1] : " zero";
			sreturn = mins[m-30] + " to " + nextHour;
		}
		else {

			sreturn = mins[m] + " past " + hours[h];
		}

	}

	return "then o'clock!";
}

bool inRangeHours(int hour)
{
	return  ((hour > -1) && (hour <12));
}

bool inRangeMinutes( unsigned min)
{
	return  ((min > -1) && (min < 60));
}

int main()
{
	ofstream fout("OUTPUT1.TXT");

	int h;
	cin >> h;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = timeInWords(h, m);

	fout << result.c_str() << "\n";

	fout.close();

	return 0;
}


