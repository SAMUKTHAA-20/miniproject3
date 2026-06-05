#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Passenger{
public:
    string name;
    int age;
    string aadhaar;
    string source;
    string destination;
    string trainName;
    string seatType;
    int pnr;
    double fare;
};
int main(){
    Passenger p;
    bool ticketBooked = false;
    int choice;
    srand(time(0));
    do{
        cout << "\n=====================================\n";
        cout << " TRAIN TICKET BOOKING SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Book Ticket\n";
        cout << "2. View Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                if(ticketBooked){
                    cout << "\nA Ticket Is Already Booked!\n";
                    break;
                }
                cout << "\nEnter Passenger Name: ";
                cin >> p.name;
                cout << "Enter Age: ";
                cin >> p.age;
                if(p.age <= 0){
                    cout << "Invalid Age!\n";
                    break;
                }
                cout << "Enter Aadhaar Number (12 Digits): ";
                cin >> p.aadhaar;
                if(p.aadhaar.length() != 12){
                    cout << "Invalid Aadhaar Number!\n";
                    break;
                }
                cout << "Aadhaar Format Verified Successfully!\n";
                cout << "Enter Source Station: ";
                cin >> p.source;
                cout << "Enter Destination Station: ";
                cin >> p.destination;
                int trainChoice;

                cout << "\nAvailable Trains\n";
                cout << "1. Chennai Express\n";
                cout << "2. Kovai Express\n";
                cout << "3. Intercity Express\n";
                cout << "Select Train: ";
                cin >> trainChoice;

                switch(trainChoice){
                    case 1:
                        p.trainName = "Chennai Express";
                        break;

                    case 2:
                        p.trainName = "Kovai Express";
                        break;

                    case 3:
                        p.trainName = "Intercity Express";
                        break;

                    default:
                        cout << "Invalid Train Selection!\n";
                        break;
                }
                int seatChoice;
                cout << "\nSeat Types\n";
                cout << "1. General  - Rs.150\n";
                cout << "2. Sleeper  - Rs.400\n";
                cout << "3. AC       - Rs.900\n";
                cout << "Select Seat Type: ";
                cin >> seatChoice;
                switch(seatChoice){
                    case 1:
                        p.seatType = "General";
                        p.fare = 150;
                        break;

                    case 2:
                        p.seatType = "Sleeper";
                        p.fare = 400;
                        break;

                    case 3:
                        p.seatType = "AC";
                        p.fare = 900;
                        break;

                    default:
                        cout << "Invalid Seat Type!\n";
                        break;
                }
                if(p.age >= 60){
                    p.fare = p.fare * 0.80;
                    cout << "\n20% Senior Citizen Discount Applied!\n";
                }
                p.pnr = rand() % 900000 + 100000;
                ticketBooked = true;
                cout << "\n=====================================\n";
                cout << "Booking Successful!\n";
                cout << "Your PNR Number: " << p.pnr << endl;
                cout << "=====================================\n";
                break;
            }
            case 2:
            {
                if(!ticketBooked){
                    cout << "\nNo Ticket Booked Yet!\n";
                }else{
                    cout << "\n=====================================\n";
                    cout << " TRAIN TICKET DETAILS\n";
                    cout << "=====================================\n";
                    cout << "PNR Number      : " << p.pnr << endl;
                    cout << "Passenger Name  : " << p.name << endl;
                    cout << "Age             : " << p.age << endl;
                    cout << "Aadhaar Status  : Verified\n";
                    cout << "Train Name      : " << p.trainName << endl;
                    cout << "From            : " << p.source << endl;
                    cout << "To              : " << p.destination << endl;
                    cout << "Seat Type       : " << p.seatType << endl;
                    cout << "Ticket Fare     : Rs." << p.fare << endl;
                }
                break;
            }
            case 3:
            {
                if(!ticketBooked){
                    cout << "\nNo Ticket Available To Cancel!\n";
                }else{
                    int cancelPNR;
                    cout << "Enter PNR Number: ";
                    cin >> cancelPNR;
                    if(cancelPNR == p.pnr){
                        double refund = p.fare - 50;
                        cout << "\nTicket Cancelled Successfully!\n";
                        cout << "Cancellation Charge : Rs.50\n";
                        cout << "Refund Amount       : Rs."
                             << refund << endl;
                        ticketBooked = false;
                    }else{
                        cout << "Invalid PNR Number!\n";
                    }
                }
                break;
            }
            case 4:
            {
                cout << "\nThank You For Using Train Ticket Booking System!\n";
                break;
            }
            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }
    } while(choice != 4);
    return 0;
