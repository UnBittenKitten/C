#include <stdio.h>
#include <stdlib.h>

int sizeOfString(char originalString[]);

char* stringMover(char* originalString, unsigned int start, int displacement) {
    if(displacement == 0) {
        return originalString;
    }
    if(displacement < 0) {
        if(abs(displacement) > start) {
        displacement = -1*start;
        }
    }

    int outSize = sizeOfString(originalString) + displacement + 1;
    char* output = malloc(outSize);

    for(int i = 0; i < start; i++) {
        output[i] = originalString[i];
    }

    for(int i = start + displacement; i < outSize; i++) {
        output[i] = originalString[i - displacement];
    }

    if(displacement > 0) {
        for(int i = start; i < start + displacement; i++) {
        output[i] = ' ';
        }
    }
    
    output[outSize] = 0;
    return output;
}

int main() {
    printf("%s", stringMover("apocosi", 3, -2));

    return 0;
}

int sizeOfString(char originalString[]) {
    int i = 0;
    while(originalString[i] != 0) {
        i++;
    }
    return i;
}
