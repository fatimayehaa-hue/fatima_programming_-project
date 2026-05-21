#include<iostream>
#include<vector>
#include<fstream>
#include <string>
using namespace  std;

struct flight
{
    int id;
    string name;
    int seats;
};

int main()
{
    int x;
    vector<flight> flights;
    
    do{
    cout << "  == == = Airline Reservation System == == =" << endl;
    cout << "1. Add Flight" << endl;
    cout << "2. Show Flights" << endl;
    cout << "3. Search Flight " << endl;
    cout << "4. Book Seat" << endl;
    cout << "5. Exit" << endl;
 
    cout << "choose :";
    cin >> x;
    if(x==1)
    {
    ofstream file("flight.txt",ios::app);
    flight f1;

    cout << "enter the id of flight :";
    cin >> f1.id;
    cout << "enter the name of flight :";
    cin>>f1.name;
    cout << "enter the namber seats of flight :";
    cin >> f1.seats;

    flights.push_back(f1);

    file << f1.id << " ";
    file << f1.name << " ";
    file << f1.seats <<endl;
    file.close();
    }
    else if(x==2)
    {
        ifstream file("flight.txt");
        flight f;
        while (file >> f.id >> f.name >> f.seats)
        {
            cout << "ID: " << f.id << endl;
            cout << "Name: " << f.name << endl;
            cout << "Seats: " << f.seats << endl;
        }
        file.close();
    }
   else if (x==3)
     {
         int id;
         cout << "enter the id of flight :";
         cin >> id;
         ifstream file("flight.txt");
         bool w=true ;
         flight f;
         while (file >> f.id >> f.name >> f.seats)
         {
            if (f.id==id)
            {
             cout << "ID: " << f.id << endl;
             cout << "Name: " << f.name << endl;
             cout << "Seats: " << f.seats << endl;
             w = false;
            }
            
         }
         if (w==true)
         {
             cout << "flight not found" << endl;
         }
         file.close();

         
     }
     else if (x == 4)
     {
         vector<flight> f2;
         f2.clear();
         ifstream file("flight.txt");
         flight f;
         while (file >> f.id >> f.name >> f.seats)
         {
             f2.push_back(f);

         }
         file.close();
         cout << "enter the flight id :";
         int id;
         cin >> id;
         for (int i = 0; i < f2.size();i++)
         {
            if (f2[i].id==id)
            {
                if (f2[i].seats > 0)
                {
                    f2[i].seats--;

                    cout << "Seat Booked ok" << endl;
                }
                else
                {
                    cout << "No Seats " << endl;
                }
            }
         }

         ofstream outfile("flight.txt");
         for (int i = 0; i < f2.size();i++)
         {
             
            
             outfile << f2[i].id << " ";
             outfile << f2[i].name << " ";
             outfile << f2[i].seats << endl;
         }
             outfile.close();
    }
    

    } while (x !=5);

    return 0;
} 

