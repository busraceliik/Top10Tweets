#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 
#include <ctime>
#include <algorithm>
#include "HashBuilder.h"
#include "ExcelParser.h"

using namespace std;

clock_t startTime, endTime;

int main() {

	time_t srand(time(NULL));
	startTime = clock();

	ifstream input;
	string line;

	input.open("C:\\training.1600000.processed.noemoticon.csv", ios::in);

	HashBuilder<string, int> *hashBuilder = new HashBuilder<string, int>;

	ExcelParser excelParser;

	while (input >> line) 
	{

		getline(input, line);

		string tweetContent = excelParser.GetTweetContent(line);

		transform(tweetContent.begin(), tweetContent.end(), tweetContent.begin(), ::tolower);

		string word;

		stringstream iss(tweetContent);

		
		while (iss >> word) 
		{

			hashBuilder->InsertNode(word, 1);
		}
	}

	if (hashBuilder->IsEmpty() == false)
	{
		hashBuilder->DisplayWithQuickSort();
	}

	input.close();
	endTime = clock();

	double diff((double)((float)endTime - (float)startTime) / 1000);
	cout << "\n\n    Total Second : " << diff << "\n\n" << endl;

	system("PAUSE");

	return 0;
}
