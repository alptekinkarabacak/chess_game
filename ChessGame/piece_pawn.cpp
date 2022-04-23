//
// Created by Alptekin's Macbook on 15.04.2022.
//

#include "piece_pawn.h"

void PiecePawn::createMoves() {
    std::shared_ptr<MoveSet> moveSet1 = std::make_shared<MoveSet>();
    moveSet1->right = 1;
    moveSet1->left = 0;
    if (this->m_piece_colour == Colour::Black) {
        moveSet1->forward = 1;
        moveSet1->backward = 0;
    } else {
        moveSet1->forward = 0;
        moveSet1->backward = 1;
    }

    m_piece_moves.push_back(moveSet1);
    std::shared_ptr<MoveSet> moveSet2 = std::make_shared<MoveSet>();
    moveSet2->right = 0;
    moveSet2->left = 1;
    if (this->m_piece_colour == Colour::Black) {
        moveSet2->forward = 1;
        moveSet2->backward = 0;
    } else {
        moveSet2->forward = 0;
        moveSet2->backward = 1;
    }

    m_piece_moves.push_back(moveSet2);
}
