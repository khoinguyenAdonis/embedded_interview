/*  yeu cau 1 . In hoa cac ky tu sau dau cham (DONE)
    yeu cau 2 . Tim chuoi tra ve ket qua va vi tri(DONE)
    yeu cau 3 . Thay the chuoi */
#include <stdio.h>
#include <stdint.h>
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
void findArray(char *arr, char *string){
    uint8_t cozz = 0;
    char *ptr = arr;
    while (*string != '\0'){
        if(*string == *arr ){
            while (*string == *arr || *arr == '\0'){
                if(*string == ' ' && *arr != '\0' || *arr !='\0' && *string == '\0' || *arr == '\0' && *string != ' ' ){
                    break;
                }
                else if (*arr == '\0'){
                    printf("Da tim thay chuoi da nhap !\nVi tri la: %d\n",cozz);
                    return ;
                }
                string++;
                arr++;
            }            
        }
        cozz++;
        string++;
        arr = ptr;

    }
    printf("Khong tim thay chuoi da nhap!\n");
}

int main (){
    char string[] = "to learn around the world learn to do annything. today we learn ab that";
 //   upper(string);
    char f[] = "lear";
    findArray(f,string);
    printf("%s\n",string);
    return 0;
}