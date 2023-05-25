#include <vector>

using namespace std;

class EvenOdd
{
public:
	vector<char> TranslateEvenOdd(vector<int> numbers)
	{
		vector<char> result;
		for (int i = 0; i < numbers.size(); i++)
			result.push_back(numbers[i] & 1 ? 'X' : 'O');

		return result;
	}
};