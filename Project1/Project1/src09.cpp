#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Sort
{
public:
	virtual void sort(vector<int>& arr) = 0;
};

class BubbleSort : public Sort
{
	void sort(vector<int>& arr) override
	{
		for (int a = 0; a < arr.size(); a++)
		{
			for (int b = 0; b < arr.size() - 1 - a; b++)
			{
				if (arr[b] > arr[b + 1])
				{
					std::swap(arr[b], arr[b + 1]);
				}
			}
		}
	}
};

class SelectionSort : public Sort
{
	void sort(vector<int>& arr) override
	{
		for (int a = 0; a < arr.size(); a++)
		{
			for (int b = a + 1; b < arr.size(); b++)
			{
				if (arr[a] > arr[b])
				{
					std::swap(arr[a], arr[b]);
				}
			}
		}
	}
};


class SortMachine
{
public:
	void insert(int val)
	{
		arr.push_back(val);
	}
	void select(string name)
	{
		if (mSort != nullptr)
		{
			delete mSort;
			mSort = nullptr;
		}
		mSort = createSort(name);

	}
	void run()
	{
		if (mSort == nullptr) return;
		mSort->sort(arr);
	}
	void show()
	{
		for (const int& val : arr)
		{
			cout << val << " ";
		}
		cout << endl;
	}


private:
	// 팩토리 패턴 
	// 가상 생성자. 한층더 추상화된 생성자
	// 생성자들을 모아서 관리할 수 있다. 
	Sort* createSort(string name)
	{
		if (name == "bubbleSort")
		{
			return new BubbleSort();
		}
		if (name == "selectionSort")
		{
			return new SelectionSort();
		}

		return nullptr; // nullptr 
	}


private:
	vector<int> arr;
	Sort* mSort;
};


int main()
{
	SortMachine* mixer = new SortMachine();
	mixer->insert(3);
	mixer->insert(1);
	mixer->insert(5);
	mixer->insert(9);
	mixer->insert(1);

	mixer->select("selectionSort");
	mixer->run();
	mixer->show();

	return 0;
}