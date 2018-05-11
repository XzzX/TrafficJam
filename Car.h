#pragma once

#include <deque>

struct Car
{
    int x = 0; ///< current position
    int v = 0; ///< current velocity

    static const int vmax = 5; ///< maximal velocity, currently the same for all cars

    Car(const int pos, const int vel) : x(pos), v(vel) {}
};

///data container of all cars
///
///This container has to be sorted at all times. back() car wich traveled the farest. first() newest car.
using TrafficLine = std::deque<Car>;

///acclerate all cars by 1
void accelerate(TrafficLine& cars);
///decelerate cars if a collision would be imminent with current velocity
void decelerate(TrafficLine& cars);
///cars dawdle (reduce their speed without any reason) with a certain probability
void dawdle(TrafficLine& cars, const double p = 0.7);
///time integrate the position of all cars
void move(TrafficLine& cars);

///add a car at the beginning of the street with a certain probability if there is no car
void addCar(TrafficLine& cars, const double p = 1.0);
///remove all cars which moved to far
void removeCars(TrafficLine& cars, const int streetLength);
