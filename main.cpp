#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> r;
vector<int> x;
vector<int> y;
vector<float> s;
vector<float> per;

int main()
{

    while (1) {
        bool InputCorrect = 0;
        cout << "USE FORMAT UNDER LINE\n---------------\n figure(x.y,r)\n";
       while(!InputCorrect){
           string input;
           cin >> input;
           if("circle" == input.substr(0 , input.find_first_of("("))) {
               int xx = atoi(input.substr(input.find_first_of("(") + 1, input.find_first_of(" ") - 1).c_str());
               x.push_back(xx);
               int yy = atoi(input.substr(input.find_first_of(".") + 1, input.find_first_of(",") - 1).c_str());
               y.push_back(yy);
                int rad = atoi(input.substr(input.find_first_of(",") + 1, input.find_last_of(")") - 1).c_str());
                r.push_back(rad);
           }
           else continue;
       }

    }
    return 0;
}
