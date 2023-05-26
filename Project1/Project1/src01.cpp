#include<iostream>
#include<vector>
using namespace std;

void elapseOneDay(vector<int>& numberOfDaysRemaining) {
	const int EMPTY = 0;
	for (int roomNumber = 0; roomNumber < numberOfDaysRemaining.size(); roomNumber++) {
		if (numberOfDaysRemaining[roomNumber] == EMPTY)
		{
			continue;
		}
		numberOfDaysRemaining[roomNumber] = numberOfDaysRemaining[roomNumber] - 1;
	}
}


int main()
{


	return 0;
}