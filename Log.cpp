//
//  Log.cpp
//  CppCourse
//
//  Created by Web Developer on 11/09/2015.
//  Copyright (c) 2015 Karol Pilch. All rights reserved.
//

#include "Log.h"


void Log::message(std::string m, unsigned int v)
{
    if (v>ver) return;
    add_indent();
    *os << name << " > " << sub.back().n << ": " << m << std::endl;
}

void Log::add_sub(const std::string& n, int v)
{
    sub.push_back(Log_sub(v,n));
    
    if (log_subs) {
        message("Started.",v);
    }
    
}

void Log::pop_sub()
{
    if (log_subs) {
        message("Terminating.",sub.back().ver);
    }
    
    sub.pop_back();
}
