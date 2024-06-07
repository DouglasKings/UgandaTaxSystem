// Function declaration
double calculateSedanTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay,
                           double plateSystem, double engineCapacity) {

    // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double DPS = 700000;
    double infrastructureLevyFee = 150000;
    double importDuty = 0.25; 
    double valueAddedTax = 0.18; 
    double witholdingTax = 0.06;
    double currentYear = 2024; 
    double carAge = currentYear - Age;  

    // Declaring variables 
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, costInsuranceFreight, parkingFeePerDay, grossWeightFee, grossWeight, 
           engineCapacityFee, engineCapacity, Age, transportationMode;

    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    printf("%.2lf\n", importDutyFee);  // Print the calculated import duty fee

    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    printf("%.2lf\n", valueAddedTaxFee);  // Print the calculated VAT fee

    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    printf("%.2lf\n", witholdingTaxFee);  // Print the calculated withholding tax fee

    // Calculating stamp duty fee based on cost of insurance freight
    printf("The stamp duty is: ", stampDuty);

    // Calculating form fees based on cost of insurance freight
    printf("The form fees are: ", formFees);

    // Calculating excise duty fee based on cost of insurance freight
    printf("The excise duty is: ", exciseDuty);

    // Determining plate system fee based on whether plate system equals 1 or not
    double plateSystemFee = 700000;
    printf("%.2lf\n", plateSystemFee);  

    // Calculating car age fee based on the age of the sedan
    if (Age > 1 && Age <= 5){
        double carAgeFee = 0.01 * costInsuranceFreight;
        printf("The fee for car age is %.2lf\n", carAgeFee);  
    }
    else if(Age > 5 && Age <= 10){
        double carAgeFee = 0.05 * costInsuranceFreight;
        printf("The fee for car age is %.2lf\n", carAgeFee);  
    } 
    else if(Age > 10){
        double carAgeFee = 0.15 * costInsuranceFreight;
        printf("The fee for car age is %.2lf\n", carAgeFee);  
    }
    else {
        printf("The fee for infrastructure levy is %.2lf\n", infrastructureLevyFee);  
    }

    // Calculating gross weight fee based on the gross weight of the sedan
    if(grossWeight >= 1500 && grossWeight <= 2000){
        grossWeightFee = 0.10 * costInsuranceFreight;
        printf("The fee  is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight > 2000){
            grossWeightFee = 0.15 * costInsuranceFreight;
            printf("The fee  is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight < 1500){
         grossWeightFee = costInsuranceFreight * 0.02;
         printf("The fee  is %.2lf\n", grossWeightFee); 
    }else{
        printf("No gross weight fee"); 

    }
    
    // Calculating engine capacity fee based on the engine capacity of the sedan
    if(engineCapacity > 2000){
        engineCapacityFee = 0.10 * costInsuranceFreight;
        printf("The fee  is %.2lf\n", engineCapacityFee);
    }
    else if(engineCapacity >= 1500 && engineCapacity <= 2000){
            engineCapacityFee = 0.05 * costInsuranceFreight;
            printf("The fee  is %.2lf\n", engineCapacityFee);
    }
    else{
        engineCapacityFee = 0.025 * costInsuranceFreight;
        printf("The fee  is %.2lf\n", engineCapacityFee);
    }
      

    // Calculating transportation fee based on the mode of transportation
    double transportationFee = (transportationMode == 1)? 0.005 * costInsuranceFreight :
                               (transportationMode == 2)? 0.015 * costInsuranceFreight : 0;
    printf("The transportation fee is %.2lf\n", transportationFee);  

    // Calculating parking fee based on the number of days in bond
    double parkingFee = (daysInBond > 30)? daysInBond * parkingFeePerDay * 0.9 : 0;
    printf("The parking fee is %.2lf\n", parkingFee);  

    // Sum up all the calculated fees and taxes to get the total taxes
    double totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + engineCapacityFee +  stampDuty + 
                        formFees + exciseDuty + DPS + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}