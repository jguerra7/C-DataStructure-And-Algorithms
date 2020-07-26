#include "../Headers/String.h"
#include "../../../System/Utils.h"





/** This function will take the initial length of the string as a parameter,
    then it will initialize a new String pointer and return it.
 * @param initialLength the string initial length
 * @return it will return the initialized string
 */

String *stringInitialization(int initialLength) {
    if (initialLength <= 0) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "initial length", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    String *myString = (String *) malloc(sizeof(String));
    if (myString == NULL) {
        fprintf(stderr, FAILED_ALLOCATION_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = FAILED_ALLOCATION;
     	#else
     		exit(FAILED_ALLOCATION);
     	#endif

    }

    myString->string = (char *) malloc(sizeof(char) * (initialLength + 1) );
    if (myString->string == NULL) {
        fprintf(stderr, FAILED_ALLOCATION_MESSAGE, "string array", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = FAILED_ALLOCATION;
     	#else
     		exit(FAILED_ALLOCATION);
     	#endif

    }

    myString->string[0] = '\0';
    myString->count = 0;
    myString->length = initialLength;

    return myString;
}




/** This function will take the string address, and the new character as a parameter,
    then it will put the new character in the end of the string.
 * @param myString the string address
 * @param c the new character
 */

void stringAddCharAtLast(String *myString, char c) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    if (myString->count == myString->length) {
        myString->length *= 2;
        myString->string = realloc(myString->string, sizeof(char) * (myString->length + 1));
        if (myString->string == NULL) {
            fprintf(stderr, FAILED_REALLOCATION_MESSAGE, "string array", "string data structure");
            #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = FAILED_REALLOCATION;
     	#else
     		exit(FAILED_REALLOCATION);
     	#endif

        }

    }

    myString->string[myString->count++] = c;
    myString->string[myString->count] = '\0';
}




/** This function will take the string address, index, and the new character as a parameters,
    then it will put the new character in the given index.
 * If the index is out of the string range the program will terminate.
 * @param myString the string address
 * @param index the new character index
 * @param c the new character
 */

void stringAddCharAtIndex(String *myString, int index, char c) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (myString->count <= index || index < 0) {
        fprintf(stderr, OUT_OF_RANGE_MESSAGE, "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = OUT_OF_RANGE;
     	#else
     		exit(OUT_OF_RANGE);
     	#endif

    }

    myString->string[index] = c;

}




/** This function will take the string address, and the index as a parameter,
    then it will remove the character in the given index.
 * If the index is out of the string range the program will terminate.
 * @param myString the string address
 * @param index the index of the char that will be removed
 */

void stringRemoveCharAtIndex(String *myString, int index) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (myString->count <= index || index < 0) {
        fprintf(stderr, OUT_OF_RANGE_MESSAGE, "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = OUT_OF_RANGE;
     	#else
     		exit(OUT_OF_RANGE);
     	#endif

    }

    for (int i = index; i < myString->count; i++)
        myString->string[i] = myString->string[i + 1];

    myString->count--;
}




/** This function will take the string address, and the new char pointer array as a parameters,
    then it will add the new array of characters in the end of the string.
 * @param myString the string address
 * @param newString the char array address
 */

void stringAddStringAtLast(String *myString, char *newString) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (newString == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "new string pointer", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    char *currentChar = newString;
    while (*currentChar != '\0') {
        stringAddCharAtLast(myString, *currentChar);
        currentChar++;
    }

}




/** This function will take the string address, and the new char pointer array as a parameters,
    then it will change the string to the new char pointer array.
 * @param string the string address
 * @param newString a char array address
 */

void stringChangeStringByCharArray(String *string, char *newString) {
    if (string == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (newString == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "new string pointer", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    string->count = 0;

    while (*newString != '\0')
        stringAddCharAtLast(string, *newString++);

}



/** This function will take string address, and the the new string address as a parameters,
    then it will change the first string to the second string.
 * @param string the string address
 * @param newString the new string address
 */

void stringChangeStringByString(String *string, String *newString) {
    if (string == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (newString == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "new string pointer", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    string->count = 0;
    string->string[string->count] = '\0';

    for (int i = 0; i < stringGetLength(newString); i++)
        stringAddCharAtLast(string, stringGetCharAtIndex(newString, i));


}




/** This function will take the string address, and the character as a parameters,
    then it will return the first occur of this character in the string and will return it's index,
    other wise it will return minus one (-1).
 * @param myString the string address
 * @param c the character value
 * @return it will return the first index of the provided character if found, other wise it will return -1
 */

int stringFindCharIndex(String *myString, char c) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    for (int i = 0; i < myString->count; i++) {
        if (myString->string[i] == c)
            return i;

    }

    return -1;
}




/** This function will take the string address, and the index as a parameters,
    then it will return the character at the given index.
 * If the index is out of the string range the program will terminate.
 * @param myString the string address
 * @param index the index of the wanted character
 * @return it will return the character at the provided index
 */

char stringGetCharAtIndex(String *myString, int index) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (myString->count <= index || index < 0) {
        fprintf(stderr, OUT_OF_RANGE_MESSAGE, "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = OUT_OF_RANGE;
     	#else
     		exit(OUT_OF_RANGE);
     	#endif

    }

    return myString->string[index];
}




/** This function will take the string address, and a char pointer array as a parameters,
    then it will return one (1) if the second char array is a substring of the first string,
    other wise it will return zero (0).
 * @param myString the string address
 * @param string a char array address
 * @return it will return one if the provided char array are a substring of the original string
 */

int stringSubString(String *myString, char *string) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (string == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "second string pointer", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    int stringLength = strlen(string);

    if (stringLength > myString->count)
        return 0;

    for (int i = 0; i <= myString->count - stringLength; i++) {
        for (int j = 0; j < stringLength; j++) {
            if (myString->string[i + j] != string[j])
                break;

            else if (j == stringLength - 1)
                return 1;

        }
    }

    return 0;
}




/** This function will take the string address as a parameter,
 * then it will convert it to a char pointer array, and return it.
 * @param myString the string address
 * @return it will return a pointer to char array that has the same string of myString
 */

char *stringToArrayOfCharacters(String *myString) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    char *arrayOfCharacters = (char *) malloc(sizeof(char) * (myString->count + 1) );
    if (arrayOfCharacters == NULL) {
        fprintf(stderr, FAILED_ALLOCATION_MESSAGE, "to array of characters", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = FAILED_ALLOCATION;
     	#else
     		exit(FAILED_ALLOCATION);
     	#endif

    }

    for (int i = 0; i <= myString->count; i++)
        arrayOfCharacters[i] = myString->string[i];

    return arrayOfCharacters;
}




/** This method will take the string address, start index, and end index as a parameters,
    then it will convert the string from the start index to the end index to a char pointer array,
    then return it.
 * @param myString the string address
 * @param startIndex the start index
 * @param endIndex the end index
 * @return it will return a pointer to character array, that has copy of the from the start index to the end index
 */

char *stringGetStringBetweenTwoIndices(String *myString, int startIndex, int endIndex) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    if (startIndex > endIndex
        || startIndex < 0 || startIndex >= myString->count
        || endIndex < 0 || endIndex >= myString->count) {

        fprintf(stderr, OUT_OF_RANGE_MESSAGE, "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = OUT_OF_RANGE;
     	#else
     		exit(OUT_OF_RANGE);
     	#endif

    }

    char *string = (char *) malloc(sizeof(char) * (endIndex - startIndex + 2) );
    if (string == NULL) {
        fprintf(stderr, FAILED_ALLOCATION_MESSAGE, "string between to indices", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = FAILED_ALLOCATION;
     	#else
     		exit(FAILED_ALLOCATION);
     	#endif

    }

    string[endIndex - startIndex + 1] = '\0';
    for (int i = 0; i <= endIndex - startIndex; i++)
        string[i] = myString->string[startIndex + i];

    return string;

}




/** This function will take the string address as a parameter,
    then it will return the string length.
 * @param myString the string address
 * @return it will return the length of the string
 */

int stringGetLength(String *myString) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    return myString->count;
}




/** This function will take the string address, and a char pointer array as a parameters,
    then it will return one (1) if the string is equal to the char array,
    other wise it will return zero (0).
 * @param myString the string address
 * @param string a character array pointer
 * @return it will return one if the provided char array is equal to the string, other wise in will return zero
 */

int stringIsEqualsToCharArray(String *myString, char *string) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (string == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "second string pointer", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    int stringLength = strlen(string);
    if (myString->count != stringLength)
        return 0;

    for (int i = 0; i < myString->count; i++) {

        if (myString->string[i] != string[i])
            return 0;

    }

    return 1;
}




/** This function will take the string address, and second string address as a parameters,
    then it will return one (1) if the first string is equal to the second string,
    other wise it will return zero (0).
 * @param myString the string address
 * @param string the other string address
 * @return it will return one if the second string is equal to the original string, other wise in will return zero
 */

int stringIsEqualsToMyString(String *myString, String *string) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    } else if (string == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "second string pointer", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = INVALID_ARG;
     	#else
     		exit(INVALID_ARG);
     	#endif

    }

    int stringLength = stringGetLength(string);
    if (myString->count != stringLength)
        return 0;

    for (int i = 0; i < stringLength; i++) {

        if (myString->string[i] != string->string[i])
            return 0;

    }

    return 1;
}






/** This function will return one (1) if the passed characters is a part of the passed character array,
 * other wise if will return zero (0).
 * @param charArr the char array pointer
 * @param c the character value, that the function will search for
 * @return it will return one if the character value exist in the char array, other wise it will return zero
 */

int stringContainsChar(char *charArr, char c) {

    while (*charArr != '\0') {
        if (*charArr++ == c)
            return 1;

    }

    return 0;

}







/** This function will take string pointer,
 * then it will removes characters specified in the second array of characters parameter,
 * from the beginning of the string.
 *
 * ex of specialCharacters array: " \t\n", the function will remove any ' ', '\t', ' ' character from the beginning.
 *
 * @param myString the string pointer
 * @param specialCharacters the special characters array pointer
 */

void stringTrimStartC(String *myString, char *specialCharacters) {

    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(NULL_POINTER);
        #endif
    } else if (specialCharacters == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "special characters array", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(INVALID_ARG);
        #endif
    }

    char *charArr = myString->string;
    while (*charArr != '\0') {

        if (stringContainsChar(specialCharacters, *charArr)) {
            char *tempPointer = charArr;

            do {
                *tempPointer = *(tempPointer + 1);
            } while (*tempPointer++ != '\0');

            myString->count--;

        } else
            break;

    }


}




/** This function will take string pointer,
 * then it will remove ' ', '\t' and '\n' characters,
 * from the beginning of the string.
 *
 * @param myString the string pointer
 */

void stringTrimStart(String *myString) {

    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(NULL_POINTER);
        #endif
    }

    stringTrimStartC(myString, " \n\t");
}







