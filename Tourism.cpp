#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>

#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*******Class holiday to implement booking of a place by user*******/

class holiday{
    private:
    int id;
    char custname[50];
    char country[50];
    char hotel[50];
    float budget;
    int pno;
    public:
        void bookholiday();
        void viewhol();
        void changebookings();
        void remove_rec();

    };

/*******Function holiday to store booking details of user*******/

void holiday::bookholiday(){

        ofstream fout("holiday.dat",ios::binary|ios::app);
        cout<<"Please enter your details for the required package: \nName: ";
        fflush(stdin);
        cin.getline(custname,50);
        cout<<"ID:  ";
        cin>>id;
        fflush(stdin);
        cout<<"Destination country:  ";
        cin.getline(country,50);
        cout<<"Hotel name:  ";
        cin.getline(hotel,50);
        cout<<"Budget:  ";
        cin>>budget;
        cout<<"Number of passengers:  ";
        cin>>pno;
        fout.write((char*)this,sizeof(holiday));
        fout.close();
        }

/*******Function viewhol to view the booking details of user*******/

void holiday::viewhol(){
        int myid;
        holiday y;
        int flag=0;
        ifstream fin("holiday.dat",ios::binary|ios::out);
        cout<<"Enter your ID:  ";
        fflush(stdin);
        cin>>myid;
        while(fin.read((char*)&y,sizeof(y))){
              if(myid==y.id){
                    flag++;
                    cout<<"\n\t\t\t\tYour package details are: \n";
                    cout<<"\t\t\t\t";
                    for(int i=0; i<25; i++) cout<<"*";
                    cout<<"\nName:  "<<y.custname;
                    cout<<"\nID:  "<<y.id;
                    cout<<"\nDestination country:  "<<y.country;
                    cout<<"\nHotel:  "<<y.hotel;
                    cout<<"\nBudget:  "<<y.budget;
                    cout<<"\nNumber of passengers:  "<<y.pno;
                    }
            }
        if(flag==0) cout<<"\nNo bookings available!\n";
        fin.close();
}

/*******Function changebookings to make changes in the details entered by user*******/

void holiday::changebookings(){
        int myid;
        ofstream fout("temp.dat",ios::binary);
        ifstream fin("holiday.dat",ios::binary);
        cout<<"Enter your ID to change your bookings:   ";
        fflush(stdin);
        cin>>myid;
        while(fin.read((char*)this,sizeof(holiday))){
            if(myid==id){
                cout<<"\n\t\t\tPlease enter your new details: \n\t\t\t";
                for(int i=0; i<30; i++) cout<<"*";
                fflush(stdin);
                cout<<"\nName:  ";
                cin.getline(custname,50);
                cout<<"ID:  ";
                cin>>id;
                fflush(stdin);
                cout<<"Destination country:  ";
                cin.getline(country,50);
                cout<<"Hotel:  ";
                cin.getline(hotel,50);
                cout<<"Budget:  ";
                cin>>budget;
                cout<<"No. of passengers:  ";
                cin>>pno;

            }
            fout.write((char*)this,sizeof(holiday));
        }
        fin.close();
        fout.close();
         remove("holiday.dat");
        rename("temp.dat","holiday.dat");
        }

/*******Function remove_rec to delete or remove a booking made by user*******/

void holiday::remove_rec(){
        int cust_id;
        holiday b;
        cout<<"To cancel booking, please enter your ID:  ";
        cin>>cust_id;
        ifstream fin("holiday.dat",ios::binary);
        ofstream fout("holiday.dat",ios::binary);
        //deleting records of holiday bookings as specified by user
        while(fin.read((char*)&b,sizeof(b))){
                if(b.id!=cust_id)
                    fout.write((char*)&b,sizeof(b));
                    }
        fin.close();
        fout.close();
        remove("holiday.dat");
        rename("new.dat","holiday.dat");
        cout<<"\nYour booking has been successfully cancelled! \n";
        }

/*******Class review to implement reviews of a particular country*******/

class review{
    private:
    char revcountry[50];
    int rating;
    int expenditure;
    char bestplace[50];
    char exp[100];
    public:
    void givereview();
    void viewreview();
};

