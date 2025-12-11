# CSC 211 Final Project - Advanced C++ Features Mockup

## Project Overview
A menu-driven Customer Management System using advanced C++ concepts. The system loads customer data from CSV files, manages purchases, and provides CRUD operations through a command-line interface.

---

## Advanced C++ Features Implementation

### 1. **CONSTRUCTORS**

#### 1.1 Default Constructors
**AllCustomers.cpp - Lines 8-11**
```cpp
//Default Constructor
AllCustomers::AllCustomers() 
    : m_firstName("N/A"), m_lastName("N/A"), m_accountNumber(0000), 
      m_streetAddress("N/A"), m_city("N/A"), m_state("N/A"), 
      m_zipCode("N/A"), m_phoneNumber("N/A") {}
```
**Purpose:** Initializes AllCustomers object with default values using member initializer list

**AllPurchases.h - Lines 45-46**
```cpp
AllPurchases(): m_accountNumber(0000), m_item("N/A"), 
    m_dateOfPurchase(), m_costOfPurchase(0.0) {}
```
**Purpose:** Initializes AllPurchases object with default purchase values

**Date Struct - Lines 16-17 (AllPurchases.h)**
```cpp
Date() : year(2025), month(1), day(1) {}
```
**Purpose:** Initializes Date with default values (January 1, 2025)

**ManageAllCustomers.h - Line 68**
```cpp
ManageAllCustomers() : M_storeName("Store Location Unknown ") {}
```
**Purpose:** Default constructor for store management system

---

#### 1.2 Parameterized Constructors
**AllCustomers.cpp - Lines 13-18**
```cpp
//PARAM Constructor
AllCustomers::AllCustomers(const std::string& firstName, const std::string& lastName, const int& accountNumber, 
    const std::string& streetAddress, const std::string& city, const std::string& state, 
    const std::string& zipCode, const std::string& phoneNumber) 
    : m_firstName(firstName), m_lastName(lastName), m_accountNumber(accountNumber),
      m_streetAddress(streetAddress), m_city(city), m_state(state),
      m_zipCode(zipCode), m_phoneNumber(phoneNumber) {}
```
**Purpose:** Constructs AllCustomers with specific customer data using member initializer list

**AllPurchases.h - Lines 48-50**
```cpp
AllPurchases(const int& accountNumber, const std::string& item, const Date& dateOfPurchase, const double& costOfPurchase) :
    m_accountNumber(accountNumber), m_item(item), m_dateOfPurchase(dateOfPurchase), m_costOfPurchase(costOfPurchase) {}
```
**Purpose:** Constructs AllPurchases with transaction details

**Date Struct - Lines 19-21 (AllPurchases.h)**
```cpp
Date(const int& yearVal, const int& monthVal, const int& dayVal)
: year(yearVal), month(monthVal), day(dayVal) {}
```
**Purpose:** Constructs Date with specific year, month, day values

**ManageAllCustomers.h - Line 69**
```cpp
ManageAllCustomers(const std::string& storeName) : M_storeName(storeName) {}
```
**Purpose:** Parameterized constructor accepting store name

---

#### 1.3 Copy Constructors
**AllCustomers.cpp - Lines 20-28**
```cpp
//Copy Constructor
AllCustomers::AllCustomers(const AllCustomers& other) {
    m_firstName = other.m_firstName;
    m_lastName = other.m_lastName;
    m_accountNumber = other.m_accountNumber;
    m_streetAddress = other.m_streetAddress;
    m_city = other.m_city;
    m_state = other.m_state;
    m_zipCode = other.m_zipCode;
    m_phoneNumber = other.m_phoneNumber;
}
```
**Purpose:** Creates a deep copy of AllCustomers object (used in std::vector operations)

**AllPurchases.h - Lines 52-59**
```cpp
AllPurchases(const AllPurchases& other) { //Copy Constructor
    m_accountNumber = other.m_accountNumber;
    m_item = other.m_item;
    m_dateOfPurchase = other.m_dateOfPurchase;
    m_costOfPurchase = other.m_costOfPurchase;
}
```
**Purpose:** Creates deep copy of AllPurchases object

---

### 2. **OVERLOADED ASSIGNMENT OPERATORS**

**AllCustomers.cpp - Lines 30-41**
```cpp
//Overloaded Assignment Operator
AllCustomers& AllCustomers::operator=(const AllCustomers& rhs){
    if (this == &rhs){
        return *this;
    }
    m_firstName = rhs.m_firstName;
    m_lastName = rhs.m_lastName;
    m_accountNumber = rhs.m_accountNumber;
    m_streetAddress = rhs.m_streetAddress;
    m_city = rhs.m_city;
    m_state = rhs.m_state;
    m_zipCode = rhs.m_zipCode;
    m_phoneNumber = rhs.m_phoneNumber;
    return *this;
}
```
**Purpose:** Enables assignment between AllCustomers objects with self-assignment check

