#include <stdio.h>

int main() {
    int n1, n2, n3, n4;
    float media;
    
    printf("Digite quatro numeros inteiros:\n");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    
    media = (n1 + n2 + n3 + n4) / 4.0;
    
    printf("A media é: %.2f\n", media);
    
    return 0;
}
