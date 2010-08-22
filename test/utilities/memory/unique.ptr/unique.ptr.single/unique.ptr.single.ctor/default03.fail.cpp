//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// Test unique_ptr default ctor

#include <memory>

// default unique_ptr ctor should require non-pointer Deleter

int main()
{
    std::unique_ptr<int, void (*)(void*)> p;
}
