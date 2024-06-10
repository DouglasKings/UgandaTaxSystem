#include <stdio.h>

// Function declaration
double calculateTrailerTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double engineCapacity,
                             double grossWeight, double plateSystem) {    
    // Declaring variables 
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee, parkingFee; 
    
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

    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    
    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
   
    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    
    // Determining plate system fee based on whether plate system equals 1 or not
    plateSystem = (plateSystem == 300000)? 300000 : 700000;
    
    // Calculating car age fee based on the age 
    if (Age >= 15) {
        printf("\nTrailers older than 15 years cannot to be imported into the country.\n");
        return 1; // Exit early since we cannot proceed with invalid inputs
    } else if (Age >= 10) {
        carAgeFee = 0.10 * costInsuranceFreight;
    } else if (Age >= 5) {
        carAgeFee = 0.05 * costInsuranceFreight;
    } else if (Age < 5) {
        carAgeFee = 0.015 * costInsuranceFreight;
    } else {
        printf("Invalid input.\n");
        return 1; // Exit early since we cannot proceed with invalid inputs
    }

    // Calculating gross weight fee based on the gross weight
    if(grossWeight >= 15000 && grossWeight <= 20000){
        grossWeightFee = 0.15 * costInsuranceFreight;
        
    } else if(grossWeight > 20000){
        grossWeightFee = 0.25 * costInsuranceFreight;
        
    } else {
        grossWeightFee = costInsuranceFreight * 0.05;
        
    }
    
    // Calculating engine capacity fee based on the engine capacity
    if(engineCapacity > 20000){
        engineCapacityFee = 0.10 * costInsuranceFreight;
         
    } else if(engineCapacity >= 20000 && engineCapacity <= 15000){
        engineCapacityFee = 0.05 * costInsuranceFreight;
         
    } else {
        engineCapacityFee = 0.025 * costInsuranceFreight;
         
    }
    
     // Transportation fee calculation varies based on mode
    if (transportationMode == 1) {
        transportationFee = 0.005 * costInsuranceFreight;
       
    } else if (transportationMode == 2) {
        transportationFee = 0.015 * costInsuranceFreight;
       
    } else {
        transportationFee = 0;
       
    }

    // Parking fee calculation depends on days in bond
    parkingFee = daysInBond * parkingFeePerDay;
    
    // Sum up all the calculated fees and taxes to get the total taxes
    double totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + engineCapacityFee +  stampDuty +
                        formFees + exciseDuty + carAgeFee + transportationFee + parkingFee;
    
    printf("\nTrailer\n");
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

    return totalTaxes;  // Return the total taxes
}