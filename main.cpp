#include <iostream>
#include <string>
#include <vector>
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

int main()
{
    vector<float> rad;
    vector<float> x;
    vector<float> y;
    vector<float> squares;
    vector<float> perimetrs;
    cout << "USE FORMAT UNDER LINE\n---------------\n figure(x y,r)\nPrint "
            "'end' to finish the input\n";
    while (1) {
        string input;
        getline(cin, input);
        if (("end" == input.substr(0, 3)) && input.length() == 3)
            break;
        if (!isFormatCorrect(input)) {
            cout << "WRONG FORMAT" << endl;
            continue;
        }
        if ("circle" == input.substr(0, input.find_first_of("("))) {
            float x_input = atof(input.substr(input.find_first_of("(") + 1,
                                            input.find_first_of(' ') - 1)
                                       .c_str());
            x.push_back(x_input);
            float y_input = atof(input.substr(input.find_first_of(' ') + 1,
                                            input.find_first_of(",") - 1)
                                       .c_str());
            y.push_back(y_input);
            float rad_input = atof(input.substr(input.find_first_of(",") + 1,
                                              input.find_last_of(")") - 1)
                                         .c_str());
            rad.push_back(rad_input);
        }
    }
    return 0;
}
