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

void addCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int *cityCount){

    char newCity[MAX_NAME_LENGTH];
    int i;

   if(cityCount< MAX_CITIES){

    printf("\nEnter city name (in lowercase):");
    fgets(newCity, sizeof(newCity),stdin);

}

   for (int i =0;i<=MAX_CITIES;i++){

     if(strcmp(cities[cityCount],newCity)== 0){

    printf("\n This city already exists.")
}
    else{

    strcpy(cities[cityCount],newCity);
    cityCount++;
}

}


}

void renameCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int cityCount){

   char newCity[MAX_NAME_LENGTH];
    int i,j;

   if(cityCount< MAX_CITIES){

    printf("\nEnter the new city name (in lowercase):");
    fgets(newCity, sizeof(newCity),stdin);
    printf("\nEnter the number of the place in array which should removed:");
    scanf("%d",j);

}

   for (int i =0;i<=MAX_CITIES;i++){

     if(strcmp(cities[cityCount],newCity)== 0){

    printf("\n This city already exists.")
}
    else{

    strncpy(cities[cityCount],newCity, int j);
    cityCount++;
}

}



}

void removeCity(char cities[MAX_CITIES][MAX_NAME_LENGTH],int *cityCount) {
    if (cityCount == 0) {
        printf("\nNo cities available!\n");
        return;
    }

    display_cities();

    int index;
    printf("\nEnter city index to remove: ");
    scanf("%d", &index;
    if(index != 1 || index < 0 || index >= city_count) {

        printf("\nInvalid city index!\n");
        return;
    }


    printf("\nCity '%s' removed successfully!\n", cities[index]);


    for (int i = index; i < cityCount - 1; i++) {
        strcpy(cities[i], cities[i + 1]);
    }


    for (int i = index; i < cityCount - 1; i++) {
        for (int j = 0; j < cityCount; j++) {
            distance_matrix[i][j] = distance_matrix[i + 1][j];
        }
    }

    for (int i = 0; i < cityCount; i++) {
        for (int j = index; j < cityCount - 1; j++) {
            distance_matrix[i][j] = distance_matrix[i][j + 1];
        }
    }

    cityCount--;
}




int main()
{
    printf("Hello world!\n");
    return 0;
}
