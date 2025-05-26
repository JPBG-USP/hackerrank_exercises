#include <iostream>

using namespace std;

class Rectangle {
    public:
        int width;
        int height;

        Rectangle(){}
        ~Rectangle(){}

        virtual void display() const {
            std::cout << width << " " << height << "\n";
        }
};

class RectangleArea : public Rectangle {
    public:
        void read_input() {
            std::cin >> width >> height;
            if (width <= 0 || height <= 0) {
                width = height = 0;
            }
        }

        void display() const override {
            std::cout << width * height << "\n";
        }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}