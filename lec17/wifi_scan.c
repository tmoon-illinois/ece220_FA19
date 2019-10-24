#include <stdio.h>
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

int readFileToWifi(Wifi *ptr, int *numWifi,  char *filename);
void displayWifi(Wifi *ptr, int numWifi);

int main()
{

    Wifi w[MAX_NETWORK];
    Wifi *ptr;
    ptr = w;
    char filename[MAX_BUF] = "data.txt";
    int numWifi;
    
    readFileToWifi(ptr, &numWifi,  filename);
    displayWifi(ptr, numWifi);

    quickSort(w, 0, numWifi-1);
    displayWifi(ptr, numWifi);

}
int readFileToWifi(Wifi *ptr, int *numWifi,  char *filename)
{
    FILE *infile;
    infile = fopen(filename, "r");
    if(infile==NULL )
    {
        printf("Cannot open the file\n");
        return -1;
    }

    char buffer[MAX_BUF];
    int cnt = 0;
    fgets(buffer, MAX_BUF, infile);// skip the header

    while( fgets(buffer, MAX_BUF, infile) ){
        sscanf(buffer, "%s %d%*c %d %lf %lf %lf", ptr->SSID, &(ptr->signalStrength),  &(ptr->channel), &(ptr->bandwidth), &(ptr->freq), &(ptr->max_rate));
        ptr++;
        cnt++;
    }
    *numWifi = cnt;

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

