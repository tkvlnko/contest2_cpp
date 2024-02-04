// Vasya wants to change his email password, because he is afraid that his mailbox might have been hacked. According to the rules, a new password must meet the following restrictions:
// consist of ASCII table characters with codes from 33 to 127;
// be at least 8 characters and no longer than 14;
// from 4 classes of symbols - large letters, small letters, numbers, other symbols - at least three of any should be present in the password.
// Help Vasya to write a program that will verify that his new password is valid.
// The solution has to include functional decomposition. Failure to follow the decomposition requirements will result in the lower score, even if the solution gets "OK" from the contest checker. You may add extra functions in addition to the required ones. This rule applies to all tasks in the contest.
// Requirement: Implement the solution as a function that takes a password as input and returns true/false for passwords that fit or don't fit the restrictions. Use this function in the function main() to solve the problem.


#include <iostream>
#include <cstring>

bool checkSize(char* password) {
    if (strlen(password) < 8 || strlen(password) > 14) {
        return false;
    }
    return true;
}

bool checkAscii(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] < 33 && password[i] > 127) {
            return false;
        }
        return true;
    }
}

bool checkClasses(char* password) {
    int counter = 0;

    // numbers
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] <= 57 && password[i] >= 48) {
            counter ++;
            break;
        }

    }
    // capital letters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] <= 90 && password[i] >= 65) {
            counter ++;
            break;
        }
    }

    // small letters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] <= 122 && password[i] >= 97) {
            counter ++;
            break;
        }
    }
    
    // other symbols
    for (int i = 0; i < strlen(password); i++) {
        if ((password[i] <= 47 && password[i] >= 33) || 
            (password[i] <= 64 && password[i] >= 58) || 
            (password[i] <= 96 && password[i] >= 91) || 
            (password[i] <= 127 && password[i] >= 123)) {
            counter ++;
            break;
        }
    }
    if (counter >= 3) {
        return true;
    }
        return false;
    }

int main() {
    char password[100];
    std::cin >> password;
    if (checkClasses(password) && checkAscii(password) && checkSize(password)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}