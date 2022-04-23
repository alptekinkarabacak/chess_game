//
// Created by Alptekin's Macbook on 15.04.2022.
//

#ifndef CHESSGAME_PIECE_KNIGHT_H
#define CHESSGAME_PIECE_KNIGHT_H

#include "peace_interface.h"

class PieceKnight : public PieceInterface{
public:
    int m_points{3};
    int m_position_x{0};
    int m_position_y{0};
    bool m_cross_move{false};
    bool m_straight_move{false};
    bool m_special_pawn_move{false};
    bool m_special_knight_move{true};
    Colour m_piece_colour;
    static constexpr int max_number_of_count = 4;
    std::vector<std::shared_ptr<MoveSet>> m_piece_moves;
    void createMoves() override;
};


#endif //CHESSGAME_PIECE_KNIGHT_H
