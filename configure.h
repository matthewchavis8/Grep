#pragma once

#include <iostream>
#include <string_view>
#include <vector>

/*
Alright so grep will take in a word or sentence and 
also a file from the command line. Then it will search for sentences that
contain that sentence and store it into a vector and return sentences that contain words

methods we need
- run
    runs the searhc
- search
    perfroms the search
*/

class Configure {
    private:
        std::string m_query{};
        std::string m_file{};
    public:
        Configure (std::string_view query, std::string_view file)
            : m_query{query}
            , m_file{file}
            {}
        const std::string& getQuery () const {return m_query;}
        const std::string& getFile () const {return m_file;}
};

