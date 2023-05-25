#include <iostream> //for output/input 
#include <string>   //for string datatype
#include <fstream>  //for file i/o

using namespace std;
void inputFile();
void outputFile();
void transferData();


int main(){
    transferData();
    return 0;
}

void inputFile(){
    //Step 1 - Declare Input File (test.txt)
    std::ifstream inputFile("test.txt");
    //Step 2a - Check to see if file exist and open it 
    if(inputFile.is_open()){
        std::string line;
        int total = 0;
        // Step 3 - while the input file has data print to screen
        while(std::getline(inputFile, line)){
            total += std::stoi(line);
            cout << line << endl;
        }
        //Step 4 - Close open file
        inputFile.close();
        cout << "Total: " << total << endl;
    }
    //Step 2b - if file does not exists print 'error' message
    else{
        cout << "Error: Cannot open file." << endl;
    }
}

void outputFile(){
    //Step 1 - Declare Input File (test.txt)
    std::ofstream outputFile("testOUT.txt");
    //Step 2a - Check to see if file exist and open it 
    if(outputFile.is_open()){
        //Step 3 - Output string to file
        outputFile << "Hello, output file." << endl;
        //Step 4 - Close file
        outputFile.close();
        cout << "Success: File Written" << endl;
    }
    else{
    //Step 2b - if file does not exists print 'error' message
        cout << "Error: Cannot open file." << endl;
    }
}

void transferData(){
    std::ifstream inputFile("test.txt");    //declare input file
    std::ofstream outputFile("testOUT.txt");    //delcare output file
    //Step 1 - check for files 
    if(inputFile.is_open() && outputFile.is_open()){
        //if files exist take data from input file and put it into output file
        //Step 2a - while input file has line send to output file
        std::string inputFileLine;
        while(std::getline(inputFile, inputFileLine)){ 
            outputFile << inputFileLine << endl;    //write inputFileLine to testOUT.txt
        }
        //Step 3 - close files
        inputFile.close();
        outputFile.close();
        //Step 4 - print success message
        cout << "Data Transfered!" << endl;
    }
    //Step 2b - if cannot open both files print error message
    else{
        cout << "Error: Check File Paths." << endl;
    }
}