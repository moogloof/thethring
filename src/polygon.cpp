#include <vector>

#include <thethring/polygon.h>

// Empty default constructor
polygon::polygon() {}

// Polygon point constructor
// Constructs polygon out of given points
polygon::polygon(std::vector<point> points) {
	vertices = points;
}

// Point add function
// Adds point to polygon point list
void polygon::add_point(point p) {
	vertices.push_back(p);
}

// Vertices get function
// Gets vertices
std::vector<point> polygon::get_vertices() {
	return vertices;
}

