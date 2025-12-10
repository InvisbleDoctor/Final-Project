#include "ManageAllCustomers.h"

void printCustomerHeader(){
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
}

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

void ManageAllCustomers::displayAllCustomerData(const std::vector<AllCustomers>& customers){

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

    for (int i = 0; i < customers.size(); ++i){
        customers[i].printCustomerData();
    }
}


void ManageAllCustomers::displaySortedCustomerData() {
    int userOption = 0;
    std::vector<AllCustomers> sortedCustomerData = defaultCustomerDataBase; //Copy original data to sorted vector
    std::cout << "1:Sort By Last Name Ascending \n2: Sort By Last Name Descending\n";
    std::cout << "Enter Option: ";
    std::cin >> userOption;

    if (userOption == 1)
    {
        std::sort(sortedCustomerData.begin(), sortedCustomerData.end(),
            [](const AllCustomers& a, const AllCustomers& b) {
                return a.getLastName() < b.getLastName();
            }
        );
    }
    else if (userOption == 2)
    {
        std::sort(sortedCustomerData.begin(), sortedCustomerData.end(),
            [](const AllCustomers& a, const AllCustomers& b) {
                return a.getLastName() > b.getLastName();
            }
        );
    }
    else 
    {
        std::cout << "Invalid Option Selected. Returning to Main Menu.\n";
        return;
    }

    
    displayAllCustomerData(sortedCustomerData);
}




void ManageAllCustomers::displayTotalCustomerSpendAmt() {
    std::cout << "Type the account number of the customer you wish to view total spend amount:";
    int accountNumber;
    std::cin >> accountNumber;
    bool customerFound = false;

    for (int i = 0; i < defaultCustomerDataBase.size(); ++i)
    {
        if(defaultCustomerDataBase[i].getAccountNumber() == accountNumber)
        {
            customerFound = true;
            double totalSpend = 0.0;
            
            for (const auto& purchase : defaultCustomerDataBase[i].getPurchaseHistory())
            {
                totalSpend += purchase.getCostOfPurchase();
            }
            defaultCustomerDataBase[i].printPurchaseHistory();
            std::cout << std::left << "\n Total Spend Amount for Customer Account #" << accountNumber << " is: $"
                      << std::fixed << std::setprecision(2) << totalSpend << std::endl;
        }
    }
    if (!customerFound)
    {
        std::cout << "Customer with account number not found: Returning to Main Menu " << accountNumber << " not found.\n";
    } 
}


