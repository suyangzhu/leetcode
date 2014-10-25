#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unordered_map>

#define EPSILON 0.000001

using namespace std;

static double abs(double x) {
	return x > 0? x:-x;
}

static bool IsEqual(double x, double y) {
	return abs(x - y) < EPSILON;
}

class Point {
public:
	Point(){}
	~Point() {}
	Point(double x, double y) : x(x), y(y) {}
	double GetX() {
		return x;
	}
	double GetY() {
		return y;
	}
	Point& operator=(Point &other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}
private:
	double x;
	double y;
};

class Rectangle {
public:
	Rectangle() {}
	~Rectangle() {}
	Rectangle(Point middle, int length, int height) : middle(middle), length(length), height(height) {}
       	Point GetMiddle() {
		return middle;
	}	
	int GetLength() {
		return length;
	}
	int GetHeight() {
		return height;
	}
private:
	Point middle;
	int length;	
	int height;
};

class Line {
public:
	Line() {}
	~Line() {}
	Line(double slope, double intercept) : slope(slope), intercept(intercept), infiniteSlop(false) {}
	Line(Point &p1, Point &p2) {
		if (abs(p1.GetX() - p2.GetX()) < EPSILON) {
			infiniteSlop = true;
			slope = 0;
			intercept = p1.GetX();
		} else {
			infiniteSlop = false;
			slope = ((p1.GetY() - p2.GetY()) / (p1.GetX() - p2.GetX()));
			intercept = p1.GetY() - slope * p1.GetX();
		}
	}
	bool operator==(Line &other) {
		if (this == &other) return true;
		return infiniteSlop == other.infiniteSlop &&
		       IsEqual(slope, other.slope) &&
		       IsEqual(intercept, other.intercept);
	}

	double GetSlope() const {
		return slope;
	}

	double GetIntercept() const {
		return intercept;
	}
private:
	bool infiniteSlop;
	double slope;
	double intercept;
};

namespace std {
	template<>
	struct hash<Line> {
		typedef Line argument_type;
		typedef std::size_t result_type;
		result_type operator()(argument_type const& line) const {
			int s = (int)(line.GetSlope() * 1000);
			int in = (int) (line.GetIntercept()*1000);
			return s | in;
		}
	};
}

int MaxPointOnSameLine(vector<Point> &pointSet) {
	unordered_map<Line, int> lineMap;
	for (int i = 0; i < pointSet.size(); i++) {
		for (int j = i; j < pointSet.size(); j++) {
			Line line(pointSet[i], pointSet[j]);
			if (lineMap.count(line) > 0) {
			} else {
			}
		}
	}
	int maxCnt = -1;
	for (unordered_map<Line, int>::iterator it = lineMap.begin(); it != lineMap.end(); it++) {
		maxCnt = (maxCnt > it->second? maxCnt:it->second);
	}
	return maxCnt;
}

int main() {
	Point *point1 = new Point(1, 1);
//	Point point1(1,1);
	Rectangle *rec = new Rectangle(*point1, 2, 2);
	Point point2 = rec->GetMiddle();
	std::cout << point2.GetX() <<  " " << point2.GetY() << std::endl;
	Point *point3 = new Point(1.00000000001, 2);
	Line *line1 = new Line(*point1, *point3);
	std::cout << "slope " << line1->GetSlope() << " intercept " << line1->GetIntercept() << std::endl; 
	return 0;
}
	
