#include <stdio.h>
#include <math.h>

#define SMALL 0.000000001

int main(){
	double features[6][3];
	char *elements[6];

	//feature names
	elements[0] = "Compute Attitude Data";
	elements[1] = "Compute Velocity Data";
	elements[2] = "Compose Attitude Message";
	elements[3] = "Display Data";
	elements[4] = "Compose Navigation Message";
	elements[5] = "Compute Position Data";

	//period
	features[0][0] = 2.56;
	features[1][0] = 40.96;
	features[2][0] = 61.44;
	features[3][0] = 1000;
	features[4][0] = 1024;
	features[5][0] = 1280;

	//runtime
	features[0][1] = 1.3;
	features[1][1] = 4.7;
	features[2][1] = 9;
	features[3][1] = 23;
	features[4][1] = 38.3;
	features[5][1] = 3;
	
	//max blocktime
	features[0][2] = 0.3;
	features[1][2] = 0.3;
	features[2][2] = 6.3;
	features[3][2] = 6.3;
	features[4][2] = 0.3;
	features[5][2] = 0;

	int i, l, k, sumcount;
	double sum;

	for(i = 0; i < 6; i++){
		for(k = 0; k < (i+1); k++){
			for(l = 0; l < floor(features[i][0]/features[k][0]); l++){
				sum = 0;
				sumcount = 0;

				while(sumcount != i){ 							//add all previous entries as many times they can possibly fit
					sum += ((features[sumcount][1] + .153) * ceil(((l+1)*features[k][0])/features[sumcount][0])); 
					sumcount++;
				}											//.153ms = 153us overhead for each task

				sum += features[i][1] + .153 + features[i][2]; 	//plus current entry and max blocking
				if(sum < features[k][0]*(l+1)){
					printf(" %s is schedulable at k = %d, l = %d.\n", elements[i], (k+1), (l+1));
					break;
				}
			}
			if(l < floor(features[i][0]/features[k][0])){		//if broken from finding the smallest l, break to i-level for-loop and go to next element
				break;
			}
		}
		if(k == (i+1)){
			printf("%s is not schedulable, element %d", elements[i], i);
		}
	}

	return 0;
}