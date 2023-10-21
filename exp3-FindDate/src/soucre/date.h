#ifndef __DATE_H__
#define __DATE_H__
#include <stdint.h>

enum{
    T2 = 3,
    T3 = 4,
    T4 = 5,
    T5 = 6,
    T6 = 0,
    T7 = 1,
    CN = 2,
};

typedef struct
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
    
    /* data */
}date;

const char *weekofDay[] = {"Friday","Satuday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
const date Date  = {1, 1, 2000};
date dateCurrent = {21, 10, 2023};

#endif