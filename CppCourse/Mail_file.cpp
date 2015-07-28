//
//  Mail_file.cpp
//  CppCourse
//
//  Created by Karol Pilch on 28/07/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//

#include "Mail_file.h"
#include <fstream>
#include <iostream>

// Load a message into the vectors
Mail_file::Mail_file(const string& fn) {
	ifstream ifile (fn);
	if (!ifile) {
		cerr << "Cannot open input file.";
	}
	
	for (string s; getline(ifile,s);)
		lines.push_back(s);
	
	auto b = lines.begin();
	for (auto c=lines.begin(); c!=lines.end(); ++c) {
		if (*c == "----" && b != c) {		// No empty messages allowed
			msgs.push_back(Message(b,c));
			b = c+1;
		}
	}
	if (msgs.size() == 0)
		throw Bad_file();		// Didn't even get one message
}