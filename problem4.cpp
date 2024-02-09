#include <iostream>
#include <cstring>
#include <string>

char* deleteVowels(char* word, int length);
char* transformToDigits(char* word, int length);
char* removeDuplicates(char* word, int length);

int main() {
    char word[21];
    std::cin >> word;
    char* wordNoWovels = deleteVowels(word, strlen(word));
    char* wordWothDigits = transformToDigits(wordNoWovels, strlen(wordNoWovels));
    char* wordTruncated = removeDuplicates(wordWothDigits, strlen(wordWothDigits));
    std::cout << wordTruncated;
}

char* deleteVowels(char* word, int length) {
    char* newWord = new char[21];
    newWord[0] = word[0];
    int k = 1;
    const char* vowels = "aehiouwy";
    for(size_t i = 1; i < length; i++) {
        bool flag = true;
        for(size_t j = 0; j < 9; j++) {
            if (word[i] == vowels[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            newWord[k] = word[i];
            k++;
        }
    }
    newWord[k] = '\0'; 
    return newWord;

}

char* transformToDigits(char* word, int length) {
    char* newWord = new char[21];
    newWord[0] = word[0];
    int k = 1;
    
    const char letters[] = {'b', 'f', 'p', 'v', 'c', 
                            'g', 'j', 'k', 'q', 's', 'x', 'z', 
                            'd', 't', 
                            'l', 
                            'm', 'n', 
                            'r'};

    const int groups[] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 4, 5, 5, 6};

    for(size_t i = 1; i < length; i++) {
        for (int j = 0; j < sizeof(letters)/sizeof(letters[0]); j++) {
        if (word[i] == letters[j]) {
            newWord[k] = '0' + groups[j];
            k++;
            break;
        }
    }
    }
    newWord[k] = '\0'; 
    return newWord;
}

char* removeDuplicates(char* word, int length) {
    char* newWord = new char[21];
    newWord[0] = word[0];
    int k;

    if (length < 3) {
        k = 1;
        while (k < 4) {
        newWord[k] = '0';
        k++;
    }
        return newWord;
    }
    k = 2;
    newWord[1] = word[1];
    char current = word[1];
    for (size_t i = 2; i < length; i++) {
        if ((word[i] != current) && k < 4) {
            newWord[k] = word[i];
            current = word[i];
            k++;
        }
    }

    while (k < 4) {
        newWord[k] = '0';
        k++;
    }
    newWord[k] = '\0'; 
    return newWord;
}