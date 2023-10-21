#include "main.h"

#include "date.h"
#include <stdbool.h>

bool checkYear(int countYear){
    if(((countYear % 4 ==0 && countYear % 100 ==0 && countYear % 400 != 0 ) || countYear % 4 != 0)) return false;
    else return true;
}
int result (){
    int countDay = 0;
    int coutnYear = Date.year;
    for (coutnYear ; coutnYear < dateCurrent.year ; coutnYear++){
        for( int coutnMonth = 1;  coutnMonth <13 ; coutnMonth ++){
           countDay += coutnofday(coutnMonth,coutnYear);
        }
    }
    for (int coutnMonth = 1; coutnMonth < dateCurrent.month; coutnMonth++ ){
        countDay += coutnofday(coutnMonth, dateCurrent.year);
    }
    countDay += dateCurrent.day;
    countDay = countDay % 7;
    findofday(countDay);
}
int coutnofday(int coutnMonth, int coutnYear1){
    int a =0;
switch (coutnMonth)
{
case 1 :
case 3 :
case 5 :
case 7 :
case 8 : 
case 10:
case 12:
    return a = 31 ;
    break;
case 2 : 
    if(checkYear(coutnYear1)){
        return a = 29;
        }
    else return a = 28;
default:
    return a = 30 ;
    break;
}}
int findofday(int coutnday1){
    switch (coutnday1)
    {
    case T2 : /* constant-expression */
        printf("Today Is %s\n",weekofDay[T2]);
        /* code */
        break;
    case T3 : /* constant-expression */
        printf("Today Is %s\n", weekofDay[T3]);
        /* code */
        break;
    case T4 : /* constant-expression */
        printf("Today Is %s\n", weekofDay[T4]);
        /* code */
        break;
    case T5 : /* constant-expression */
        printf("Today Is %s\n", weekofDay[T5]);
        /* code */
        break;
    case T6 : /* constant-expression */
        printf("Today Is %s\n" ,weekofDay[T6]);
        /* code */
        break;
    case T7 : /* constant-expression */
        printf("Today Is %s\n", weekofDay[T7]);
        /* code */
        break;
    case CN :
        printf("Today Is %s\n", weekofDay[CN]);
        break;
    default:
        printf("fail");
        break;
    }
}
int main(){
    result();
    return 0;
}