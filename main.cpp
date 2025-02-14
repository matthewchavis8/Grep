#include <iostream>
#include "grep.h"
#include "args.h"

int main (int argc, char* argv[]) {
    args::ArgParser cli;
    Grep grep;

    cli.option("out o", "grep.txt");
    cli.option("pattern r", "");
    cli.flag("case-sensitive i");

    cli.parse(argc, argv);

    auto size = cli.args.size();
    
    //Gives options to user to turn on insensitve, output to file, or regex patterns
    if (cli.found("i"))
        grep.case_sensitive = true;
    if (cli.found("o"))
        grep.path = cli.value("out");
    if (cli.found("r"))
        grep.pattern = cli.value("r");
    
    if (size == 1)
        grep.path = cli.args[0];
    else if (size == 2) {
        grep.word = cli.args[0];
        grep.path = cli.args[1];
        grep.pattern = cli.args[0];
    } else {
        std::cerr << "not enough arguments supplied" << '\n';
    }

    if (grep.run()) {
        for (auto &line : grep.lines_found) {
            if (cli.found("o"))
                grep.write_to_file(line);
            else 
                std::cout << line << '\n';
        }
    } else {
        std::cerr << "An error has occured parsing file!" << '\n';
    }
}