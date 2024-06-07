// Function declaration
double calculateTrailerTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay,
                             double engineCapacity,  double plateSystem) {    
    // Declaring variables 
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, grossWeight, engineCapacityFee;
    
    // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevyFee = 150000;
    double importDuty = 0.25; 
    double valueAddedTax = 0.18; 
    double witholdingTax = 0.06;
    double currentYear = 2024;
    double carAge = currentYear - Age;

    double transportationFee = 0;
    double parkingFee = 0;   
        
    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    printf("The import duty fee is %.2lf\n", importDutyFee);  // Print the calculated import duty fee

    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);  // Print the calculated VAT fee

    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);  // Print the calculated withholding tax fee

    // Determining plate system fee based on whether plate system equals 1 or not
    plateSystem = (plateSystem == 300000)? 300000 : 700000;
    printf("The plate system fee is %.2lf\n", plateSystem);  // Print the calculated plate system fee

    // Calculating car age fee based on the age 
    if (Age >= 15) {
        printf("Trailers older than 15 years cannot be imported.\n");
    } else if (Age >= 10) {
        double carAgeFee = 0.10 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    } else if (Age >= 5) {
        double carAgeFee = 0.05 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
    } else if (Age < 5) {
        double carAgeFee = 0.015 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
    } else {
        printf("Invalid input.\n");
    }

    // Calculating gross weight fee based on the gross weight
    if(grossWeight >= 15000 && grossWeight <= 20000){
        grossWeightFee = 0.15 * costInsuranceFreight;
        printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    } else if(grossWeight > 20000){
        grossWeightFee = 0.25 * costInsuranceFreight;
        printf("The gross weight fee is %.2lf\n", grossWeightFee);
    } else {
        grossWeightFee = costInsuranceFreight * 0.05;
        printf("The gross weight fee is %.2lf\n", grossWeightFee);
    }
    
    // Calculating engine capacity fee based on the engine capacity
    if(engineCapacity > 20000){
        engineCapacityFee = 0.10 * costInsuranceFreight;
        printf("The engine capacity fee is %.2lf\n", engineCapacityFee); 
    } else if(engineCapacity >= 20000 && engineCapacity <= 15000){
        engineCapacityFee = 0.05 * costInsuranceFreight;
        printf("The engine capacity fee is %.2lf\n", engineCapacityFee); 
    } else {
        engineCapacityFee = 0.025 * costInsuranceFreight;
        printf("The engine capacity fee is %.2lf\n", engineCapacityFee); 
    }
    
    // Calculating transportation fee based on the mode of transportation
    transportationFee = (transportationMode == 1)? 0.005 * costInsuranceFreight :
                       (transportationMode == 2)? 0.015 * costInsuranceFreight : 0;
    printf("The transportation fee is %.2lf\n", transportationFee);  

    // Calculating parking fee based on the number of days in bond
    parkingFee = (daysInBond > 30)? daysInBond * parkingFeePerDay * 0.9 : 0;
    printf("The parking fee is %.2lf\n", parkingFee);  

    // Sum up all the calculated fees and taxes to get the total taxes
    double totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + engineCapacityFee +  stampDuty +
                        formFees + exciseDuty + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}