void ManageAllCustomers::insertNewCustomer() {
    int userCancel = 0;
    std::cout << "Customer insertion Tool: Type -1 at any prompt to cancel insertion and return to main menu.\n";
        std::string firstName, lastName,
        streetAddress, city, state, zipCode, phoneNumber;
        int accountNumber; //Temp variables to hold data from user

        //Get User Input For New Customer Data
        std::cout << "Enter First Name: \n";
        getline(std::cin, firstName);
        if (firstName == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }
        //Validate Name Input
        while (!isValidName(firstName)) {
            std::cout << "Invalid first name. Please enter a valid first name: \n";
            getline(std::cin, firstName);
            if (firstName == "-1") {
                std::cout << "Insertion cancelled. Returning to main menu.\n";
                return;
            }
        }

        std::cout << "Enter Last Name: \n";
        getline(std::cin, lastName);
        if (lastName == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }
        //Validate Name Input
        while (!isValidName(lastName)) {
            std::cout << "Invalid last name. Please enter a valid last name: \n";
            getline(std::cin, lastName);
            if (lastName == "-1") {
                std::cout << "Insertion cancelled. Returning to main menu.\n";
                return;
            }
        }

        std::cout << "Enter Street Address: \n";
        getline(std::cin, streetAddress);
        if (streetAddress == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }

        std:: cout << "Enter City: \n";
        getline(std::cin, city);
        if (city == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }

        //validate city name
        while (!isValidName(city)) {
            std::cout << "Invalid city name. Please enter a valid city name: \n";
            getline(std::cin, city);
            if (city == "-1") {
                std::cout << "Insertion cancelled. Returning to main menu.\n";
                return;
            }
        }

        std:: cout << "Enter State (2-letter abbreviation: E.g.NY NJ): \n";
        getline(std::cin, state);
        if (state == "-1") {   
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }
        //validate state name
        while (!isValidState(state)) {
            std::cout << "Invalid state abbreviation. Please enter a valid state name: \n";
            getline(std::cin, state);
            if (state == "-1") {
                std::cout << "Insertion cancelled. Returning to main menu.\n";
                return;
            }
        }

        std:: cout << "Enter Zip Code: \n";
        getline(std::cin, zipCode);
        if (zipCode == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }
        //Validate Zip Code Input
        while (!isValidZipCode(zipCode)) {
            std::cout << "Invalid zip code. Please enter a valid 5-digit zip code: \n";
            getline(std::cin, zipCode);
            if (zipCode == "-1") {
                std::cout << "Insertion cancelled. Returning to main menu.\n";
                return;
            }
        }

        std:: cout << "Enter Phone Number (10 digits, no spaces or dashes): \n";
        getline(std::cin, phoneNumber);
        if (phoneNumber == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }
        //Validate Phone Number Input
        while (!isValidPhoneNumber(phoneNumber)) {
            std::cout << "Invalid phone number. Please enter a valid 10-digit phone number no spaces or dashes: \n";
            getline(std::cin, phoneNumber);
            if (phoneNumber == "-1") {
                std::cout << "Insertion cancelled. Returning to main menu.\n";
                return;
            }
        }

        //Formats phone number to XXX-XXX-XXXX
        phoneNumber = phoneNumber.substr(0, 3) + "-" + phoneNumber.substr(3, 3) + "-" + phoneNumber.substr(6, 4);

        //Format State to Uppercase
        std::transform(state.begin(), state.end(), state.begin(), ::toupper);

        std:: cout << "Account Number will be Generated Automatically.\n";
        accountNumber = defaultCustomerDataBase.size() + 1001; //Simple account number generation

        if (firstName == "-1" || lastName == "-1" || streetAddress == "-1" || city == "-1" || state == "-1" || zipCode == "-1" || phoneNumber == "-1") {
            std::cout << "Insertion cancelled. Returning to main menu.\n";
            return;
        }
        /*AllCustomers(const std::string& firstName, const std::string& lastName, const int& accountNumber, 
    const std::string& streetAddress, const std::string& city, const std::string& state, 
    const std::string& zipCode, const std::string& phoneNumber);*/

        AllCustomers newCustomer(firstName, lastName, accountNumber, streetAddress, city, state, zipCode, phoneNumber);
        defaultCustomerDataBase.push_back(newCustomer);
        std::cout << "Customer added successfully.\n";

        std::cout << "Add another customer? (1 for Yes, -1 to Cancel): ";
        std::cin >> userCancel;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        if (userCancel == 1) {
            insertNewCustomer(); //Recursive call to add another customer
        } else {
            std::cout << "Returning to main menu.\n";
        }
}

