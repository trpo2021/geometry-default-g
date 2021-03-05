#ifndef FIGURE_H_
#define FIGURE_H_
#include <string>
#include <vector>

struct Figure {
    std::string name;
    float x_coordinate;
    float y_coordinate;
    float radius_or_side;
    float square;
    float perimeter;
};

void calculate_square_and_perimeter_for_figures(std::vector<Figure>& figures);

void print_data_of_figure(Figure figure);

void print_data_of_all_figures(std::vector<Figure> figures);

#endif