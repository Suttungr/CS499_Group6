#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool characteristic(char numString[], int *c);
bool mantissa(char numString[], int *numerator, int *denominator);

int main()
{
    char number[] = "123.00456";
    int c, n, d;
    characteristic(number, &c);
    mantissa(number, &n, &d);
    
    printf("This is our 'c' (characteristic)number: %d\n", c);
    printf("This is our 'n' (numerator) number: %d\n", n);
    printf("This is our 'd' (denominator) number: %d\n", d);
}

bool characteristic(char numString[], int *c){
    char *copy = malloc(strlen(numString) + 1);
    strcpy(copy, numString);
    char *token = strtok(copy,".");
    
    if(token){
        *c = atoi(token);
        return true;
    }
    else{
        return false;
    }
}

bool mantissa(char numString[], int *numerator, int *denominator){
    char *copy1 = malloc(strlen(numString) + 1);
    strcpy(copy1, numString);
    char *token1 = strchr(copy1,".");
    token1 = strtok(NULL, ".");
    
    char *token2 = token1;
    char temp[] = "1";
    int len = strlen(token2);
    
    for(int i=0;i<len;i++)
    {
        strcat(&temp[i],"0");
    }
    
    if(token1){
        *numerator = atoi(token1);
        *denominator = atoi(temp);
        return true;
    }
    else{
        return false;
    }
}