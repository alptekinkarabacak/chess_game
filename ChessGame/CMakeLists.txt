cmake_minimum_required(VERSION 3.20)
project(ChessGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessGame main.cpp table.cpp table.h peace_interface.h piece_bishop.cpp piece_bishop.h piece_pawn.cpp piece_pawn.h piece_knight.cpp piece_knight.h piece_rook.cpp piece_rook.h piece_queen.cpp piece_queen.h piece_king.cpp piece_king.h move_set.h)
