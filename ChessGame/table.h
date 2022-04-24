//
// Created by Alptekin's Macbook on 9.04.2022.
//

#ifndef CHESSGAME_TABLE_H
#define CHESSGAME_TABLE_H

#include "peace_interface.h"
#include <string>
#include <vector>
#include <array>
#include <optional>



class Table {
public:
    static constexpr int table_size{8};
    std::array<std::array<PieceInterface *, 8>, 8 > m_loaded_table;
    int loadFromFile(std::string fileName, std::vector<std::string> &stringOfPieces);
    std::array<std::array<PieceInterface *, 8>, 8 > loadToTable(std::vector<std::string> stringOfPieces);
    void calculatePiecePoints();
    void totalPiecePoints();
    void test(std::array<std::array<PieceInterface *, 8>, 8 > &&pieceTable) {
        pieceTable[0][0]->m_points = 30;
    }
};


#endif //CHESSGAME_TABLE_H
