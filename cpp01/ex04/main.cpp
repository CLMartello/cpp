
#include <iostream> //input and output handling
#include <string>
#include <fstream> //file handling
#include <cstdlib> //exit function


int main(int argc, char **argv) {
    if (argc != 4)
        return (std::cerr << "Arguments must be: ./program filename s1 s2\n", 1);
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (filename.empty() || s1.empty() || s2.empty())
        return (std::cerr << "Arguments can not be empty\n", 1);
    std::ifstream file(filename);
    if (!file.is_open())
        return (std::cerr << "Error in file opening\n", 1);
    std::string line;
    std::ofstream output(filename + ".replace");
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