#include "Car.h"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>

const int Car::vmax;

void accelerate(TrafficLine& cars)
{
   std::for_each(cars.begin(), cars.end(), [](Car& car){ car.v = std::min(car.v + 1, car.vmax);} );
}
void decelerate(TrafficLine& cars)
{
   if (cars.empty()) return;
   for (auto carIt = cars.rbegin() + 1; carIt!=cars.rend(); ++carIt)
   {
      auto d = (carIt - 1)->x + (carIt - 1)->v - carIt->x;
      if (d <= carIt->v)
      {
         carIt->v = std::min(d-1, carIt->vmax);
      }
   }
}
void dawdle(TrafficLine& cars, const double p)
{
   static std::default_random_engine generator( std::chrono::system_clock::now().time_since_epoch().count() );
   std::uniform_real_distribution<double> distribution(0.0,1.0);
   std::for_each(cars.begin(), cars.end(), [&](Car& car){ if (distribution(generator) < p) car.v = std::max(car.v - 1, 0); } );
}
void move(TrafficLine& cars)
{
   std::for_each(cars.begin(), cars.end(), [](Car& car){ car.x = car.x + car.v;} );
}

void addCar(TrafficLine& cars, const double p)
{
   static std::default_random_engine generator( std::chrono::system_clock::now().time_since_epoch().count() );
   std::uniform_real_distribution<double> distribution(0.0,1.0);
   if (!cars.empty() && (cars.front().x == 0)) return;
   if (distribution(generator) < p)
   {
      cars.emplace_front(0, Car::vmax);
   }

}
void removeCars(TrafficLine& cars, const int streetLength)
{
   assert(streetLength > 0);
   while (!cars.empty() && cars.back().x >= streetLength)
   {
      cars.pop_back();
   }
}
