#include <string>
using namespace std;
bool isFormatCorrect(string str)
{
    if (str.empty())
        return 0;

    int amountOfSymbol = 0;
    for (auto chr : str)
        if (chr == ' ')
            amountOfSymbol++;
    if (amountOfSymbol != 1)
        return 0;

    amountOfSymbol = 0;
    for (auto chr : str)
        if (chr == ',')
            amountOfSymbol++;
    if (amountOfSymbol != 1)
        return 0;

    amountOfSymbol = 0;
    for (auto chr : str)
        if (chr == '(')
            amountOfSymbol++;
    if (amountOfSymbol != 1)
        return 0;

    amountOfSymbol = 0;
    for (auto chr : str)
        if (chr == ')')
            amountOfSymbol++;
    if (amountOfSymbol != 1)
        return 0;
    if (str.find('(') > str.find(')'))
        return 0;
    if (str.find(' ') > str.find(','))
        return 0;
    if ("circle" != str.substr(0, str.find_first_of("(")))
        return 0;
    return 1;
}