#include <iostream>
#include <vector>
using namespace std;

class Paper {
public:
	int dateCode;
	string name;

	Paper(int dateCode, string name) {
		this->dateCode = dateCode;
		this->name = name;
	}
};

class Sign {
public:
	void makeSign(vector<Paper>& signs) {
		sortSigns(signs);

		if (isValid(signs) == false) {
			throw "Invalid dateCode";
		}

		doSign(signs);

	}

	void sortSigns(vector<Paper>& signs)
	{
		for (int y = 0; y < signs.size(); y++) {
			for (int x = y + 1; x < signs.size(); x++) {
				if (signs[y].dateCode > signs[x].dateCode) {
					Paper temp(signs[y].dateCode, signs[y].name);
					signs[y].dateCode = signs[x].dateCode;
					signs[y].name = signs[x].name;
					signs[x].dateCode = temp.dateCode;
					signs[x].name = temp.name;
				}
			}
		}
	}

	bool isValid(vector<Paper>& signs)
	{
		for (Paper tar : signs) {
			if (tar.dateCode > 0 && tar.dateCode < 10) continue;
			return false;
		}
		return true;
	}

	void doSign(vector<Paper>& signs)
	{
		for (Paper tar : signs) {
			cout << tar.dateCode << " : " << tar.name << endl;
		}
	}

};

int main() {
	Sign sign;
	vector<Paper> arr;
	arr.push_back(Paper(5, "KFC"));
	arr.push_back(Paper(1, "JASON"));
	arr.push_back(Paper(2, "LUCKY"));

	try {
		sign.makeSign(arr);
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}

	return 0;
}