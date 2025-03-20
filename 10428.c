#include <stdio.h>
#include <stdint.h>

#define MaxN 75000

int count_row(int n, uint64_t arr[]){
    int row_n = 0;
    for(int i=0;i<MaxN;i++){
        if(n>64) return 0;

        uint64_t tmp = (1ULL<<n)-1;
        for(int j=0;j<65-n;j++){
            uint64_t now = tmp<<j ;
            if( (arr[i]&now) == now )  row_n++;
        }
    }
    return row_n;
}

int count_col(int n, uint64_t arr[]){
    int col_n = 0;
    for(int i=0;i<MaxN-n+1;i++){
        uint64_t tot = arr[i];
        for(int k=1;k<n;k++)
            tot = tot&arr[i+k];
        
        for(int j=0;j<64;j++){
            uint64_t tmp = 1ULL<<j;
            if( (tmp&tot)!=0 ) col_n++;
        }
    }
    return col_n;
}

int count_dia(int n, uint64_t arr[], int start_pos, int dir){
    int dia_n = 0;
    for(int i=0;i<MaxN-n+1;i++){
        uint64_t tot = arr[i]>>(start_pos);
        for(int k=1;k<n;k++)
            tot &= arr[i+k]>>(start_pos+dir*k);
        
        for(int j=0;j<65-n;j++){
            uint64_t tmp = 1ULL<<j;

            if( (tmp&tot)!=0 ) dia_n++;
        }
    }
    return dia_n;
}

int main(){
        uint64_t arr[MaxN];
        int n;
        scanf("%d", &n);
 
        for(int i=0;i<MaxN;i++){
                scanf("%llu", &arr[i]);
        }
 
        // row
        int row_n = count_row(n, arr);
        printf("%d\n", row_n);
 
        // column
        int col_n = count_col(n, arr);
        printf("%d\n",col_n);
 
        // dia
        int dia_n = count_dia(n, arr, n-1, -1);
        printf("%d\n",dia_n);
 
        // anti-dia
        int adia_n = count_dia(n, arr, 0, 1);
        printf("%d\n",adia_n);
}