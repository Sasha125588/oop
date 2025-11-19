#include <iostream>
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include "PoliceOfficer.hpp"
using namespace std;

void displayMainMenuTask2();
void demoScenariosTask2();
void testTask2();

int main()
{
    // demoScenariosTask2();
    testTask2();
    
    return 0;
}

void displayMainMenuTask2() {
    cout << "\n┌─────────────────────────────────────────────────┐" << endl;
    cout << "│            PARKING ENFORCEMENT SYSTEM           │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ 1. Create Police Officer                       │" << endl;
    cout << "│ 2. Create Parked Car                           │" << endl;
    cout << "│ 3. Create Parking Meter                        │" << endl;
    cout << "│ 4. Officer Patrol (Check for violations)       │" << endl;
    cout << "│ 5. Show Officer Information                    │" << endl;
    cout << "│ 6. Show Car Information                        │" << endl;
    cout << "│ 7. Show Meter Information                      │" << endl;
    cout << "│ 8. Demo Scenarios                              │" << endl;
    cout << "│ 0. Exit                                        │" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
    cout << "Enter your choice: ";
}

void demoScenariosTask2() {
    cout << "\n🎬 DEMONSTRATION SCENARIOS 🎬" << endl;
    cout << "This will show how the classes collaborate in real scenarios.\n" << endl;
    
    // Create a police officer
    PoliceOfficer officer("John Smith", "PD-1234");
    
    cout << "👮 Officer " << officer.getOfficerName() << " (Badge #" << officer.getBadgeNumber() << ") is on patrol...\n" << endl;
    
    // Scenario 1: No violation
    cout << "📍 SCENARIO 1: No Violation" << endl;
    cout << string(50, '=') << endl;
    ParkedCar car1("Toyota", "Camry", "Blue", "ABC-123", 30); // Parked for 30 minutes
    ParkingMeter meter1(60); // Paid for 60 minutes
    officer.patrolCar(car1, meter1);
    
    // Scenario 2: Minor violation
    cout << "\n📍 SCENARIO 2: Minor Violation (First Hour)" << endl;
    cout << string(50, '=') << endl;
    ParkedCar car2("Honda", "Civic", "Red", "XYZ-789", 90); // Parked for 90 minutes
    ParkingMeter meter2(60); // Paid for 60 minutes (30 minutes over)
    officer.patrolCar(car2, meter2);
    
    // Scenario 3: Major violation
    cout << "\n📍 SCENARIO 3: Major Violation (Multiple Hours)" << endl;
    cout << string(50, '=') << endl;
    ParkedCar car3("BMW", "X5", "Black", "DEF-456", 200); // Parked for 200 minutes
    ParkingMeter meter3(60); // Paid for 60 minutes (140 minutes over = 2.33 hours)
    officer.patrolCar(car3, meter3);
    
    // Scenario 4: Extreme violation
    cout << "\n📍 SCENARIO 4: Extreme Violation (Many Hours)" << endl;
    cout << string(50, '=') << endl;
    ParkedCar car4("Ford", "F-150", "White", "GHI-321", 480); // Parked for 480 minutes (8 hours)
    ParkingMeter meter4(60); // Paid for 60 minutes (420 minutes over = 7 hours)
    officer.patrolCar(car4, meter4);
    
    // Show officer's final statistics
    cout << "\n📊 OFFICER'S PATROL SUMMARY" << endl;
    cout << string(50, '=') << endl;
    officer.displayOfficerInfo();
    
    cout << "\n✅ Demonstration completed! All classes worked together successfully." << endl;
}

void testTask2() {
    PoliceOfficer* officer = nullptr;
    ParkedCar* car = nullptr;
    ParkingMeter* meter = nullptr;
    int choice;
    
    cout << "🚔 Welcome to Parking Enforcement System! 🚔" << endl;
    cout << "This program demonstrates how PoliceOfficer, ParkedCar, ParkingMeter," << endl;
    cout << "and ParkingTicket classes collaborate to enforce parking regulations." << endl;
    
    do {
        displayMainMenuTask2();
        cin >> choice;
        
        switch(choice) {
            case 1: {
                string name, badge;
                cout << "Enter officer name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter badge number: ";
                getline(cin, badge);
                
                officer = new PoliceOfficer(name, badge);
                cout << "\n✅ Police officer created successfully!" << endl;
                break;
            }
            
            case 2: {
                string make, model, color, license;
                int minutesParked;
                
                cout << "Enter car make: ";
                cin.ignore();
                getline(cin, make);
                cout << "Enter car model: ";
                getline(cin, model);
                cout << "Enter car color: ";
                getline(cin, color);
                cout << "Enter license number: ";
                getline(cin, license);
                cout << "Enter minutes parked: ";
                cin >> minutesParked;
                
                car = new ParkedCar(make, model, color, license, minutesParked);
                cout << "\n✅ Parked car created successfully!" << endl;
                break;
            }
            
            case 3: {
                int minutesPurchased;
                cout << "Enter minutes purchased on meter: ";
                cin >> minutesPurchased;
                
                meter = new ParkingMeter(minutesPurchased);
                cout << "\n✅ Parking meter created successfully!" << endl;
                break;
            }
            
            case 4: {
                if (officer == nullptr || car == nullptr || meter == nullptr) {
                    cout << "\n✗ Please create officer, car, and meter first!" << endl;
                } else {
                    officer->patrolCar(*car, *meter);
                }
                break;
            }
            
            case 5: {
                if (officer == nullptr) {
                    cout << "\n✗ Please create officer first!" << endl;
                } else {
                    officer->displayOfficerInfo();
                }
                break;
            }
            
            case 6: {
                if (car == nullptr) {
                    cout << "\n✗ Please create car first!" << endl;
                } else {
                    car->displayInfo();
                }
                break;
            }
            
            case 7: {
                if (meter == nullptr) {
                    cout << "\n✗ Please create meter first!" << endl;
                } else {
                    cout << "\n📊 PARKING METER INFORMATION:" << endl;
                    cout << "Minutes Purchased: " << meter->getMinutesPurchased() << endl;
                }
                break;
            }
            
            case 8: {
                demoScenariosTask2();
                break;
            }
            
            case 0:
                cout << "\n👋 Thank you for using Parking Enforcement System!" << endl;
                cout << "Cleaning up..." << endl;
                break;
                
            default:
                cout << "\n✗ Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 0);
}