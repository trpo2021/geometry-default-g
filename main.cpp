#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> r;
vector<int> x;
vector<int> y;
vector<float> s;
vector<float> per;

bool isFormatCorrect(string str)
{
    if (str.empty())
        return 0;

    if (strchr(str.c_str(), ' '))
        return 0;

    int k = 0;
    for (auto i : str)
        if (i == '.')
            k++;
    if (k != 1)
        return 0;

    k = 0;
    for (auto i : str)
        if (i == ',')
            k++;
    if (k != 1)
        return 0;

    k = 0;
    for (auto i : str)
        if (i == '(')
            k++;
    if (k != 1)
        return 0;

    k = 0;
    for (auto i : str)
        if (i == ')')
            k++;
    if (k != 1)
        return 0;
    if (str.find('(') > str.find(')'))
        return 0;
    if (str.find('.') > str.find(','))
        return 0;
    if ("circle" != str.substr(0, str.find_first_of("(")))
        return 0;
    return 1;
}

int main()
{
    cout << "USE FORMAT UNDER LINE\n---------------\n figure(x.y,r)\n";
    while (1) {
        string input;
        cin >> input;
        if ("end" == input.substr(0, 3))
            break;
        if (!isFormatCorrect(input)) {
            cout << "WRONG FORMAT" << endl;
            continue;
        }
        if ("circle" == input.substr(0, input.find_first_of("("))) {
            int xx = atoi(input.substr(input.find_first_of("(") + 1,
                                       input.find_first_of(" ") - 1)
                                  .c_str());
            x.push_back(xx);
            int yy = atoi(input.substr(input.find_first_of(".") + 1,
                                       input.find_first_of(",") - 1)
                                  .c_str());
            y.push_back(yy);
            int rad = atoi(input.substr(input.find_first_of(",") + 1,
                                        input.find_last_of(")") - 1)
                                   .c_str());
            r.push_back(rad);
        }
    }
    return 0;
}