**AllPurchases.h - Lines 61-73**
```cpp
AllPurchases& operator=(const AllPurchases& rhs){ //Overloaded Assignment Operator
    if (this == &rhs){
        return *this;
    }
    m_accountNumber = rhs.m_accountNumber;
    m_item = rhs.m_item;
    m_dateOfPurchase = rhs.m_dateOfPurchase;
    m_costOfPurchase = rhs.m_costOfPurchase;
    return *this;
}
```
**Purpose:** Enables assignment between AllPurchases objects with self-assignment protection

---

### 3. **DESTRUCTORS**

**AllCustomers.h - Line 76**
```cpp
~AllCustomers(){}
```
**Purpose:** Default destructor for AllCustomers (empty because no dynamic memory)

**ManageAllCustomers.h - Line 91**
```cpp
~ManageAllCustomers(){} //Destructor
```
**Purpose:** Default destructor for ManageAllCustomers (std::vector handles cleanup automatically)

---

### 4. **RANGE-BASED FOR LOOPS**

**ManageAllCustomers.h - Line 18**
```cpp
for(char c : input){
    if(!std::isalpha(c) && c != ' ' && c != '-') return false;
}
```
**Purpose:** Validates each character in name input (isValidName helper function)

**ManageAllCustomers.h - Line 25**
```cpp
for(char c : input){
    if(!std::isdigit(c)) return false;
}
```
**Purpose:** Validates phone number digits (isValidPhoneNumber helper function)

**ManageAllCustomers.h - Line 31**
```cpp
for(char c : input){
    if(!std::isdigit(c)) return false;
}
```
**Purpose:** Validates zip code digits (isValidZipCode helper function)

**ManageAllCustomers.h - Line 37**
```cpp
for(char c : input){
    if(!std::isalpha(c)) return false;
}
```
**Purpose:** Validates state abbreviation (isValidState helper function)

**ManageAllCustomers.cpp - Line 600**
```cpp
for(auto& account : defaultCustomerDataBase){
    if(account.getAccountNumber() == accountNumber){
```
**Purpose:** Iterates through customer database to find matching account (addNewCustomerPurchase function)

---

### 5. **LAMBDA FUNCTIONS & SORTING**

**ManageAllCustomers.cpp - Lines 237-242**
```cpp
std::sort(sortedCustomerData.begin(), sortedCustomerData.end(),
    [](const AllCustomers& a, const AllCustomers& b) {
        return a.getLastName() < b.getLastName();
    }
);
```
**Purpose:** Sorts customers by last name in ascending order using lambda comparator

**ManageAllCustomers.cpp - Lines 246-251**
```cpp
std::sort(sortedCustomerData.begin(), sortedCustomerData.end(),
    [](const AllCustomers& a, const AllCustomers& b) {
        return a.getLastName() > b.getLastName();
    }
);
```
**Purpose:** Sorts customers by last name in descending order using lambda comparator

---

### 6. **RECURSION**

#### 6.1 Recursive Customer Insertion
**ManageAllCustomers.cpp - Line 436**
```cpp
insertNewCustomer(); //Recursive call to add another customer
```
**Context (Lines 433-438):**
```cpp
std::cout << "Add another customer? (1 for Yes, -1 to Cancel): ";
std::cin >> userCancel;
std::cin.ignore(); // To ignore the newline character left in the buffer

if (userCancel == 1) {
    insertNewCustomer(); //Recursive call to add another customer
} else {
    std::cout << "Returning to main menu.\n";
}
```
**Purpose:** Allows user to add multiple customers recursively after each insertion

#### 6.2 Recursive Purchase Addition
**ManageAllCustomers.cpp - Line 656**
```cpp
addNewCustomerPurchase(); //Recursive call to add another purchase
```
**Context (Lines 652-660):**
```cpp
std::cout << "Add another purchase? (1 for Yes, 0 for No): ";
int userOption;
std::cin >> userOption;
std::cin.ignore(); //Ignore newline character
if (userOption == 1) {
    addNewCustomerPurchase(); //Recursive call to add another purchase
} else {
    std::cout << "Returning to main menu.\n";
}
```
**Purpose:** Allows user to add multiple purchases for same customer recursively

#### 6.3 Recursive Customer Index Selection
**ManageAllCustomers.cpp - Line 822**
```cpp
return userCustomerSelectIndex();
```
**Context (Lines 818-826):**
```cpp
if(userIndex < 0 || userIndex >= defaultCustomerDataBase.size()){
    std::cout << "Invalid index selected. Trying again.\n";
    return userCustomerSelectIndex();
}
else {
    return defaultCustomerDataBase[userIndex].getAccountNumber();
}
```
**Purpose:** Re-prompts user if invalid index selected, recursively calls itself

