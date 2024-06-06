#include <stdio.h>
#include <stdlib.h>

// Function prototype for calculating ambulance taxes
double calculateAmbulanceTaxes(int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double totalFee);
double calculateEstateTaxes(int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double totalFee, double seatingCapacity);
double calculateSedanTaxes(int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double totalFee);
double calculateSUVTaxes(int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double totalFee, double seatingCapacity, double grossWeight);

int main() {
    int vehicleType, transportationMode; 
    double Age, grossWeight, engineCapacity, seatingCapacity, costInsuranceFreight, plateSystem, APS, DPS, daysInBond, totalFee,
           parkingFeePerDay = 0.0, totalFee = 0.0;

    //Validating user input
    do {
        printf("Enter the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV) & 5 for Trailer): \n");
        scanf("%d", &vehicleType);
        printf("Vehicle type is: %d \n", vehicleType);

        if (vehicleType!= 1 && vehicleType!= 2 && vehicleType!= 3 && vehicleType!= 4 && vehicleType!= 5) {
            printf("Invalid vehicle type.\n");
            continue;
        }

        if (vehicleType == 1 || vehicleType == 2) {
            printf("Enter engine capacity: ");
            scanf("%lf", &engineCapacity); 
            printf("Engine capacity is: %.2lf \n", engineCapacity);
        } else if (vehicleType == 3 || vehicleType == 4) { 
            printf("Enter seating capacity: ");
            scanf("%lf", &seatingCapacity); 
            printf("Seating capacity is: %.2lf \n", seatingCapacity);
            printf("Enter engine capacity: ");
            scanf("%lf", &engineCapacity);
            printf("Engine capacity is: %.2lf \n", engineCapacity);
        }

    } while (vehicleType <= 0 || vehicleType > 5);

    printf("Enter the Cost Insurance Freight: ");
    scanf("%lf", &costInsuranceFreight);
    printf("Cost Insurance Freight: %.2lf\n", costInsuranceFreight);

    printf("Enter the vehicle age in years: ");
    scanf("%lf", &Age);
    printf("Age is: %.2lf\n", Age);

    do {
        printf("Enter plate system (1 for Analog Plate System (300000) or 2 for Digital Plate System (700000), Ambulance & Sedan is DPS, SUV is APS): ");
        scanf("%lf", &plateSystem);
        if ((plateSystem!= 300000 && plateSystem!= 700000)) {
            printf("Invalid input. Please enter APS or DPS. \n");
        } else {
            break;
        }
    } while (!plateSystem);
    printf("Plate system is: %.0lf\n", plateSystem);

    printf("Enter the transportation mode (e.g., 1 for Carrier bed or 2 for Driven): ");
    scanf("%d", &transportationMode);

    if (transportationMode == 1) {
        printf("The fee of a vehicle delivered on a carrier bed is: %d \n", transportationMode);
    } else if (transportationMode == 2) {
        printf("The fee of a vehicle driven into the country is: %d \n", transportationMode);
    } else {
        printf("Invalid transportation mode. Please enter 1 for Carrier bed or 2 for Driven.\n");    
    }

    printf("Enter number of days the vehicle spends in the bond: ");
    scanf("%lf", &daysInBond);
    printf("Days in bond is %.2lf \n", daysInBond);

    switch(vehicleType){
        case 1:
            printf("Ambulance\n");
            double totalTaxes = calculateAmbulanceTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, totalFee);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 2:
            printf("Estate\n");
            double totalTaxes = calculateEstateTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, totalFee, seatingCapacity);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 3:
            printf("Sedan\n");
            double totalTaxes = calculateSedanTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, totalFee);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 4:
            printf("Sports Utility Vehicle\n");
            double totalTaxes = calculateSUVTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, totalFee, seatingCapacity, grossWeight);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        
    }

    return 0;
}