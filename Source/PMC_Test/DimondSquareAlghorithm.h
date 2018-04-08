// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <vector>
#include <map>

/**
 * 
 */
class DimondSquareAlghorithm
{
public:
	DimondSquareAlghorithm(int x_len, int y_len)
	{
		X_len = x_len;
		Y_len = y_len;
		values.Init(0, x_len * y_len);
	}

	TArray<double> values;
	int X_len;
	int Y_len;

	double frand(double fMin = 0, double fMax = 1)
	{
		double f = (double)rand() / RAND_MAX;
		return fMin + f * (fMax - fMin);
	}

	double getValue(int x, int y)
	{
		return values[x + y * Y_len];
	}

	void setValue(int x, int y, double value)
	{
		values[x + y * Y_len] = value;
	}

	void squareStep(int x, int y, int size, double value)
	{
		int hs = size / 2;

		// a     b 
		//
		//    x
		//
		// c     d

		double a = getValue(x - hs, y - hs);
		double b = getValue(x + hs, y - hs);
		double c = getValue(x - hs, y + hs);
		double d = getValue(x + hs, y + hs);

		setValue(x, y, ((a + b + c + d) / 4.0) + value);
	}

	void diamondStep(int x, int y, int size, double value)
	{
		int hs = size / 2;

		//   c
		//
		//a  x  b
		//
		//   d

		double a = getValue(x - hs, y);
		double b = getValue(x + hs, y);
		double c = getValue(x, y - hs);
		double d = getValue(x, y + hs);

		setValue(x, y, ((a + b + c + d) / 4.0) + value);
	}

	void DiamondSquare(int stepsize, double scale)
	{

		int halfstep = stepsize / 2;

		for (int y = halfstep; y < Y_len + halfstep; y += stepsize)
		{
			for (int x = halfstep; x < X_len + halfstep; x += stepsize)
			{
				squareStep(x, y, stepsize, frand() * scale);
			}
		}

		for (int y = 0; y < Y_len; y += stepsize)
		{
			for (int x = 0; x < X_len; x += stepsize)
			{
				diamondStep(x + halfstep, y, stepsize, frand() * scale);
				diamondStep(x, y + halfstep, stepsize, frand() * scale);
			}
		}

	}

	void generateDS(int featuresize)
	{
		for (int y = 0; y < Y_len; y += featuresize)
			for (int x = 0; x < X_len; x += featuresize)
			{
				setValue(x, y, frand());  //IMPORTANT: frand() is a random function that returns a value between -1 and 1.
			}

		int samplesize = featuresize;

		double scale = 1.0;

		while (samplesize < 1)
		{

			DiamondSquare(samplesize, scale);

			samplesize /= 2;
			scale /= 2.0;
		}
	}
};
