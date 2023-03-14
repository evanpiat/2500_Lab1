#include <stdio.h>

int main (int argc, char *argv[])
{
    int numWords=0;
    int numLines=0;
    int numChars;
    char character;
    int numOfArray[100];
    int numOfLine=0;
    if (argc < 2){
        printf ("\nError with program!\n");
        return 1;
    }else{
        printf ("\nFile used: %s\n", argv[1]);
        FILE *fp = fopen (argv[1],"r");
        
        while ((character = fgetc(fp))!='.'){
            numChars++;    
            if (character == ' ' || character  == '\n' || character == '\0'){
                numWords++;
                numOfLine++;
            }
            if (character == '\n'|| character=='\0'){
                numOfArray[numLines]=numOfLine;
                numLines++;
                numOfLine=0;
            }
        }
        if (numChars > 0){
            numWords++;
            numLines++;
            numOfLine++;
            numOfArray[numLines-1]=numOfLine;
        }
        
        printf("%d on %d lines\n",numWords, numLines);
        
        for (int i=0; i < numLines;i++){
            printf("%d ", numOfArray[i]);
        }

        printf("\n");
        fclose (fp);
    }
    return 0;
}