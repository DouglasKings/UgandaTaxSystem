#include <stdio.h>

double calculateSedanTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay,
                           double plateSystem, double engineCapacity, double grossWeight) {

    // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevyFee = 150000;
    double importDuty = 0.25; 
    double valueAddedTax = 0.18; 
    double witholdingTax = 0.06;
    double currentYear = 2024; 
    double carAgeFee = 0; // Initialize carAgeFee

    // Declaring and initializing variables 
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee,
           parkingFee, totalTaxes;

    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    //printf("The import duty fee is %.2lf\n", importDutyFee);

    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    //printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);

    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    //printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);   

    // Adjusting plate system fee based on input value
    if (plateSystem!= 700000) { 
        printf("The plate system fee is %.2lf\n", plateSystem);   
    } else {
        //printf("Default plate system fee applied.\n"); // Handle default case
    }

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

    // Calculating gross weight fee based on the gross weight of the sedan
    if(grossWeight >= 1500 && grossWeight <= 2000){
        grossWeightFee = 0.10 * costInsuranceFreight;
        //printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight > 2000){
            grossWeightFee = 0.15 * costInsuranceFreight;
            //printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight < 1500){
         grossWeightFee = costInsuranceFreight * 0.02;
         //printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }
    else{
        grossWeightFee = 0;
        //printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }
    
    // Calculating engine capacity fee based on the engine capacity of the sedan
    if(engineCapacity > 2000){
        engineCapacityFee = 0.10 * costInsuranceFreight;
        //printf("The engine capacity fee is %.2lf\n", engineCapacityFee);
    }
    else if(engineCapacity >= 1500 && engineCapacity <= 2000){
            engineCapacityFee = 0.05 * costInsuranceFreight;
            //printf("The engine capacity fee is %.2lf\n", engineCapacityFee);
    }
    else{
        engineCapacityFee = 0.025 * costInsuranceFreight;
        //printf("The engine capacity fee is %.2lf\n", engineCapacityFee);
    }      

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
        parkingFee = 0; // Corrected to simply set parkingFee to 0
        //printf("The parking fee is %.2lf\n", parkingFee);
    }

    // Sum up all the calculated fees and taxes to get the total taxes
    totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + engineCapacityFee + 
                 stampDuty + formFees + exciseDuty + plateSystem + carAgeFee + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}