//============================================================================
// Name        : CSC450-1-Week5.cpp
// Author      : Laure A-G Jean
// Version     :
// Copyright   : Your copyright notice
// Description : User Input Program
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For std::reverse

// Function to reverse the content of a file
void reverseFileContent(const std::string& inputFileName, const std::string& outputFileName) {
    // Open the input file for reading
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file " << inputFileName << std::endl;
        return;
    }

    // Read the entire content of the input file
    std::string content((std::istreambuf_iterator<char>(inputFile)),
                        std::istreambuf_iterator<char>());
    inputFile.close();

    // Reverse the content
    std::reverse(content.begin(), content.end());

    // Open the output file for writing
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the file " << outputFileName << std::endl;
        return;
    }

    // Write the reversed content to the output file
    outputFile << content;
    outputFile.close();

    std::cout << "Reversed content has been saved to " << outputFileName << std::endl;
}

int main() {
    // Define the file names
    const std::string mainFileName = "CSC450_CT5_mod5.txt";
    const std::string reversedFileName = "CSC450-mod5-reverse.txt";

    // Open the file in append mode
    std::ofstream outputFile(mainFileName, std::ios::app);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the file " << mainFileName << std::endl;
        return 1;
    }

    // Get input from the user
    std::cout << "Enter the text you want to append to the file (type 'END' to finish):" << std::endl;
    std::string userInput;
    while (true) {
        std::getline(std::cin, userInput);

        // Stop if the user types 'END'
        if (userInput == "END") {
            break;
        }

        // Append the input to the file
        outputFile << userInput << std::endl;
    }

    // Close the file after appending
    outputFile.close();

    std::cout << "Data successfully appended to " << mainFileName << std::endl;

    // Reverse the content of the main file and save it to the reversed file
    reverseFileContent(mainFileName, reversedFileName);

    return 0;
}


