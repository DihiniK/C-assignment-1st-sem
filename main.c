#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_NAME_LENGTH 50
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0


void addCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int *cityCount);
void renameCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int cityCount);
void removeCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int *cityCount);
void displayCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int cityCount);
void manageDistance(char cities[MAX_CITIES][MAX_NAME_LENGTH],float distance_matrix[MAX_CITIES][MAX_CITIES],int cityCount);
void displayDistanceTable(char cities[MAX_CITIES][MAX_NAME_LENGTH],float distance_matrix[MAX_CITIES][MAX_CITIES],int cityCount);
void deliveryRequest(char cities[MAX_CITIES][MAX_NAME_LENGTH], float distance_matrix[MAX_CITIES][MAX_CITIES], int *deliveryCount, int cityCount);
void report(float distance_matrix[MAX_CITIES][MAX_CITIES], int deliverySource[MAX_DELIVERIES], int deliveryDestination[MAX_DELIVERIES], float customerCharge[MAX_DELIVERIES], float profit[MAX_DELIVERIES], float time[MAX_DELIVERIES], int deliveryCount);
void leastDistanceRoute(char cities[MAX_CITIES][MAX_NAME_LENGTH],float distance_matrix[MAX_CITIES][MAX_CITIES],int cityCount);

char *vehicle[3] = {"Van", "Truck", "Lorry"};
int capacity[3] = {1000, 5000, 10000};
float ratePerKm[3] = {30, 40, 80};
float avgSpeed[3] = {60, 50, 45};
float fuelEfficiency[3] = {12, 6, 4};

char cities[MAX_CITIES][MAX_NAME_LENGTH];
int cityCount = 0;
float distance_matrix[MAX_CITIES][MAX_CITIES];

int deliverySource[MAX_DELIVERIES];
int deliveryDestination[MAX_DELIVERIES];
float deliveryWeight[MAX_DELIVERIES];
int deliveryVehicleType[MAX_DELIVERIES];
float deliveryCost[MAX_DELIVERIES];
float fuelUsedList[MAX_DELIVERIES];
float totalCostList[MAX_DELIVERIES];
float profitList[MAX_DELIVERIES];
float chargeList[MAX_DELIVERIES];
float timeList[MAX_DELIVERIES];
int deliveryCount= 0;




int main()
{
    printf("Hello world!\n");
    return 0;
}
