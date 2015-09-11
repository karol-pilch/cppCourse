//
//  Exercise02.cpp
//  CppCourse
//
//  Created by Web Developer on 10/09/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//

#include "Exercise02.h"
#include "Mail_file.h"
#include "std_lib_facilities.h"     // You bastard!

void ex2() {
    // Testing the Multimap with subjects
    
    // Start by reading the file
    string test_file_name = "Test_files/my_mail.txt";
    Mail_file test_file(test_file_name);
    
    // See what's in the map!
    cout << "Read following subjects in the map:\n";
    for (auto b = test_file.subjects.begin(); b != test_file.subjects.end(); b++) {
        cout << "Subject: " << b->first << endl;
    }
}