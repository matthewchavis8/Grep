#include <configure.h>
using std::vector, std::string;



vector<string> search (string& query, string& contents) {
    
    vector<string> text{};
    string line;

    while (std::getline(contents, line)) 
        text.push_back(line);

} 

void run (Configure& config) {

}
