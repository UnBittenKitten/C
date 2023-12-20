#include <stdio.h> 
#include <stdlib.h>

//takes 3 arguments, the string itself, the start and the end point

int sizeOfString(char originalString[]);

char* stringSnipper(char wholeString[], unsigned int start, unsigned int end) {
    if(start > end) {
        return 0; //ensures that end > start
    }
    if(end > sizeOfString(wholeString)) {
        end = sizeOfString(wholeString); 
    }
    
    char *p = malloc(end - start + 2);
    int i;
    for(i = 0; i < end - start + 1; i++) {
        p[i] = wholeString[i + start];
    }
    p[i] = '\0';
    return p;
}

int main() {
    char testString[20] = "iHatePointers";
    printf("The result string is: \n%s", stringSnipper(testString, 1, 7));
    return 0;
}

int sizeOfString(char originalString[]) {
    int i = 0;
    while(originalString[i] != 0) {
        i++;
    }
    return i;
}
