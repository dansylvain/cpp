#include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		// Constructors & destructors
		Point();
		Point(const float x, const float y);
		Point(const Point& src);
		~Point();
		
		// assignment operator
		Point& operator=(const Point& src);

		// others...
};
