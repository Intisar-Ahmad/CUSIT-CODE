#include <iostream>
#include <vector>    //vectors
#include <algorithm> // equal
#include <cctype>    // tolower
using namespace std;

// Intisar is very cool


// Please do not run this code on Dev C++ or any other online compiler, as may not support the latest C++ standards.
// This code uses things like forEach loops etc which are beyond the scope of Dev C++ as it uses a 98-Compiler.
//  For this code to run , please use the latest version of Visaul Studio or any other IDE that supports C++17 or above.


// I have explained the code in comments


class Product // This is the product class. All products are objects of this.
{
    string name;// contains name quantity and price. pretty simple
    int quantity;
    double price;

public:
    Product(string name, int qty, double price)// constructor initializing the product.
    {

        // I know I know, the validation is done down below in a seperate function. 

        this->name = name;
        this->quantity = qty;
        this->price = price;
    }


    // simple getters. The const is just my 'fanciness' at peak.
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void reduceQuantity(int qty) { quantity -= qty; }// if you buy a product it will get reduced.1


    //very simple display function displays all the properties
    void display() const
    {
        cout << "Name: " << name << " | Quantity: " << quantity << " | Price: $" << price << "\n";
    }
};


// Inheritance Check
class User // user class. Not necessary but kinda useful here since most of the function of customers and admin are the same.
{


protected:
    string email;
    string password;

public:
    User(string email, string password) : email(email), password(password) {} 


    //Pure virtual function 
    // abstract classes check
    virtual void showMenu() = 0;


    
    virtual bool checkLogin(string inputEmail, string inputPass)
    {
        return inputEmail == email && inputPass == password;
    }

    virtual void changePassword()
    {
        string oldPass, newPass;

        cout << "Enter current password: ";
        cin.ignore(1000, '\n'); // Clear leftover input
        getline(cin, oldPass);

        if (oldPass != password)
        {
            cout << "Incorrect password.\n";
            return;
        }

        cout << "Enter new password: ";
        getline(cin, newPass);// useful for spaces and stuff

        this->password = newPass;
        cout << "Password changed successfully.\n";
    }
};

class Admin : public User
{
    //composition check
    vector<Product> &products;
    string username = ""; //default username is always safer than garbage value;

public:
    Admin(string email, string username, string password, vector<Product> &prodList)
        : User(email, password), products(prodList), username(username) {}


        // polymorphism check
    bool checkLogin(string username, string inputPass)
    {
        return username == this->username && inputPass == this->password;
    }

    void addProduct()
    {
        string name;
        int qty;
        double price;
        cout << "Enter product name: ";
        cin.ignore(100,'\n');
        getline(cin,name);

        // Check if name already exists (case insensitive)
        for (auto &p : products)
        {
            string existing = p.getName();
            // this took a while to understand but it basically checks if the name matches another one in the array
            if (equal(name.begin(), name.end(), existing.begin(), existing.end(),
                      [](char a, char b)
                      { return tolower(a) == tolower(b); }))
            {
                cout << "Product already exists.\n";
                return;
            }
        }
        // the product validation from earlier
        cout << "Enter quantity: ";
        cin >> qty;
        cout << "Enter price: ";
        cin >> price;

        if (qty < 0 || price <= 0)
        {
            cout << "Invalid quantity or price.\n";
            return;
        }

        products.push_back(Product(name, qty, price));
        cout << "Product added successfully.\n";
    }

    void viewProducts()// nothing special
    {
        if (products.empty())
        {
            cout << "No products available.\n";
            return;
        }
        for (const auto &p : products)// for each or range-based for . pretty cool
            p.display();
    }

    void showMenu() override
    {
        int choice;
        do
        {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. View Products\n2. Add Product\n3. Change Password\n4. Logout\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                viewProducts();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                cout << "Logged out.\n";
                break;
            default:
                cout << "Invalid option.\n";// i could have broken out here but thats just inconvenient
            }
        } while (choice != 4);
    }
};

class CartItem // I had to complete the four classes requirement
{
public:
    Product *product;// Composition once again.
    int quantity;
};

