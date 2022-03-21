#include <stdio.h>
#include <math.h>

float absolute(float value) {
  if (value < 0)
    return -value;
  return value;
}

int main(){
  float xo,i;
  int n;
  printf("Insira a primeira coordenada desejada:");
  scanf("%f",&xo);
  printf("Insira a segunda coordenada desejada:");
  scanf("%f",&i);
  printf("Insira o valor de n:");
  scanf("%d",&n);
  if(xo>i){
    float sub = xo;
    xo = i;
    i = sub;
  }
  float sum = 0;
  float dxi = (i-xo)/n;
  float xi = xo+dxi;

  while(xi<=i){
    float ci =(xo+xi)/2;
    printf("Xo = %.2f\n", xo);
    printf("Ci = %.2f\n", ci);

    float temp = (pow(ci,3)+1)*dxi;
    sum+=absolute(temp);

    printf("%f\n", absolute(pow(ci,3)));
    printf("Sum = %.2f\n", sum);
    xi+= dxi;
    xo+= dxi;
  }
  printf("O resultado é: %.2f\n", sum);
}
