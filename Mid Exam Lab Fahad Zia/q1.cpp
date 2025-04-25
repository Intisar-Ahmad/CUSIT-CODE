#include <iostream>

using namespace std;

class App
{
private:
    string applicationName;
    string installDate;
    double rating;
    static int totalAppCount;

public:
    App(string name, string date, double rating)
    {
        if (date.length() == 0)
        {
            installDate = __DATE__;
        }
        else
        {
            installDate = date;
        }
        if (name.length() == 0)
        {
            applicationName = "App";
        }
        else
        {
            applicationName = name;
        }
        if (rating > 5 || rating < 1)
        {
            this->rating = 1;
        }
        else
        {
            this->rating = rating;
        }
        totalAppCount++;
    }

    void setRating(double r)
    {
        if (r > 0 && r <= 5)
        {
            rating = r;
        }

        else
        {
            cout << "Couldn't set rating invalid input" << endl;
        }
    }

    void setInstallDate(string d)
    {
        installDate = d;
    }

    string getRanking()
    {
        if (rating >= 4.5)
        {
            return "Top Rated";
        }
        else if (rating >= 3.5 && rating < 4.5)
        {
            return "Popular";
        }
        else
        {
            return "Average";
        }
    }

    void displayInstallInfo()
    {
        cout << "Name: " << applicationName << endl;
        cout << "Date: " << installDate << endl;
        cout << "Rating: " << rating << endl;
        cout << "Ranking: " << getRanking() << endl;
    }

    static int getTotalAppsCount()
    {
        return totalAppCount;
    }
};

int App ::totalAppCount = 0;

int main()
{
    App a1("App1", "3-December-2009", 0);
    App a2("App2", "12-May-2024", 4.5);
    App a3("App3", "9-March-2024", 1.2);
    App a4("App4", "9-June-1990", 3);
    a1.setRating(5); // setting ratings
    a2.setRating(4);
    a3.setRating(3);
    a4.setRating(2);

    cout<<"\n\n";
    cout<<a1.getRanking()<<endl;
    cout<<a2.getRanking()<<endl;
    cout<<a3.getRanking()<<endl;
    cout<<a4.getRanking()<<endl;


    a1.displayInstallInfo(); // showing details
    a2.displayInstallInfo();
    a3.displayInstallInfo();
    a4.displayInstallInfo();

    cout << "\n\nTotal Number of apps published: " << App::getTotalAppsCount << endl;
    return 0;
}