/*******Function givereview for the users to enter review of a country visited by them*******/

void review::givereview(){

        ofstream fout("review.dat",ios::binary|ios::app);
        cout<<"\n\t\t\tREVIEWS\n";
        fflush(stdin);
        cout<<"Which country did you visit? :  ";
        cin.getline(revcountry,100);
        cout<<"Please rate your overall experience (out of ten) :  ";
        cin>>rating;
        cout<<"Your approximate expenditure :  ";
        cin>>expenditure;
        fflush(stdin);
        cout<<"Which is the best place to visit in this country? :  ";
        cin.getline(bestplace,50);
        cout<<"Please give a brief account of your experience:  ";
        cin.getline(exp,100);
        fout.write((char*)this,sizeof(review));
        fout.close();
}

/*******Function viewreview for users to see previously entered reviews of a country*******/

void review::viewreview(){
        char mycountry[50];

        int flag=0;
        ifstream fin("review.dat",ios::binary|ios::in);
        cout<<"Enter the country whose reviews you wish to see :  ";
        cin>>mycountry;
        int l=strlen(mycountry);
        while(fin.read((char*)this,sizeof(review))){
            if(strcmpi(mycountry,revcountry)==0){
                    flag++;
                    cout<<"\n\t\t\t\t"<<mycountry;
                    cout<<"\n\t\t\t\t";
                    for(int i=0; i<l; i++) cout<<"*";

                    cout<<"\nRatings (out of ten) :  "<<rating;
                    cout<<"\nAverage expenditure:  "<<expenditure;
                    cout<<"\nBest place to visit in "<<mycountry<<" :  "<<bestplace;
                    cout<<"\nExperience of previous visitors:  "<<exp;
            }
        }
        if(flag==0) cout<<"\nNo reviews available for this country!\n";
        fin.close();
}

/*******Function suggestedsports to view the recommended activities by us to try in certain countries*******/

void suggestedsports(){
        int no;
        cout<<"\n\t\t\tSuggested sports\n";
        cout<<"\tEnter your choice please:-\n\t\t1: India\n\t\t2: Australia\n\t\t3: Maldives\n\t\t4: Los Angeles\n\t\tChoice= ";
        cin>>no;
        if(no==1) cout<<"\nIndia is famous for its chess players. When in India, do play a game of chess with the locals!";
        else if(no==2) cout<<"\nNever leave Australie without trying your hand at bungee jumping.";
        else if(no==3) cout<<"\nScuba diving is something that is best experienced only in Maldives!";
        else if(no==4) cout<<"\nUniversal studios in Los Angeles offers the best theme-based rides in the world.";
        else cout<<"Invalid choice!";
        }

/*******Main function*******/

int main(){
    char ch='y';
    remove("holiday.dat");
    remove("review.dat");
    int choice;
    holiday h;
    holiday b;
    review r;
	cout<<"\n\t\t\tWELCOME TO INCREDIBLE INDIA TOURISM\n";
	cout<<"\t\t\t"; int i;
	for(i=0; i<35; i++)
		cout<<"*";
	while(ch=='y' || ch=='Y'){
	cout<<"\n\nPlease enter your choice:-\n\t1 : Book a new holiday package\n\t2 : View your bookings\n\t3 : Change bookings\n\t4 : Cancel a booking\n\t5 : Give review of a country you visited\n\t6 : View previously entered reviews of countries\n\t7 : Recommended activities by us in famous countries\n\t8 : Exit\n\t";
	cout<<"Choice=  ";
	cin>>choice;
	if(choice==1) h.bookholiday();
	else if(choice==2) h.viewhol();
	else if(choice==3) h.changebookings();
	else if(choice==4) b.remove_rec();
	else if(choice==5) r.givereview();
	else if(choice==6) r.viewreview();
	else if(choice==7) suggestedsports();
	else if(choice==8) break;
	cout<<"\n";
	for(int i=0; i<26; i++) cout<<" * ";
	cout<<" *";
	//after all function calls have ended
	cout<<"\n\nEnter y to continue :  ";
	cin>>ch;
	system("cls");
	}
	cout<<"\n\t\tTHANK YOU FOR VISITING INCREDIBLE INDIA TOURISM";
	return 0;
}

