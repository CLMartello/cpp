
int main(int argc, char **argv) {
    //check number of arguments
    if (argc != 4)
        return (1);
    //reads a file -> argv[1]
    //copies this file to argv[1].replace
    //s1 -> argv[2]
    //s2 -> argv[3]
    //change all occurence of s1 for s2 in argv[1].replace

    //reads file
    //searchs for s1
    //replace s1 for s2
    //write new file .replace

    //check all 3 arguments are not empty
    for (int i = 1; i <= argc; i++) {
        if (argv[i] == NULL) //verify more, if it is /n or space, tab, ..
            return (1);
    }

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