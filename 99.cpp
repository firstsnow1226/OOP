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
        players[i].set_name(name);

        int num;
        for(int j=0;j<M*M;j++){
            cin>>num;
            players[i].set_pos(j,num);
        }
    }

    

    return 0;
}