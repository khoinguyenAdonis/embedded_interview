#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    char* ptr;
    uint8_t length;
    uint8_t count ;
    /* data */
}words;

words *splistString(char array[], uint8_t size){
    words *arr = (words*)malloc(sizeof(words) * size);
    uint8_t index =0;
    uint8_t count =0;
    arr[index].ptr = array;
    while ( *array != '\0')
    {
        if(*array == ' '){
            arr[index].length = count;
            count = 0;
            array++;
            index++; 
            arr[index].ptr = array;
        }else{
            
            count++;
            array++;
        }
     
    }
    arr[index].length = count;  
    return arr;
    
}


uint8_t numberChar(char* arr){
    uint8_t count = 0;
    while(*arr != '\0')
    {
        if(*arr == ' ') count++;
        arr++;
        /* code */
    }
    return count+1;
    
}
void display(words array[], uint8_t size ){
    for(uint8_t i = 0; i < size ; i++){
        uint8_t j = 0;

        while (j != array[i].length)
        {
            printf("%c", array[i].ptr[j]);
            j++;
            /* code */
        }
       printf(" ");
        
    }
}
bool compare(const char arr1[], const char arr2[]){
    uint8_t i = 0;
    while ( arr1[i] != ' ')
    {
        if (arr1[i] > arr2[i] ) return true;
        else if ( arr1[i] < arr2[i])
        {
            return false;
            /* code */
        }
        i++;
        /* code */
    }
    return false;
    
}
void sortName(words array[], uint8_t size){
    for(uint8_t i = 0; i< size; i++)
    {
        uint8_t temp = i;
        for(uint8_t j = i+1 ; j < size; j++){
            if (compare(array[temp].ptr,array[j].ptr)) temp = j;
        }
        words s = array[i];
        array[i] = array[temp];
        array[temp] = s;
    }
}
bool cpare(const char arr1[],const char arr2[]){
    uint8_t i = 0;
    while ( arr1[i] != ' ')
    {
        if (arr1[i] > arr2[i] ) return false;
        else if ( arr1[i] < arr2[i])
        {
            return false;
            /* code */
        }
        
        i++;
        /* code */
    }
    return true;
    
    
}
void occurrences(words array[], uint8_t size){
    uint8_t count = 0;
    for(uint8_t i = 0; i< size; i++){
        for(uint8_t j = 0 ; j < size; j++){  

            if (cpare(array[i].ptr,array[j].ptr))
            {
                
                count +=1;
            }
            
           
    }
        array[i].count = count;
        count = 0;
    }
    
}
void printoCcur(words array [], uint8_t size){
    for(int i = 0 ; i < size ; i++){
        int j = 0;
        while ( j != array[i].length)
        {
            printf("%c",array[i].ptr[j]);
            j++;
            /* code */
        }
       printf(": %d\n", array[i].count);
        
    } 

}
int main ()
{
    char array[] = "nam bao hoang hoang yen nam hoang yen ";
    uint8_t size = numberChar(array);
    words* string = splistString(array,size);
   
    display(string, size);
    
    sortName(string,size);
    printf("\n-------------------------------\n");

    display(string,size);
    
    printf("\n-------------------------------\n");
    
    words* arr = splistString(array,size);
    occurrences(arr,size);
    printoCcur(arr,size);
    return 0;
}