#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
char* numBer2Word(int number){
    switch (number){
    case 0 : return "khong " ;
    case 1 : return "mot "   ;
    case 2 : return "hai "   ;
    case 3 : return "ba "    ;
    case 4 : return "bon "   ;
    case 5 : return "nam "   ;
    case 6 : return "sau "   ;
    case 7 : return "bay "   ;
    case 8 : return "tam "   ;
    case 9 : return "chin "  ;
    default:
        break;
    }
}
char* position(int location){
    switch (location){
    case 1  : return "dong.\n"     ;
    case 2  : return "muoi "      ; 
    case 3  : return "tram "      ; 
    case 4  : return "nghin "     ; 
    case 5  : return "muoi "      ; 
    case 6  : return "tram "      ; 
    case 7  : return "trieu "     ; 
    case 8  : return "muoi "      ; 
    case 9  : return "tram "      ; 
    case 10 : return "ti "        ; 
    case 11 : return "muoi "      ;
    case 12 : return "tram "      ;
    case 13 : return "nghin "     ;
    default:
        break;
    }
}
uint8_t numberChar(char* array){
    uint8_t count = 0;
    while (*array != '\0'){
        count ++;
        array ++;
    }
    return count; 
}
void resufl(char* array){
    uint8_t location = numberChar(array);
    long long int number = atoll(array);
    long long int  sum =0;
    long long int  a = 0;
    uint8_t surplus = 0;
    while (number > 0){
        surplus = number%10;
        sum =sum*10 +surplus;
        number= number/10;
    }
    number = sum;
    
    while (number != 0)
    {
        surplus = number%10;
        if (surplus == 0){
            if (location  == 3 || location == 6 || location == 9)
            {
                printf("%s%s",numBer2Word(surplus), position(location));
                location --;
                number = number/10;
            }else if (location == 2||location == 5||location == 8 ||location ==11){
                a = number/10;
                surplus = a%10;
                if (surplus != 0)
                {
                    printf("le ");
                    location --;
                    number = number/10;
                }
                else{
                location --;
                number = number/10;}
            }
            else{
                printf("%s", position(location));
                location --;
                number = number/10;
                if (location < 0 ){
                    break;
                }                 
            }
        }
        else if (surplus == 1 && location == 11 ||surplus == 1 && location == 8 ||surplus == 1 && location == 5 ||surplus == 1 && location == 2){
            printf("%s",position(location));
            location--;
            number = number/10;
        }
        
        else{
            printf("%s%s",numBer2Word(surplus), position(location));          
            location--;  
            if (location == 0 ){
                break;
            }  
            number = number/10;  
        }        
    }
}
int main (){
    char array[] = "210300211002";
    resufl(array);
    return 0;   
}