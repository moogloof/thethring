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
display::display(int width, int height, std::vector<polygon*> polygons) {
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
void display::add_polygon(polygon *p) {
	polygons.push_back(p);
}

// Point render function
// Updates rendered_canvas with point
void display::render_point(int x, int y) {
	// Fill in only if inside bounds
	if (y < height && y >= 0)
		if (x < width && x >= 0)
			rendered_canvas[y][x] = true;
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
		y_direction = 1;
	else
		y_direction = -1;
	// Get line y-direction
	if (dx < 0)
		x_direction = 1;
	else
		x_direction = -1;

	// Render line
	if (dx == 0 && dy == 0) {
		// Render point
		// If the line goes from a point to the same point, it is a point
		render_point(std::round(p1.x), std::round(p1.y));
	} else if (std::abs(dx) > std::abs(dy)) {
		// Render line loop
		// Direction of render is in the x
		for (int i = 0; i <= std::abs(dx); i++) {
			// Get canvas coords
			double cX, cY, j;
			j = i * x_direction;
			cX = j;
			cY = j * (dy/dx);

			cX += p1.x;
			cY += p1.y;

			cX = std::round(cX);
			cY = std::round(cY);

			// Fill in spaces on canvas that correspond with line
			render_point(static_cast<int>(cX), static_cast<int>(cY));
		}
	} else {
		// Render line loop
		// Direction of render is in the y
		for (int i = 0; i <= std::abs(dy); i++) {
			// Get canvas coords
			double cX, cY, j;
			j = i * y_direction;
			cX = j * (dx/dy);
			cY = j;

			cX += p1.x;
			cY += p1.y;

			cX = std::round(cX);
			cY = std::round(cY);

			// Fill in spaces on canvas that correspond with line
			render_point(static_cast<int>(cX), static_cast<int>(cY));
		}
	}
}

// Render function
// Updates rendered_canvas with polygons
void display::render() {
	// Render all polygons
	for (polygon *p : polygons) {
		// Get vertices of polygon
		std::vector<point> vertices = p->get_vertices();
		// Get relative coord of polygon
		point relative_coord = p->get_coords();

		// Render polygon
		if (vertices.size() > 1) {
			// Render polygon loop
			for (int i = 0; i < vertices.size() - 1; i++) {
				// Add relative coords
				point vertice1 = vertices.at(i);
				point vertice2 = vertices.at(i+1);

				vertice1.x += relative_coord.x;
				vertice1.y += relative_coord.y;
				vertice2.x += relative_coord.x;
				vertice2.y += relative_coord.y;

				// Render side of polygon as line
				render_line(vertice1, vertice2);
			}
		} else if (!vertices.empty()) {
			// Render point
			// Add relative coords
			point vertice = vertices.at(0);

			vertice.x += relative_coord.x;
			vertice.y += relative_coord.y;

			// If the polygon has only 1 vertice, it is a point
			render_line(vertice, vertice);
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

// Show render function
// Displays rendered_canvas to console
void display::show() {
	// Clear screen
	std::cout << "\033[2J\033[1;1H";

	// Display canvas loop
	for (int i = 0; i < height; i++) {
		// Display canvas row loop
		for (int j = 0; j < width; j++) {
			// Print canvas spot state
			if (rendered_canvas[i][j])
				// Print filled in
				std::cout << "#";
			else
				// Print empty
				std::cout << " ";
		}
		// Print newline
		std::cout << std::endl;
	}
}

