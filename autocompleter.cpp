#include <iostream> //allow input output 
#include <fstream> // open files
#include <string> // use strings

using namespace std;

int size(); //function prototypes

int main(){
    int wordCount = size(); // calls function takes wordCount of dictionarry
    cout << "Words in dictionary counted by size(): " << wordCount<< endl;
    return 0;
}

int size(){
    //get size of dictionariy already made? number of strings of possible completions
    //run in o(n) number of strings
    //open dictionary and run thru it and update a counter then return it?

    ifstream file("words2.txt"); //open words2 file

    if(!file) { //check if file is opened right
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int count = 0;
    string word;
    while(file >> word){ //read word for word 
        count ++; //count the words and add them to a int variable
    }
    file.close(); //close file
    return count;
}
