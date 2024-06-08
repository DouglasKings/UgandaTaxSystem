#include <stdio.h>

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
    double carAgeFee = currentYear - Age;  

    // Declaring variables 
    double importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee, transportationFee, parkingFee, totalTaxes; 

    // Calculating import duty fee based on cost of insurance freight
    importDutyFee = importDuty * costInsuranceFreight;
    //printf("The import duty fee is %.2lf\n", importDutyFee);  // Print the calculated import duty fee

    // Calculating value-added tax fee based on cost of insurance freight
    valueAddedTaxFee = valueAddedTax * costInsuranceFreight; 
    //printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);  // Print the calculated VAT fee

    // Calculating withholding tax fee based on cost of insurance freight
    witholdingTaxFee = witholdingTax * costInsuranceFreight;             
    //printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);  // Print the calculated withholding tax fee

    // Adjusting plate system fee based on input value
    if (plateSystem!= 300000) { 
        //printf("The plate system fee is %.2lf\n", plateSystem);   
    } else {
        //printf("Default plate system fee applied.\n");
    }

    // Calculating seating capacity fee based on the seating capacity 
    double seatingCapacityFee = (seatingCapacity > 5)? 350000 * seatingCapacity: 0;
    printf("The seating capacity fee is %.2lf\n", seatingCapacityFee);

    // Calculating car age fee based on the age 
    if (Age > 1 && Age <= 5){
        carAgeFee = 0.01 * costInsuranceFreight;
        //printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    }
    else if(Age > 5 && Age <= 10){
        carAgeFee = 0.15 * costInsuranceFreight;
        //printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    } 
    else if(Age > 10){
        carAgeFee = 0.25 * costInsuranceFreight;
        //printf("The infrastructure levy fee is %.2lf\n", carAgeFee);  
    }
    else {
        carAgeFee = infrastructureLevyFee; 
        //printf("The infrastructure levy fee is %.2lf\n", carAgeFee);   
    }

    // Calculating gross weight fee based on the gross weight 
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
    }else{
        grossWeightFee = 0;
        //printf("The gross weight fee is %.2lf\n", grossWeightFee);
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
    totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + stampDuty + formFees + exciseDuty +
                 plateSystem + carAgeFee + infrastructureLevyFee + transportationFee + parkingFee;

    return totalTaxes;  // Return the total taxes
}