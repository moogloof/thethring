#include <cstdlib>
#include <iostream>
#include <stdio.h>

#include <thethring/polygon.h>
#include <thethring/display.h>

int main() {
	// Setup polygons and screen
	// Declare displayer
	display screen(64, 64);
	// Declare polygons
	polygon face;
	polygon smile;
	polygon eye1, eye2;
	// Declare running flag
	bool running = true;

	// Face points
	point face_p1 = {12, 13}, face_p2 = {47, 7}, face_p3 = {51, 43}, face_p4 = {9, 40};
	face.add_point(face_p1);
	face.add_point(face_p2);
	face.add_point(face_p3);
	face.add_point(face_p4);
	face.add_point(face_p1);

	// Smile points
	point smile_p1 = {18, 29}, smile_p2 = {26, 35}, smile_p3 = {36, 35}, smile_p4 = {44, 28};
	smile.add_point(smile_p1);
	smile.add_point(smile_p2);
	smile.add_point(smile_p3);
	smile.add_point(smile_p4);

	// Eye points
	point eye1_p1 = {18, 19}, eye1_p2 = {25, 18}, eye2_p1 = {35, 18}, eye2_p2 = {43, 19};
	eye1.add_point(eye1_p1);
	eye1.add_point(eye1_p2);
	eye2.add_point(eye2_p1);
	eye2.add_point(eye2_p2);

	// Add polygons for rendering
	screen.add_polygon(&face);
	screen.add_polygon(&smile);
	screen.add_polygon(&eye1);
	screen.add_polygon(&eye2);

	while (running) {
		// Render and display
		std::system("stty cooked");
		screen.clear_render();
		screen.render();
		screen.show();

		std::system("stty raw");
		// Wait for wasd keys to maneuver
		switch (getchar()) {
			case 'w':
				face.move(0, -1);
				smile.move(0, -1);
				eye1.move(0, -1);
				eye2.move(0, -1);
				break;
			case 'a':
				face.move(-1, 0);
				smile.move(-1, 0);
				eye1.move(-1, 0);
				eye2.move(-1, 0);
				break;
			case 's':
				face.move(0, 1);
				smile.move(0, 1);
				eye1.move(0, 1);
				eye2.move(0, 1);
				break;
			case 'd':
				face.move(1, 0);
				smile.move(1, 0);
				eye1.move(1, 0);
				eye2.move(1, 0);
				break;
			case 'q':
				running = false;
				break;
			default:
				break;
		}
	}

	std::system("stty cooked");

	return 0;
}

