#include<iostream>
#include<vector>
#include<fstream>
#include <string>
using namespace  std;

struct flight
{
    int id;
    string name;
    string time;
    int seats;
};

int main()
{
    int x;
    
    
    do{
    cout << "  == == = Airline Reservation System == == =" << endl;
    cout << "1. Add Flight" << endl;
    cout << "2. Show Flights" << endl;
    cout << "3. Search Flight " << endl;
    cout << "4. Book Seat" << endl;
    cout << "5.Browse Available Destinations" << endl;
    cout << "6. Exit" << endl;
 
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
    cout << "enter the time of flight :";
    cin >> f1.time;
    cout << "enter the namber seats of flight :";
    cin >> f1.seats;



    file << f1.id << " ";
    file << f1.name << " ";
    file << f1.time << " ";
    file << f1.seats <<endl;
    file.close();
    }
    else if(x==2)
    {
        ifstream file("flight.txt");
        flight f;
        while (file >> f.id >> f.name >>f.time>> f.seats)
        {
            cout << "ID: " << f.id << endl;
            cout << "Name: " << f.name << endl;
            cout << "time :" << f.time << endl;
            cout << "Seats: " << f.seats << endl;
        }
        file.close();
    }
   else if (x==3)
     {
         string name;
         cout << "enter the name of flight :";
         cin >> name;

         ifstream file("flight.txt");
         bool w=true ;
         flight f;
         while (file >> f.id >> f.name >>f.time>> f.seats)
         {
            if (f.name==name &&f.seats>0)
            {
             cout << "ID: " << f.id << endl;
             cout << "Name: " << f.name << endl;
             cout << "time :" << f.time << endl;
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
         while (file >> f.id >> f.name >>f.time>> f.seats)
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
                    flight *ptr = &f2[i];
                    ptr->seats--;

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
             outfile << f2[i].time << " ";
             outfile << f2[i].seats << endl;
         }
             outfile.close();
    }

    else if(x==5)
    {
        string destinations[30] = {"Baghdad", "Basra", "Erbil", "Najaf", "Mosul", "Dubai", "Istanbul", "Cairo", "Amman", "Doha",
             "Kuwait", "Beirut", "Tehran", "Riyadh", "Jeddah", "Ankara", "Paris", "London", "Berlin", "Rome", "Damascus", "Sharjah",
              "AbuDhabi", "Muscat", "Manama", "Frankfurt", "Madrid", "Toronto", "NewYork", "KualaLumpur"};

        for (int i = 0; i < 30;i++)
        {
            cout << i+1 << "." << destinations[i] << endl;
        }
    }
    else 
    {
        cout << "Invalid choice, please try again." << endl;
    }
    

    } while (x !=6);

    return 0;
} 