---

### 7. **VECTORS (Dynamic Arrays)**

**ManageAllCustomers.h - Line 61**
```cpp
std::vector<AllCustomers> defaultCustomerDataBase;
```
**Purpose:** Stores all customers dynamically, allowing expansion as customers are added

**AllCustomers.h - Line 21**
```cpp
std::vector<AllPurchases> customerPurchaseHistory;
```
**Purpose:** Stores all purchases for each customer dynamically

**ManageAllCustomers.cpp - Line 427**
```cpp
AllCustomers newCustomer(firstName, lastName, accountNumber, streetAddress, city, state, zipCode, phoneNumber);
defaultCustomerDataBase.push_back(newCustomer);
```
**Purpose:** Adds new customer to vector

---

### 8. **FILE I/O & PARSING**

**ManageAllCustomers.cpp - Lines 62-71 (loadCustomerDataFromFile)**
```cpp
std::ifstream inputFile;
inputFile.open(filename);
if (!inputFile.is_open()){/* Error handling */}
std::string line = ""; //Temp string to hold each line of file

getline(inputFile, line); //Skip header line
line = ""; //Clear line variable

while(getline(inputFile, line)) 
{/* CSV parsing logic */}
```
**Purpose:** Loads customer data from CSV file with error checking

**ManageAllCustomers.cpp - Lines 112-120 (loadCustomerPurchaseDataFromFile)**
```cpp
std::ifstream inputFile;
inputFile.open(filename);
if (!inputFile.is_open()){/* Error handling */}
std::string line = ""; 

getline(inputFile, line); //Skip header line
line = "";

while(getline(inputFile, line)) 
{/* CSV parsing logic */}
```
**Purpose:** Loads purchase data from CSV file with custom delimiter parsing

---

### 9. **CONST MEMBER FUNCTIONS**

**AllCustomers.h - Line 50**
```cpp
std::vector<AllPurchases> getPurchaseHistory() const {return customerPurchaseHistory;}
```
**Purpose:** Guarantees function doesn't modify object state

**AllCustomers.h - Lines 47-53**
```cpp
int getAccountNumber() const {return m_accountNumber;}
std::string getFirstName() const {return m_firstName;}
std::string getLastName() const {return m_lastName;}
std::string getStreetAddress() const {return m_streetAddress;}
std::string getCity() const {return m_city;}
std::string getState() const {return m_state;}
std::string getZipCode() const {return m_zipCode;}
std::string getPhoneNumber() const {return m_phoneNumber;}
```
**Purpose:** Getter functions prevent accidental modification

**AllCustomers.cpp - Line 43**
```cpp
void AllCustomers::printCustomerData() const
```
**Purpose:** Const method that prints customer data without modification

---

### 10. **ALGORITHM LIBRARY FUNCTIONS**

**ManageAllCustomers.h - Line 18 (isValidName)**
```cpp
std::all_of(yearStr.begin(), yearStr.end(), ::isdigit)
```
**Purpose:** Validates all characters in string are digits using std::all_of

**ManageAllCustomers.cpp - Line 625**
```cpp
std::all_of(yearStr.begin(), yearStr.end(), ::isdigit) &&
std::all_of(monthStr.begin(), monthStr.end(), ::isdigit) &&
std::all_of(dayStr.begin(), dayStr.end(), ::isdigit);
```
**Purpose:** Validates date input strings contain only digits

**ManageAllCustomers.cpp - Lines 237-242**
```cpp
std::sort(sortedCustomerData.begin(), sortedCustomerData.end(),
    [](const AllCustomers& a, const AllCustomers& b) {
        return a.getLastName() < b.getLastName();
    }
);
```
**Purpose:** Uses std::sort with custom lambda comparator

---

### 11. **STRING MANIPULATION**

**ManageAllCustomers.cpp - Line 395**
```cpp
phoneNumber = phoneNumber.substr(0, 3) + "-" + phoneNumber.substr(3, 3) + "-" + phoneNumber.substr(6, 4);
```
**Purpose:** Formats phone number from "1234567890" to "123-456-7890" using substr()

**ManageAllCustomers.cpp - Line 401**
```cpp
std::transform(state.begin(), state.end(), state.begin(), ::toupper);
```
**Purpose:** Converts state abbreviation to uppercase using std::transform

