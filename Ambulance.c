// Function declaration
double calculateAmbulanceTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem){
    
    // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevyFee = 150000;
    double parkingFeePerDay = 15000;
    double currentYear = 2024;
    double carAgeFee = currentYear - Age; 

    double transportationFee, parkingFee, totalTaxes;

    // Adjusting plate system fee based on input value
    if (plateSystem!= 700000) { 
           
    } else {
        
    }

    // Calculating fees based on different conditions
    if (Age > 10) {
        carAgeFee = 0.15 * costInsuranceFreight; 
    } else {
        carAgeFee = infrastructureLevyFee;
    }

    // Transportation fee calculation varies based on mode
    if (transportationMode == 1) {
        transportationFee = 0.005 * costInsuranceFreight;
    } else if (transportationMode == 2) {
        transportationFee = 0.015 * costInsuranceFreight;
    } else {
               
    }

    // Parking fee calculation depends on days in bond
    parkingFee = daysInBond * parkingFeePerDay;
    
    // Sum up all tax components to calculate total taxes
    totalTaxes = stampDuty + formFees + exciseDuty + plateSystem + carAgeFee + transportationFee + parkingFee;

     printf("\nAmbulance\n");
     printf("The stamp duty fee is %.2lf\n", stampDuty);
     printf("The form fees are %.2lf\n", formFees);
     printf("The excise duty fee is %.2lf\n", exciseDuty);
     printf("The plate system fee is %.2lf\n", plateSystem);
     printf("The infrastructure levy fee is %.2lf\n", carAgeFee); 
     printf("The transportation fee is %.2lf\n", transportationFee); 
     printf("The parking fee is %.2lf\n", parkingFee);
     printf("Total Taxes: %.2lf\n", totalTaxes);

    return totalTaxes;
}