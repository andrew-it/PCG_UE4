// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class DSA
{
public:
    int range; // Degree of randomness / roughness. Larger values generate rougher images.
    int size;
    int maxV;
    
    // The 2D array of integer values into which our fractal will be written
    TArray<int> map;
    

public:
    DSA(int size, int max)
    {
        this->size = size + 1;
        this->maxV = max;
        this->range = max/2;
        map.Init(0, this->size * this->size);
        init();
        fractal();
        clamp_map();
    }
    
    int getValue(int x, int y)
    {
        return map[x + y * size];
    }
    
    void setValue(int x, int y, int v)
    {
        map[x + y * size] = v;
    }
    
    // Random helper
    int rnd(int min, int max)
    {
        return min + (rand() % static_cast<int>(max - min + 1));
    }
    
    int rnd()
    {
        return 0 + (rand() % static_cast<int>(maxV - 0 + 1));
    }
    
    // Init corner values
    void init()
    {
        setValue(0, 0, rnd());
        setValue(0, size - 1, rnd());
        setValue(size - 1, 0, rnd());
        setValue(size - 1, size - 1, rnd());
    }
    
    // Diamond step
    void diamond(int sideLength)
    {
        int halfSide = sideLength / 2;
        
        for (int y = 0; y < size / (sideLength-1); y++)
        {
            for (int x = 0; x < size / (sideLength-1); x++)
            {
                int center_x = x*(sideLength-1) + halfSide;
                int center_y = y*(sideLength-1) + halfSide;
                
                int avg = (getValue(x*(sideLength - 1), y*(sideLength - 1)) +
                           getValue(x*(sideLength - 1), (y+1) * (sideLength - 1)) +
                           getValue((x + 1) * (sideLength - 1), y*(sideLength - 1)) +
                           getValue((x + 1) * (sideLength - 1), (y + 1) * (sideLength - 1)))
                / 4.0f;
                
                setValue(center_x, center_y, avg + rnd(-range, range));
            }
        }
        
    }
    
    // Averaging helper function for square step to ignore out of bounds points
    void average(int x, int y, int sideLength)
    {
        float counter = 0;
        float accumulator = 0;
        
        int halfSide = sideLength / 2;
        
        if (x != 0)
        {
            counter += 1.0f;
            accumulator += getValue(y, x - halfSide);
        }
        if (y != 0)
        {
            counter += 1.0f;
            accumulator += getValue(y - halfSide, x);
        }
        if (x != size - 1)
        {
            counter += 1.0f;
            accumulator += getValue(y, x + halfSide);
        }
        if (y != size - 1)
        {
            counter += 1.0f;
            accumulator += getValue(y + halfSide, x);
        }
        
        setValue(y, x, (accumulator / counter) + rnd(-range, range));
    }
    
    // Square step
    void square(int sideLength)
    {
        int halfLength = sideLength / 2;
        
        for (int y = 0; y < size / (sideLength - 1); y++)
        {
            for (int x = 0; x < size / (sideLength - 1); x++)
            {
                // Top
                average(x*(sideLength - 1) + halfLength, y*(sideLength - 1), sideLength);
                // Right
                average((x + 1)*(sideLength - 1), y*(sideLength - 1) + halfLength, sideLength);
                // Bottom
                average(x*(sideLength - 1) + halfLength, (y+1)*(sideLength - 1), sideLength);
                // Left
                average(x*(sideLength - 1), y*(sideLength - 1) + halfLength, sideLength);
            }
        }
    }
    
    // Main fractal generating loop
    void fractal()
    {
        int sideLength = size/2;
        
        diamond(size);
        square(size);
        
        range /= 2;
        
        while (sideLength >= 2)
        {
            diamond(sideLength + 1);
            square(sideLength + 1);
            sideLength /= 2;
            range /= 2;
        }
    }
    
    
    // Function to clamp all map values
    void clamp_map()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int value = getValue(i, j);
                int min = 0;
                if (value < min) setValue(i, j, min);
                if (value > maxV) setValue(i, j, maxV);
            }
        }
    }
};
