#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>
class InvalidRadius : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error radius.";
    }
};

