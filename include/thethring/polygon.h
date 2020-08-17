#include <vector>

#ifndef POLYGON_H
#define POLYGON_H

struct point {
	double x;
	double y;
};

class polygon {
	private:
		std::vector<point> vertices;
	public:
		polygon();
		polygon(std::vector<point>);
		void add_point(point);
		std::vector<point> get_vertices();
};

#endif

