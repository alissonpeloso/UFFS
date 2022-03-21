#include <stdio.h>
#include <math.h>

int main(){
  int n;
  double answer;
  printf("Digite o número desejado: ");
  scanf("%d", &n);
  answer = (sqrt(5)/5)*(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n));
  printf("A resposta é: %.f\n", answer);
}