void ManageAllCustomers::updateCustomerInformation() {

    std::cout << "Type Account Number of Customer to Update: ";
    int accountNumber;
    std::cin >> accountNumber;
    

    for (int i = 0; i < defaultCustomerDataBase.size(); ++i)
    {
        if(defaultCustomerDataBase[i].getAccountNumber() == accountNumber)
        {
            std::cout << "Customer Found. \n";
            printCustomerHeader();
            defaultCustomerDataBase[i].printCustomerData();
            while(true) {
                int userSelect;
                std::cout << "Select Field to Update:\n"
                            << "1: First Name\n"
                            << "2: Last Name\n"
                            << "3: Street Address\n"
                            << "4: City\n"
                            << "5: State\n"
                            << "6: Zip Code\n"
                            << "7: Phone Number\n"
                            << "8: Exit Update Menu\n"
                            << "Enter Option: ";
                std::cin >> userSelect;
                std::cin.ignore(); //Ignore newline character
                //Perform Update Based on User Selection
                switch(userSelect){
                    case 1:{
                        std::string newFirstName;
                        std::cout << "Enter New First Name: ";
                        getline(std::cin, newFirstName);
                        while(isValidName(newFirstName) == false){
                            std::cout << "Invalid first name. Please enter a valid first name: \n";
                            getline(std::cin, newFirstName);
                        }
                        newFirstName[0] = toupper(newFirstName[0]); //Capitalize first letter
                        defaultCustomerDataBase[i].setFirstName(newFirstName);
                        break;
                    }
                    case 2:{
                        std::string newLastName;
                        std::cout << "Enter New Last Name: ";
                        getline(std::cin, newLastName);
                        while(isValidName(newLastName) == false){
                            std::cout << "Invalid last name. Please enter a valid last name: \n";
                            getline(std::cin, newLastName);
                        }
                        newLastName[0] = toupper(newLastName[0]); //Capitalize first letter
                        defaultCustomerDataBase[i].setLastName(newLastName);
                        break;
                    }
                    case 3:{
                        std::string newStreetAddress;
                        std::cout << "Enter New Street Address: ";
                        getline(std::cin, newStreetAddress);
                        defaultCustomerDataBase[i].setStreetAddress(newStreetAddress);
                        break;
                    }
                    case 4:{
                        std::string newCity;
                        std::cout << "Enter New City: ";
                        getline(std::cin, newCity);
                        defaultCustomerDataBase[i].setCity(newCity);
                        break;
                    }
                    case 5:{
                        std::string newState;
                        std::cout << "Enter New State: ";
                        getline(std::cin, newState);
                        while(!isValidState(newState)){  //Check for valid state input
                            std::cout << "Invalid state abbreviation. Please enter a valid state name: \n";
                            getline(std::cin, newState);
                        }
                        std::transform(newState.begin(), newState.end(), newState.begin(), ::toupper); //Convert to uppercase
                        defaultCustomerDataBase[i].setState(newState);
                        break;
                    }
                    case 6:{
                        std::string newZipCode;
                        std::cout << "Enter New Zip Code: ";
                        getline(std::cin, newZipCode);
                        while(!isValidZipCode(newZipCode)){ //Check for valid zip code input
                            std::cout << "Invalid zip code. Please enter a valid 5-digit zip code: \n";
                            getline(std::cin, newZipCode);
                        }
                        defaultCustomerDataBase[i].setZipCode(newZipCode);
                        break;
                    }
                    case 7:{
                        std::string newPhoneNumber;
                        std::cout << "Enter New Phone Number: no spaces or dashes: ";
                        getline(std::cin, newPhoneNumber);
                        while(!isValidPhoneNumber(newPhoneNumber)){
                            std::cout << "Invalid phone number. Please enter a 10-digit phone number: no spaces or dashes: \n";
                            getline(std::cin, newPhoneNumber);
                        }
                        newPhoneNumber = newPhoneNumber.substr(0, 3) + "-" + newPhoneNumber.substr(3, 3) + "-" + newPhoneNumber.substr(6, 4);
                        defaultCustomerDataBase[i].setPhoneNumber(newPhoneNumber);
                        break;
                    }
                    case 8:{
                        std::cout << "Done Updating. Returning to Main Menu.\n";
                        return; //Exit update menu
                    }
                    default:
                        std::cout << "Invalid Option Selected. Returning to Main Menu.\n";
                }
                std::cout << "Updated Customer Information: \n";
                printCustomerHeader();
                defaultCustomerDataBase[i].printCustomerData();
            }
        }
    }
}


