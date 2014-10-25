class Line {
public:
	static double epsilon;
	// under
	double slope;
	double yIntercept;
	bool IsIntersect(Line &line2) {
		if (this == &line2) return true;
		return abs(slope - line2.slope) > epsilon || 
		       abs(yIntercept - line2.yIntercept) < epsilon;
	}

};
