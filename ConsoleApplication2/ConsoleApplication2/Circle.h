#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>
#include "InvalidRad.h"
#include "NullRad.h"
class Circle {
private:
    double radius;

public:
    // ???????????
    Circle(double radius) : radius(radius) {}

    // ??????? ??? ?????????? ???????
    double calculateArea() {
        if (radius < 0) {
            throw InvalidRadius();
        }
        else if (radius == 0) {
            throw NullRadius();
        }
        else {
            return M_PI * pow(radius, 2);
        }
    }
};