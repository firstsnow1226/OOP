#include <string>
using namespace std;

#define MAXM 256

class Player{
private:
    string name;
    int pos_of_num[MAXM*MAXM+1];
    int cnt_of_line[2*MAXM+2];
public:
    Player();
    string get_name();
    void set_name(string name);
    void set_pos(int pos,int num);
};