#include <stdio.h>
#include <stdlib.h>
#include "Ambulance.c"
#include "Estate.c"
#include "Sedan.c"
#include "SUV.C"
#include "Trailer.c"
#include "OtherVehicle.c"

// Assuming the functions for calculating taxes are correctly implemented in the included.c files
double calculateAmbulanceTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem);
double calculateEstateTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double seatingCapacity, double engineCapacity, double grossWeight, double plateSystem);
double calculateSedanTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem, double engineCapacity, double grossWeight);
double calculateSUVTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double seatingCapacity, double grossWeight, double plateSystem);
double calculateTrailerTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double engineCapacity, double grossWeight, double plateSystem);
double calculateOtherVehicleTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem);

int main() {
    int vehicleType; 
    double Age, grossWeight, engineCapacity, seatingCapacity, costInsuranceFreight, plateSystem, totalTaxes, transportationMode,
           daysInBond; 
     // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000; 
    double exciseDuty = 200000; 
    double infrastructureLevyFee = 150000; 
    double importDuty = 0.25; 
    double valueAddedTax = 0.18; 
    double witholdingTax = 0.06; 
    double currentYear = 2024; 
    double carAgeFee = currentYear - Age; 
    double parkingFeePerDay = 15000;

    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee,
           parkingFee, seatingCapacityFee;
            
    // Validating user input
    do {
        printf("Enter the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV), 5 for Trailer & 6 for Other Vehicles): ");
        scanf("%d", &vehicleType);
        printf("Vehicle type is: %d \n", vehicleType);
        if (vehicleType!= 1 && vehicleType!= 2 && vehicleType!= 3 && vehicleType!= 4 && vehicleType!= 5 && vehicleType!= 6) {
            printf("Invalid vehicle type.\n");
            continue;
        }

        if (vehicleType == 2 || vehicleType == 3 || vehicleType == 5) {
            printf("Enter engine capacity: ");
            scanf("%lf", &engineCapacity); 
            printf("Engine capacity is: %.2lf \n", engineCapacity);
        } else if (vehicleType == 2 || vehicleType == 4) { 
            printf("Enter seating capacity: ");
            scanf("%lf", &seatingCapacity); 
            printf("Seating capacity is: %.2lf \n", seatingCapacity);
        }

        if(vehicleType != 6){
            printf("Enter the Cost Insurance Freight: ");
            scanf("%lf", &costInsuranceFreight);
            printf("Cost Insurance Freight: %.2lf\n", costInsuranceFreight);

            printf("Enter the vehicle age in years derived from the year of manufacturer: ");
            scanf("%lf", &Age);
            printf("Age is: %.2lf\n", Age);
        } else{
            
        }      

    } while (vehicleType <= 0 || vehicleType > 6);
 
    do {
        printf("Enter plate system (Analog Plate System (300000) or Digital Plate System (700000), Ambulance & Sedan is DPS, SUV is APS): ");
        scanf("%lf", &plateSystem);
        // Checking if the input is neither APS nor DPS
        if ((plateSystem!= 300000 && plateSystem!= 700000)) {
            printf("Invalid input. Please enter 300000 or 700000. \n");
        } else {
            // Determining if the plate system is analog or digital
            if (plateSystem == 300000) {
                printf("The plate system is Analog Plate System .\n");
            } else { 
                printf("The plate system is Digital Plate System .\n");
            }
            break; 
        }
    } while (!plateSystem);

    printf("Enter the transportation mode (e.g., 1 for Carrier bed or 2 for Driven): ");
    scanf("%lf", &transportationMode);
    if (transportationMode == 1) {
        printf("The mode of transportation was on a carrier bed. \n"); 
    } else if (transportationMode == 2) {
        printf("The vehicle was driven into the country. \n"); 
    } else {
        printf("Invalid transportation mode. Please enter 1 for Carrier bed or 2 for Driven.\n");    
    }

    printf("Enter number of days the vehicle spends in the bond: ");
    scanf("%lf", &daysInBond);
    printf("Days in bond is %.2lf \n", daysInBond);

    switch(vehicleType){
        case 1:             
            totalTaxes = calculateAmbulanceTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem);             
            break;

        case 2:           
            totalTaxes = calculateEstateTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);            
            break;

        case 3:            
            totalTaxes = calculateSedanTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem, engineCapacity, grossWeight);
            break;

        case 4:            
            totalTaxes = calculateSUVTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, grossWeight, plateSystem);
            break;

        case 5:            
            totalTaxes = calculateTrailerTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, engineCapacity, grossWeight, plateSystem);
            break;

        case 6:            
            totalTaxes = calculateOtherVehicleTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem);
            break;
        
        default:
            printf("Invalid input. Please choose the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV), 5 for Trailer & 6 for Other Vehicles) ");
        
        // Ask the user if they want to try again
        char choice;
        printf("\nDo you want to choose another car? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to skip any whitespace characters
        getchar(); // To consume the newline character left by scanf
        
        if(choice == 'n' || choice == 'N') {
            break; // Exit the loop if the user does not wish to try again
        }
    }
        
    return 0;
}