#include <bits/stdc++.h>
using namespace std;

// global declarations
// material - listing
int counter = 0;
float teaLeavesStock = 500, teaLeavesCutoff = 50; float teaLeavesCost = 1.0;
float coffeePowderStock = 500, coffeePowderCutoff = 50; float coffeePowderCost = 2;
float sugarStock = 600, sugarCutoff = 50; float sugarCost = 1.5;
float milkStock = 8000, milkCutoff = 4000; float milkCost = 0.15;
float waterStock = 15000, waterCutoff = 600; float waterCost = 0.02;
float teaLeavesMax = 500, coffeePowderMax = 500, sugarMax = 4200, waterMax = 15000, milkMax = 4200;

// selling price
// float strongCoffeeSP = 17.5, lightCoffeeSP = 16.5, strongTeaSP = 15.50, lightTeaSP = 15.0; 

bool valid = true;
float milkLeakageLost = 0, waterLeakageLost = 0;

float maal = 500 + 1000 + 900 + 1200 + 300;

float profit;
float milkServed = 0, waterServed = 0;

// stocks consumed
float teaLeavesCon = 0, coffeePowderCon = 0, milkCon = 0, waterCon = 0, sugarCon = 0;


// stock filling

void stockFilling() {
    
    bool chalega = true;
    cout << "---------- Choose stock to fill ----------" << endl;
    cout << "1. Tea Leaves (Currently -> " << teaLeavesStock << ") Capacity -> " << teaLeavesMax << endl;
    cout << "2. Coffee Powder (Currently -> " << coffeePowderStock << ") Capacity -> " << coffeePowderMax << endl;
    cout << "3. Sugar (Currently -> " << sugarStock << ") Capacity -> " << sugarMax << endl;
    cout << "4. Milk (Currently -> " << milkStock << ") Capacity -> " << milkMax << endl;
    cout << "5. Water (Currently -> " << waterStock << ") Capacity -> " << waterMax << endl;
    cout << "6. Exit the operation, and return to main menu" << endl;
    cout << endl;

    while(chalega) {

        cout << "Enter a choice to update: ";
        int num; cin >> num;

        switch (num) {
        case 1:
            int stock1;
            cout << "Enter tea leaves stock to fill: ";
            cin >> stock1;
            if(teaLeavesStock + stock1 > teaLeavesMax) {
                cout << "Tea Leaves capacity overflow!! Cannot add, reduce the number of stocks" << endl;
                break;
            } else {
                teaLeavesStock += stock1;
                cout << "Stock updated successfully!" << endl;
            }
            break;

        case 2:
            int stock2;
            cout << "Enter coffee powder stock to fill: ";
            cin >> stock2;
            if(coffeePowderStock + stock2 > coffeePowderMax) {
                cout << "Coffee Powder capacity overflow!! Cannot add, reduce the number of stocks" << endl;
                break;
            } else {
                coffeePowderStock += stock2;
                cout << "Stock updated successfully!" << endl;
            }
            break;

        case 3:
            int stock3;
            cout << "Enter sugar stock to fill: ";
            cin >> stock3;
            if(sugarStock + stock3 > sugarMax) {
                cout << "Sugar capacity overflow!! Cannot add, reduce the number of stocks" << endl;
                break;
            } else {
                sugarStock += stock3;
                cout << "Stock updated successfully!" << endl;
            }
            break;

        case 4:
            int stock4;
            cout << "Enter milk stock to fill: ";
            cin >> stock4;
            if(milkStock + stock4 > milkMax) {
                cout << "Milk capacity overflow!! Cannot add, reduce the number of stocks" << endl;
                break;
            } else {
                milkStock += stock4;
                cout << "Stock updated successfully!" << endl;
            }
            break;

        case 5:
            int stock5;
            cout << "Enter water stock to fill: ";
            cin >> stock5;
            if(waterStock + stock5 > waterMax) {
                cout << "Water capacity overflow!! Cannot add, reduce the number of stocks" << endl;
                break;
            } else {
                waterStock += stock5;
                cout << "Stock updated successfully!" << endl;
            }
            break;
        
        case 6:
            chalega = false; break;

        default:
            break;
        }
    }
}



