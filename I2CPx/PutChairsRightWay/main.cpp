#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv){
    
    ifstream input;
    input.open("chairs.in", ios::in);
    int a, b, c;
    input>>a>>b>>c;
    input.close();
    double ans;
    cout<<fixed<<showpoint;
    cout<<setprecision(30);
    ans = ((double)(a + b+ c)/2)/3;
    
    ofstream output;
    output.open("chairs.out", ios::out);
    output<<setprecision(30)<<ans;
    cout<<ans;
    output.close();
    
    return 0;
}
