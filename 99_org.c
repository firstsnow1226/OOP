#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
 
    char s[N][64];
    int cnt[2*M+2][N];
    int index[M*M][N];
 
    for(int i=0;i<2*M+2;i++){
        for(int j=0;j<N;j++)
            cnt[i][j]=0;
    }
 
    for(int k=0;k<N;k++){
        scanf("%s",s[k]);
 
        for(int i=0;i<M*M;i++){
            int a;
            scanf("%d",&a);
            index[a-1][k]=i;
        }
    }
 
    bool check(int num, int x){
        int r=index[num][x]/M;
        int c=index[num][x]%M;
 
        cnt[r][x]++;
        cnt[M+c][x]++;
 
        if( c==r  ) cnt[2*M][x]++;
        if( r+c==M-1 ) cnt[2*M+1][x]++;
 
        if(  cnt[r][x]==M || cnt[M+c][x]==M || cnt[2*M][x]==M || cnt[2*M+1][x]==M )
                return 1;
        return 0;
    }
 
 
    for(int i=0;i<M*M;i++){
        int num;
        scanf("%d",&num);
        num--;
        bool find_ans=0;
 
        for(int k=0;k<N;k++){
            bool find=check(num, k);
 
            if( find && !find_ans ){
                printf("%d",num+1);
                find_ans=1;
            }
            if( find ){
                printf(" ");
                for(int i=0;i<strlen(s[k]);i++)
                    printf("%c",s[k][i]);
            }
 
        }
 
 
        if( find_ans ){
            printf("\n");
            return 0;
        }
 
    }
}