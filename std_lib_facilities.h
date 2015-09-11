
//
// This is a standard library support code to the chapters of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef STD_LIB_FACILITIES_GUARD
#define STD_LIB_FACILITIES_GUARD 1

#include <algorithm>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "Log.h"

using namespace std;

//------------------------------------------------------------------------------

// The call to keep_window_open() is needed on some Windows machines to prevent
// them from closing the window before you have a chance to read the output. 
inline void keep_window_open()
{
    cin.get();
}

//------------------------------------------------------------------------------

inline void keep_window_open(const string& str)
{
    static int attempts = 10; // Maximum number of attempts before forceful exit

    while (--attempts)
    {
        cout << "Please enter " << str << " to exit" << endl;

        bool exit = true;

        for(string::const_iterator p = str.begin(); p != str.end(); ++p)
            if (*p != cin.get())
            {
                exit = false;
                break;
            }

         if (exit)
             break;
    }
}

//------------------------------------------------------------------------------

// Helper function to show an error message
inline void error(const string& errormessage)
{
    cerr << errormessage << endl;
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

inline void error(string s1, string s2)
{
    error(s1+s2);
}

//------------------------------------------------------------------------------

template <typename Target, typename Source>
Target narrow_cast(Source src)
{
    Target tgt = src;

    if ((Source)tgt != src)
        error("Invalid narrowing conversion");

    return tgt;
}

//------------------------------------------------------------------------------

inline ios_base& general(ios_base& b)    // to complement fixed and scientific
{
    b.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return b;
}


// Added by Karol Pilch 18/11/2014
// Copied from http://www.stroustrup.com/Programming/PPP2code/std_lib_facilities.h


// TODO: Redo for OS X
//inline int randint(int min, int max)
//{ 
//	static default_random_engine ran (time(nullptr));
//	ran();	// For some reason the first one is always the same :(
//	return uniform_int_distribution<>{min, max}(ran); 
//}
//inline int randint(int max) { return randint(0, max); }

//------------------------------------------------------------------------------

// Added by Karol Pilch 24/04/2015
// Timer to time functions

class Timer {
	chrono::time_point<chrono::system_clock> b;
	chrono::time_point<chrono::system_clock> e;
	bool running = false;

	public :
	void start();
	void stop();
	long int duration_in_ms();
};

inline void Timer::start()
{
	if (running) return;	// Can't start an already running timer
	running = true;
	b = chrono::system_clock::now();
}

inline void Timer::stop()
{
	if (!running) return;	// Can't stop a non-running timer
	running = false;
	e = chrono::system_clock::now();
}

inline long int Timer::duration_in_ms() 
{
	if (running) 
		return 0;
	else
		return chrono::duration_cast<chrono::milliseconds>(e-b).count();
}

// Added by Karol Pilch on 28/04/2015
// Prints a container between {} with commas in between values
template <typename ForwardIterator>	// Requires Forward Iterator
void print_container(ForwardIterator b, ForwardIterator e)
{
	cout << "{";
	while (b != e) {
		cout << *b;
		if (++b != e) cout << ", ";
	}
	cout << "}\n";
}


//------------------------------------------------------------------------------
#endif // STD_LIB_FACILITIES_GUARD

