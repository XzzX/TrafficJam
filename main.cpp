#include "Car.h"

#include "lodepng/lodepng.h"

#include <iostream>
#include <vector>

const int streetLength = 500;
const int timesteps = 500;

int main()
{
   TrafficLine tl;

   std::vector<unsigned char> image(streetLength * timesteps, 255);
   for (int timestep = 0; timestep < timesteps; ++timestep)
   {
      if (timestep % 100 == 0)
         std::cout << "timestep: " << timestep << std::endl;
      addCar(tl, 0.4);
      accelerate(tl);
      decelerate(tl);
      dawdle(tl, 0.7);
      move(tl);
      removeCars(tl, streetLength);
      for (const Car& car : tl)
      {
         image[timestep * streetLength + car.x] = 0;
      }
   }

   lodepng::encode("output.png", image, streetLength, timesteps, LCT_GREY, 8);
   return 0;
}
