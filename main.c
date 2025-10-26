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

void displayCities(char cities[MAX_CITIES][MAX_NAME_LENGTH],int cityCount) {
    int i;

    if(cityCount == 0) {
        printf("\nNo cities stored.\n");
        return;
    }

    printf("\nStored Cities:\n");
    for(i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }
}


void manageDistance(char cities[MAX_CITIES][MAX_NAME_LENGTH],float distance_matrix[MAX_CITIES][MAX_CITIES],int cityCount)
{

    if (cityCount == 0)
    {
        printf("No cities added yet.\n");
        return;
    }
    for (int i = 0; i < cityCount; i++){
        printf("cities : %d. %s\n", i, cities[i]);
    }


    if (cityCount < 2)
    {
        printf("At least two cities are required!\n");
        return;
    }
    int i, j;
    int city1,city2;
    printf("Enter source city index: ");
    scanf("%d", &city1);
    printf("Enter destination city index: ");
    scanf("%d", &city2);
    if (city1 == city2)
    {
        printf("Distance from a city to itself is 0.\n");
        return;
    }
    printf("Enter distance (km): ");
    scanf("%f", &distance_matrix[i][j]);
    distance_matrix[j][i] = distance_matrix[i][j];
    printf("Distance recorded successfully!\n");
}

void displayDistanceTable(char cities[MAX_CITIES][MAX_NAME_LENGTH],float distance_matrix[MAX_CITIES][MAX_CITIES],int cityCount)
{
    printf("\nDistance Table (km):\n");
    for (int i = 0; i < cityCount; i++)
    {
        for (int j = 0; j < cityCount; j++)
            printf("%6.1f ", distance_matrix[i][j]);
        printf("\n");
    }
}


void deliveryRequest(char cities[MAX_CITIES][MAX_NAME_LENGTH], float distance_matrix[MAX_CITIES][MAX_CITIES], int *deliveryCount, int cityCount)
{
    if (*deliveryCount >= MAX_DELIVERIES){
        printf("Couldn't loud . Delivery limit exceeds.");
        return;

   }

    if (cityCount < 2)
    {
        printf("Add at least two cities first!\n");
        return;
    }


    int city1, city2, vehicleType;
    float weight;
    printf("Enter source city index: ");
    scanf("%d", &city1);
    printf("Enter destination city index: ");
    scanf("%d", &city2);
    printf("Enter weight (kg): ");
    scanf("%f", &weight);
    printf("Vehicle (1=Van, 2=Truck, 3=Lorry): ");
    scanf("%d", &vehicleType);
    vehicleType--;

    if (city1 == city2)
    {
        printf("Error: Same cities!\n");
        return;
 }
    if (vehicleType < 0 || vehicleType > 3)
    {
        printf("Invalid vehicle type!\n");
        return;
    }
    if (weight > capacity[vehicleType])
    {
        printf("Error: Exceeds capacity!\n");
        return;
    }

    float D = distance_matrix[city1][city2];
    float R = ratePerKm[vehicleType];
    float S = avgSpeed[vehicleType];
    float E = fuelEfficiency[vehicleType];


    float cost = D * R * (1 + weight / 10000.0);
    float fuelUsed = D / E;
    float fuelCost = fuelUsed * FUEL_PRICE;
    float totalCost = cost + fuelCost;
    float profit = cost * 0.25;
    float customerCharge = totalCost + profit;
    float time = D / S;


    int i = *deliveryCount;
    deliverySource[i] = city1;
    deliveryDestination[i] = city2;
    deliveryVehicleType[i] = vehicleType;
    deliveryWeight[i] = weight;
    deliveryCost[i] = cost;
    fuelUsedList[i] = fuelUsed;
    totalCostList[i] = totalCost;
    profitList[i] = profit;
    chargeList[i] = customerCharge;
    timeList[i] = time;
    (*deliveryCount)++;

    printf("\nDELIVERY SUMMARY\n");
    printf("From: %s  To: %s\n", citie[city1], cities[city2]);
    printf("Vehicle: %s\n",vehicle[vehicleType]);
    printf("Weight: %.1f kg\n", weight);
    printf("Minimum Distance: %.1f km\n", D);
    printf("Base Cost: %.1f LKR\n", cost);
    printf("Fuel Used: %.1f L\n", fuelUsed);
    printf("Fuel Cost: %.1f LKR\n", fuelCost);
    printf("Operational Cost: %.1f LKR\n", totalCost);
    printf("Profit: %.1f LKR\n", profit);
    printf("Customer Charge: %.1f LKR\n", customerCharge);
    printf("Estimated Time: %.1f hrs\n", time);
    printf("\n----------------------------\n");
}



void leastDistanceRoute(char cities[MAX_CITIES][MAX_NAME_LENGTH],float distance_matrix[MAX_CITIES][MAX_CITIES],int cityCount){

int city1,city2;
float min = distance_matrix[city1][city2];
int mid= -1;
float total;

    printf("Enter source index: ");
    scanf("%d", &city1);
    printf("Enter destination index: ");
    scanf("%d", &city2);
    if (city1 == city2)
    {
        printf("Source and destination cannot be same.\n");
        return;
    }

    if (distance[city1][city2] == 0)
    {
        printf("No direct distance  between recorded cities.\n");
        return;
    }



    for (int i = 0; i < cityCount; i++)
    {
        if (i == city1 || i == city2){


        if (distance_matrix[city1][i] > 0 && distance_matrix[i][city2] > 0)
        {
            total = distance_matrix[city1][i] + distance_matrix[i][city2];
            if (total < min)
            {
                min = total;
                mid= i;
            }
        }
    }
    }


    if (mid == -1)
    {
        printf("%s -> %s\n", cities[city1], cities[city2]);
    }
    else
    {
        printf("%s -> %s -> %s\n", cities[city1], cities[mid], cities[city2]);


    }
    printf("Minimum distance: %.2f km\n", min);


}




int main()
{
    printf("Hello world!\n");
    return 0;
}
