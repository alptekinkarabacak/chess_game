//
// Created by Alptekin's Macbook on 15.04.2022.
//

#ifndef CHESSGAME_PIECE_BISHOP_H
#define CHESSGAME_PIECE_BISHOP_H

#include "peace_interface.h"
#include <iostream>

class PieceBishop : public PieceInterface {
public:
    PieceBishop() {
        createMoves();
    }

    Colour m_piece_colour;
    int m_points{3};
    int m_position_x{0};
    int m_position_y{0};
    bool m_cross_move{true};
    bool m_straight_move{false};
    bool m_special_pawn_move{false};
    bool m_special_knight_move{false};
    int m_max_move_count_x{8};
    int m_max_move_count_y{8};
    static constexpr int max_number_of_count = 4;
    std::vector<std::shared_ptr<MoveSet>> m_piece_moves;
    void createMoves() override;
};


#endif //CHESSGAME_PIECE_BISHOP_H
