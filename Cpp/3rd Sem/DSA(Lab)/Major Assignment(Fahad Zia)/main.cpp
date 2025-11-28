#include <iostream>
#include<vector>
#include<limits>

using namespace std;


// Item class(Node for Items Class)
class Item
{
public:
    string name;
    Item *next;
    Item *prev;
    Item(string name) : name(name)
    {
        next = nullptr;
        prev = nullptr;
    }
};

// list of items
class Items
{
public:
    // constructor
    Item* head = nullptr;
    Item* tail = nullptr;


    // Insert at end
    void append(string name){
        Item* newItem = new Item(name);
        if(!head){
            head = newItem;
            tail = newItem;
        }
        else{
            tail->next = newItem;
            newItem->prev = tail;
            tail = newItem;
        }
    }
    
    // display Items
    void display(){
        if(!head){
            cout << "List is empty\n";
            return;
        }
        Item* temp = head;
        while(temp){
            cout << temp->name << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

// orderPackage (contains lists of Items)
class orderPackage{
    public:
    Items list;
    string shopName;
    float distance;
    string address;

    orderPackage(){}
    
    orderPackage(Items list,string shopName,string address,float distance):list(list),shopName(shopName),address(address),distance(distance){}



    // display 
    void display(){
        cout << "Items:";
        list.display();
        cout << shopName << endl;
        cout << distance << endl;
        cout << address << endl;
    }
};

// bag stack
class bagStack{
    public:
    orderPackage orders[3];
    int top = -1;


    // push
    void push(orderPackage order){
        if(top == 2){
            cout << "Stack overflow\n";
            return;
        }
        orders[++top] = order;
    }

    //isEmpty
    bool isEmpty(){
         if(top == -1){
            return true;
        }
        return false;
    }

    // pop
       orderPackage pop(){
        if(isEmpty()){
            cout << "Stack underflow\n";
            return orderPackage();
        }
       return orders[top--];
    }
};

// Nodes for conveyer belt
class bagNode{
    public:
    bagStack bag;
    bagNode* next = nullptr;
    bagNode(bagStack bag):bag(bag){}
};

// conveyer belt queue
class conveyerBeltQueue{
    public:
    bagNode* front = nullptr;
    bagNode* rear = nullptr;

    // enqueue
    void enqueue(bagStack bag){
        bagNode* newBag = new bagNode(bag);
        if(isEmpty()){
            front = newBag;
            rear = newBag;
        }
        else{
            rear->next = newBag;
            rear = newBag;
        }
    }
    
    // dequeue
    bagStack dequeue(){
        if(isEmpty()){
            cout << "Queue is empty\n";
            return bagStack();
        }
        bagNode* temp = front;
        front = front->next;
        bagStack bag = temp->bag;
        delete temp;
        return bag;
    }

    // isEmpty
    bool isEmpty(){
        if(!front && !rear){
            return true;
        }
        return false;
    }

};


// merging of Arrays
void merge(vector<orderPackage>& orders,int leftSt,int leftEnd, int rightEnd){
    vector<orderPackage> temp;
    int i = leftSt;
    int j = leftEnd + 1;
    while(i <= leftEnd && j <= rightEnd){
        if(orders[i].distance > orders[j].distance){
            temp.push_back(orders[i++]);
        }
        else{
            temp.push_back(orders[j++]);
        }
    }

    while(i <= leftEnd){
        temp.push_back(orders[i++]);
    }

    while(j <= rightEnd){
        temp.push_back(orders[j++]);
    }
   
    // filling the original array
    i = leftSt;
    j = 0;
    int size = temp.size();
    while(i <= rightEnd && j < size){
        orders[i++] = temp[j++];
    }


}

// mergeSort
void mergeSort(vector<orderPackage>& orders, int st, int end){
    if(st < end){
        int mid = st + (end - st)/2;
        
        // Left half
        mergeSort(orders,st,mid);
        
        // Right half
        mergeSort(orders,mid + 1,end);

        // merging
        merge(orders,st,mid,end);
        
    }
}

int main()
{

    vector<orderPackage> orders;
    int isRunning = 1;
    conveyerBeltQueue belt;

   // --- Inside main() ---

// input loop
while(isRunning){
    string name;
    string address;
    Items list;
    float distance;

    cout << "Enter your details:\n";

    cout << "Enter shop name: ";
    getline(cin, name);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Distance: ";
    cin >> distance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

    cout << "Enter Items:\n";
    int ordering = 1;
    while(ordering){
        string itemName;
        cout << "Enter item name: ";
        getline(cin, itemName);
        list.append(itemName);

        cout << "Press 0 to exit and 1 to stay: ";
        cin >> ordering;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
    }

    orderPackage order(list,name,address,distance);
    orders.push_back(order);

    cout << "Enter 1 to continue ordering and 0 to see results: ";
    cin >> isRunning;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
}

// --- Delivery loop ---

cout << "\nDelivering Orders:\n\n";
while(!belt.isEmpty()){
    bagStack bag = belt.dequeue();
    bool emptyBag = false; // reset for each bag
    while(!emptyBag){
        cout << "Order\n\n";
        orderPackage order = bag.pop();
        order.display();
        cout << "Order Complete\n\n";
        emptyBag = bag.isEmpty();
    }
}


    // sort the vector
    mergeSort(orders,0,orders.size() - 1);
    int sizeOfOrders = orders.size();

    // adding items to belt
    for (int i = 0; i < sizeOfOrders; ) {
    bagStack bag;
    int counter = 0;
    while(counter < 3 && i < sizeOfOrders) {
        bag.push(orders[i]);
        i++;
        counter++;
    }
    belt.enqueue(bag);
}

    

    // dequeueing
    cout << endl << endl << "Delivering Orders:\n\n";
    bool emptyBelt = belt.isEmpty();
    bool emptyBag = false;
    while(!emptyBelt){
        bagStack bag = belt.dequeue();
        while(!emptyBag){
            cout << "Order\n\n";
            orderPackage order = bag.pop();
            order.display();
            emptyBag = bag.isEmpty();
            cout << endl;
            cout << "Order Complete\n\n";
        }
        emptyBelt = belt.isEmpty();
    }
    
    
    return 0;
}