#pragma once

#include <deque>

struct Car
{
    int x = 0; ///< current position
    int v = 0; ///< current velocity

    static const int vmax = 5; ///< maximal velocity, currently the same for all cars

    Car(const int pos, const int vel) : x(pos), v(vel) {}
};

using TrafficLine = std::deque<Car>;


void accelerate(TrafficLine& cars);
void decelerate(TrafficLine& cars);
void dawdle(TrafficLine& cars, const double p = 0.7);
void move(TrafficLine& cars);

void addCar(TrafficLine& cars, const double p = 1.0);
void removeCars(TrafficLine& cars, const int streetLength);
