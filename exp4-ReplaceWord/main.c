/*  yeu cau 1 . In hoa cac ky tu sau dau cham (DONE)
    yeu cau 2 . Tim chuoi tra ve ket qua va vi tri(DONE)
    yeu cau 3 . Thay the chuoi */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void upper(char *string){
    while (*string != '\0'){
        if (*string == '.'){
            string++;
            while (*string != '\0'){
                if(*string == ' ') string++;
                *string = *string - 32;
                string++;
            }                               
        }
        string++;
    }      
}
int findArray(char *arr, char *string){
    int count = 0;
    char *ptr = arr;
    while (*string != '\0'){
        if(*string == *arr ){
            while (*string == *arr || *arr == '\0'){
                if(*string == ' ' && *arr != '\0' || *arr !='\0' && *string == '\0' || *arr == '\0' && *string != ' ' ){                  
                     break;
                }
                else if (*arr == '\0'){                    
                    return count;
                }           
                string++;
                arr++;
            }count++ ;        
        }
        count++;
        string++;
        arr = ptr;

    }
    return count = - 1;
}
uint8_t numberWord(char *arr){
    uint8_t coutn = 0;
    while (*arr != '\0')    {
        coutn ++;
        arr++;
    }
    return coutn;
}
char* replaceWord(char *string, char *arr, char* arrReplace ){
    int location = findArray(arr,string);
    uint8_t numberReplace = numberWord(arr);
    uint8_t numberString = numberWord(string);
    uint8_t numberArrR = numberWord(arrReplace);
    char* Sstring = string + location;
    char* Aarayy = Sstring + numberReplace;
    char* array = (char*)malloc(sizeof(char)*(numberString+numberArrR-numberReplace+1));
    char* stringrl = array;
    if (location > -1){
        while (string < Sstring){
            *array = *string;
            string++;
            array++;
        }
        while(Sstring < Aarayy && *arrReplace != '\0'){
            *array = *arrReplace; 
            arrReplace++; 
            array++;            
            Sstring++; 
            string++;        
            if(*arrReplace == '\0' && Sstring< Aarayy){
                while(Sstring< Aarayy){
                    Sstring++;
                    string++;
                }       
            }
            else if (Sstring == Aarayy && *arrReplace != '\0'){
                while(*arrReplace != '\0'){
                    *array = *arrReplace;
                    array++;
                    arrReplace++;          
            }                              
        }}
        while (*string != '\0'){
            *array = *string;
            string++;
            array++;
        }
        if (*string == '\0'){
            *array = '\0';
        } 
        return stringrl;     
    }else printf("Khong tim thay chuoi can thay the\n");
}
int main (){
    char string[] = "to learn around the world learn to do annything. today we learn ab that";
   // upper(string);
    char f[] = "learn";
    printf("%s\n",string);
    int location = findArray(f,string);
    printf("Text: %s\n",f);
    printf((location>-1)?"Ket qua: Co\nVi Tri: %d\n":"Ket qua: Khong co\n", location);   
    char* replaWord = replaceWord(string,"ab","about");
    printf("%s\n",replaWord);
    return 0;
}