// functions
void strongCoffee() {

    bool wantSugar;
    cout << "Would you prefer sugar? 1 for yes, and 0 for no: ";
    cin >> wantSugar;

    if (milkServed >= 200) {
        milkServed = 0;
        milkStock -= 10;
        milkLeakageLost += 10;
    }

    if(waterServed >= 500) {
        waterServed = 0;
        waterStock -= 25;
        waterLeakageLost += 25;
    }

    if ((milkStock < milkCutoff) || (sugarStock < sugarCutoff) || (teaLeavesStock < teaLeavesCutoff) || (coffeePowderStock < coffeePowderCutoff) || (waterStock < waterCutoff) ) {
        int n;
        cout << "---------- Current Stocks ----------" << endl;
        cout << "Tea Leaves: " << teaLeavesStock << endl;
        cout << "Coffee Powder: " << coffeePowderStock << endl;
        cout << "Sugar: " << sugarStock << endl;
        cout << "Milk: " << milkStock << endl;
        cout << "Water: " << waterStock << endl;
        cout << "---------------------------------------" << endl;
        cout << "WARNING! Stock refill is needed! Press 1 to fill the stocks or any other number to continue: ";
        cin >> n;
        if (n == 1) stockFilling();
    }


    if (!milkStock || !teaLeavesStock || !coffeePowderStock || !sugarStock || !waterStock) {
        cout << "Please refill first!! One of the raw materials is out of stock" << endl;
        return;
    }

    if (wantSugar) {
        if (sugarStock < 2) {
            cout << "Not enough sugar to serve with coffee. Please refill sugar." << endl;
            return;
        }
        sugarCon += 2;
        sugarStock -= 2;
    }

    milkServed += 50;

    milkStock -= 50;
    milkCon += 50;

    coffeePowderStock -= 4;
    coffeePowderCon += 4;

    waterStock -= 100;
    waterCon += 100;
    waterServed += 100;

    profit += 17.5;
    counter++;
    
    cout << "-----------------------------" << endl;
    cout << "| Strong Coffee is served!  |" << endl;
    cout << "-----------------------------" << endl << endl;

    cout << "---------- Current Stocks ----------" << endl;
    cout << "Tea Leaves: " << teaLeavesStock << endl;
    cout << "Coffee Powder: " << coffeePowderStock << endl;
    cout << "Sugar: " << sugarStock << endl;
    cout << "Milk: " << milkStock << endl;
    cout << "Water: " << waterStock << endl;
    cout << "---------------------------------------" << endl;
}

void lightCoffee() {

    bool wantSugar;
    cout << "Would you prefer sugar? 1 for yes, and 0 for no: ";
    cin >> wantSugar;

    if (milkServed >= 200 && milkStock >= milkCutoff) {
        milkServed = 0;
        milkStock -= 10;
        milkLeakageLost += 10;
    }

    if(waterServed >= 500) {
        waterServed = 0;
        waterStock -= 25;
        waterLeakageLost += 25;
    }


    if ((milkStock < milkCutoff) || (sugarStock < sugarCutoff) || (teaLeavesStock < teaLeavesCutoff) || (coffeePowderStock < coffeePowderCutoff) || (waterStock < waterCutoff) ) {
        int n;
        cout << "---------- Current Stocks ----------" << endl;
        cout << "Tea Leaves: " << teaLeavesStock << endl;
        cout << "Coffee Powder: " << coffeePowderStock << endl;
        cout << "Sugar: " << sugarStock << endl;
        cout << "Milk: " << milkStock << endl;
        cout << "Water: " << waterStock << endl;
        cout << "---------------------------------------" << endl;
        cout << "WARNING! Stock refill is needed! Press 1 to fill the stocks or any other number to continue: ";
        cin >> n;
        if (n == 1) stockFilling();
    }

    
    if (!milkStock || !teaLeavesStock || !coffeePowderStock || !sugarStock || !waterStock) {
        cout << "Please refill first!! One of the raw materials is out of stock" << endl;
        return;
    }

    if (wantSugar) {

        if (sugarStock < 1.5) {
            cout << "Not enough sugar to serve with coffee. Please refill sugar." << endl;
            return;
        }

        sugarCon += 1.5;
        sugarStock -= 1.5;
    }

    milkStock -= 60;
    milkServed += 60;
    milkCon += 60;
    coffeePowderStock -= 2;
    coffeePowderCon += 2;
    waterStock -= 100;
    waterCon += 100;
    waterServed += 100;

    profit += 16.5;
    counter++;
    
    cout << "----------------------------" << endl;
    cout << "| Light Coffee is served!  |" << endl;
    cout << "----------------------------" << endl << endl;

    cout << "---------- Current Stocks ----------" << endl;
    cout << "Tea Leaves: " << teaLeavesStock << endl;
    cout << "Coffee Powder: " << coffeePowderStock << endl;
    cout << "Sugar: " << sugarStock << endl;
    cout << "Milk: " << milkStock << endl;
    cout << "Water: " << waterStock << endl;
    cout << "-------------------------------------" << endl;
    
}


