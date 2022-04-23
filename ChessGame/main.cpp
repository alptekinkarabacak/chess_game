#include <iostream>
#include "table.h"

int main() {
    std::unique_ptr<Table> myTable = std::make_unique<Table>();
    std::vector<std::string> pieceString;
    if (!myTable->loadFromFile("board1.txt", pieceString));
    myTable->m_loaded_table = myTable->loadToTable(pieceString, myTable->m_loaded_table);
    myTable->test(std::move(myTable->m_loaded_table));
    std::cout<<myTable->m_loaded_table[0][0]->m_points<<std::endl;
    myTable->calculatePiecePoints(myTable->m_loaded_table);
    myTable->totalPiecePoints(myTable->m_loaded_table);
    return 0;
}
