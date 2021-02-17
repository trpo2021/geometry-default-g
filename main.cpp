#include <iostream>
#include <vector>

using namespace std;
vector<int> r;
vector<int> x;
vector<int> y;
vector<float> s;
vector<float> per;

int main()
{
    cout << "Enter 0 for radius to stop entering circles" << endl;
    int i = 1;
    while (1) {
        cout << "Circle #" << i++ << endl;
        cout << "Enter radius" << endl;
        int radius = 0;
        cin >> radius;
        if (radius == 0)
            break;
        r.push_back(radius);
        cout << "Enter X coordinate: ";
        int xx = 0;
        cin >> xx;
        x.push_back(xx);
        cout << "Enter Y coordinate: ";
        int yy = 0;
        cin >> yy;
        y.push_back(yy);
    }
    return 0;
}
