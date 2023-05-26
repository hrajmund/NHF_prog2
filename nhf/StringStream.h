#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

#include <iostream>
#include "string5.h"
#include "memtrace.h"

//class StringStream {
//    String data;
//    size_t position;
//public:
//    StringStream(const String& str) : data(str), position(0) {}
//
//    /*bool operator>>(String& output) {
//        output = "";
//        while (position < data.size() && data[position] != ';' && data[position] != '\t' && data[position] != '\n') {
//            output = output + data[position];
//            ++position;
//        }
//        skipWhitespace();
//        return true;
//    }*/
//    bool operator>>(String& output) {
//        output = "";
//        while (position < data.size() && data[position] != ';' && data[position] != '\t' && data[position] != '\n') {
//            output = output + data[position];
//            ++position;
//        }
//        skipWhitespace();
//        return true;
//    }
//
//    void skipWhitespace() {
//        while (position < data.size() && (data[position] == ';' || data[position] == '\t' || data[position] == '\n')) {
//            ++position;
//        }
//    }
//
//
//};

class StringStream {
    String data;
    int currentPosition;

public:
    StringStream(const String& str) : data(str), currentPosition(0) {}

    template <typename T>
    StringStream& operator>>(T& value) {
        // Skip whitespace characters
        while (currentPosition < data.size() && std::isspace(data[currentPosition]))
            currentPosition++;

        // Read value
        std::stringstream ss;
        while (currentPosition < data.size() && !std::isspace(data[currentPosition])) {
            ss << data[currentPosition];
            currentPosition++;
        }

        ss >> value;
        return *this;
    }

    bool eof() const {
        return currentPosition >= data.size();
    }
};
#endif // !STRINGSTREAM_H
