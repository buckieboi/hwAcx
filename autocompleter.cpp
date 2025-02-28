#include <iostream> //allow input output 
#include <fstream> // open files
#include <string> // use strings
int size():{
    //get size of dictionariy already made? number of strings of possible completions
    //run in o(n) number of strings
    //open dictionary and run thru it and update a counter then return it?

    ifstream file("words2.txt"); //open words2 file

    if(!file) { //check if file is opened right
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int count = 0;
    while(file >> word){ //read word for word 
        count ++; //count the words and add them to a int variable
    }
    file.close(); //close file
    return count;
}


#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("words.txt"); // Open the file

    if (!file) { // Check if file opened successfully
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string word;
    while (file >> word) { // Read word by word
        std::cout << word << std::endl; // Print each word
    }

    file.close(); // Close the file
    return 0;
}
