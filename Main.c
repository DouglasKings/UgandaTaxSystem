#include <stdio.h>
#include <stdlib.h>
#include "Ambulance.c"
#include "Estate.c"
#include "Sedan.c"
#include "SUV.C"
#include "Trailer.c"

// Assuming the functions for calculating taxes are correctly implemented in the included.c files
double calculateAmbulanceTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double plateSystem);
double calculateEstateTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double seatingCapacity, double engineCapacity, double grossWeight, double plateSystem);
double calculateSedanTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double plateSystem, double engineCapacity, double grossWeight);
double calculateSUVTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double seatingCapacity, double grossWeight, double plateSystem);
double calculateTrailerTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double engineCapacity, double grossWeight, double plateSystem);

int main() {
    int vehicleType; 
    double Age, grossWeight, engineCapacity, seatingCapacity, costInsuranceFreight, plateSystem, totalTaxes, transportationMode,
           daysInBond; 
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevyFee = 150000;
    double  parkingFeePerDay = 15000;
    double currentYear = 2024;
    double carAgeFee = currentYear - Age;

    double importDutyFee = 0.0, valueAddedTaxFee = 0.0, witholdingTaxFee = 0.0, grossWeightFee = 0.0, engineCapacityFee = 0.0, transportationFee = 0.0,
           parkingFee = 0.0, seatingCapacityFee = 0.0;
            
    // Validating user input
    do {
        printf("Enter the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV) & 5 for Trailer): \n");
        scanf("%d", &vehicleType);
        printf("Vehicle type is: %d \n", vehicleType);
        if (vehicleType!= 1 && vehicleType!= 2 && vehicleType!= 3 && vehicleType!= 4 && vehicleType!= 5) {
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

    } while (vehicleType <= 0 || vehicleType > 5);

    printf("Enter the Cost Insurance Freight: ");
    scanf("%lf", &costInsuranceFreight);
    printf("Cost Insurance Freight: %.2lf\n", costInsuranceFreight);

    printf("Enter the vehicle age in years: ");
    scanf("%lf", &Age);
    printf("Age is: %.2lf\n", Age);

    do {
        printf("Enter plate system (Analog Plate System (300000) or Digital Plate System (700000), Ambulance & Sedan is DPS, SUV is APS): ");
        scanf("%lf", &plateSystem);
        // Checking if the input is neither APS nor DPS
        if ((plateSystem!= 300000 && plateSystem!= 700000)) {
            printf("Invalid input. Please enter 300000 or 700000. \n");
        } else {
            // Determining if the plate system is analog or digital
            if (plateSystem == 300000) {
                printf("The plate system is Analog.\n");
            } else { 
                printf("The plate system is Digital.\n");
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
            printf("Ambulance\n");
            totalTaxes = calculateAmbulanceTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, plateSystem);
            // Printing fixed taxes
            printf("The stamp duty fee is %.2lf\n", stampDuty);
            printf("The form fees are %.2lf\n", formFees);
            printf("The excise duty fee is %.2lf\n", exciseDuty);
            printf("The plate system fee is %.2lf\n", plateSystem);
            printf("The infrastructure levy fee is %.2lf\n", carAgeFee); 
            printf("The transportation fee is %.2lf\n", transportationFee); 
            printf("The parking fee is %.2lf\n", parkingFee);   
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 2:
            printf("Estate\n");
            totalTaxes = calculateEstateTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, seatingCapacity, engineCapacity, grossWeight, plateSystem);
            // Printing Statements
            printf("The import duty fee is %.2lf\n", importDutyFee);
            printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
            printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
            printf("The stamp duty fee is %.2lf\n", stampDuty);
            printf("The form fees are %.2lf\n", formFees);
            printf("The excise duty fee is %.2lf\n", exciseDuty);
            printf("The plate system fee is %.2lf\n", plateSystem);
            printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
            printf("The seating capacity fee is %.2lf\n", seatingCapacityFee);  
            printf("The gross weight fee is %.2lf\n", grossWeightFee);
            printf("The engine capacity fee is %.2lf\n", engineCapacityFee); 
            printf("The transportation fee is %.2lf\n", transportationFee);
            printf("The parking fee is %.2lf\n", parkingFee);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 3:
            printf("Sedan\n");
            totalTaxes = calculateSedanTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, plateSystem, engineCapacity, grossWeight);
            // Printing Statements
            printf("The import duty fee is %.2lf\n", importDutyFee);
            printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
            printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
            printf("The stamp duty fee is %.2lf\n", stampDuty);
            printf("The form fees are %.2lf\n", formFees);
            printf("The excise duty fee is %.2lf\n", exciseDuty);
            printf("The plate system fee is %.2lf\n", plateSystem);
            printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
            printf("The gross weight fee is %.2lf\n", grossWeightFee);
            printf("The transportation fee is %.2lf\n", transportationFee);
            printf("The parking fee is %.2lf\n", parkingFee);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 4:
            printf("Sports Utility Vehicle\n");
            totalTaxes = calculateSUVTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, seatingCapacity, grossWeight, plateSystem);
            // Printing Statements
            printf("The import duty fee is %.2lf\n", importDutyFee);
            printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
            printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
            printf("The stamp duty fee is %.2lf\n", stampDuty);
            printf("The form fees are %.2lf\n", formFees);
            printf("The excise duty fee is %.2lf\n", exciseDuty);
            printf("The plate system fee is %.2lf\n", plateSystem);
            printf("The seating capacity fee is %.2lf\n", seatingCapacityFee);
            printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
            printf("The gross weight fee is %.2lf\n", grossWeightFee);
            printf("The transportation fee is %.2lf\n", transportationFee);
            printf("The parking fee is %.2lf\n", parkingFee);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        case 5:
            printf("Trailer\n");
            totalTaxes = calculateTrailerTaxes(Age, costInsuranceFreight, transportationMode, daysInBond, parkingFeePerDay, engineCapacity, grossWeight, plateSystem);
            // Printing Statements
            printf("The import duty fee is %.2lf\n", importDutyFee);
            printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
            printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
            printf("The stamp duty fee is %.2lf\n", stampDuty);
            printf("The form fees are %.2lf\n", formFees);
            printf("The excise duty fee is %.2lf\n", exciseDuty);
            printf("The plate system fee is %.2lf\n", plateSystem);
            printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
            printf("The gross weight fee is %.2lf\n", grossWeightFee);
            printf("The transportation fee is %.2lf\n", transportationFee);
            printf("The parking fee is %.2lf\n", parkingFee);
            printf("Total Taxes: %.2lf\n", totalTaxes);
            break;
        
    }

    return 0;
}