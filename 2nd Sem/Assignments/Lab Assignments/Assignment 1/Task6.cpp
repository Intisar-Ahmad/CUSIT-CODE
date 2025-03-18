#include <iostream>

using namespace std;

/*
Task 6: Develop a Netflix-like streaming platform module.
Class: Movie
Attributes:
• name
• releaseDate
• rating
• category
Requirements:
• If rating is less than 0 or more than 50, show an error: "Invalid Rating Input!"
• If category is not one of the allowed ones, display: "Invalid category! Allowed: adventure, action, comedy, thriller."
*/

class Movie {
private:
    string name;
    string releaseDate;
    int rating;
    string category;

public:
    void setName(string n) { name = n; }
    void setReleaseDate(string date) { releaseDate = date; }

    void setRating(int r) {
        if (r < 0 || r > 50) {
            cout << "Invalid Rating Input!" << endl;
        } else {
            rating = r;
        }
    }

    void setCategory(string c) {
        if (c == "adventure" || c == "action" || c == "comedy" || c == "thriller") {
            category = c;
        } else {
            cout << "Invalid category! Allowed: adventure, action, comedy, thriller." << endl;
        }
    }

    void displayMovieInfo() {
        cout << "Name: " << name << endl;
        cout << "Release Date: " << releaseDate << endl;
        cout << "Rating: " << rating << endl;
        cout << "Category: " << category << endl;
    }
};

int main() {
    Movie movie1;
    movie1.setName("Inception");
    movie1.setReleaseDate("2010-07-16");
    movie1.setRating(45);  // Valid rating
    movie1.setCategory("sci-fi");  // Invalid category

    movie1.displayMovieInfo();
    return 0;
}
