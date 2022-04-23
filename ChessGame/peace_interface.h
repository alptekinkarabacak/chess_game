//
// Created by Alptekin's Macbook on 9.04.2022.
//

#ifndef CHESSGAME_PEACE_INTERFACE_H
#define CHESSGAME_PEACE_INTERFACE_H
#include "move_set.h"
#include <vector>

enum class Colour {
    White = 0,
    Black = 1
};

class PieceInterface {
public:
    int m_position_x{0};
    int m_position_y{0};
    bool m_cross_move{false};
    bool m_straight_move{false};
    bool m_special_pawn_move{false};
    bool m_special_knight_move{false};
    int m_max_move_count_x{0};
    int m_max_move_count_y{0};
    double m_points;
    Colour m_piece_colour;
    virtual void createMoves() = 0;
};

#endif //CHESSGAME_PEACE_INTERFACE_H
