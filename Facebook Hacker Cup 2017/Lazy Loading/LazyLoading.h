#include <iostream>
#include <algorithm>
#include <fstream>
#include <deque>

using namespace std;

int lazy(){
//    cout<<"Hi!"<<endl;
    ifstream input;
    ofstream ansFile;
    ansFile.open("output2.txt",ios::out);
    input.open("input2.in", ios::in);
    int T, j = 1;
    input>>T;
    while(j <= T){
//        cout<<"In Main Loop"<<endl;
        int Trips = 0, N;
        input>>N;
        deque<int> weights;
        for( int i = 0; i< N; i++){
            int temp;
            input>>temp;
//            cout<<temp<<endl;
            weights.push_back(temp);
        }
//        cout<<"Fetched Elements for the Day"<<endl;
        sort(weights.begin(), weights.end());
        int Flag = 1;
        while(Flag == 1){
            if(weights.size() == 0){
                break;
            }
            int max;
            max = weights.back();
            int i;
            for(i = 1; i <= N; i++){
                int out;
                out = max * i;
//                cout<<"Value of "<<max<<" * "<<i<<" = "<< out<<endl;
                if(out >= 50){ //50 is Weight required per trip
                    break;
                }
            }
            unsigned int toPop;
            toPop = i;
//            cout<<"To pop : "<<toPop<<" and size : "<<weights.size()<<endl;
            if(toPop > weights.size()){
                Flag = -1;
//                cout<<"Calculated Trips for the Day : "<<Trips<<endl;
            }
            else{
//                cout<<"to pop : "<<toPop<<" Size : "<< weights.size()<< endl;
                weights.pop_back();
//                cout<<"popped!"<<endl;
                if (toPop != 1){
                    for(unsigned int k = 1; k < toPop; k++){
                        weights.pop_front();
                    }
//                cout<<"out of loop"<<endl;
                }
                Trips++;
//                cout<<"Trips added "<<endl;
            }
        }
        cout<<"Case #"<<j<<": "<<Trips;
        ansFile<<"Case #"<<j<<": "<<Trips;
        j++;
        if(j <= T){
            cout<<endl;
            ansFile<<endl;
        }
    }
    return 0;
}
