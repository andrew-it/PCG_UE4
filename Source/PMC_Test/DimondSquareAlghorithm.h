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
	DimondSquareAlghorithm(int size);

	~DimondSquareAlghorithm();

	void generateWorld();

	double fRand2(double fMin, double fMax);

	void timeReset();

	void init_blocks_cords(DimondSquareAlghorithm algorithm);

	void setScaleASmooth(int scale, int smooth);

	std::map<int, std::vector<std::vector<double>>> getBlocks();

	std::vector<std::vector<double>> tiles;
	int worldSize; // Only the power of two + 1

	std::map<int, std::map<int, std::vector<double>>> hmBlocks;

	std::map<int, std::vector<double>> hmCoord;
	// final set of drawing blocks, block id - point id - x || y || z
	std::map<int, std::vector<std::vector<double>>> finalMapOfBlocks;
	// final set of drawing blocks, block id - point id - x || y || z with smooth
	std::map<int, std::vector<std::vector<double>>> finalMapOfBlocksWithSizeASmooth;
};
