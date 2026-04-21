#include "colors.h"

const Color grey = { 30, 30, 30, 255 };
const Color red = { 255, 155, 190, 255 };
const Color orange = { 255, 200, 140, 255 };
const Color yellow = { 249, 255, 149, 255 };
const Color green = { 155, 255, 166, 255 };
const Color cyan = { 129, 243, 255, 255 };
const Color blue = { 61, 118, 255, 255 };
const Color purple = { 153, 134, 255, 255 };

std::vector<Color> GetCellColors()
{
	return { grey, red, orange, yellow, green, cyan, blue, purple };
}