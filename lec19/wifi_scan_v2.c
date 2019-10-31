#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NETWORK 100
#define MAX_BUF 200
int readFileToWifi();
void displayWifi();

typedef struct wifiStruct Wifi;
struct wifiStruct{
    char SSID[MAX_BUF];
    int signalStrength;
    int channel;
    double bandwidth;
    double freq;
    double max_rate;
    Wifi *next;
};

void swap(Wifi *firstVal, Wifi *secondVal);
void quickSort(Wifi array[], int low, int high);
int partition(Wifi array[], int low, int high);
int readFileToWifi(Wifi *ptr, char *filename);
void displayWifi(Wifi *ptr);

int readLines(char *filename);

// version 2.0
Wifi *createWifi(Wifi *next, Wifi *Data);
void appendWifi(Wifi *headptr, Wifi *Data);
Wifi *searchSSID(Wifi *headptr, char *SSID);
int main()
{

    //Wifi w[MAX_NETWORK];

    Wifi headptr; //emptry 
    headptr.next = NULL;
    
    // introduce complicated treatment
    //Wifi *headptr;
    //headptr = NULL;

    char filename[MAX_BUF] = "data.txt";

    readFileToWifi(&headptr, filename);
    displayWifi(&headptr);


    char buffer[MAX_BUF];
    printf("Enter SSID to search: ");
    scanf("%s", buffer);
    Wifi *prevNode = searchSSID(&headptr, buffer);

    if(prevNode->next == NULL) 
        printf("No match found. \n");
    else
        printf("%s is found\n", (prevNode->next)->SSID);


}
int readFileToWifi(Wifi *headptr,  char *filename)
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

    Wifi *Data = (Wifi*) malloc(sizeof(Wifi));
    while( fgets(buffer, MAX_BUF, infile) ){
        sscanf(buffer, "%s %d%*c %d %lf %lf %lf", Data->SSID, &(Data->signalStrength),  &(Data->channel), &(Data->bandwidth), &(Data->freq), &(Data->max_rate));
        appendWifi(headptr, Data);
    }
    free(Data);

    fclose(infile);
}

void displayWifi(Wifi *headptr)
{
    int i;
    Wifi *current = headptr->next;
    printf("=======================================================================================\n");
    //printf("Name,Team,HR,R,RBI,AVG,WAR\n");
    printf("%-20s%-15s%-10s%-15s%-15s%-15s\n", "SSID", "Strength", "Channel", "Bandwidth", "Frequency", "Max rate");
    printf("---------------------------------------------------------------------------------------\n");
    while(current != NULL){
        printf("%-20s%-15d%-10d%-15.3lf%-15.3lf%-15.3lf\n", current->SSID, current->signalStrength, current->channel, current->bandwidth, current->freq, current->max_rate );

        current = current->next;
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
Wifi *createWifi(Wifi *next, Wifi *Data)
{
    Wifi *new = (Wifi*) malloc(sizeof(Wifi));

    strcpy(new->SSID, Data->SSID);
    new->signalStrength = Data->signalStrength;
    new->channel= Data->channel;
    new->bandwidth= Data->bandwidth;
    new->freq= Data->freq;
    new->max_rate= Data->max_rate;

    new->next = next;

}

void appendWifi(Wifi *headptr, Wifi *Data)
{
    Wifi *current = headptr->next;
    Wifi *new = createWifi(NULL, Data);


    if(current == NULL)
        headptr->next = new;
    else{
        while(current->next !=NULL)
            current = current->next;

        current->next = new;
    }
}
Wifi *searchSSID(Wifi *headptr, char *SSID)
{
    Wifi *prevNode = headptr;
    Wifi *currNode = headptr->next;

    while( currNode != NULL && strcmp(currNode->SSID, SSID) != 0){
        prevNode = currNode;
        currNode = currNode->next;
    }

    return prevNode;

}





