// Function declaration
double calculateAmbulanceTaxes(double Age, double costInsuranceFreight, double transportationMode, double daysInBond, double parkingFeePerDay,
                               double plateSystem){
    double totalTaxes;
    // Fixed tax amounts
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevyFee = 150000;
    double currentYear = 2024;
    double carAge = currentYear - Age;

    double transportationFee;
    double parkingFee; 

    // Calculating stamp duty fee based on cost of insurance freight
    printf("The stamp duty fee is %.2lf", stampDuty);

    // Calculating form fees based on cost of insurance freight
    printf("The form fees are %.2lf", formFees);

    // Calculating excise duty fee based on cost of insurance freight
    printf("The excise duty fee is %.2lf", exciseDuty);

    // Determining plate system fee based on whether plate system equals 1 or not
    plateSystem = 700000;
    printf("%.2lf\n", plateSystem);   
    
    // Calculate fees based on different conditions
    if (Age > 10) {
        double carAgeFee = 0.15 * costInsuranceFreight;
        printf("The infrastructure levy fee is %.2lf\n", carAgeFee);
    } else {
        printf("The infrastructure levy fee is %.2lf\n", infrastructureLevyFee);
    }

    if (transportationMode == 1) {
        transportationFee = 0.005 * costInsuranceFreight;
        printf("The transportation fee is %.2lf\n", transportationFee);
    } else if (transportationMode == 2) {
        transportationFee = 0.015 * costInsuranceFreight;
        printf("The transportation fee is %.2lf\n", transportationFee);
    } else {
        printf("No transportation fee\n");
    }

    if (daysInBond > 30) {
        parkingFee = daysInBond * parkingFeePerDay * 0.9;
        printf("The parking fee is %.2lf\n", parkingFee);
    } else {
        printf("No parking fee\n");
    }

    // Sum up all tax components
    totalTaxes = stampDuty + formFees + exciseDuty + plateSystem + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;
}