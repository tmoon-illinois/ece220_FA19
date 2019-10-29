#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NETWORK 100
#define MAX_BUF 200
int readFileToWifi();
void displayWifi();

typedef struct wifiStruct{

    char SSID[MAX_BUF];
    int signalStrength;
    int channel;
    double bandwidth;
    double freq;
    double max_rate;
}Wifi;

void swap(Wifi *firstVal, Wifi *secondVal);
void quickSort(Wifi array[], int low, int high);
int partition(Wifi array[], int low, int high);
int readFileToWifi(Wifi *ptr, char *filename);
void displayWifi(Wifi *ptr, int numWifi);

int readLines(char *filename);
int main()
{

    //Wifi w[MAX_NETWORK];
   
    char filename[MAX_BUF] = "data.txt";
    int numWifi = readLines(filename)-1;; // subtract 1 for header
    Wifi *ptr = (Wifi*) malloc(numWifi*sizeof(Wifi));
    
    readFileToWifi(ptr, filename);
    displayWifi(ptr, numWifi);

    Wifi *temp;
    strcpy(filename, "data2.txt");
    int new_numWifi = readLines(filename)-1;;
    temp = (Wifi*) realloc(ptr, (numWifi + new_numWifi)*sizeof(Wifi));
    if(temp ==NULL)
        return -1;
    else{
        ptr = temp;
        readFileToWifi(ptr+ numWifi, filename);
        displayWifi(ptr, numWifi+new_numWifi);
    }

    quickSort(ptr, 0, numWifi+ new_numWifi -1);
    displayWifi(ptr, numWifi + new_numWifi);

    free(ptr);

}
int readFileToWifi(Wifi *ptr,  char *filename)
{
    FILE *infile;
    infile = fopen(filename, "r");
    if(infile==NULL )
    {
        printf("Cannot open the file\n");
        return -1;
    }

    char buffer[MAX_BUF];
    fgets(buffer, MAX_BUF, infile);// skip the header

    while( fgets(buffer, MAX_BUF, infile) ){
        sscanf(buffer, "%s %d%*c %d %lf %lf %lf", ptr->SSID, &(ptr->signalStrength),  &(ptr->channel), &(ptr->bandwidth), &(ptr->freq), &(ptr->max_rate));
        ptr++;
    }

    fclose(infile);
}

void displayWifi(Wifi *ptr, int numWifi)
{
    int i;
    printf("=======================================================================================\n");
    //printf("Name,Team,HR,R,RBI,AVG,WAR\n");
    printf("%-20s%-15s%-10s%-15s%-15s%-15s\n", "SSID", "Strength", "Channel", "Bandwidth", "Frequency", "Max rate");
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0;i<numWifi;i++){
        printf("%-20s%-15d%-10d%-15.3lf%-15.3lf%-15.3lf\n", ptr->SSID, ptr->signalStrength, ptr->channel, ptr->bandwidth, ptr->freq, ptr->max_rate );
        ptr++;
    }
    printf("=======================================================================================\n\n\n");
}

void swap(Wifi *firstVal, Wifi *secondVal)
{
    Wifi tempVal;

    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}
void quickSort(Wifi array[], int low, int high)
{
    //base case
    if(low >= high)
        return;

    //recursive case
    int pivot_index = partition(array, low, high);
    quickSort(array, low , pivot_index-1 );// first half
    quickSort(array, pivot_index+1 , high );//second half
}

// partition: returing the pivot index
int partition(Wifi array[], int low, int high)
{
    int pivot = array[high].signalStrength; //set the last element as pivot
    int i = low - 1; // index of smaller element
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(array[j].signalStrength < pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i+1], &array[high]);


    return i+1;
}
int readLines(char *filename)
{
    FILE *infile;
    infile = fopen(filename, "r");
    if(infile==NULL )
    {
        printf("Cannot open the file\n");
        return -1;
    }
    char c;
    int cnt = 0;

    c = getc(infile);
    while(c != EOF){
        if(c=='\n')
            cnt++;
        c = getc(infile);
    }
    fclose(infile);

    return cnt;
}

