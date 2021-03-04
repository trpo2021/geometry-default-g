#include "lib/formatcheck.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Figure {
    string name;
    float x_coordinate;
    float y_coordinate;
    float radius_or_side;
    float square;
    float perimeter;
};

int main()
{
    vector<Figure> figures;
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
        Figure tmp_figure_structure;
        if ("circle" == input.substr(0, input.find_first_of("("))) {
            tmp_figure_structure.name = "circle";

            float x_input = atof(input.substr(input.find_first_of("(") + 1,
                                              input.find_first_of(' ') - 1)
                                         .c_str());
            tmp_figure_structure.x_coordinate = x_input;
            float y_input = atof(input.substr(input.find_first_of(' ') + 1,
                                              input.find_first_of(",") - 1)
                                         .c_str());
            tmp_figure_structure.y_coordinate = y_input;
            float rad_or_side_input
                    = atof(input.substr(input.find_first_of(",") + 1,
                                        input.find_last_of(")") - 1)
                                   .c_str());
            tmp_figure_structure.radius_or_side = rad_or_side_input;

            figures.push_back(tmp_figure_structure);
        }
    }
    return 0;
}
