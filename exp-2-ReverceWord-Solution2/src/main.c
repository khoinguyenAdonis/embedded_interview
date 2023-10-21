#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
    char *ptr;
    uint8_t lenght;
}words;

static uint8_t numberWord (char *string){
    uint8_t count = 0;
    while (*string != '\0'){
        if(*string == ' ') count ++;
        string++;
    }
    return count+1;
}

words* splistString(char string[]){
    uint8_t size =  numberWord(string);
    words *arr =(words*)malloc(sizeof(words)*size);
    uint8_t index = size - 1;
    uint8_t count = 0;
    arr[index].ptr = string;
    while (*string != '\0'){
        if (*string == ' ')
        {
            arr[index].lenght = count;
            count = 0;
            string++;
            index--;
            arr[index].ptr= string;
        }
        else{
            count++;
            string++;
        }       
    }
    arr[index].lenght = count;
    return arr;
}
void display(words *string, char *arr ){
    uint8_t size = numberWord(arr);
    for(uint8_t i = 0; i < size; i++){
        for (uint8_t j = 0; j < string[i].lenght; j++)
        {
            printf("%c", string[i].ptr[j]);
            /* code */
        }
        printf(" ");        
    }
    printf("\n");
}

int main(){
    char string[]  = "nhat hoang tuan nam nhat tuan hoang nhat nam bao an quoc";
    words *array = splistString(string);
    display(array,string); 
    return 0;
}