/** This function will take string pointer,
 * then it will removes characters specified in the second array of characters parameter,
 * from the end of the string.
 *
 * ex of specialCharacters array: " \t\n", the function will remove any ' ', '\t', ' ' character from the end.
 *
 * @param myString the string pointer
 * @param specialCharacters the special characters array pointer
 */

void stringTrimEndC(String *myString, char *specialCharacters) {

    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(NULL_POINTER);
        #endif
    } else if (specialCharacters == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "special characters array", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(INVALID_ARG);
        #endif
    }

    char *charArr = myString->string;
    char *startPointer = myString->string;

    while (*charArr != '\0')
        charArr++;

    while ( startPointer - sizeof(char) != --charArr && stringContainsChar(specialCharacters, *charArr) ) {
        *charArr = '\0';
        myString->count--;
    }

}



/** This function will take string pointer,
 * then it will remove ' ', '\t' and '\n' characters,
 * from the end of the string.
 *
 *
 * @param myString the string pointer
 */

void stringTrimEnd(String *myString) {

    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(NULL_POINTER);
        #endif
    }

    stringTrimEndC(myString, " \n\t");
}






/** This function will take string pointer,
 * then it will remove ' ', '\t' and '\n' characters,
 * from the beginning and the end of the string.
 *
 *
 * @param myString the string pointer
 */

