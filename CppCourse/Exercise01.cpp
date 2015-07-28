//
//  Exercise01.cpp
//  CppCourse
//
//  Created by Karol Pilch on 28/07/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//

#include "Exercise01.h"
#include "Mail_file.h"
#include "std_lib_facilities.h"

// TODO here: Locate the file properly...
// Testing mail file class
void ex_01() {
	// Check if it works...
	string test_file_name = "Test_files/my_mail.txt";
	Mail_file test_file(test_file_name);
	cout << "Read " << test_file.lines.size() << " lines in " << test_file.msgs.size() << " messages.\n";
}