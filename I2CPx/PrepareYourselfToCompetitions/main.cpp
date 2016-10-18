#include <stdio.h>
#include <fstream>

using namespace std;

int checkExist(char* array,int size, char c){
    /*
     * Zero is doesnt exist, returns location + 1 if exist.
     */
    for (int i = 0; i< size; i++){
        if(array[i] == c){
            return i + 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    ifstream input;
    input.open("prepare.in", ios::in);
    int n;
    input>>n;
    int* practical, *theory, *diff;
    char* answer;
    
    practical = new int[n];
    theory = new int[n];
    answer = new char[n];
    diff = new int[n];
    
    for(int i = 0; i <n; i++){
        input>>practical[i];
    }
    for(int i = 0; i <n; i++){
        input>>theory[i];
        diff[i] = practical[i] - theory[i]; // Negative when Theory has higher value. Zero when equals.
        if (diff[i] > 0){
            answer[i] = 'P';
        }
        else if (diff[i] < 0){
            answer[i] = 'T';
        }
        else{
            answer[i] = 'X';
        }
    }
    input.close();
    //Check for Practical
    if (!checkExist(answer, n, 'P')){
        int loc, FLAG = 0;
        loc = checkExist(answer, n, 'X');
        if(loc){
            answer[loc - 1] = 'P';
            FLAG = 1;
        }
        if(FLAG == 0){
            int replace, maxNeg = -9999;
            for(int i = 0; i < n; i++){
                if(maxNeg < diff[i]){
                    maxNeg = diff[i];
                    replace = i;
                }
            }
            answer[replace] = 'P';
        }
    }
    //Check for Theory
    if (!checkExist(answer, n, 'T')){
        int loc, FLAG = 0;
        loc = checkExist(answer, n, 'X');
        if(loc){
            answer[loc - 1] = 'T';
            FLAG = 1;
        }
        if(FLAG == 0){
            int replace, minPos = 9999;
            for(int i = 0; i < n; i++){
                if(minPos > diff[i]){
                    minPos = diff[i];
                    replace = i;
                }
            }
            answer[replace] = 'T';
        }
    }
    //Replace all X and calculate O/P
    int output = 0;
    for (int i = 0; i < n; i++){
        if (answer[i] == 'X'){
            answer[i] = 'P';
        }
        if (answer[i] == 'P'){
            output += practical[i];
        }
        else{
            output += theory[i];
        }
    }
    ofstream op;
    op.open("prepare.out", ios::out);
    op<<output;
    op.close();
    
	return 0;
}
