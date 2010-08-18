//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <regex>

// template <class charT, class traits = regex_traits<charT>> class basic_regex;

// basic_regex& operator=(const charT* ptr);

#include <regex>
#include <cassert>

int main()
{
    std::regex r2;
    r2 = "(a([bc]))";
    assert(r2.flags() == std::regex::ECMAScript);
    assert(r2.mark_count() == 2);
}