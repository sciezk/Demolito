/*
 * Demolito, a UCI chess engine.
 * Copyright 2015 lucasart.
 *
 * Demolito is free software: you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Demolito is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
*/
#include "types.h"

int64_t dbgCnt[2] = {0, 0};

int opposite(int color)
{
    BOUNDS(color, NB_COLOR);
    return color ^ BLACK;
}

int push_inc(int color)
{
    static const int PushInc[NB_COLOR] = {UP, DOWN};
    BOUNDS(color, NB_COLOR);
    return PushInc[color];
}

int square_from(int rank, int file)
{
    BOUNDS(rank, NB_RANK);
    BOUNDS(file, NB_FILE);
    return NB_FILE * rank + file;
}

int rank_of(int square)
{
    BOUNDS(square, NB_SQUARE);
    return square / NB_FILE;
}

int file_of(int square)
{
    BOUNDS(square, NB_SQUARE);
    return square % NB_FILE;
}

int relative_rank(int color, int rank)
{
    BOUNDS(color, NB_COLOR);
    BOUNDS(rank, NB_RANK);
    return rank ^ (7 * color);
}

int relative_rank_of(int color, int square)
{
    BOUNDS(square, NB_SQUARE);
    return relative_rank(color, rank_of(square));
}