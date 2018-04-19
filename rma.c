/*  Corey Rondeau
 *  ECE 4680 - Lab 8
 *  4/17/18
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_TASKS 6
int main()
{
    // indexing values
    int i, k, l, j;
    int count = 0;
    int breakFlag = 0;
    float sum;
    // Initializing our values ---------------------------------------------------
    // Periods of the features
    float featurePeriods[6] = {2.56, 40.96, 61.44, 1000, 1024, 1280};
    // .153 ms overhead time
    float overhead = .153;
    // Task values (in ms)
    float taskRunTimes[6] = {1.3, 4.7, 9.0, 23.0, 38.3, 3.0};
    float taskTableUsages[6] = {.2, .2, .2, .3, .15, .3};
    float taskChannelUsages[6] = {0.0, 0.0, 0.0, 0.0, 3.0, 6.0};
    // Blocking times (in ms)
    float blockingTimes[6] = {0.3, 0.3, 6.3, 6.3, 0.3, 0.0};
    // Begin algorithm ------------------------------------------------------------
    // Loop for i (1 to number of tasks)
    for(i = 1; i <= NUM_TASKS; i++)
    {
        breakFlag = 0;
        // For each i, we have k = 1...i
        for(k = 1; k <= i; k++)
        {
            // For each k, we have l = 1...floor(period[i]/period[k])
            for(l = 1; l <= floor(featurePeriods[i-1]/featurePeriods[k-1]); l++)
            {
                // Reset sum value for new iteration
                sum = 0.0;
                // Compute sum on left side of equation from j = 1...i-1
                for(j = 1; j <= i - 1; j++)
                {
                    sum += ((taskRunTimes[j-1] + overhead)*(ceil((l * featurePeriods[k-1])/featurePeriods[j-1])));
                }
                sum += ((taskRunTimes[i-1] + overhead) + blockingTimes[i-1]);
                if(sum <= (l * featurePeriods[k-1]))
                {
                    // Found valid values, don't continue
                    count++;
                    // We also need to break out of the current k loop so we can go to
                    // the next i loop
                    breakFlag = 1;
                    printf("Found task with priority %d is schedulable with i:%d k:%d l:%d\n",i,i,k,l);
                    break;
                }
            }
            if(breakFlag) break;
        }
    }
    if((i-1) != count) printf("---------- !!NOT SCHEDULABLE!! ----------\n");
    else printf("---------- This is schedulable ----------\n");
    return 0;
}