// Function declaration
double calculateSUVTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay,
                         double seatingCapacity, double grossWeight, double plateSystem) {
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

    double transportationFee;
    double parkingFee;   

    // Declaring variables 
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee;

    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    printf("The import duty fee is %.2lf\n", importDutyFee);  // Print the calculated import duty fee

    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);  // Print the calculated VAT fee

    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);  // Print the calculated withholding tax fee

    // Calculating stamp duty fee based on cost of insurance freight
    printf("The stamp duty fee is %.2lf", stampDuty);

    // Calculating form fees based on cost of insurance freight
    printf("The form fees are %.2lf", formFees);

    // Calculating excise duty fee based on cost of insurance freight
    printf("The excise duty fee is %.2lf", exciseDuty);
    
    // Determining plate system fee based on whether plate system equals 1 or not
    plateSystem = 300000;
    printf("The plate system is %.2lf\n", plateSystem);

    // Calculating seating capacity fee based on the seating capacity 
    double seatingCapacityFee = (seatingCapacity > 5)? 350000 * seatingCapacity: 0;
    printf("The seating capacity fee is %.2lf\n", seatingCapacityFee);

    // Calculating car age fee based on the age 
    if (Age > 1 && Age <= 5){
        double carAgeFee = 0.01 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    }
    else if(Age > 5 && Age <= 10){
        double carAgeFee = 0.15 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    } 
    else if(Age > 10){
        double carAgeFee = 0.25 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    }
    else {
        printf("The infrastructure levy fee is %.2lf\n", infrastructureLevyFee);  
    }

    // Calculating gross weight fee based on the gross weight 
    if(grossWeight >= 1500 && grossWeight <= 2000){
        double grossWeightFee = 0.10 * costInsuranceFreight;
        printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight > 2000){
            double grossWeightFee = 0.15 * costInsuranceFreight;
            printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }
    else if(grossWeight < 1500){
         double grossWeightFee = costInsuranceFreight * 0.02;
         printf("The gross weight fee is %.2lf\n", grossWeightFee); 
    }else{
        printf("No gross weight fee"); 

    }
    
    // Calculating transportation fee based on the mode of transportation
    transportationFee = (transportationMode == 1)? 0.005 * costInsuranceFreight :
                               (transportationMode == 2)? 0.015 * costInsuranceFreight : 0;
    printf("The transportation fee is %.2lf\n", transportationFee);  

    // Calculating parking fee based on the number of days in bond
    parkingFee = (daysInBond > 30)? daysInBond * parkingFeePerDay * 0.9 : 0;
    printf("The parking fee is %.2lf\n", parkingFee);  

    // Sum up all the calculated fees and taxes to get the total taxes
    double totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + stampDuty + formFees + exciseDuty
                        + plateSystem + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}