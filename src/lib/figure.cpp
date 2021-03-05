#include "figure.h"
#include <iostream>
#define PI 3.14
#include <string>
#include <vector>
using namespace std;

void calculate_square_and_perimeter_for_figures(vector<Figure>& figures)
{
    for (auto& fig : figures) {
        fig.square = fig.radius_or_side * fig.radius_or_side * PI;
        fig.perimeter = 2 * PI * fig.radius_or_side;
    }
}
void print_data_of_figure(Figure figure)
{
    cout << figure.name << endl;
    cout << "Coords : "
         << "(" << figure.x_coordinate << "; " << figure.y_coordinate << ")"
         << endl;
    cout << "Radius : " << figure.radius_or_side << endl;
    cout << "Square : " << figure.square << endl;
    cout << "Perimeter : " << figure.perimeter << endl << endl;
}
void print_data_of_all_figures(vector<Figure> figures)
{
    for (auto fig : figures)
        print_data_of_figure(fig);
}