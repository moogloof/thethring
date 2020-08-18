#include <vector>

#include <thethring/polygon.h>

#ifndef DISPLAY_H
#define DISPLAY_H

class display {
	private:
		std::vector<polygon*> polygons;
		int width, height;
		bool **rendered_canvas;
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

