/*  Corey Rondeau
 *  ECE 4680 - Lab 8
 *  4/17/18
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, k, l;
    int count;
    float sum;

    // Initializing our values ---------------------------------------------------
    // Features
    float altitudeDataT = 2.56;
    float velocityDataT = 40.96;
    float positionDataT = 1280.0;
    float dispData = 1000.0;
    float attitudeMessage = 61.44;
    float navigationMessage = 1024.0;
    float overhead = .153;  // .153 ms overhead time

    // Tasks
    float attRT = 1.3, attTableUsage = .2, attChannelUsage = 0;
    float veloRT = 4.7, veloTableUsage = .2, veloTableUsage = 0;
    float posRT = 3.00, posTableUsage = .2, posChannelUsage = 0;
    float dispRT = 23.0, dispTableUsage = .3, dispChannelUsage = 0;
    float attMessRT = 9.0, attMessTableUsage = .15, attMessChannelUsage = 3.0;
    float navMessRT = 38.3, navMessTableUsage = .3, navMessageChannelUsage = 6.0;




    return 0;
}