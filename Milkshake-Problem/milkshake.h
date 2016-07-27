#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ofstream ansFile;

void displayAnswer(vector<int> answer, int tcase){
	ansFile<<"Case #"<<(tcase+1)<<": ";
	for(int i = 0; i < answer.size(); i++){
		ansFile<<answer.at(i)<<" ";
	}
	ansFile<<endl;
}

int checkSatisfy(vector<int> customerX, vector<int> customerY, vector<int> answer){ // customerX takes flavor, customerY takes malted or unmalted
//	cout<<"Inside Function.";
//	cin.ignore();
	for(int i = 0; i< customerX.size(); i++){
//		cout<<"In for loop iteration no : "<<i;
//		cin.ignore();
//		cout<<"\nIn iteration : "<<i<<" Value of Y : "<<customerY.at(i)<<" Value at answer : "<<answer.at(customerX.at(i) - 1);
		if((customerY.at(i) == 0) && (answer.at(customerX.at(i) - 1) == 0)) // if value is unmalted and the value of the same flavor(Told by customerX) at answer is +ve (unmalted)
			return 0; //This customer is Satisfied.
		else if((customerY.at(i) == 1) && (answer.at(customerX.at(i) - 1) == 1)) // Malted satisfibility.
			return 0;
//		cout<<"\nThis iteration not satisfied!\n";
	}
//	cout<<"Returning -1\n";
	return -1; //unSatisfied
}

int milk()
{
	ansFile.open("myAnswerLarge.txt", ios::app);
	ifstream input;
	//ofstream op;
	input.open("B-large-practice.in", ios::in);
	//op.open("Test.vs", ios::out);
	int C, i = 0, N, M, T, j = 0, k = 0,testCase = 0;
	int Impossible = 0; //Just used to stop printing answer in case of impossible.
	input>>C; // C contains the Number of Test Cases.
	//op<<"Number of test cases are : "<<C<<endl;
	while(C > testCase) // Runs per test case.
	{
//		cout<<"\n\nTest number : "<<testCase<<"\n\n";
		vector <vector<int> > X, Y;
		vector <int> noFlavor; //Number of flavours a customer likes 
		// X is the vector of vector having the list of milkshake types and
		// Y is the vector of vector of unmalted (0) or malted (1) corresponding to X.
		input>>N;
		// N is Total number of Milkshake flavors.
	//	op<<"Total number of flavors in "<<testCase<<" Case : "<<N<<endl;
		input>>M;
		// M takes the number of Customers in a Test Case.
	//	op<<"\n-----\nNumber of Customers : "<<M<<endl;
		while(M > j){ // Runs for each customer in a single test case.
			vector<int> tempX,tempY;
			input>>T;
	//		op<<"\nNo. of Milkshake Types "<<j<<" Likes : "<<T<<endl<<"Type: | Malted?\n";
			noFlavor.push_back(T);
			// T takes number of Milkshake Types a customer likes.
			while(T > k){ // Runs for a single customer, to fetch his likes.
				int temp;
				input>>temp;
	//			op<<temp;
				tempX.push_back(temp); // Fill in Milkshake Type
				input>>temp;
	//			op<<"       "<<temp<<endl;
				tempY.push_back(temp); // Fill in Malted (1) or unMalted (0)
				k++;
			}
			X.push_back(tempX); // Fills in the vector of a single customer.
			Y.push_back(tempY);
			k = 0;
			j++;
		}
		vector<int> answer; //3 means Type 3 is unmalted and -3 means it is malted.
		for(int i = 0; i < N; i++) // Initializes all as unmalted.
		{
			answer.push_back(0);
		}
		int weight = 0, satisfy,foundAt;
		vector<int> satisfied;
		vector<int>::iterator findMalt,findSatisfy;
		i = 0;
		while(i<M){
//			cout<<"Entered While for customer number : "<<i;
//			cin.ignore();
			findSatisfy = find(satisfied.begin(),satisfied.end(),i); // Check the satisfied list.
//			cout<<"Entered Check for Satisfy.";
//			cin.ignore();
			if (findSatisfy == satisfied.end()){ //If the customer is not in satisfied list.
//				cout<<"Customer is not in Satisfied list yet.";
//				cin.ignore();
				satisfy = checkSatisfy(X.at(i), Y.at(i), answer); // Check if he is satisfied with present answer.
//				cout<<"Successfully Executed Function!";
//				cin.ignore();
				if (satisfy == 0){
					i++;
//					cout<<"Passed Check for Satisfaction.";
//					cin.ignore();
					continue; //Skips the rest of this iteration
				}
//				cout<<"Failed Satisfaction... Finding Malt.";
//				cin.ignore();
				findMalt = find(Y.at(i).begin(),Y.at(i).end(),1); // Only accessed if customer is not satisfied. Checks if he has a Malted flavor in his liking.
				if (findMalt != Y.at(i).end()){ // If found a Malted.
					foundAt = (findMalt - Y.at(i).begin()); // Location in Y vector,
//					cout<<"Malt found at : "<<foundAt;
//					cin.ignore();
					answer.at(X.at(i).at(foundAt) - 1) = 1; // X.at(foundAt) tells the flavor number of the found Malted favorite 
					//and this statement change our answer to malted for that flavor.
//					cout<<"Changed Answer\n";
//					displayAnswer(answer);
					satisfied.push_back(i); // Add him to satisfied list
					i = 0; //Now back validate every customer.
				}
				else if (findMalt == Y.at(i).end()){ // No malted flavor found.
					ansFile<<"Case #"<<(testCase+1)<<": IMPOSSIBLE ";
					ansFile<<endl;
					Impossible = -1;
					i = M; //To exit Loop.
				}
			}
			else{ //If customer is already in Satisfied list, i.e. - He caused a change to Malted.
				i++;
			}
		}
		if(Impossible == 0){
			displayAnswer(answer,testCase);
		}
		//Reset for next iteration and increment.
		Impossible = 0;
		j = 0;
		testCase++;
	}
	ansFile.close();
	return 0;
}