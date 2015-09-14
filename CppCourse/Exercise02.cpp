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
#include <string>

void ex2() {
    // Testing the Multimap with subjects
    
    // Start by reading the file
    string test_file_name = "Test_files/my_mail.txt";
    Mail_file test_file(test_file_name);
    
    // See what's in the map!
    cout << "Read following subjects in the map:\n";
    for (auto b = test_file.subjects.begin(); b != test_file.subjects.end(); b++) {
        cout << "Message subject: \"" << b->first << "\"\n";
    }
    
    // Now, to the exercise proper:
    cout << "Enter the subject line to look up...\n> ";
    string lookup_subject;
    getline(cin, lookup_subject);
    
    cout << "Looking for: \"" << lookup_subject << "\"\n";
    
    auto found_subjects = test_file.subjects.equal_range(lookup_subject);
    if (found_subjects.first != found_subjects.second) {
        cout << "Found messages:\n";
        int count = 1;
        for (auto b = found_subjects.first; b != found_subjects.second; ++b) {
            cout << "Message " << count++ << ":\n" << b->second << "*** END ***\n";
        }
    }
    else
        cout << "No messages found for this subject line.\n";
}