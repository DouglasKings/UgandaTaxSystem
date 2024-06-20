#include <stdio.h> // Standard Input Output library for basic input/output operations
#include <stdlib.h> // General Purpose Functions
#include "Ambulance.c" // Custom implementation for ambulance vehicles
#include "Estate.c" // Custom implementation for estate vehicles
#include "Sedan.c" // Custom implementation for sedan vehicles
#include "SUV.c" // Custom implementation for sports utility vehicles (SUVs)
#include "Trailer.c" // Custom implementation for trailer vehicles
#include "OtherVehicle.c" // Custom implementation for other types of vehicles

// Function prototypes for calculating taxes based on different vehicle types
double calculateAmbulanceTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem);
double calculateEstateTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double seatingCapacity, double engineCapacity, double grossWeight, double plateSystem);
double calculateSedanTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem, double engineCapacity, double grossWeight);
double calculateSUVTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double seatingCapacity, double grossWeight, double plateSystem);
double calculateTrailerTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double engineCapacity, double grossWeight, double plateSystem);
double calculateOtherVehicleTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem);

int main() {
    char choice; // Variable to store user choice

    // Main loop to continuously process vehicle details until user decides to exit
    while (1) {
        int vehicleType; // Variable to store the selected vehicle type
        
        // Variables to store vehicle details and calculated values
        double Age, grossWeight, engineCapacity, seatingCapacity, costInsuranceFreight, plateSystem, totalTaxes, transportationMode, daysInBond;
        
        // Fixed tax amounts and fees
        double stampDuty = 35000, formFees = 20000, exciseDuty = 200000, infrastructureLevyFee = 150000, importDuty = 0.25, valueAddedTax = 0.18, withholdingTax = 0.06, currentYear = 2024, carAgeFee, parkingFeePerDay = 15000;
        
        double importDutyFee, valueAddedTaxFee, withholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee, parkingFee, seatingCapacityFee;

        // User input validation loop
        do {
            printf("Enter the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV), 5 for Trailer & 6 for Other Vehicles): ");
            scanf("%d", &vehicleType);
            printf("Vehicle type is: %d \n", vehicleType);
            if (vehicleType!= 1 && vehicleType!= 2 && vehicleType!= 3 && vehicleType!= 4 && vehicleType!= 5 && vehicleType!= 6) {
                printf("Invalid vehicle type.\n");
                continue;
            }

            // Additional inputs required based on vehicle type
            if (vehicleType == 2 || vehicleType == 3 || vehicleType == 5) {
                printf("Enter engine capacity (Measured in CC): ");
                scanf("%lf", &engineCapacity); 
                printf("Engine capacity is: %,.2lf \n", engineCapacity);
            } 
            else if (vehicleType == 2 || vehicleType == 4) { 
                printf("Enter seating capacity: ");
                scanf("%lf", &seatingCapacity); 
                printf("Seating capacity is: %,.2lf \n", seatingCapacity);
            }
            else if (vehicleType == 2 || vehicleType == 3 || vehicleType == 4 || vehicleType == 5) { 
                printf("Enter gross weight (Measured in tons): ");
                scanf("%lf", &grossWeight); 
                printf("Gross weight is: %,.2lf \n", grossWeight);
            }
            else{

            }

            // Common inputs for all except Other Vehicles
            if(vehicleType!= 6){
                printf("Enter the Cost Insurance Freight: ");
                scanf("%lf", &costInsuranceFreight);
                printf("Cost Insurance Freight: %,.2lf\n", costInsuranceFreight);

                printf("Enter the vehicle age in years derived from the year of manufacturer: ");
                scanf("%lf", &Age);
                printf("Age is: %.2lf\n", Age);
            }      

        } while (vehicleType <= 0 || vehicleType > 6);

        // Plate system selection
        do {
            printf("Enter plate system (Analog Plate System (300000) or Digital Plate System (700000), Ambulance & Sedan is DPS, SUV is APS): ");
            scanf("%lf", &plateSystem);
            if ((plateSystem!= 300000 && plateSystem!= 700000)) {
                printf("Invalid input. Please enter 300000 or 700000. \n");
            } else {
                if (plateSystem == 300000) {
                    printf("The plate system is Analog Plate System.\n");
                } else { 
                    printf("The plate system is Digital Plate System.\n");
                }
                break; 
            }
        } while (!plateSystem);

        // Transportation mode selection
        printf("Enter the transportation mode (e.g., 1 for Carrier bed or 2 for Driven): ");
        scanf("%lf", &transportationMode);
        if (transportationMode == 1) {
            printf("The mode of transportation was on a carrier bed. \n"); 
        } else if (transportationMode == 2) {
            printf("The vehicle was driven into the country. \n"); 
        } else {
            printf("Invalid transportation mode. Please enter 1 for Carrier bed or 2 for Driven.\n");    
        }

        // Days in bond input
        printf("Enter number of days the vehicle spends in the bond: ");
        scanf("%lf", &daysInBond);
        printf("Days in bond is %.2lf \n", daysInBond);

        // Calculate total taxes based on vehicle type
        switch(vehicleType) {
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
                break;
        }

        printf("Total Taxes: %.2lf\n", totalTaxes);

        // Ask the user if they want to choose another car
        printf("\nDo you want to choose another car? (Y/N): ");
        scanf(" %c", &choice); // Note the space before %c to skip any whitespace characters
        getchar(); // To consume the newline character left by scanf

        // Check if the user wants to stop
        if (choice == 'n' || choice == 'N') {
            break; // Exit the loop if the user chooses 'N' or 'n'
        }
    }

    return 0;
}