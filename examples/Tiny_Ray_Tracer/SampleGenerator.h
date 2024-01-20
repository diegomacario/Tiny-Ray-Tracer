#ifndef SAMPLE_GENERATOR_H
#define SAMPLE_GENERATOR_H

#include "Sample.h"

/*
Description:

   The SampleGenerator class is used to generate Sample objects for every pixel on the image plane.

   Samples are generated line by line from left to right, starting at the upper-left corner of the image plane.
   Each sample specifies the coordinates of the center of a pixel.

   The samples generated by this class are used to compute the rays that are shot by the camera through the center of each pixel.
*/

class SampleGenerator
{
public:

   SampleGenerator(const int width, const int height);
   ~SampleGenerator();

   // Samples are generated line by line from left to right, starting at the upper-left corner of the image plane
   void generateSample(Sample& sample);

   bool sampleIsAvailable();

private:

   // Print how much of the image has been generated (10%, 20%, ...)
   void displayProgress(const float y);

   // Number of pixels = Number of samples = width * height
   int width, height;

   // x and y are equal to zero at the upper-left corner
   // x increases as we move towards the right, while y increases as we move towards the bottom
   float x, y;
};

#endif

