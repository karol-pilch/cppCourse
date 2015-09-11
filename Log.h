/*
	Log.h
	Created by Karol Pilch
	28/04/2015

	Interfac and implementatione for class Log
	Log allows for easy logging of debug messages
	With custom verbosity
*/

#include <iostream>
#include <string>
#include <vector>

struct Log_sub {
	int ver;
	std::string n;
	Log_sub(int v, const std::string& name) : ver(v), n(name) {  }
};

class Log {
	public:
		Log(std::string ln, unsigned int v=0, bool s = true, std::ostream& o = std::cout) : os(&o), name(ln), ver(v), log_subs(s)
	{
		sub.push_back(Log_sub(v,""));	// Start with an empty one
	}

		void set_verbosity(unsigned int v) { ver = v; }
		void add_sub(const std::string&,int);
		void pop_sub();
		void set_sub_creation_msg(bool b) { log_subs = b; }

		void message(std::string m, unsigned int v);

	private:
		std::ostream* os;
		std::string name;
		std::vector<Log_sub> sub;
		bool log_subs;
		unsigned int ver;	//verbosity: 0 == top priority
		void add_indent() { for (int i=1; i<sub.size(); ++i) *os << "\t"; }
};

