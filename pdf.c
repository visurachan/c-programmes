#include <stdio.h>
#include <stdint.h>
#include "cs50.h"

int main (int args, string argv[])
{
    if (args != 2)
    {
        printf("Unsupported input \n");
        return 1;
    }

    uint8_t buffer [4];
    uint8_t signature[] = {37,80,68,70};
    string file_name = argv[1];

    FILE *file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("File not found \n");
        return 1;
    }

    fread (buffer,1,4,file);
    for (int i =0; i<4; i++)
    {
        printf("%i \n",buffer[i]);
    }
    
    for (int i = 0; i<4 ;i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("File type is not likely pdf \n");
            
            return 0;
        
        }

    }
    printf("File type likely pdf. \n");
    fclose(file);
    return 1;

}   
