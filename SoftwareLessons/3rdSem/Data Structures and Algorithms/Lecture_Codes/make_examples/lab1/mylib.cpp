#include <iostream>
#include "header.hpp"

double sum(double arr[], int n)
{
    int sum = 0; // initialize sum
 
    // Iterate through all elements
    // and add them to sum
    for (int i = 0; i < n; i++)
    sum += arr[i];
 
    return sum;

}

double mean(double arr[], int n)
{
    // Find sum of array element
    int sum = 0;
    for (int i=0; i<n; i++)
       sum += arr[i];
 
    return (double)sum/n;
}

void print (double arr[], int n)
{
    
}