void ManageAllCustomers::deleteCustomer(){
    std::cout << "Type Account Number of Customer to Delete: ";
    int accountNumber;
    int finalConfirm;
    std::cin >> accountNumber;
    std::cin.ignore(); //Ignore newline character

    std::cout << "Are you sure you want to delete this customer? Type 1 for Yes, 0 for No: ";
    std::cin >> finalConfirm;
    std::cin.ignore(); //Ignore newline character
    if(finalConfirm != 1){
        std::cout << "Deletion cancelled. Returning to Main Menu.\n";
        return;
    }
    for (int i = 0; i < defaultCustomerDataBase.size(); ++i)
    {
        if(defaultCustomerDataBase[i].getAccountNumber() == accountNumber)
        {
            std::cout << "Customer Found. Deleting Customer Account #: " << accountNumber << "\n";
            defaultCustomerDataBase.erase(defaultCustomerDataBase.begin() + i); //Remove from vector (destructor called automatically)
            std::cout << "Customer Deleted Successfully. Returning to Main Menu.\n";
            return;
        }
        else {
            std::cout << "Customer with account number not found: Returning to Main Menu " << accountNumber << " not found.\n";
        }
    }

}
void ManageAllCustomers::addNewCustomerPurchase() {
    std::cout << "Type Account Number of Customer to Add Purchase: ";
    int accountNumber;
    std::cin >> accountNumber;
    std::cin.ignore(); //Ignore newline character

    for(auto& account : defaultCustomerDataBase){
        if(account.getAccountNumber() == accountNumber){
            std::string item;
            std::string yearStr, monthStr, dayStr;
            double costOfPurchase;

            std::cout << "Enter Item Name: ";
            getline(std::cin, item);

            bool validDate = false;
            int year, month, day;
            
            while (!validDate) {  //Check for valid date input
                std::cout << "Enter Date of Purchase (YYYY MM DD):";
                std::cout << "Year (YYYY): " << std::endl; 
                getline(std::cin, yearStr);
                std::cout << "Month (MM): " << std::endl;
                getline(std::cin, monthStr);
                std::cout << "Day (DD): " << std::endl;
                getline(std::cin, dayStr);
                //std::cin.ignore(); //Ignore newline character

                validDate = yearStr.size() == 4 &&
                        monthStr.size() == 2 &&
                        dayStr.size() == 2 &&
                        std::all_of(yearStr.begin(), yearStr.end(), ::isdigit) &&
                        std::all_of(monthStr.begin(), monthStr.end(), ::isdigit) &&
                        std::all_of(dayStr.begin(), dayStr.end(), ::isdigit);
                
                if (!validDate) {
                    std::cout << "Invalid date format. Please use YYYY MM DD format.\n";
                } else {
                    year = std::stoi(yearStr);
                    month = std::stoi(monthStr);
                    day = std::stoi(dayStr);
                }
            }

            std::cout << "Enter Cost of Purchase: ";
            std::cin >> costOfPurchase;
            std::cin.ignore(); //Ignore newline character

            Date purchaseDate(year, month, day);
            AllPurchases newPurchase(accountNumber, item, purchaseDate, costOfPurchase);
            account.addPurchaseToHistory(newPurchase);
            std::cout << "Purchase added successfully.\n";

            std::cout << "Add another purchase? (1 for Yes, 0 for No): ";
            int userOption;
            std::cin >> userOption;
            std::cin.ignore(); //Ignore newline character
            if (userOption == 1) {
                addNewCustomerPurchase(); //Recursive call to add another purchase
            } else {
                std::cout << "Returning to main menu.\n";
            }
            return;
        }
    }
    std::cout << "Customer with account number " << accountNumber << " not found.\n";
}

void ManageAllCustomers::exportCustomerData() {
    std::string userDefinedFilename;
    std::cout << "Would you like to (1) Overwrite existing file or (2) Export to new file? Enter 1 or 2: ";
    int userOption;
    std::cin >> userOption;
    std::cin.ignore(); //Ignore newline character

    if (userOption == 1) {
        userDefinedFilename = "CustomerData.csv"; //Default filename to overwrite
    } else if (userOption == 2) {
        std::cout << "Enter new filename (with .csv extension): ";
        getline(std::cin, userDefinedFilename);
    } else {
        std::cout << "Invalid option selected. Returning to main menu.\n";
        return;
    }

    std::ofstream outputFile(userDefinedFilename); //Open file for writing
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << userDefinedFilename << std::endl;
        return;
    }
    //Write Header Line
    outputFile << "accountNumber,firstName,lastName,streetAddress,city,state zipCode,phoneNumber\n";
    //Write Customer Data
    for (const auto& customer : defaultCustomerDataBase) {
        outputFile << customer.getAccountNumber() << ","
                   << customer.getFirstName() << ","
                   << customer.getLastName() << ","
                   << customer.getStreetAddress() << ","
                   << customer.getCity() << ","
                   << customer.getState() << ","
                   << customer.getZipCode() << ","
                   << customer.getPhoneNumber() << "\n";
    }
    outputFile.close(); //Close the file after writing
    std::cout << "Customer data exported successfully to " << userDefinedFilename << "\n";
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
            printCustomerHeader();
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