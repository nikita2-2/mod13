#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>

#include "Circle.h"
#include "NullRad.h"
#include "InvalidRad.h"

int main() {
    // a) Вектор целых чисел от 10 до 50
    std::vector<int> numbers(41);
    std::iota(numbers.begin(), numbers.end(), 10);

    // b) Вывод всех четных чисел из вектора
    std::cout << "even numbers: ";
    std::for_each(numbers.begin(), numbers.end(),
        [](int num) {
            if (num % 2 == 0) {
                std::cout << num << " ";
            }
        }
    );
    std::cout << std::endl;

    // c) Подсчет суммы всех элементов вектора
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "summ all elements: " << sum << std::endl;

    // d) Умножение каждого элемента вектора на значение переменной factor
    int factor = 3;
    std::transform(numbers.begin(), numbers.end(), numbers.begin(),
        [factor](int num) {
            return num * factor;
        }
    );
    std::cout << "vec * const " << factor << ": ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Работа с исключениями
    std::cout << "input radiuss: ";
    double radius;
    std::cin >> radius;

    Circle circle(radius);

    try {
        double area = circle.calculateArea();
        std::cout << "Circle area: " << area << std::endl;
    }
    catch (const InvalidRadius& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const NullRadius& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
