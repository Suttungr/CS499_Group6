
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool characteristic(char numString[], int *c);
bool mantissa(char numString[], int *numerator, int *denominator);

int main()
{

char number[] = "123.00456";
int c, n, d;

//if the conversion from C string to integers can take place
if(characteristic(number, &c) && mantissa(number, &n, &d))
{
    //do some math with c, n, and d

}
else
{
    //handle the error on input

}
}

bool characteristic(char numString[], int *c){
    char *copy = malloc(strlen(numString) + 1);
    strcpy(copy, numString);
    char *token = strtok(copy,".");

    if(token){
        c = atoi(token);
        return true;
    }
    else{
        return false;
    }
}

bool mantissa(char numString[], int *numerator, int *denominator){
    char *copy1 = malloc(strlen(numString) + 1);
    strcpy(copy1, numString);

    char *token1 = strtok(copy1,".");
    token1 = strtok(NULL, ".");

    char temp[] = "1";

    for(int i=0;i<strlen(token1)+1;i++)
    {
        //strcat(temp,"0");
    }

    // the end result of this would be a way to get
    // the denominator but i am not possitive

    if(token1){
      numerator = atoi(token1);
      // do not know how to figure out the denominator part
      // im guessing it has something to do with logs


      return true;
    }
    else{
        return false;
    }
}
