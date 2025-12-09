#include "ManageAllCustomers.h"


bool ManageAllCustomers::loadCustomerDataFromFile(const std::string& filename)
{
    //Checking if file opens correctly
    std::ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile.is_open()){
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::string line = ""; //Temp string to hold each line of file

    getline(inputFile, line); //Skip header line
    line = ""; //Clear line variable

    while(getline(inputFile, line)) //While there are lines to read in file
    {
        std::string tempString; //Temp string to hold each data value

        std::string firstName, lastName,
        streetAddress, city, state, zipCode, phoneNumber;
        int accountNumber; //Temp variables to hold data from file

        std::stringstream inputString(line); //Create string stream from line
        //Read in each data value from line
        //Convert account number from string to int
        getline(inputString, tempString, ',');
        accountNumber = std::stoi(tempString);
        tempString = ""; //Clear temp string
        
        getline(inputString,firstName, ',');
        getline(inputString,lastName, ',');
        getline(inputString,streetAddress, ',');
        getline(inputString,city, ',');
        getline(inputString,state, ',');
        getline(inputString,zipCode, ',');
        getline(inputString,phoneNumber, ',');

        

        //Create new Allcustomers object with data from file
        AllCustomers newCustomer(firstName, lastName, accountNumber,
        streetAddress, city, state, zipCode, phoneNumber);
        
        //Add new customer to database
        defaultCustomerDataBase.push_back(newCustomer);
    }
    return true; //File loaded successfully data loaded into database
}

bool ManageAllCustomers::loadCustomerPurchaseDataFromFile(const std::string& filename)
{
    //Checking if file opens correctly
    std::ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile.is_open()){
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::string line = ""; //Temp string to hold each line of file

    getline(inputFile, line); //Skip header line
    line = ""; //Clear line variable

    while(getline(inputFile, line)) //While there are lines to read in file
    {
        std::string tempString; //Temp string to hold each data value
        std::string item;
        int accountNumber,year,month,day;
        double costOfPurchase; //Temp variables to hold data from file

        //Get Account Number
        std::stringstream inputString(line); //Create string stream from line that holds line data
        getline(inputString, tempString, ','); //Read account number
        accountNumber = std::stoi(tempString);
        tempString = ""; //Clear temp string

        //Get Item Name
        getline(inputString, item, ',');

        //Get Year, Month, Day from Date String
        getline(inputString, tempString, '-');
        year = std::stoi(tempString);
        tempString = "";
        getline(inputString, tempString, '-');
        month = std::stoi(tempString);
        tempString = "";
        getline(inputString, tempString, ','); //Read Day Comma delimited as it is last value in date
        day = std::stoi(tempString);
        tempString = "";

        //Get Cost of Purchase
        getline(inputString, tempString, ',');
        costOfPurchase = std::stod(tempString);

        //Create Date Object
        Date purchaseDate(year, month, day);

        //Match Account Number to Customer and Add Purchase to their History
        for (int i = 0; i < defaultCustomerDataBase.size(); ++i)
        {
            //Check for matching account number
            if(defaultCustomerDataBase[i].getAccountNumber() == accountNumber)
            {
                //Create new AllPurchases object and add to customer's purchase history if account number matches
                AllPurchases newPurchase(accountNumber, item, purchaseDate, costOfPurchase);  //AllPurchases(const int& accountNumber, const std::string& item, const Date& dateOfPurchase, const double& costOfPurchase)
                defaultCustomerDataBase[i].addPurchaseToHistory(newPurchase);
                break; //Exit loop once purchase is added
            }
        }
    }
    return true; //File loaded successfully data loaded into database
}




void ManageAllCustomers::displayAllCustomerData(){

    const int wAccountNumberCollum = 10;
    const int wFirstNameCollum = 20;
    const int wLastNameCollum = 20;
    const int wStreetAddressCollum = 40;
    const int wCityCollum = 15;
    const int wStateCollum = 15;
    const int wZipCodeCollum = 15;
    const int wPhoneNumberCollum = 20;

    //Helper Chars
    const char dashFillChar = '-';
    const std::string bar = "|";

    //Header Collum For Dispaying All Customer Data   accountNumber,firstName,lastName,streetAddress,city,state,zipCode,phoneNumber
    std::cout << std::left << std::setw(wAccountNumberCollum) << "Account #" << bar 
              << std::left << std::setw(wFirstNameCollum) << "First Name" << bar
              << std::left << std::setw(wLastNameCollum) << "Last Name" << bar
              << std::left << std::setw(wStreetAddressCollum) << "Street Address" << bar
              << std::left << std::setw(wCityCollum) << "City" << bar
              << std::left << std::setw(wStateCollum) << "State" << bar
              << std::left << std::setw(wZipCodeCollum) << "Zip Code" << bar
              << std::left << std::setw(wPhoneNumberCollum) << "Phone Number" << std::endl;

    for (int i = 0; i < defaultCustomerDataBase.size(); ++i){
        defaultCustomerDataBase[i].printCustomerData();
    }
}


void ManageAllCustomers::displaySortedCustomerData() {
    std::cout << "Display Sorted Customer Data function called.\n";
    // Implementation
}

void ManageAllCustomers::displayTotalCustomerSpendAmt() {
    std::cout << "Display Total Customer Spend Amount function called.\n";
    // Implementation
}

void ManageAllCustomers::insertNewCustomer() {
    std::cout << "Insert New Customer function called.\n";
}

void ManageAllCustomers::updateCustomerInformation() {

    std::cout << "Update Customer Information function called.\n";
}

void ManageAllCustomers::deleteCustomer() {
    std::cout << "Delete Customer function called.\n";
}

void ManageAllCustomers::addNewCustomerPurchase() {
    std::cout << "Add New Customer Purchase function called.\n";
}

void ManageAllCustomers::exportCustomerData() {
    std::cout << "Export Customer Data function called.\n";
}

void ManageAllCustomers::displaySpecificCustomerAccountAndPurchaseHistory()
{
   std::cout << "Type the account number of the customer you wish to view: ";
    int accountNumber;
    std::cin >> accountNumber;
    bool customerFound = false;

    for (int i = 0; i < defaultCustomerDataBase.size(); ++i)
    {
        if(defaultCustomerDataBase[i].getAccountNumber() == accountNumber)
        {
            customerFound = true;
            std::cout << "\nCustomer Information:\n";
            defaultCustomerDataBase[i].printCustomerData();
            std::cout << "\nPurchase History:\n";
            defaultCustomerDataBase[i].printPurchaseHistory();
        }
    }
    if (!customerFound)
    {
        std::cout << "Customer with account number not found: Returning to Main Menu" << accountNumber << " not found.\n";
    }
}