// Function declaration
double calculateOtherVehicleTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem) {    
    // Declaring variables for storing various fees and taxes
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee, parkingFee,
           seatingCapacityFee, totalTaxes;
    
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
    double plateSystemFee = (plateSystem == 300000)? 300000 : 700000;
          
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
    totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + seatingCapacityFee + grossWeightFee + engineCapacityFee +
                 stampDuty + formFees + exciseDuty + plateSystemFee + carAgeFee + transportationFee + parkingFee;

     printf("\nOtherVehicleTaxes\n");
     printf("The import duty fee is %.2lf\n", importDutyFee);
     printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
     printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
     printf("The stamp duty fee is %.2lf\n", stampDuty);
     printf("The form fees are %,.2lf\n", formFees);
     printf("The excise duty fee is %.2lf\n", exciseDuty);
     printf("The plate system fee is %.2lf\n", plateSystem);
     printf("The transportation fee is %.2lf\n", transportationFee);
     printf("The parking fee is %.2lf\n", parkingFee);
     printf("Total Taxes: %.2lf\n", totalTaxes);

    return totalTaxes;  // Return the total taxes
}