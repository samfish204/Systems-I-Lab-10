// Copyright 2020 Samuel Fisher
// lab10
// CSE278 - Section B 
// Professor Vendome
// This program takes input from the user
// to see how many numbers they want and
// then takes the numbers they enter and finds the factors of each.
// This is done using pointers instead of normal array traversal
#include <iostream>
#include <string>

// Find factors of each number that was entered by the user
// using pointers
void factorsOf(const int* nums, int size) {
    nums += size - 1;

    std::string result;
    
    for (int i = size; i > 0; i--) {
        result = "";
        std::cout << "The factors of " << *nums << " are:\n"; 
        
        for (int j = *nums - 1; j >= 2; j--) {
            if (*nums % j == 0) {
                result = result + std::to_string(j) + " ";
            }
        }
        std::cout << result << std::endl;
        nums--;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Specify number with argument" << std::endl;
        return 1;
    }

    std::string numString = argv[1]; int nums = stoi(numString);

    std::cout << "Enter " << nums << " number(s):";

    std::getline(std::cin, numString);
    
    int numArray[nums]; int currNum; int index = 0;
    while (numString.find(' ') != std::string::npos) {
        currNum = stoi(numString.substr(0, numString.find(' ')));
        numString = numString.substr(numString.find(' ')+1, numString.length());
        *(numArray + index) = currNum;
        index++;
    }
    currNum = stoi(numString.substr(0, numString.length()));
    *(numArray + index) = currNum;
    
    factorsOf(numArray, nums);

    return 0;
}
