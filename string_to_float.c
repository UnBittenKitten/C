#include <stdio.h>


int pows(int base, int expo);
int digitsOfInteger(int originalInteger);

int sizeOfString(char originalString[]);
float stringToFloat(char originalString[]);

int main() {
    char testString[] = "1234.612245";
    printf("The floating Point number in the string is: %f", stringToFloat(testString));

    return 0;
}

float stringToFloat(char originalString[]) {
    int i = 0;

    int integerPart = 0;
    float floatingPart = 0.0;
    float floatDestination;

    int boolCheck = 0;
    int negativeCheck = 0;

    //integerPart
    for(i = 0; i < sizeOfString(originalString); i++) {
        if(originalString[i] == 45) {
            negativeCheck++;
        }
        if(originalString[i] == 46) {
            boolCheck = 1;
            break;
        }
        if(originalString[i] > 47) {
            if(originalString[i] < 58) {
                int temporalIntValue;
                temporalIntValue = originalString[i] - 48;
                integerPart = 10 * integerPart + temporalIntValue;
            }  
        }
    }

    //floating point part
    if(boolCheck == 1) {

        for(i = i + 1; i < sizeOfString(originalString); i++) {
           if(originalString[i] > 47) {
                if(originalString[i] < 58) {
                    int temporalIntValueTwo;
                    temporalIntValueTwo = originalString[i] - 48;
                    floatingPart = 10 * floatingPart + temporalIntValueTwo;
                }  
            } 
        }
    }

    floatDestination = integerPart + floatingPart/pows(10, digitsOfInteger(floatingPart));

    if(negativeCheck > 0) {
        floatDestination *= -1;
    }
    return floatDestination;
}

int sizeOfString(char originalString[]) {
    int i = 0;
    while(originalString[i] != 0) {
        i++;
    }
    return i;
}

int digitsOfInteger(int originalInteger) {
    if(originalInteger < 0) {
        originalInteger *= -1;
    }
    int i = 1;
    int temporalInt = originalInteger / pows(10, i);
    while(temporalInt > 0) {
        i++;
        temporalInt = originalInteger / pows(10, i);
    }
    return i;
}

int pows(int base, int expo){
    int originalBase = base;
    long int answer = 1;
    if(expo != 0){
        for(int i = expo; i > 0; i--){
            answer = answer * originalBase;
        }
    } else { answer = 1;}
    return answer;
}
