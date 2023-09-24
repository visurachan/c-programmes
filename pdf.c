#include <stdio.h>
#include <stdint.h>


int main (int args, char * argv[])
{
    if (args != 2)
    {
        printf("Unsupported input \n");
        return 1;
    }

    uint8_t buffer [4];
    uint8_t signature[] = {37,80,68,70};
    char *file_name = argv[1];

    FILE *file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("File not found \n");
        fclose(file);
        return 1;
    }

    fread (buffer,1,4,file);
    
    for (int i = 0; i<4 ;i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("File type is not likely pdf \n");
            fclose (file);
            return 0;
        
        }

    }
    printf("File type likely pdf. \n");
    fclose(file);
    return 1;

}   
