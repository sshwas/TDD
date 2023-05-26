#include<iostream>
#include<vector>
using namespace std;

struct Point2D {
	int x;
	int y;
};

class Canvas {
public:
	void addPoint(Point2D point) {
		mPoints.push_back(point);
	}

	void drawPoint() {
		for (Point2D point : mPoints) {
			cout << point.x << " " << point.y << endl;
		}
	}

private:
	vector<Point2D> mPoints;

};


int main()
{


	return 0;
}