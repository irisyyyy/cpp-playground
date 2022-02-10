#include <iostream>
#include <string>

/*
using rules specified here:
    https://isbn-information.com/check-digit-for-the-13-digit-isbn.html
    https://isbn-information.com/the-10-digit-isbn.html
*/

bool CheckTenDigits(std::string s);
bool CheckThirteenDigits(std::string s);

int main() {
    
    //promt the user enter the 10 digits or 13 digits ISBN#
    std::string isbn;
    std::cout << "Please enter the 10 digit or 13 digit ISBN number you want to check: ";
    std::cin >> isbn;
    
    //check if the ISBN is valid
    bool result;
    if (isbn.length() == 13) {
        result = CheckThirteenDigits(isbn);
    } else if (isbn.length() == 10) {
        result = CheckTenDigits(isbn);
    } else {
        std::cout << "You must enter a 10 or 13 digit ISBN number. \n";
    }

    //return the validation result to the user
    if (result) {
        std::cout << isbn << " is a valid ISBN number.\n";
    } else {
        std::cout << isbn << " is not a valid ISBN number.\n";
    }

}

// 10 digits
bool CheckTenDigits(std::string s) {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (s[i] - '0') * (10 - i);
    }
    int lastDigit = sum % 11;
    lastDigit = (lastDigit == 0) ? lastDigit : 11 - lastDigit;

    if (lastDigit != (s[9] - '0'))
        return false;
    
    sum += lastDigit;

    return sum % 11 == 0;
}

// 13 digits
bool CheckThirteenDigits(std::string s) {
    int sum = 0;
    for (int i = 0; i < 12; i += 2) {
        sum += (s[i] - '0');
        sum += (s[i + 1] - '0') * 3;
    }
    sum %= 10;
    sum = sum == 0 ? sum : 10 - sum;
    
    return sum == (s[12] - '0');
}