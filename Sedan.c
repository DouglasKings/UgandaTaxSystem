// Function declaration
double calculateSedanTaxes(int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay, double totalFee) {

    // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double DPS = 700000;
    double infrastructureLevyFee = 150000;
    int currentYear = 2024;   

    // Declaring variables 
    double importDuty, valueAddedTax, witholdingTax, costInsuranceFreight, parkingFeePerDay, grossWeightFee, grossWeight, 
           engineCapacityFee, engineCapacity;
    int Age, transportationMode, daysInBond;

    // Calculating import duty fee based on cost of insurance freight
    double ImportDutyFee = importDuty * costInsuranceFreight;
    printf("%.2lf\n", ImportDutyFee);  // Print the calculated import duty fee

    // Calculating value-added tax fee based on cost of insurance freight
    double ValueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    printf("%.2lf\n", ValueAddedTaxFee);  // Print the calculated VAT fee

    // Calculating withholding tax fee based on cost of insurance freight
    double WitholdingTaxFee = witholdingTax * costInsuranceFreight;             
    printf("%.2lf\n", WitholdingTaxFee);  // Print the calculated withholding tax fee

    // Calculating car age fee based on the age of the sedan
    if (Age > 1 && Age <= 5){
        int carAge = currentYear - Age;
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
        double grossWeightFee = 0.10 * costInsuranceFreight;
        printf("The fee  is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight > 2000){
            double grossWeightFee = 0.15 * costInsuranceFreight;
            printf("The fee  is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight < 1500){
         double grossWeightFee = costInsuranceFreight * 0.02;
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
    double totalTaxes = ImportDutyFee + ValueAddedTaxFee + WitholdingTaxFee + grossWeightFee + engineCapacityFee +  stampDuty + 
                        formFees + exciseDuty + DPS + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}