#include "../include/Wave.h"

Wave::Wave(field& field) : field_for_search(field.get_cloud_arr()), unchecked_points_count(field_for_search.size()) { }

void Wave::find(const double EPS) {
    while (unchecked_points_count) {
        for (point& i : field_for_search) {
            if (i.get_label() == 0) {
                find_neighbours(i, EPS);
                while (!points_queue.empty()) {
                    point temp = points_queue.front();
                    points_queue.pop();
                    find_neighbours(temp, EPS);
                }
                write_to_final_field();
            }
        }
    }
}

void Wave::write_to_final_field() {
    for (point& i : field_for_search) {
        if (i.get_label() == 2) {
            i.set_label(label_for_marking);
            final_field.push_back(i);
        }
    }
    ++label_for_marking;
}

void Wave::find_neighbours(point& start_point, const double EPS) {
    for (point& i : field_for_search) {
        if (i.get_label() < 2) {
            double distance = sqrt(pow(i.get_x() - start_point.get_x(), 2) + pow(i.get_y() - start_point.get_y(), 2));
            if (distance < EPS) {
                if (distance == 0) {
                    i.set_label(2);
                    --unchecked_points_count;
                }
                if (i.get_label() == 0) {
                    i.set_label(1);
                    points_queue.push(i);
                }
            }
        }
    }
}

vector<point>& Wave::get_final_field() {
    return final_field;
}