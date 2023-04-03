#include "Grid.h"


Grid::Grid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->arr_obj[i][j] = 3;
        }
    }
}


Grid::~Grid() {}


void Grid::addX(const int index_row, const int index_col, const int index_fill) {
    this->arr_obj[index_row][index_col] = 1;

}


void Grid::addO(const int index_row, const int index_col, const int index_fill) {
    this->arr_obj[index_row][index_col] = 0;
}


void Grid::printGrid() {
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << this->arr_obj[0][0] << "  |  " << this->arr_obj[0][1] << "  |  " << this->arr_obj[0][2] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << this->arr_obj[1][0] << "  |  " << this->arr_obj[1][1] << "  |  " << this->arr_obj[1][2] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << this->arr_obj[2][0] << "  |  " << this->arr_obj[2][1] << "  |  " << this->arr_obj[2][2] << std::endl;

    std::cout << "     |     |     " << std::endl << std::endl;
}

