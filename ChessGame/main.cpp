#include <iostream>
#include "table.h"

int main() {
    std::unique_ptr<Table> myTable = std::make_unique<Table>();
    std::vector<std::string> pieceString;
    if (!myTable->loadFromFile("board1.txt", pieceString));
    myTable->m_loaded_table = myTable->loadToTable(pieceString);
    myTable->calculatePiecePoints();
    myTable->totalPiecePoints();
    return 0;
}
