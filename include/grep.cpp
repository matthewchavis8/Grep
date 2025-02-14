#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <regex>
#include "grep.h"

using std::regex_constants::ECMAScript;
using std::regex_constants::icase;

void Grep::search(const std::string_view word, const std::string_view text, const int line_number) {
    
    //If patter is empyty search by eitheir case sensitive regex or non case sensitive regex
    if (!pattern.empty()) {
        std::regex rgx{pattern};
        std::regex irgx{pattern, ECMAScript | icase};
        std::smatch smatch{};

        if (case_sensitive)
            match(word, text, smatch, rgx, line_number);
        else 
            match(word, text, smatch, irgx, line_number);

    } else {
        std::regex rgx{ static_cast<std::string>(word) };
        std::smatch smatch{};
        match(word, text, smatch, rgx, line_number);
    }
}

void Grep::match(
    const std::string_view word, 
    const std::string_view text,
    std::smatch& smatch,
    const std::regex& rgx,
    int line_number) 
{   
    std::string text_str{text};
    if (std::regex_search(text_str, smatch, rgx)) {
        
        /*
            if we our search returns true then we will iterate over our contianer
            and create a result object then push that result object into our vector
        */
        for (std::size_t i{}; i < smatch.size(); ++i) {
            Result r;
            r.position = smatch.position(i);
            r.line_number = line_number;
            r.line = text;
            r.word = pattern;

            lines_found.push_back(r);
        }
    } 
}

bool Grep::run() {
    std::ifstream file(path, std::ios_base::in);

    if (file.is_open()) {

        while (file.good()) {
            std::getline(file, text);
            line_cnt++;
            search(word, text, line_cnt);
        }

        file.close();
        return true;
    } 
    return false;
}

void Grep::write_to_file(Result r) {
    std::ofstream file(path, std::ios_base::app | std::ios_base::out);

    if (file.is_open()) {
        file << r;
        file.close();
    }
}


