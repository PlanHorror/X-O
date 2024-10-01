#ifndef PLAYER_X_H
#define PLAYER_X_H
#include <vector>
class PlayerX {
public:
    bool win;
    std::vector<std::vector<int>> moves;
    int val;
    void set_move(int row, int col) {
        std::vector<int> move_address;
        move_address.push_back(row);
        move_address.push_back(col);
        moves.push_back(move_address);
        
    }
    void set_win(bool w) {
        win = w;
    }
    PlayerX() {
        win = false;
        
        moves = {};
        val = 1;
    }
};
#endif // PLAYER_X_H