#include <cmath>
#include <iostream>
#include <vector>

#include <thethring/display.h>
#include <thethring/polygon.h>

// Display default constructor
display::display(int width, int height) {
	// Set width and height of canvas
	this->width = width;
	this->height = height;

	// Allocate canvas
	rendered_canvas = new bool*[height];
	for (int i = 0; i < height; i++)
		rendered_canvas[i] = new bool[width];
}

// Display polygon constructor
// Constructs display out of given polygons
display::display(int width, int height, std::vector<polygon> polygons) {
	// Do default construction
	display(width, height);

	// Set polygons
	this->polygons = polygons;
}

// Display destructor
// Deallocates canvas
display::~display() {
	// Deallocate canvas
	for (int i = 0; i < height; i++)
		delete [] rendered_canvas[i];
	delete [] rendered_canvas;
}

// Polygon add function
// Adds polygon to display polygon list
void display::add_polygon(polygon p) {
	polygons.push_back(p);
}

// TODO: Enforce non-repeatability and efficiency
// Line render function
// Updates rendered_canvas with line
void display::render_line(point p1, point p2) {
	// Set slope
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	// Set increment direction
	short int x_direction, y_direction;

	// Get line directions
	// Get line x-direction
	if (dy < 0)
		x_direction = 1;
	else
		x_direction = -1;
	// Get line y-direction
	if (dx < 0)
		y_direction = 1;
	else
		y_direction = -1;

	// Render line
	if (dx == 0 && dy == 0) {
		// Render point
		// If the line goes from a point to the same point, it is a point
		rendered_canvas[static_cast<int>(p1.y + 0.5)][static_cast<int>(p1.x + 0.5)] = true;
	} else if (std::abs(dx) > std::abs(dy)) {
		// Render line loop
		// Direction of render is in the x
		for (int i = 0; i <= std::abs(dx); i++) {
			// Get canvas coords
			int cX, cY, j;
			j = i * x_direction;
			cX = j;
			cY = static_cast<int>(j * (dy/dx) + 0.5);

			cX += p1.x;
			cY += p1.y;

			// Fill in spaces on canvas that correspond with line
			// Fill in only if inside bounds
			if (cY < height && cY >= 0)
				if (cX < width && cX >= 0)
					rendered_canvas[cY][cX] = true;
		}
	} else {
		// Render line loop
		// Direction of render is in the y
		for (int i = 0; i <= std::abs(dy); i++) {
			// Get canvas coords
			int cX, cY, j;
			j = i * y_direction;
			cX = static_cast<int>(j * (dx/dy) + 0.5);
			cY = j;

			cX += p1.x;
			cY += p1.y;

			// Fill in spaces on canvas that correspond with line
			if (cY < height && cY >= 0)
				if (cX < width && cX >= 0)
					rendered_canvas[cY][cX] = true;
		}
	}
}

// Render function
// Updates rendered_canvas with polygons
void display::render() {
	// Render all polygons
	for (polygon p : polygons) {
		// Get vertices of polygon
		std::vector<point> vertices = p.get_vertices();

		// Render polygon
		if (vertices.size() > 1) {
			// Render polygon loop
			for (int i = 0; i < vertices.size() - 1; i++) {
				render_line(vertices.at(i), vertices.at(i+1));
			}
		} else if (!vertices.empty()) {
			// Render point
			// If the polygon has only 1 vertice, it is a point
			render_line(vertices.at(0), vertices.at(0));
		}
	}
}

// Clear render function
// Updates rendered_canvas to empty
void display::clear_render() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			rendered_canvas[i][j] = false;
}

// TODO: Add show function
void display::show() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (rendered_canvas[i][j])
				std::cout << "#";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

