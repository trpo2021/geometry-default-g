#include <iostream>
#include <string>
#include <vector>
#include "formatcheck.h"
using namespace std;


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
