#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "RandomSampleGenerator.h"

RandomSampleGenerator::RandomSampleGenerator()
   : width(0)
   , height(0)
   , coordinates()
   , currentCoordinate()
{ }

RandomSampleGenerator::RandomSampleGenerator(const int width, const int height)
   : width(width)
   , height(height)
   , coordinates()
   , currentCoordinate()
{
   // Generate all possible (x, y) pairs
   for (int y = 0; y < height; ++y)
   {
       for (int x = 0; x < width; ++x)
       {
           coordinates.push_back({x, y});
       }
   }

   // Shuffle the pairs
   std::random_device rd;
   std::mt19937 g(rd());
   std::shuffle(coordinates.begin(), coordinates.end(), g);

   // Set the current coordinate to the beginning of the shuffled list
   currentCoordinate = coordinates.begin();
}

RandomSampleGenerator::~RandomSampleGenerator()
{ }

void RandomSampleGenerator::generateSample(Sample& sample)
{
   // Update sample with the current coordinate
   sample.x = currentCoordinate->first;
   sample.y = currentCoordinate->second;

   // Move to the next coordinate in the shuffled list
   ++currentCoordinate;
}

bool RandomSampleGenerator::sampleIsAvailable()
{
   // Check if we have reached the end of the shuffled list
   return currentCoordinate != coordinates.end();
}

