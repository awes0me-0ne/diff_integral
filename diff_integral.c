#include<stdio.h>

typedef double (* DOUBLE_FUNC_POINTER_DOUBLE)(double);//関数へのポインタ型定義
//                ↑関数のポインタ名

typedef double (* D_FP_DFPD_I)(DOUBLE_FUNC_POINTER_DOUBLE,int);

//プロトタイプ宣言
double diff_methods(D_FP_DFPD_I integral1,D_FP_DFPD_I integral2,DOUBLE_FUNC_POINTER_DOUBLE f,int n);

double k_integral(DOUBLE_FUNC_POINTER_DOUBLE f,int n);//短形法
double d_integral(DOUBLE_FUNC_POINTER_DOUBLE f,int n);//台形法

double calc_pi(double x);//円周率の計算

int main(){
  int n;
  DOUBLE_FUNC_POINTER_DOUBLE f;//被積分関数
  D_FP_DFPD_I f1;
  D_FP_DFPD_I f2;
  
  printf("数値積分手法比較プログラム\n");
  printf("分割値を入力して下さい\n");
  scanf("%d",&n);
  
  f=&calc_pi;
  f1=&k_integral;
  f2=&d_integral;
  
  printf("result1=%f\n",f1(f,n));
  printf("result2=%f\n",f2(f,n));
  printf("diff=%f\n",diff_methods(f1,f2,f,n));
  
  return 0;
}
//短形法と台形方の差を求める
double diff_methods(D_FP_DFPD_I integral1,D_FP_DFPD_I integral2,DOUBLE_FUNC_POINTER_DOUBLE f,int n){
  return integral1(f,n)-integral2(f,n);
}

//短形法
double k_integral(DOUBLE_FUNC_POINTER_DOUBLE f,int n){
  double sum=0.0;
  double h=1.0/(double)n ;
  double x;
  int i;
  for(i=0;i<n;i++){
    x=(double)i*h;
    sum+=h*f(x);
  }
  return sum;
}
//台形法
double d_integral(DOUBLE_FUNC_POINTER_DOUBLE f,int n){
  int i;
  double h=1.0/(double)n;
  double sum=(f(0)+f(1))/2.0;
  double x=0.0;
  for (i = 1; i < n; i++) {
    x += h;
    sum += f(x);
  }
  sum=h*sum;
  return sum;
}
double calc_pi(double x){
  return 4.0/(1.0+x*x);
}

/*
(戻り値 *) 関数名(引数リスト)//戻り値がアドレスの関数定義

f_p=&f;すると
(*f_p)(3.0)はf(3.0)として動く
*/
