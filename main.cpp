#include <iostream>
#include <string_view>
#include <fstream>
#include "configure.h"

using std::cout, std::cin, std::cerr;

int main (int argc, char* argv[]) {
   
    std::ifstream inputFile;

    std::string query = argv[1];
    std::string file = argv[2];

    Configure config(query, file);

    inputFile.open(config.getFile());

    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << '\n';
        std::exit(1);
    }

    std::string line;
    while (std::getline(inputFile, line))
        cout << line << '\n';
    
    inputFile.close();

    return 0;
}