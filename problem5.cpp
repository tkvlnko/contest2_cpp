// Write a program that adds 1 to the natural number N (the length of the number N is up to 1000 characters).

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

const int LEN = 1001;

char *addOne(char*, char*);

int main()
{
    char s[LEN];
    char s1[LEN + 1];
    std::cin >> s;
    std::cout << addOne(s, s1);
    return 0;
}

char *addOne(char *s, char *s1)
{
    size_t slen = strlen(s);
    if (s[slen - 1] != '9')
    {
        s[slen - 1]++;
    }
    else
    {
        s[slen - 1] = '0';
        for (int i = slen - 2; i >= 0; i--)
        {
            if (s[i] == '9') {
                s[i] = '0';
            } else {
                s[i]++;
                break;
            }
        }
        if (s[0] == '0')
        {
            s1[0] = '1';
            for (size_t i = 0; i < LEN; i++) {
                s1[i + 1] = s[i];
            }
            return s1;
        }
    }
    return s;
}