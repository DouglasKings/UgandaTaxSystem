#include <stdio.h>

// Function declaration
double calculateEstateTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay,
                            double seatingCapacity, double engineCapacity, double grossWeight, double plateSystem) {    
    // Declaring variables for storing various fees and taxes
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee, parkingFee,
           seatingCapacityFee, totalTaxes;
    
    // Fixed tax amounts
    double stampDuty = 35000; // Stamp Duty amount
    double formFees = 20000; // Form Fees amount
    double exciseDuty = 200000; // Excise Duty amount
    double infrastructureLevyFee = 150000; // Infrastructure Levy Fee amount
    double importDuty = 0.25; // Import Duty rate
    double valueAddedTax = 0.18; // Value Added Tax rate
    double witholdingTax = 0.06; // Withholding Tax rate
    double currentYear = 2024; // Current year for calculating car age
    double carAgeFee = currentYear - Age; // Car age calculation
        
    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    //printf("The import duty fee is %.2lf\n", importDutyFee);  // Corrected printf usage
    
    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    //printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);  // Corrected printf usage
    
    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    //printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);  // Corrected printf usage
    
    // Determining plate system fee based on whether plate system equals 1 or not
    double plateSystemFee = (plateSystem == 300000)? 300000 : 700000;
    //printf("The plate system fee is %.2lf\n", plateSystemFee);
    
    // Calculating car age fee based on the age 
    if (Age > 1 && Age <= 5){
        carAgeFee = 0.01 * costInsuranceFreight;
    }
    else if(Age > 5 && Age <= 10){
        carAgeFee = 0.05 * costInsuranceFreight;
    } 
    else if(Age > 10){
        carAgeFee = 0.15 * costInsuranceFreight;
    }
    else {
        carAgeFee = infrastructureLevyFee; 
    }

    // Calculating seating capacity fee based on the seating capacity
    seatingCapacityFee = (seatingCapacity > 5)? 250000 * seatingCapacity: 0;  
    //printf("The seating capacity fee is %.2lf\n", seatingCapacityFee);  
    
    // Calculating gross weight fee based on the gross weight
    if(grossWeight >= 1500 && grossWeight <= 2000){
        grossWeightFee = 0.05 * grossWeight;
    }
    else if(grossWeight > 2000){
            grossWeightFee = 0.10 * grossWeight;
    }
    else{
         grossWeightFee = 0.02 * grossWeight;
    }
    
    // Calculating engine capacity fee based on the engine capacity
    engineCapacityFee = (engineCapacity > 1800)? costInsuranceFreight * 0.05: costInsuranceFreight * 0.025;
    //printf("The engine capacity fee is %.2lf\n", engineCapacityFee);  
    
    // Transportation fee calculation varies based on mode
    if (transportationMode == 1) {
        transportationFee = 0.005 * costInsuranceFreight;
        //printf("The transportation fee is %.2lf\n", transportationFee);
    } else if (transportationMode == 2) {
        transportationFee = 0.015 * costInsuranceFreight;
        //printf("The transportation fee is %.2lf\n", transportationFee);
    } else {
        transportationFee = 0;
        //printf("The transportation fee is %.2lf\n", transportationFee);
    }

    // Parking fee calculation depends on days in bond
    if (daysInBond > 30) {
        parkingFee = daysInBond * parkingFeePerDay;
        //printf("The parking fee is %.2lf\n", parkingFee);
    } else {
        parkingFee = 0; 
        //printf("The parking fee is %.2lf\n", parkingFee);
    }
    
    // Sum up all the calculated fees and taxes to get the total taxes
    totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + seatingCapacityFee + grossWeightFee + engineCapacityFee +
                 stampDuty + formFees + exciseDuty + plateSystemFee + carAgeFee + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}