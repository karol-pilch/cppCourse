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
#include <regex>

// Load a message into the vectors
Mail_file::Mail_file(const string& fn) {
	ifstream ifile (fn);
	if (!ifile) {
		cerr << "Cannot open input file.";
	}
	
	for (string s; getline(ifile,s);)
		lines.push_back(s);
	
	auto b = lines.begin();
	for (auto c=lines.begin(); c!=lines.end(); ++c) { //TODO: last message isn't added if there's no trailing '----'
		if (*c == "----" && b != c) {		// No empty messages allowed
            Message new_message(Message(b,c));
            msgs.push_back(new_message);
            subjects.insert(pair<string, Message>(find_subject(&new_message), new_message));
			b = c+1;
		}
	}
	if (msgs.size() == 0)
		throw Bad_file();		// Didn't even get one message
}

// Place sender of message into s and return true if found
// From line starts with 'From:'
bool find_from_addr(const Message* m, string& s) {
	regex from_address (R"(^From:\s(.*)$)");
	smatch matches;
	for (Line_iter b = m->begin(); b != m->end(); ++b) {
		if (regex_search(*b, matches, from_address) && matches.size() >= 2) {
			s = matches[1];
			return true;
		}
	}
	return false;
}


// Find the subject line and return it
string find_subject(const Message* m) {
    regex subject (R"(^Subject:\s(.*)$)");
    smatch matches;
    for (Line_iter b = m->begin(); b != m->end(); ++b) {
        if (regex_search(*b, matches, subject) && matches.size() >= 2) {
            return matches[1];
        }
    }
    return "";
}


// Print a Message
ostream& operator<< (ostream& os, const Message& m) {
    for (auto b=m.begin(); b != m.end(); b++) {
        os << "> " << *b << endl;
    }
    return os;
}