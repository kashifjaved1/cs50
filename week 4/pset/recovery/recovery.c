#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]){

    if (argc != 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    unsigned char buffer[512];
    int count = 0, found = 0;
    FILE *output = NULL;

    while(fread(buffer, 512, 1, file)){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if(found == 1){
                fclose(output);
            }
            else{
                found = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", count++);
            output = fopen(filename, "w");
        }
        if(found == 1){
            fwrite(buffer, 512, 1, output);
        }
    }

    fclose(file);
    fclose(output);

}