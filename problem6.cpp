// Напишите программу, вычисляющую остаток от деления заданного «длинного» числа на заданную цифру.

#include <iostream>
#include <string>


short remainder(short n, std::string s)
{
    short remain = 0;

    for (size_t i = 0; i < s.size();i++)
    {
            remain = (remain * 10 + (int(s[i]) - '0')) % n;
    }
    return remain;
}

int main()
{
    std::string s;
    short n;
    std::cin >> n >> s;
    std::cout << remainder(n, s);

    return 0;
}