class Customer : public User
{
    vector<Product> &products;
    vector<CartItem> cart;

public:
    Customer(string email, string password, vector<Product> &prodList)
        : User(email, password), products(prodList) {}

    void viewProducts()
    {
        if (products.empty())
        {
            cout << "No products available.\n";
            return;
        }
        for (const auto &p : products)
            p.display();
    }

    void searchProduct()
    {
        string name;
        cout << "Enter product name to search: ";
        cin.ignore(1000, '\n');
        getline(cin, name);
        bool found = false;
        for (auto i = 0; i < products.size(); i++)
        {
            string existing = products[i].getName();
            if (equal(name.begin(), name.end(), existing.begin(), existing.end(),
                      [](char a, char b)
                      { return tolower(a) == tolower(b); }))
            {
                products[i].display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Product not found.\n";
    }

    void addToCart()
    {
        string name;
        int qty;
        cout << "Enter product name to add to cart: ";
        cin >> name;

        for (auto &p : products)
        {
            if (p.getName() == name)
            {
                cout << "Enter quantity: ";
                cin >> qty;
                if (qty <= 0 || qty > p.getQuantity())
                {
                    cout << "Invalid quantity.\n";
                    return;
                }
                cart.push_back({&p, qty});
                cout << "Added to cart.\n";
                return;
            }
        }
        cout << "Product not found.\n";
    }

    void checkout()
    {
        if (cart.empty())
        {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "\n--- Cart Summary ---\n";
        double total = 0;
        for (auto &item : cart)
        {
            double cost = item.quantity * item.product->getPrice();
            cout << item.product->getName() << " x" << item.quantity
                 << " = $" << cost << "\n";
            total += cost;
        }
        cout << "Total: $" << total << "\n";

        char confirm;
        cout << "Confirm purchase? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y')
        {
            for (auto &item : cart)
            {
                item.product->reduceQuantity(item.quantity);
            }
            cart.clear();
            cout << "Purchase successful.\n";
        }
    }

    void showMenu() override
    {
        int choice;
        do
        {
            cout << "\n--- Customer Menu ---\n";
            cout << "1. View Products\n2. Search Product\n3. Add to Cart\n4. Checkout\n5. Change Password\n6. Logout\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                viewProducts();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                addToCart();
                break;
            case 4:
                checkout();
                break;
            case 5:
                changePassword();
                break;
            case 6:
                cout << "Logged out.\n";
                break;
            default:
                cout << "Invalid option.\n";
            }
        } while (choice != 6);
    }
};

int main()
{
    vector<Product> productList;
    Admin admin("intisar12122000@gmail.com", "Bhino", "16880", productList);
    vector<Customer> customers;

    int userType;
    do
    {
        cout << "\n--- Welcome ---\n1. Admin Login\n2. Customer Signup\n3. Customer Login\n4. Exit\nChoice: ";
        cin >> userType;

        if (cin.fail()) // if user is Pakistani
        {
            cout << "\nInvalid input. Program exiting...\n";
            exit(1);
        }

        if (userType == 1)
        {
            string u, p;
            cout << "Admin Username: ";
            cin.ignore(1000, '\n');
            getline(cin, u);
            cout << "Password: ";
            getline(cin, p);
            if (admin.checkLogin(u, p))
                admin.showMenu();
            else
                cout << "Login failed.\n";
        }
        else if (userType == 2)
        {
            string email, pass;
            cout << "Enter email: ";
            cin.ignore(1000, '\n');
            getline(cin, email);
            if (!(email.find('@') != string::npos && email.find('.') != string::npos))
            {
                cout << "Invalid email: missing '@' or '.'" << endl;
                continue;
            }

            cout << "Enter password: ";
            getline(cin, pass);
            customers.push_back(Customer(email, pass, productList));
            cout << "Signup successful.\n";
        }
        else if (userType == 3)
        {
            string email, pass;
            cout << "Enter email: ";
            cin.ignore(1000, '\n');
            getline(cin, email);
            cout << "Enter password: ";
            getline(cin, pass);
            bool found = false;
            for (auto &cust : customers)
            {
                if (cust.checkLogin(email, pass))
                {
                    cust.showMenu();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "User Doesn't Exist\n";
        }
    } while (userType != 4);

    return 0;
}
