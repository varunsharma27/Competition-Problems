#include <stdio.h>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

int returnMax(int arr[][3]){
    // Returns a 2 digit integer :- [row + 1][coumn]
    int rowColumn;
    int max;
    max = arr[0][0];
    rowColumn = 10;
    for (int i = 0; i<3; i++){
        for (int j = 0; j < 3; j++){
            if (max < arr[i][j]){
                max = arr[i][j];
                rowColumn = ((i + 1) * 10) + j;
            }
        }
    }
    return rowColumn;
}

int main(int argc, char** argv){
    ifstream input;
    input.open("team.in", ios::in);
    int arr[3][3];
    //Read from file
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            input>>arr[i][j];
        }
    }
    input.close();
    //Calculate value of a, b and c
    int count = 0, ans[] = {-1, -1, -1};
    while (count != 3){
        int loc, r, c;
        loc = returnMax(arr);
        c = loc % 10;
        loc = loc/10;
        r = (loc % 10) - 1;
        if (ans[c] == -1){
            ans[c] = arr[r][c];
            //Now disqualify entire row(The person) for further rounds
            arr[r][0] = -1;
            arr[r][1] = -1;
            arr[r][2] = -1;
            count++;
            continue;
        }
        else{ //Disqualify the current column (Position) as its already taken
            arr[r][c] = -1;
            continue;
        }
    }
    //calculate efficiency
    long double value;
    int ax, bx, cx;
    ax = ans[0];
    bx = ans[1];
    cx = ans[2];
    value = sqrt((ax * ax) + (bx * bx) + (cx * cx));
    //Write to file
    ofstream write;
    write.open("team.out", ios::out);
    write<<setprecision(30)<<value;
    
    return 0;
}
