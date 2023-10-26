#include <stdio.h>
#include <math.h>

#define k 0.5


int main(void){

    int x_num=10; 
    double x_max=1.0, delta_x=x_max/x_num, delta_t=0.001;

    double u_[x_num+1];
    int u_size=sizeof(u_)/sizeof(double);

    // 初期化
    for ( int i = 0; i < u_size; i++){
        float x_i = delta_x*i;
        if(x_i>0.0 && x_i<0.25){
            continue;
        } else if(x_i>=0.25 && x_i<0.75){
            u_[i]=1.0;
        }else if(x_i>0.75 && x_i<1.0){
            continue;
        }
    }


    printf("x_i,\tu_i\n");
    for ( int i = 0; i < u_size; i++){
        if(i==0) printf("t=0\n");
        float x_i = delta_x*i;
        printf("%lf, %lf, \n",x_i, u_[i]);
    }
/*
    for ( int j = 0; j < t_size; j++){
        printf("%lf\n", t_[j]);
    }
*/

    for ( int j = 1; j <= 100; j++){
        printf("t=%lf\n", delta_t*j);
        for (int i = 0; i < u_size; i++){
            float x_i=delta_x*i;
            if(i==0 || i==u_size-1){
                printf("%lf, %lf, \n",x_i, u_[i]);
                continue;
            }
            u_[i] = u_[i] + k*delta_t/(delta_x*delta_x)*(u_[i+1] - 2*u_[i] + u_[i-1]);
            printf("%lf, %lf, \n",x_i, u_[i]);
        }
        
    }
  
    return 0;
}