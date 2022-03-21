#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int x,y,m;
    while ( scanf("%i %i %i", &x, &y, &m) != EOF)
    {
        int i,xi,yi;
        for (i=0; i<m; i++){
            scanf("%i %i", &xi, &yi);

            if (xi*yi <= x*y){
                if (xi<= x && yi<= y)
                {
                    printf("Sim\n");
                }
                else if (xi<=y && yi<=x)
                {
                    printf("Sim\n");
                }
                else
                {
                    printf("Nao\n");
                }                           
            
            }
            else
            {
                printf("Nao\n");
            }
            
        }
    }
    return 0;
}
