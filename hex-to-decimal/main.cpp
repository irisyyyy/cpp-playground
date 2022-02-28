//
//  main.cpp
//  practice
//
//  Created by Iris Yang on 2020/5/8.
//  Copyright © 2020 Iris Yang. All rights reserved.

/*16.5 (HexFormatException) Implement the hex2Dec function in Programming Exercise 16.1 to throw a HexFormatException if 
the string is not a hex string. Define a custom exception class named HexFormatException. Write a test program that prompts 
the user to enter a hex number as a string and displays the number in decimal..*/

#include <iostream>
#include <string>



int hex2Dec(const std::string& hex);
int hexCharToDecimal(char ch);

class HexFormatException: public std::runtime_error {
private:
    char ch;
    
public:
    HexFormatException(char ch):runtime_error("Not a hex number") {
        this->ch = ch;
    
    }
    char getChar() {
        return ch;
    }
    
};

int hexCharToDecimal(char ch) {
ch = toupper(ch);
if (ch >= 'A' && ch <= 'F')
    return 10 + ch - 'A';
else if (ch >= '0' && ch <= '9')
    return ch - '0';
else
    throw HexFormatException(ch);
}

int hex2Dec(const std::string& hex){
    int decnum = 0;
    for(int i = 0; i < hex.size(); i++){
        decnum = decnum * 16 + hexCharToDecimal(hex[i]);
    }
    return decnum;
}


int main(int argc, const char * argv[]) {
    
    std::string hexs;
    try {
        std::cout << "Enter a hex number:" << std::endl;
        std::cin >> hexs;
        std::cout << hex2Dec(hexs) << std::endl;
    }
    catch(std::runtime_error er){
        std::cout << er.what() << std::endl;
    }
    
    return 0;
}

