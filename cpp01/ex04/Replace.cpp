
#include "Replace.hpp"

int    replace(std::string filename, std::string s1, std::string s2) {
    
    if (filename.empty() || s1.empty() || s2.empty())
        return (std::cerr << "Arguments can not be empty\n", 1);
    
    std::ifstream file;
    file.open(filename.c_str());
    if (!file.is_open())
        return (std::cerr << "Error in file opening\n", 1);
    
    std::string line;
    std::ofstream output;
    output.open((filename + ".replace").c_str());
    
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        output << line << "\n";
    }
    
    file.close();
    output.close();
    return (0);
}
