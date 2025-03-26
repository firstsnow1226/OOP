#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
    for(int i=0;i<(2*MAXM+2);i++)
        cnt_of_line[i] = 0;
}

string Player::get_name(){
    return name;
}

void Player::set_board_size(int size){
    board_size = size;
}

void Player::set_name(string n){
    name = n;
}

void Player::set_pos(int pos,int num){
    pos_of_num[num] = pos;
}

void Player::update_cnt(int num){
    int pos = pos_of_num[num];
    int row = pos/board_size;
    int col = pos%board_size;

    cnt_of_line[row]++;
    cnt_of_line[board_size+col]++;
 
    if( row == col  ) cnt_of_line[2*board_size]++;
    if( row + col == board_size-1 ) cnt_of_line[2*board_size+1]++;
}
