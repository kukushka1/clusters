#include "../include/point.h"

point::point() : x_coord(0), y_coord(0), label(0) {} // default contructor

point::point(double x, double y) : x_coord(x), y_coord(y), label(0) {	} // Initialize fields with passed parameters

point::point(double x, double y, int label) : x_coord(x), y_coord(y), label(label) {	}

point::point(const point &other)   // Copy constructor
{
    this->x_coord = other.x_coord;
    this->y_coord = other.y_coord;
    this->label = other.label;
}

double point::get_x() const
{
    return this->x_coord;
}

double point::get_y() const
{
    return this->y_coord;
}

int point::get_label() const
{
    return this->label;
}

void point::set_x(double x)
{
    this->x_coord = x;
}

void point::set_y(double y)
{
    this->y_coord = y;
}

void point::set_label(int l)
{
    this->label = l;
}

void point::add_x(double x)
{
    this->x_coord += x;
}

void point::add_y(double y)
{
    this->y_coord += y;
}
