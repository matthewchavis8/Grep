#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>
#include "args.h"
#include <string_view>

struct Result {
    int position{};
    int line_number{};
    std::string line{};
    std::string word{};
    std::string output{};

    operator const char*() {
        std::ostringstream res;
        res << "on line " << line_number << " at position " << position 
        << '\n' << line << '\n';
        
        output = res.str();
        return output.c_str();
    }
};

struct Grep {
    bool case_sensitive{};
    int line_cnt{};
    std::vector<Result> lines_found{};
    std::string pattern{};
    std::string word{};
    std::string text{};
    std::string path{};
    std::ofstream file{};

    void search (const std::string_view word, const std::string_view text, const int line_number);
    void match (
        const std::string_view word, 
        const std::string_view text, 
        std::smatch& smatch, 
        const std::regex& rgx, 
        int line_number
    );
    bool run ();
    void write_to_file(Result r);
};
