#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>

#include <thethring/polygon.h>

class display {
	private:
		std::vector<polygon*> polygons;
		int width, height;
		bool **rendered_canvas;
		void render_point(int, int);
		void render_line(point, point);
	public:
		display(int, int);
		display(int, int, std::vector<polygon*>);
		~display();
		void add_polygon(polygon *);
		void render();
		void clear_render();
		void show();
};

#endif

