#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

int pie() {
    ifstream input;
    ofstream ansFile;
    ansFile.open("output.txt", ios::out);
    const int radius = 50;
    input.open("input1.in", ios::in);
    int T, i = 1, Flag = 0;
    input>>T;
    while(i <= T) {
        int P, x, y;
        double dist;
        input>>P>>x>>y;
        dist = sqrt(pow((x-50),2) + pow((y - 50),2));
//        cout<<dist;
/*        if ( i == 35){
            cout<<P<<"   "<<x<<"    "<<y<<endl;
            cout<<"Hi!";
        }*/
        if(dist <= radius){
            const double pi = 3.145926535897;
            double Angle, perpendicular, hypo, AngleXY;
            Angle = P * 3.6;
            perpendicular = abs(x - 50);
            hypo = dist;
            AngleXY = asin(perpendicular/hypo) * (180/pi);
            if((x >= 50) && (y >= 50)) { //First Quadrant
            //Angle Remains the Same
            }
            else if((y <= 50) && (x >= 50)){ //Second Quadrant
                AngleXY = 180 - AngleXY;
            }
            else if ((x <= 50) && (y <= 50)){ //Third Quadrant
                AngleXY = 180 + AngleXY;
            }
            else{ //Fourth Quadrant
                AngleXY = 360 - AngleXY;
            }
            if(AngleXY <= Angle){
                cout<<"Case #"<<i<<": black"<<endl;
                ansFile<<"Case #"<<i<<": black";
                Flag = 1;
            }
        }
        if(Flag == 0){
            cout<<"Case #"<<i<<": white"<<endl;
            ansFile<<"Case #"<<i<<": white";
        }
        Flag = 0;
        i++;
        if(i <= T){
            ansFile<<endl;
        }
    }
    ansFile.close();
    input.close();
    return 0;
}
