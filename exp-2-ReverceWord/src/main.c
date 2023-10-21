#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char *ptr;
    uint8_t lenght;
    /* data */
}words;

uint8_t numberWord (char *string){
    uint8_t count = 0;
    while (*string != '\0'){
        /* code */
        if(*string == ' ') count ++;
        string++;
    }
    return count+1;
}

words* splistString(char string[], uint8_t size){
    words *arr =(words*)malloc(sizeof(words)*size);
    uint8_t index = 0;
    uint8_t count = 0;
    arr[index].ptr = string;
    while (*string != '\0'){
        if (*string == ' ')
        {
            arr[index].lenght = count;
            count = 0;
            string++;
            index++;
            arr[index].ptr= string;
            /* code */
        }
        else{
            count++;
            string++;
        }
        
    }
    arr[index].lenght = count;
    return arr;

}
void display(words *string, uint8_t size ){

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
 words *ReverceWord(words* array, uint8_t size){ 
    words *arr = (words*)malloc(sizeof(words)*size);
    for (uint8_t i = 0; i < size; i++)
    {
        
        arr[i] = array[size - 1 - i];
                          /* code */
    }
    return arr;
}

int main(){
    char string[]  = "nhat hoang tuan nam nhat tuan hoang nhat nam bao an quoc";
    uint8_t size = numberWord(string);
    words *array = splistString(string,size);
    display(array,size); 
    words *recerArray = ReverceWord(array,size);
    display(recerArray,size); 
    return 0;
}