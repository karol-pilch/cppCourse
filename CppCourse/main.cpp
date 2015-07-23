//
//  main.cpp
//  CppCourse
//
//  Created by Karol Pilch on 23/07/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//
//  Exercises for Chapter 23

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// FINALLY WORKING Try This #2!
void tt_2 () {
	// regex pattern;
	regex pattern;
	
	string pat;
	cout << "Enter pattern... \n";
	getline (cin,pat);
	try {
		cout << "Your pattern: \"" << pat << "\", size: " << pat.size() << endl;
		pattern = pat;
	}
	catch (regex_error) {
		cout << pat << " is not a valid regex.\n";
		exit(1);
	}
	
	cout << "Now enter lines...\n";
	
	int lineno = 0;
	for (string line; getline(cin,line);) {
		if (line == "") break;
		++lineno;
		smatch matches;
		cout << "Searching in \"" << line << "\".\n";
		bool found = regex_search(line, matches, pattern);
		cout << "Matches size: " << matches.size() << endl;
		if (found) {
			cout << setw(3) << lineno << ": " << line << endl;
			for (int i=0; i<matches.size(); ++i) {
				cout << "\tmatches[" << i << "]: " << matches[i] << endl;
			}
		}
		else
			cout << "No match.\n";
	}

}


int main(int argc, const char * argv[]) {
	tt_2();
	return 0;
}
