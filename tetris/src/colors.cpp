#include "colors.h"

const Color darkGrey = { 30, 30, 30, 255 };
const Color red = { 235, 66, 113, 255 };
const Color orange = { 247, 136, 15, 255 };
const Color yellow = { 235, 231, 39, 255 };
const Color green = { 96, 235, 53, 255 };
const Color cyan = { 33, 235, 219, 255 };
const Color blue = { 53, 103, 235, 255 };
const Color purple = { 120, 99, 242, 255 };
const Color scoreGrey = { 35, 35, 35, 255 };

std::vector<Color> GetCellColors()
{
	return { darkGrey, red, orange, yellow, green, cyan, blue, purple, scoreGrey };
}