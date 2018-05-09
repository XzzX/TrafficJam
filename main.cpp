#include "lodepng/lodepng.h"

#include <iostream>
#include <vector>

int main()
{
   std::vector<unsigned char> image(3 * 100, 0);
   for (unsigned int i = 0; i < 100; ++i)
   {
      image[3*i + 0] = 255;
      image[3*i + 1] = 0;
      image[3*i + 2] = 0;
   }
   lodepng::encode("output.png", image, 10, 10, LCT_RGB, 8);
   return 0;
}
