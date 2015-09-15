//
//  Exercise03.cpp
//  CppCourse
//
//  Created by Web Developer on 15/09/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//
// Exercise: "Write a program that finds dates in a text file. Write them in format:
// <line number>: <line>

#include "Exercise03.h"
#include "std_lib_facilities.h"

// Returns true if date was found in a line
// TODO: Write this function.
bool find_date (const string& line) {
    return line == "";
}

void ex3() {
    cout << "Exercise 3:\n";
    
    string filename ("Test_files/dates.txt");
    ifstream dates_file (filename);

    if (dates_file) {
        int line_no (0);
        string line;
        while (getline(dates_file, line)) {
            if (find_date(line))
                cout << setw(5) << line_no << ": " << line << endl;
            line_no++;
        }
        cout << "File read complete. " << line_no << " lines read from file \"" << filename << "\".\n";
    }
}