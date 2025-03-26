#include "Player.h"
#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;

    Player players[N];
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        players[i].set_board_size(M);
        players[i].set_name(name);

        int num;
        for(int j=0;j<M*M;j++){
            cin>>num;
            players[i].set_pos(j,num);
        }
    }
    bool find_ans = false;
    for(int i=0;i<M*M and !find_ans;i++){
        int bingo_num;
        cin>>bingo_num;

        for(int j=0;j<N;j++){
            players[j].update_cnt(bingo_num);
            bool check_win = players[j].check(bingo_num);

            if( !find_ans and check_win ){
                cout<<bingo_num;
                find_ans = true;
            }
            if( check_win )
                cout<<' '<<players[j].get_name();
        }
    }
    return 0;
}