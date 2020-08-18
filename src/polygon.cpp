#include <vector>

#include <thethring/polygon.h>

// Default constructor
polygon::polygon() {
	// Set initial polygon coords
	x = 0;
	y = 0;
}

// Polygon point constructor
// Constructs polygon out of given points
polygon::polygon(std::vector<point> points) {
	polygon();
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

// Move function
// Adds x and y to current position of polygon
void polygon::move(double x, double y) {
	this->x += x;
	this->y += y;
}

// Coord get function
// Get position as point
point polygon::get_coords() {
	point coords = {x, y};
	return coords;
}

