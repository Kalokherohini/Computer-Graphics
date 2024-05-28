#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Pixel class
class Pixel {
public:
    int x, y, color;
    Pixel(int x = 0, int y = 0, int color = WHITE) : x(x), y(y), color(color) {}

    void draw() {
        putpixel(x, y, color);
    }
};

// Circle class inherits Pixel class
class Circle : public Pixel {
public:
    int radius;

    Circle(int x, int y, int radius, int color = WHITE) : Pixel(x, y, color), radius(radius) {}

    void drawDDA() {
        int x = radius;
        int y = 0;
        int p = 1 - radius;

        while (x > y) {
            y++;
            if (p <= 0) {
                p = p + 2 * y + 1;
            } else {
                x--;
                p = p + 2 * y - 2 * x + 1;
            }
            if (x < y)
                break;

            drawSymmetricPoints(x, y);
            if (x != y) {
                drawSymmetricPoints(y, x);
            }
        }
    }

    void drawBresenham() {
        int x = 0;
        int y = radius;
        int d = 3 - 2 * radius;
        drawSymmetricPoints(x, y);
        while (y >= x) {
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }
            drawSymmetricPoints(x, y);
        }
    }

private:
    void drawSymmetricPoints(int x, int y) {
        putpixel(this->x + x, this->y + y, color);
        putpixel(this->x - x, this->y + y, color);
        putpixel(this->x + x, this->y - y, color);
        putpixel(this->x - x, this->y - y, color);
        putpixel(this->x + y, this->y + x, color);
        putpixel(this->x - y, this->y + x, color);
        putpixel(this->x + y, this->y - x, color);
        putpixel(this->x - y, this->y - x, color);
    }
};

// Main function to initialize graphics and draw circles
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Circle circle1(200, 200, 100);
    circle1.drawDDA();

    Circle circle2(400, 200, 100);
    circle2.drawBresenham();

    getch();
    closegraph();
    return 0;
}

