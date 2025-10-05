#include <iostream>
#include "TV.hpp"
#include "Remote.hpp"
using namespace std;

void displayMainMenuTask1();
void displayTVControlMenuTask1();
void controlTVTask1(Remote& remote, TV& tv);
void testTask1();


int main() {
    testTask1();

    return 0;
}

void displayMainMenuTask1() {
    cout << "\n┌─────────────────────────────────────────────────┐" << endl;
    cout << "│                TV CONTROL SYSTEM               │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ 1. Create TVs                                  │" << endl;
    cout << "│ 2. Control TV 1                                │" << endl;
    cout << "│ 3. Control TV 2                                │" << endl;
    cout << "│ 4. Show all TVs status                         │" << endl;
    cout << "│ 5. Switch remote to TV 1                       │" << endl;
    cout << "│ 6. Switch remote to TV 2                       │" << endl;
    cout << "│ 7. Show current remote target                  │" << endl;
    cout << "│ 0. Exit                                        │" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
    cout << "Enter your choice: ";
}

void displayTVControlMenuTask1() {
    cout << "\n┌─────────────────────────────────────────────────┐" << endl;
    cout << "│                TV CONTROL MENU                  │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ 1. Power ON/OFF                                │" << endl;
    cout << "│ 2. Next Channel                                │" << endl;
    cout << "│ 3. Previous Channel                            │" << endl;
    cout << "│ 4. Increase Volume                             │" << endl;
    cout << "│ 5. Decrease Volume                             │" << endl;
    cout << "│ 6. Go to specific channel                      │" << endl;
    cout << "│ 7. Show TV status                              │" << endl;
    cout << "│ 0. Back to main menu                           │" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
    cout << "Enter your choice: ";
}

void testTask1() {
    TV* tv1 = nullptr;
    TV* tv2 = nullptr;
    Remote* remote = nullptr;
    TV* currentTarget = nullptr;
    int choice;
    
    cout << "🎬 Welcome to TV Control System! 🎬" << endl;
    cout << "This program demonstrates control of multiple TVs with one remote." << endl;
    
    do {
        displayMainMenuTask1();
        cin >> choice;
        
        switch(choice) {
            case 1: {
                if (tv1 == nullptr || tv2 == nullptr) {
                    // Create two different TVs with different specifications
                    tv1 = new TV(OFF, 1, 50, 5, 30);
                    tv2 = new TV(OFF, 10, 100, 15, 50);
                    
                    cout << "\n✅ Successfully created two TVs:" << endl;
                    cout << "TV 1: 50 channels, max volume 30" << endl;
                    cout << "TV 2: 100 channels, max volume 50" << endl;
                    
                    // Set initial remote to TV 1
                    if (remote == nullptr) {
                        remote = new Remote(tv1);
                        currentTarget = tv1;
                        cout << "📱 Remote is now connected to TV 1" << endl;
                    }
                } else {
                    cout << "\n⚠️  TVs already created!" << endl;
                }
                break;
            }
            
            case 2: {
                if (tv1 == nullptr) {
                    cout << "\n✗ Please create TVs first (option 1)!" << endl;
                } else {
                    cout << "\n📺 Controlling TV 1..." << endl;
                    tv1->show();
                    Remote tempRemote(tv1);
                    controlTVTask1(tempRemote, *tv1);
                }
                break;
            }
            
            case 3: {
                if (tv2 == nullptr) {
                    cout << "\n✗ Please create TVs first (option 1)!" << endl;
                } else {
                    cout << "\n📺 Controlling TV 2..." << endl;
                    tv2->show();
                    Remote tempRemote(tv2);
                    controlTVTask1(tempRemote, *tv2);
                }
                break;
            }
            
            case 4: {
                if (tv1 == nullptr || tv2 == nullptr) {
                    cout << "\n✗ Please create TVs first (option 1)!" << endl;
                } else {
                    cout << "\n📊 ALL TVs STATUS:" << endl;
                    cout << "\n=== TV 1 ===" << endl;
                    tv1->show();
                    cout << "\n=== TV 2 ===" << endl;
                    tv2->show();
                }
                break;
            }
            
            case 5: {
                if (tv1 == nullptr) {
                    cout << "\n✗ Please create TVs first (option 1)!" << endl;
                } else {
                    if (remote != nullptr) {
                        delete remote;
                    }
                    remote = new Remote(tv1);
                    currentTarget = tv1;
                    cout << "\n📱 Remote switched to TV 1" << endl;
                    tv1->show();
                }
                break;
            }
            
            case 6: {
                if (tv2 == nullptr) {
                    cout << "\n✗ Please create TVs first (option 1)!" << endl;
                } else {
                    if (remote != nullptr) {
                        delete remote;
                    }
                    remote = new Remote(tv2);
                    currentTarget = tv2;
                    cout << "\n📱 Remote switched to TV 2" << endl;
                    tv2->show();
                }
                break;
            }
            
            case 7: {
                if (remote == nullptr) {
                    cout << "\n✗ No remote available! Please create TVs first." << endl;
                } else {
                    cout << "\n📱 Current remote target:" << endl;
                    if (currentTarget == tv1) {
                        cout << "Remote is connected to TV 1" << endl;
                    } else if (currentTarget == tv2) {
                        cout << "Remote is connected to TV 2" << endl;
                    }
                    currentTarget->show();
                }
                break;
            }
            
            case 0:
                cout << "\n👋 Thank you for using TV Control System!" << endl;
                cout << "Cleaning up..." << endl;
                break;
                
            default:
                cout << "\n✗ Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 0);
};

void controlTVTask1(Remote& remote, TV& tv) {
    int choice;
    int channel;
    
    do {
        displayTVControlMenuTask1();
        cin >> choice;
        
        switch(choice) {
            case 1:
                remote.power();
                cout << "\n✓ Power button pressed!" << endl;
                break;
                
            case 2:
                remote.nextChannel();
                cout << "\n✓ Next channel button pressed!" << endl;
                break;
                
            case 3:
                remote.prevChannel();
                cout << "\n✓ Previous channel button pressed!" << endl;
                break;
                
            case 4:
                remote.incVolume();
                cout << "\n✓ Volume up button pressed!" << endl;
                break;
                
            case 5:
                remote.decVolume();
                cout << "\n✓ Volume down button pressed!" << endl;
                break;
                
            case 6:
                cout << "Enter channel number: ";
                cin >> channel;
                if (channel >= 1 && channel <= tv.getChannelsCount()) {
                    remote.goToChannel(channel);
                    cout << "\n✓ Switched to channel " << channel << "!" << endl;
                } else {
                    cout << "\n✗ Invalid channel number! Available: 1-" << tv.getChannelsCount() << endl;
                }
                break;
                
            case 7:
                cout << "\n";
                tv.show();
                break;
                
            case 0:
                cout << "\n← Returning to main menu..." << endl;
                break;
                
            default:
                cout << "\n✗ Invalid choice! Please try again." << endl;
        }
        
        if (choice != 0 && choice != 7) {
            cout << "\n";
            tv.show();
        }
        
    } while (choice != 0);
}

