#include <vector>
#include <iostream>
#include "cell.cpp"
#include "player_x.cpp"
#include "player_o.cpp"
class Board {
public:
    int board_size;
    int number_cell_blank;
    int number_cell_non_blank;
    std::vector<std::vector<Cell>> board;
    void set_board_size(int size) {
        board_size = size;
    }
    void set_cell(int row, Cell value) {
        board[row].push_back( value);
    }
    void print_board() {
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                std::cout << board[i][j].cell_value << " ";
            }
            std::cout << std::endl;
        }
    }
    void set_cell_value(int row, int col, int value) {
        board[row][col].cell_value = value;
        board[row][col].is_blank = false;
    }
    bool check_cell(int row, int col) {
        if (board[row][col].is_blank) {
            return true;
        } else {
            std::cout << "Cell is non-blank" << std::endl;
            return false;
        }
    };
    void make_move(int row, int col, int value) {
        if (check_cell(row, col))
        {
            /* code */
            set_cell_value(row, col, value);
            number_cell_blank--;
            number_cell_non_blank++;
        }
        
        
    }
    Board (int size) {
        board_size = size;
        number_cell_blank = size * size;
        number_cell_non_blank = 0;
        for (int i = 0; i < size; i++) {
            board.push_back({});
            for (int j = 0; j < size; j++) {
                Cell cell {i * size + j, i, j};
                set_cell(i, cell);
            }
        }
    }
};