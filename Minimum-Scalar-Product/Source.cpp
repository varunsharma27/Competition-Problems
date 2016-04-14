// Code_Jam.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
#include <algorithm>

using namespace std;

struct greater
{
	template<class T>
	bool operator()(T const &a, T const &b) const { return a > b; }
};

int main(){
	int t, n;
	ifstream myfile("Input.in");
	ofstream output("Output.in");
	myfile >> t;
	cout << t;
	for (int i = 1; i <= t; i ++ ){
		myfile >> n;
		vector<long long int> v1(n), v2(n);
		__int64  sum = 0;
		for (int j = 0; j < n; j++){
			myfile >> v1[j];
		}
		for (int j = 0; j < n; j++){
			myfile >> v2[j];
		}
		long long int temp;
		std::sort(v1.begin(), v1.end(), greater());
		std::sort(v2.begin(), v2.end());
		for (int j = 0; j < n; j++){
			temp = v1[j] * v2[j];
			sum += temp;
			/*cout<< temp<<" + ";*/

		}
		//cout << " = " << sum;
		output << "Case #" << i << ": " << sum << endl;
	}


	//_getch();
	return 0;
}
