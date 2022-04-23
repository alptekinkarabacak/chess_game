//
// Created by Alptekin's Macbook on 9.04.2022.
//

#include "table.h"
#include <fstream>
#include <iostream>
#include "piece_bishop.h"
#include "piece_king.h"
#include "piece_knight.h"
#include "piece_pawn.h"
#include "piece_queen.h"
#include "piece_rook.h"



int Table::loadFromFile(std::string fileName, std::vector<std::string> &stringOfPieces) {
    std::fstream chessFile;
    chessFile.open(fileName, std::ios::in); //open a file to perform read operation using file object
    if (chessFile.fail()) {
        std::cout<<"File not found\n";
        return -1;
    }

    std::string chessString;
    std::string lineString;
    std::string piece{"  "};
    int piece_index{0};
    std::string::iterator itLine;
    while(getline(chessFile, lineString)) { //read data from file object and put it into string.
        itLine = lineString.begin();
       for (int i = 0; i < lineString.length() ; ++i) {
           if (*itLine == ' ' || *itLine == '\r' || i == lineString.length() - 1) {
               piece_index = 0;
               stringOfPieces.push_back(piece);
               itLine++;
               continue;
           } else {
               piece.at(piece_index) = *itLine;
               ++piece_index;
               itLine++;
           }
       }
    }

    return 0;
}

std::array<std::array<PieceInterface *, 8>, 8 > Table::loadToTable (std::vector<std::string> stringOfPieces, std::array<std::array<PieceInterface *, 8>, 8 > &pieceTable) {
    /*
    int number_of_pawn, number_of_queen, number_of_rook, number_of_knight, number_of_king, number_of_bishop;
    number_of_rook = number_of_bishop = number_of_king = number_of_knight = number_of_pawn = number_of_queen = 0;
     */
    int number_of_pawn{0}, number_of_queen{0}, number_of_rook{0}, number_of_knight{0}, number_of_king{0}, number_of_bishop{0};
    int x = 0;
    int y = 0;
    for(auto &string_piece : stringOfPieces) {
        switch (string_piece.at(0)) {
            case 'k':
                ++number_of_rook;
                if (number_of_rook > PieceRook::max_number_of_count) {
                    std::cout<<"Possible rook count limit has overcame!\n";
                } else {
                    PieceRook* Rook = new PieceRook;
                    if (string_piece.at(1) == 's') {
                        Rook->m_piece_colour = Colour::Black;
                    } else if (string_piece.at(1) == 'b') {
                        Rook->m_piece_colour = Colour::White;
                    } else {
                        std::cout<<"Unknown colour type\n";
                    }

                    Rook->m_points = 20;
                    Rook->m_position_x = x;
                    Rook->m_position_y = y;
                    pieceTable[x][y] = Rook;
                }
                break;
            case 'a':
                ++number_of_knight;
                if (number_of_knight > PieceKnight::max_number_of_count) {
                    std::cout<<"Possible Knight count limit has overcame!\n";
                } else {
                    PieceKnight* Knight = new PieceKnight;
                    if (string_piece.at(1) == 's') {
                        Knight->m_piece_colour = Colour::Black;
                    } else if (string_piece.at(1) == 'b') {
                        Knight->m_piece_colour = Colour::White;
                    } else {
                        std::cout<<"Unknown colour type\n";
                    }

                    Knight->m_position_x = x;
                    Knight->m_position_y = y;
                    pieceTable[x][y] = Knight;
                }
                break;
            case 's':
                ++number_of_king;
                if (number_of_king > PieceKing::max_number_of_count) {
                    std::cout<<"Possible King count limit has overcame!\n";
                } else {
                    PieceKing* King = new PieceKing;
                    if (string_piece.at(1) == 's') {
                        King->m_piece_colour = Colour::Black;
                    } else if (string_piece.at(1) == 'b') {
                        King->m_piece_colour = Colour::White;
                    } else {
                        std::cout<<"Unknown colour type\n";
                    }

                    King->m_position_x = x;
                    King->m_position_y = y;
                    pieceTable[x][y] = King;
                }
                break;
            case 'v':
                ++number_of_queen;
                if (number_of_queen > PieceQueen::max_number_of_count) {
                    std::cout<<"Possible Queen count limit has overcame!\n";
                } else {
                    PieceQueen* Queen = new PieceQueen;
                    if (string_piece.at(1) == 's') {
                        Queen->m_piece_colour = Colour::Black;
                    } else if (string_piece.at(1) == 'b') {
                        Queen->m_piece_colour = Colour::White;
                    } else {
                        std::cout<<"Unknown colour type\n";
                    }

                    Queen->m_position_x = x;
                    Queen->m_position_y = y;
                    pieceTable[x][y] = Queen;
                }
                break;
            case 'f':
                ++number_of_bishop;
                if (number_of_bishop > PieceBishop::max_number_of_count) {
                    std::cout<<"Possible Bishop count limit has overcame!\n";
                } else {
                    PieceBishop* Bishop = new PieceBishop();
                    if (string_piece.at(1) == 's') {
                        Bishop->m_piece_colour = Colour::Black;
                    } else if (string_piece.at(1) == 'b') {
                        Bishop->m_piece_colour = Colour::White;
                    } else {
                        std::cout<<"Unknown colour type\n";
                    }

                    Bishop->m_position_x = x;
                    Bishop->m_position_y = y;
                    pieceTable[x][y] = Bishop;
                }
                break;
            case 'p':
                ++number_of_pawn;
                if (number_of_pawn > PiecePawn::max_number_of_count) {
                    std::cout<<"Possible Pawn count limit has overcame!\n";
                } else {
                    PiecePawn* Pawn = new PiecePawn;
                    if (string_piece.at(1) == 's') {
                        Pawn->m_piece_colour = Colour::Black;
                    } else if (string_piece.at(1) == 'b') {
                        Pawn->m_piece_colour = Colour::White;
                    } else {
                        std::cout<<"Unknown colour type\n";
                    }

                    Pawn->m_position_x = x;
                    Pawn->m_position_y = y;
                    pieceTable[x][y] = Pawn;
                }

                break;
            default:
                pieceTable[x][y] = nullptr;
                break;
        }
        ++y;
        if(y == 8) {
            ++x;
            y = 0;
            if (x == 8) {
                std::cout<<"All pieces are placed.\n";
                return pieceTable;
            }
        }
    }
}

