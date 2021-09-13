#include <stdio.h>
#include <math.h> // fabs (float absolute) needs this



int main(){
    int numCo; //number of points (coordinates)
    printf("Enter the number of your coordinates: ");
    scanf("%d", &numCo);

    double xArray[numCo+1]; //declare an array to store the x-compositions
    double yArray[numCo+1]; //declare an array to store the y-compositions

    printf("Now, enter all of your coordinates in clockwise or counterclockwise.\n");
    //because, if you have a set of points, you can construct more than one polygon.

    for (int i = 0; i < numCo; i++)
    {
        printf("x_%d = ", i+1);
        scanf("%lf", &xArray[i]);
        printf("y_%d = ", i+1);
        scanf("%lf", &yArray[i]);
    }


    xArray[numCo] = xArray[0]; //assign the last entry to be the same as the first
    yArray[numCo] = yArray[0]; //because of math stuff lol


    double multiDown[numCo]; //store some important things
    double multiUp[numCo]; //which are involving math again
    double almostArea;
    // don't blame me! this is how OCD declare variables

    for (int j = 0; j < numCo; j++)
    {
        multiDown[j] = xArray[j] * yArray[j+1];
        multiUp[j] = -1 * xArray[j+1] * yArray[j];
        almostArea += multiDown[j] + multiUp[j];
    }

    double area = 0.5 * fabs(almostArea);

    printf("The area is %lf units^2\n", area);

    return 0;
}
