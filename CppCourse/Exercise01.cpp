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

// Testing mail file class
void ex_01() {
	// Check if it works...
	string test_file_name = "Test_files/my_mail.txt";
	
	Mail_file test_file(test_file_name);
	cout << "Read " << test_file.lines.size() << " lines in " << test_file.msgs.size() << " messages.\n";
	for (Mess_iter b = test_file.begin(); b != test_file.end(); b++) {
		// cout << "Message begin:\n" << *b->begin() << "... and end:\n" << *b->end() << endl;
		string from_addr;
		if (find_from_addr(&*b, from_addr))
			cout << "Message from: " << from_addr
                 << "\n\tSubject: " << find_subject(&*b) << endl;
		else
			cout << "From line not found.\n";
	}
    
    // HERE: TODO: Finish testing in Ex1 and carry on!
}