void Table::calculatePiecePoints(std::array<std::array<PieceInterface *, 8>, 8> &pieceTable) {
    int x{0}, y{0};
    pieceTable[0][0]->m_piece_colour;
    for(auto &row : pieceTable) {
        for(auto piece : row) {
            if (piece != nullptr) {
                if (pieceTable[0][1]->m_cross_move == true) {
                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    for (int i = 0; x < 8 || y < 8 || i <= piece->m_max_move_count_x; i++) {
                        ++x;
                        ++y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    for (int i = 0; x > 0 || y < 8 || i <= piece->m_max_move_count_x; i++) {
                        --x;
                        ++y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    for (int i = 0; x < 8 || y > 0 || i <= piece->m_max_move_count_x; i++) {
                        ++x;
                        --y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    for (int i = 0; x > 0 || y > 0 || i <= piece->m_max_move_count_x; i++) {
                        --x;
                        --y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }
                }

                if (pieceTable[0][0]->m_straight_move == true) {
                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    for (int i = 0; y < 8 || i <= piece->m_max_move_count_y; i++) {
                        ++y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }

                    y = piece->m_position_y;
                    for (int i = 0; y > 0 || i <= piece->m_max_move_count_y; i++) {
                        --y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }

                    y = piece->m_position_y;
                    for (int i = 0; x < 8 || i <= piece->m_max_move_count_x; i++) {
                        ++x;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }

                    x = piece->m_position_x;
                    for (int i = 0; x > 8 || i <= piece->m_max_move_count_x; i++) {
                        --x;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }
                }

                if (pieceTable[0][1]->m_special_knight_move) {
                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    ++y;
                    x += 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    ++y;
                    x -= 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    --y;
                    x += 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    --y;
                    x -= 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    ++x;
                    y += 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    --x;
                    y += 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    ++x;
                    y -= 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }

                    x = piece->m_position_x;
                    y = piece->m_position_y;
                    --x;
                    y -= 2;
                    if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                        pieceTable[x][y]->m_points /= 2;
                    }
                }

                if (piece->m_special_pawn_move) {
                    if (piece->m_piece_colour == Colour::Black) {
                        x = piece->m_position_x;
                        y = piece->m_position_y;
                        --x;
                        --y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }

                        x = piece->m_position_x;
                        y = piece->m_position_y;
                        ++x;
                        --y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    } else {
                        x = piece->m_position_x;
                        y = piece->m_position_y;
                        ++x;
                        ++y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }

                        x = piece->m_position_x;
                        y = piece->m_position_y;
                        --x;
                        ++y;
                        if (pieceTable[x][y]->m_piece_colour != piece->m_piece_colour) {
                            pieceTable[x][y]->m_points /= 2;
                        }
                    }
                }
            }
        }
    }
}

void Table::totalPiecePoints(std::array<std::array<PieceInterface *, 8>, 8> &pieceTable) {
    double black_team{0}, white_team{0};
    for(auto & row : pieceTable) {
        for(auto & piece : row) {
            if (piece != nullptr) {
                if (piece->m_piece_colour == Colour::Black) {
                    black_team += piece->m_points;
                } else {
                    white_team += piece->m_points;
                }
            }
        }
    }
    std::cout<<"Black Team is : "<< black_team<<std::endl;
    std::cout<<"White Team is : "<< white_team<<std::endl;


}


