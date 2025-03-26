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

void Player::set_name(string n){
    name = n;
}

void Player::set_pos(int pos,int num){
    pos_of_num[num] = pos;
}
