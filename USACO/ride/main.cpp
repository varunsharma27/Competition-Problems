/*
ID: varundb1
LANG: C++
TASK: ride
*/
#include <fstream>
#include <iostream>
using namespace std;

int calc(string str)
{
	int i = 0, ans=1;
	while( i < str.length()){
		ans *= (int(str.at(i)) - 64);
		i++;
	}
	ans = ans%47;
	return ans;
}

int main2()
{
	ifstream rd;
	ofstream create;
	rd.open("ride.in", ios::in );
	ofstream wr;
	wr.open("ride.out", ios::out);
	int c = 0, n = 0;
	string com, name;
	while(getline(rd,com))
	{
		cout<<"first loop";
		getline(rd,name);
		if (calc(com) == calc (name)){
			wr<<"GO"<<endl;
		}
		else{
			wr<<"STAY"<<endl;
		}
	}
	rd.close();
	wr.close();
	return 0;
}