void strongTea() {

    bool wantSugar;
    cout << "Would you prefer sugar? 1 for yes, and 0 for no: ";
    cin >> wantSugar;

    if (milkServed >= 200 && milkStock >= milkCutoff) {
        milkServed = 0;
        milkStock -= 10;
        milkLeakageLost += 10;
    }

    if(waterServed >= 500) {
        waterServed = 0;
        waterStock -= 25;
        waterLeakageLost += 25;
    }


    if ((milkStock < milkCutoff) || (sugarStock < sugarCutoff) || (teaLeavesStock < teaLeavesCutoff) || (coffeePowderStock < coffeePowderCutoff) || (waterStock < waterCutoff) ) {
        int n;
        cout << "---------- Current Stocks ----------" << endl;
        cout << "Tea Leaves: " << teaLeavesStock << endl;
        cout << "Coffee Powder: " << coffeePowderStock << endl;
        cout << "Sugar: " << sugarStock << endl;
        cout << "Milk: " << milkStock << endl;
        cout << "Water: " << waterStock << endl;
        cout << "---------------------------------------" << endl;
        cout << "WARNING! Stock refill is needed! Press 1 to fill the stocks or any other number to continue: ";
        cin >> n;
        if (n == 1) stockFilling();
    }

    
    if (!milkStock || !teaLeavesStock || !coffeePowderStock || !sugarStock || !waterStock) {
        cout << "Please refill first!! One of the raw materials is out of stock" << endl;
        return;
    }

    if (wantSugar) {
        if (sugarStock < 2) {
            cout << "Not enough sugar to serve with coffee. Please refill sugar." << endl;
            return;
        }
        sugarCon += 2;
        sugarStock -= 2;
    }

    milkStock -= 30 ;
    milkServed += 30    ;
    milkCon += 30   ;
    coffeePowderStock -= 0;
    coffeePowderCon += 0;
    waterStock -= 150;
    waterCon += 150;
    waterServed += 150;
    teaLeavesStock -= 4;
    teaLeavesCon += 4;

    profit += 15.50;
    counter++;
    
    cout << "----------------------------" << endl;
    cout << "| Strong tea is served!  |" << endl;
    cout << "----------------------------" << endl << endl;

    cout << "---------- Current Stocks ----------" << endl;
    cout << "Tea Leaves: " << teaLeavesStock << endl;
    cout << "Coffee Powder: " << coffeePowderStock << endl;
    cout << "Sugar: " << sugarStock << endl;
    cout << "Milk: " << milkStock << endl;
    cout << "Water: " << waterStock << endl;
    cout << "-------------------------------------" << endl;
    
}


