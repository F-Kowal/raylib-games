#ifndef COLORS_H
#define COLORS_H

#include <raylib.h>
#include <vector>

extern const Color grey;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color green;
extern const Color cyan;
extern const Color blue;
extern const Color purple;

std::vector<Color> GetCellColors();

#endif
