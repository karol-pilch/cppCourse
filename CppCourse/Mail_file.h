//
//  Mail_file.h
//  CppCourse
//
//  Created by Karol Pilch on 28/07/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//

#ifndef __CppCourse__Mail_file__
#define __CppCourse__Mail_file__

#include <stdio.h>
#include <map>
#include <vector>
#include <string>

using namespace std;

//================================= Message ==================================================/

using Line_iter = vector<string>::const_iterator;

// Points to the first and the last lines of the message
class Message {
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter beg, Line_iter end) : first(beg), last(end) {}
	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }
};

//================================= Mail_file ================================================/

using Mess_iter = vector<Message>::const_iterator;

// Holds all lines and manages access to messages
struct Mail_file {
	string fname;				// File name
    
	vector<string> lines;		// Lines in order
	vector<Message> msgs;		// Messages in order
    multimap<string, Message> subjects;     // Messages sorted by subject
	
	Mail_file(const string&);	// Read a file into lines
	
	Mess_iter begin() const { return msgs.begin(); }
	Mess_iter end()   const { return msgs.end();   }
	
	class Bad_file {};
};

// Place sender of message into s and return true if found
bool find_from_addr(const Message* m, string& s);

// Return the subject or "" if doesn't exist
string find_subject(const Message* m);

// Print a Message
ostream& operator<< (ostream& os, const Message& m);

#endif /* defined(__CppCourse__Mail_file__) */