void stringTrim(String *myString) {

    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(NULL_POINTER);
        #endif
    }

    stringTrimStartC(myString, " \n\t");
    stringTrimEndC(myString, " \n\t");

}







/** This function will take string pointer,
 * then it will removes characters specified in the second array of characters parameter,
 * from the beginning and the end of the string.
 *
 * ex of specialCharacters array: " \t\n", the function will remove any ' ', '\t', ' ' character from the end.
 *
 * @param myString the string pointer
 * @param specialCharacters the special characters array pointer
 */

void stringTrimC(String *myString, char *specialCharacters) {

    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(NULL_POINTER);
        #endif
    } else if (specialCharacters == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "special characters array", "string data structure");
        #ifdef CU_TEST_H
            DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
        #else
            exit(INVALID_ARG);
        #endif
    }

    stringTrimStartC(myString, specialCharacters);
    stringTrimEndC(myString, specialCharacters);

}









/** This function will take the string address as a parameter,
 * then it will read the input from the stdin file and put it in the string.
 * @param myString the string address
 */

void stringFGetS(String *myString) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    char c;

    while (1) {
        c = fgetc(stdin);

        if (c == '\n')
            break;

        stringAddCharAtLast(myString, c);
    }

    fseek(stdin, 0, SEEK_END);
}






/** This function will take the string address as a parameter,
 * then it will print the string in the stdout file.
 * @param string the string address
 */

void printString(String *string) {

    if (string == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    fprintf(stdout, "%s", string->string);

}





/** This function will take the string address as a parameter,
 * then it will destroy and free the string from the memory.
 * @param myString the string address
 */

void destroyString(String *myString) {
    if (myString == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "string", "string data structure");
        #ifdef CU_TEST_H
     		DUMMY_TEST_DATASTRUCTURE->errorCode = NULL_POINTER;
     	#else
     		exit(NULL_POINTER);
     	#endif

    }

    free(myString->string);
    free(myString);
}