class Cell {
public:
    int cell_index;
    int cell_value;
    bool is_blank;
    int cell_address[2];
    void set_cell_address(int row, int col) {
        cell_address[0] = row;
        cell_address[1] = col;
    }
    void set_cell_value(int index, int value) {
        cell_index = index;
        cell_value = value;
    }
    Cell( int index, int row, int col) {
        is_blank = true;
        cell_index = index;
        cell_value = 0;
        set_cell_address(row, col);
    }
};