void lightTea() {

    bool wantSugar;
    cout << "Would you prefer sugar? 1 for yes, and 0 for no: ";
    cin >> wantSugar;

    if (milkServed >= 200 && milkStock >= milkCutoff) {
        milkServed = 0;
        milkStock -= 10;
        milkLeakageLost += 10;
    }

    if(waterServed >= 500) {
        waterServed = 0;
        waterStock -= 25;
        waterLeakageLost += 25;
    }


    if ((milkStock < milkCutoff) || (sugarStock < sugarCutoff) || (teaLeavesStock < teaLeavesCutoff) || (coffeePowderStock < coffeePowderCutoff) || (waterStock < waterCutoff) ) {
        int n;
        cout << "---------- Current Stocks ----------" << endl;
        cout << "Tea Leaves: " << teaLeavesStock << endl;
        cout << "Coffee Powder: " << coffeePowderStock << endl;
        cout << "Sugar: " << sugarStock << endl;
        cout << "Milk: " << milkStock << endl;
        cout << "Water: " << waterStock << endl;
        cout << "---------------------------------------" << endl;
        cout << "WARNING! Stock refill is needed! Press 1 to fill the stocks or any other number to continue: ";
        cin >> n;
        if (n == 1) stockFilling();
    }

    
    if (!milkStock || !teaLeavesStock || !coffeePowderStock || !sugarStock || !waterStock) {
        cout << "Please refill first!! One of the raw materials is out of stock" << endl;
        return;
    }

    if (wantSugar) {
        if (sugarStock < 1.5) {
            cout << "Not enough sugar to serve with coffee. Please refill sugar." << endl;
            return;
        }
        sugarCon += 1.5;
        sugarStock -= 1.5;
    }

    milkStock -= 40;
    milkServed += 40;
    milkCon += 40;
    coffeePowderStock -= 0;
    coffeePowderCon += 0;
    waterStock -= 150;
    waterCon += 150;
    waterServed += 150;
    teaLeavesStock -= 3;
    teaLeavesCon += 3;

    profit += 15.00;
    counter++;
    
    cout << "----------------------------" << endl;
    cout << "| Light Tea is served!  |" << endl;
    cout << "----------------------------" << endl << endl;

    cout << "---------- Current Stocks ----------" << endl;
    cout << "Tea Leaves: " << teaLeavesStock << endl;
    cout << "Coffee Powder: " << coffeePowderStock << endl;
    cout << "Sugar: " << sugarStock << endl;
    cout << "Milk: " << milkStock << endl;
    cout << "Water: " << waterStock << endl;
    cout << "-------------------------------------" << endl;
    
}


void displayData() {
    float val = (maal - profit);
    cout << maal << endl;
    cout << "---------- REPORT ----------" << endl;
    cout << "Tea Leaves stock consumed " << teaLeavesCon << " stock remaining is " << teaLeavesStock << endl;
    cout << "Coffee Powder stock consumed " << coffeePowderCon << " stock remaining is " << coffeePowderStock << endl;
    cout << "Sugar stock consumed " << sugarCon << " stock remaining is " << sugarStock << endl;
    cout << "Milk stock consumed " << milkCon << " stock remaining is " << milkStock << endl;
    cout << "Water stock consumed " << waterCon << " stock remaining is " << waterStock << endl;
    cout << "Cups of tee or coffee disposed are " << counter << endl;
    cout << "Units of milk lost is " << milkLeakageLost << endl;
    cout << "Units of water lost is " << waterLeakageLost << endl;
    if(val > 0) {
        cout << "Running in loss of " << val << endl;
    } else {
        cout << "Running in profit of " << (-1 * val) << endl;
    }
    cout << "---------------------------------------" << endl;
}

void mainCaller() {
    while(valid) {
        cout << "---------- Enter your choice ----------" << endl;
        cout << "1. Strong Coffee" << endl;
        cout << "2. Light Coffee" << endl;
        cout << "3. Strong Tea" << endl;
        cout << "4. Light Tea" << endl;
        cout << "5. Exit" << endl;
        cout << "---------------------------------------" << endl;
        int num;
        cout << "Enter a valid choice: ";
        cin >> num;
        switch (num) {
        case 1:
            cout << "Chose strong coffee" << endl;
            strongCoffee();
            break;
        case 2:
            cout << "Chose light coffee" << endl;
            lightCoffee();
            break;
        case 3:
            cout << "Chose strong tee" << endl;
            strongTea();
            break;
        case 4:
            cout << "Chose light tee" << endl;
            lightTea();
            break;
        case 5:
            displayData();
            valid = false;
            break;
        default:
            cout << "Choose a valid option" << endl;
            break;
        }
    }
}

int main() {
    mainCaller();
}