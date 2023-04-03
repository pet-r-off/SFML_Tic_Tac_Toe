#ifndef TIC_TAC_GRID_H
#define TIC_TAC_GRID_H


#include "../../../stdafx.h"


class Grid {
public:
    Grid();
    ~Grid();

    void addX(int index_row, int index_col, int index_fill);
    void addO(int index_row, int index_col, int index_fill);
    void printGrid();

    std::array<std::array<int, 3>, 3>  arr_obj;
private:
};


#endif //TIC_TAC_GRID_H
