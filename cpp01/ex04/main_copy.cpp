
#include <iostream> //input and output handling
#include <string>
#include <fstream> //file handling
#include <cstdlib> //exit function


int main(int argc, char **argv) {
    //check number of arguments
    if (argc != 4)
        return (std::cerr << "Arguments must be: ./program filename s1 s2\n", 1);
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (filename.empty() || s1.empty() || s2.empty())
        return (std::cerr << "Arguments can not be empty\n", 1);
    //reads a file -> argv[1]
    std::ifstream file(filename);
    //creates a file strem with filename.txt, if the case
    //file.open(filename); -> not necessary, the constructor before already open the file
    //open the filename.txt in the file stream file
    if (!file.is_open())
        return (std::cerr << "Error in file opening\n", 1);
    //verify if it was open correctly, otherwise gives error 1
    std::string line;
    size_t pos = 0;
    std::ofstream output(filename + ".replace");
    while (std::getline(file, line)) {
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            if (pos > 0) {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
        }
        output << line << "\n";
    }
    file.close();
    output.close();
    return (0);
    //copies this file to argv[1].replace
    //s1 -> argv[2]
    //s2 -> argv[3]
    //change all occurence of s1 for s2 in argv[1].replace

    //reads file
    //searchs for s1
    //replace s1 for s2
    //write new file .replace
    //check all 3 arguments are not empty
    //check first argument (filename) exists and f is openable
    //open argv[1] filename
    //reads all content of filename -> store in memory as a big string
    //find occurrence of argv[2] s1 -> if there is none, return filename original ??
        //when  searching, check space before and after to not found another string with beggining s1
    //replace s1 for argv[3] s2
    //string search function
    //substring replacement function
    //create new file .replace
    
    //write modify big string that is located on memory
}