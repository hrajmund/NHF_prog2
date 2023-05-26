#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

#include <iostream>
#include "string5.h"
#include "memtrace.h"

class StringStream {
    String data;
    unsigned int position;
public:
    StringStream(const String& str) : data(str), position(0) {}

    bool operator>>(String output) {
        output = "";
        while (position < data.size() && data[position] != ';' && data[position] != '\t' && data[position] != '\n') {
            output = output + data[position];
            ++position;
        }
        skipWhitespace();
        return true;
    }

    void skipWhitespace() {
        while (position < data.size() && (data[position] == ';' || data[position] == '\t' || data[position] == '\n')) {
            ++position;
        }
    }


};
#endif // !STRINGSTREAM_H
