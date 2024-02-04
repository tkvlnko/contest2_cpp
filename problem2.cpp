// A string consisting of lowercase Latin letters and spaces is given. Check whether it is a palindrome without spaces (eg, "no lemon no melon").

#include <iostream>
#include <cstring>
#include <string>


std::string removeSpaces(std::string str);
bool checkPalindrome(std::string str);


int main() {
    std::string str;
    std::getline(std::cin, str);
    std::string newStr = removeSpaces(str);
    std::cout << (checkPalindrome(newStr) ? "yes" : "no");
}

std::string removeSpaces(std::string str) {
    char newStr[100];
    for (int i = 0; i < 100; i++) {
        newStr[i] = 0;
    }

    int counter = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != 32) {

            newStr[counter] = str[i];
            counter++;
        }
    }
    return newStr;
}

bool checkPalindrome(std::string str) {
    int len = str.length() - 1;

    for (int i = 0; i <= len / 2; i++) {
        // std::cout << str[i] << '\t' << str[len - i ] << '\n';
        if (str[i] != str[len - i]) {
            return false;
        }
    }
    return true;
}