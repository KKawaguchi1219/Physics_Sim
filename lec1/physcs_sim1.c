#include <stdio.h>
#include <math.h>

#define k 1.2

// dθ/dt
double func(double t, double theta){
    return -k*sin(theta);
}

// 解析解 a=0.017453 rad(1.0 °), b=0.0 rad/s
double func_exa(double t){
    return M_PI/180*cos(sqrt(k)*t);
}

// 保存量
double conserved_quantity(double t, double theta, double phi){
  return 1.0/2.0*phi*phi - k*cos(theta);
}

int main(){
    int i=0;
    double t=0.0, t_max=10.0, delta_t=0.01;

    FILE *fp;
    // 課題番号ごとに適宜変更
    char *fname = "physcs_sim1d.csv";

    fp = fopen( fname, "w" );
    if( fp == NULL ){
      printf( "%sファイルが開けません\n", fname );
      return -1;
    }

    // theta[rad]
    // a=thera_init, b=phi
    double deg=60.0;
    double theta=deg*M_PI/180.0, phi=0.0;
    double theta_init=theta;

    printf("t,  theta,  phi, (other options)\n");

    while(1){
        if(t>t_max){
          break;
        }

        // 適宜コメントアウトを切り替え
        //printf("%lf, %lf, %lf\n", t, theta, phi);
        //printf("%lf, %lf, %lf, %lf\n", t, theta, phi, func_exa(t));
        printf("%lf, %lf, %lf, %lf\n", t, theta, phi, conserved_quantity(t, theta, phi));
    
        //fprintf( fp, "%lf, %lf, %lf\n", t, theta, phi);
        //fprintf( fp, "%lf, %lf, %lf, %lf\n", t, theta, phi, func_exa(t));
        fprintf( fp, "%lf, %lf, %lf, %lf\n", t, theta, phi, conserved_quantity(t, theta, phi));

        theta = theta + phi*delta_t;
        phi = phi + func(t, theta)*delta_t;
        t += delta_t;

    }
    fclose( fp );
    printf("theta= %lf rad, %lf deg\n", theta_init, deg);
    
    return 0;
}