**AllPurchases.h - Lines 28-33 (returnDateAsString)**
```cpp
std::string returnDateAsString() const{
    std::stringstream dateStream;
    dateStream << std::setw(4) << std::setfill('0') << year << "-"
               << std::setw(2) << std::setfill('0') << month << "-"
               << std::setw(2) << std::setfill('0') << day;
    return dateStream.str();
}
```
**Purpose:** Formats date from integers to "YYYY-MM-DD" string format

---

### 12. **EXCEPTION HANDLING**

**ManageAllCustomers.h - Lines 45-54 (readMenuChoice)**
```cpp
try {
    int choice = std::stoi(line);
    return choice;
} 
catch(...) {
    std::cout << "Please enter a number. \n";
}
```
**Purpose:** Catches std::invalid_argument exception when stoi() fails on non-numeric input

---

### 13. **MEMBER INITIALIZER LISTS**

**AllCustomers.cpp - Lines 8-11**
```cpp
AllCustomers::AllCustomers() 
    : m_firstName("N/A"), m_lastName("N/A"), m_accountNumber(0000), 
      m_streetAddress("N/A"), m_city("N/A"), m_state("N/A"), 
      m_zipCode("N/A"), m_phoneNumber("N/A") {}
```
**Purpose:** Efficient initialization of all member variables before constructor body executes

---

### 14. **PUBLIC MEMBER FUNCTIONS**

**All operations implemented as public member functions:**
- `displayAllCustomerData()` - Line 75 (ManageAllCustomers.h)
- `displaySortedCustomerData()` - Line 80 (ManageAllCustomers.h)
- `insertNewCustomer()` - Line 82 (ManageAllCustomers.h)
- `updateCustomerInformation()` - Line 84 (ManageAllCustomers.h)
- `deleteCustomer()` - Line 85 (ManageAllCustomers.h)
- `addNewCustomerPurchase()` - Line 88 (ManageAllCustomers.h)
- `displaySpecificCustomerAccountAndPurchaseHistory()` - Line 92 (ManageAllCustomers.h)
- `customerManageMenuApp()` - Line 93 (ManageAllCustomers.h)

---

## File Structure

```
Final-Project/
├── storeApp.cpp              (Main entry point)
├── AllCustomers.h            (Customer class header)
├── AllCustomers.cpp          (Customer class implementation)
├── AllPurchases.h            (Purchase class header & Date struct)
├── AllPurchases.cpp          (Purchase class implementation)
├── ManageAllCustomers.h      (Management class header)
├── ManageAllCustomers.cpp    (Management class implementation)
├── customerAccountData.csv   (Customer data file)
├── customerPurchases.csv     (Purchase data file)
└── PROJECT_MOCKUP.md         (This file)
```

---

## Menu Options & Features

| Menu Option | Implementation Location | Advanced Features Used |
|---|---|---|
| 1. Display All Customers | `displayAllCustomerData()` | Vector iteration, File I/O |
| 2. Display Sorted Customers | `displaySortedCustomerData()` | std::sort, Lambda functions |
| 3. Add New Customer | `insertNewCustomer()` | Recursion, Validation, Copy constructor |
| 4. Update Customer | `updateCustomerInformation()` | Member functions, Range-based for |
| 5. Delete Customer | `deleteCustomer()` | Vector operations, Validation |
| 6. Display Specific Customer | `displaySpecificCustomerAccountAndPurchaseHistory()` | Const functions, Vector |
| 7. Add Purchase | `addNewCustomerPurchase()` | Recursion, File I/O, Exception handling |
| 8. View Total Spend | `displayTotalCustomerSpendAmt()` | Vector iteration, Calculations |
| 9. Export Data | `exportCustomerData()` | File I/O, User selection |

---

## Compilation Command

```bash
g++ -std=c++11 storeApp.cpp AllCustomers.cpp AllPurchases.cpp ManageAllCustomers.cpp -o storeApp
```

---

## Summary of Advanced Features

✅ **Constructors** (Default, Parameterized, Copy) - AllCustomers, AllPurchases, Date, ManageAllCustomers  
✅ **Overloaded Assignment Operators** - AllCustomers, AllPurchases  
✅ **Destructors** - AllCustomers, ManageAllCustomers  
✅ **Range-Based Loops** - Validation functions, Database iteration  
✅ **Lambda Functions** - std::sort comparators  
✅ **Recursion** - Customer insertion, Purchase addition, Index selection  
✅ **Vectors** - Dynamic customer & purchase storage  
✅ **File I/O** - CSV parsing for customers and purchases  
✅ **Const Member Functions** - Getters and display methods  
✅ **std::sort & std::all_of** - Algorithm library usage  
✅ **String Manipulation** - Phone formatting, state conversion, date formatting  
✅ **Exception Handling** - stoi() error handling  
✅ **Member Initializer Lists** - Efficient object initialization  
✅ **Public Member Functions** - All operations as class methods  

