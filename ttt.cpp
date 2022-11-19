#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> vec = {
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
    };

void draw_vector() {
    std::cout << "\n\n";
  for (int i=0; i < vec.size(); i++) {
    for (int j=0; j < vec[0].size(); j++) {
      std::cout << "| " << vec[i][j] << " ";
    }
    std::cout << "|\n";
  }
}

void insert(int row, int column, std::string s) {
    if (vec[row-1][column-1] == " ") {
        vec[row-1][column-1] = s;
        draw_vector();
    } else {
        std::cout << "Box already filled!\n";
        std::cout << "Write a non-filled box: ";
        std::cout << "\nPlease write the box's row you want to fill: ";
        std::cin >> row;
        std::cout << "\nNow the column: ";
        std::cin >> column;
        insert(row, column, s);
    }
}

bool is_full() {
    for (int i=0; i < vec.size(); i++) {
        for (int j=0; j < vec[i].size(); j++) {
            if (vec[i][j] == " ") {
                return false;
            }
    }
  }
  return true;
}

void play(int num) {
    int row, column;
    std::string s;
    if (num == 0) { 
        s = "X";
    } else {
        s = "O";
    }
    std::cout << "\nPlayer " << num+1 << ", it's your turn!\nPlease write the box's row you want to fill: ";
    std::cin >> row;
    std::cout << "\nNow the column: ";
    std::cin >> column;
    insert(row, column, s);
}

bool is_winner() {
    for (int i=0; i < vec.size(); i++) {
        if (vec[i][0] != " " && vec[i][0]==vec[i][1] && vec[i][1]==vec[i][2]) {
            return true;
        } else if (vec[0][i] != " " && vec[0][i]==vec[1][i] && vec[1][i]==vec[2][i]) {
            return true;
        }
    }
    if (vec[0][0] != " " && vec[0][0]==vec[1][1] && vec[1][1]==vec[2][2]) {
        return true;
    }
    if (vec[1][1] != " " && vec[0][2]==vec[1][1] && vec[1][1]==vec[2][0]) {
        return true;
    }
    return false;
}


int main() {
    draw_vector();
    int i = 0;
    while (!is_full()) {
        int player = i % 2;
        play(player);
        if (is_winner()) {
            std::cout << "Player " << player+1 << " won!!\n";
            break;
        }
        i++;
    }
    if (is_full()) {
        std::cout << "TIED!";
    }
    return 0;
}