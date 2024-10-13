//De Castro Daryl Vince B
//C2A Midterms
#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>

using namespace std;

class Item {
	protected:
	    string id,name,category;
	    int quantity;
	    double price;
	
	public:
	    virtual void displayItem() const=0;
	
	    string getID() const {
	        return id;
	    }
	    string getName() const {
	        return name;
	    }
	    string getCategory() const {
	        return category;
	    }
	    int getQuantity() const {
	        return quantity;
	    }
	    double getPrice() const {
	        return price;
	    }
	
	    void setQuantity(int newQuantity) {
	        quantity=newQuantity;
	    }
	    void setPrice(double newPrice) {
	        price=newPrice;
	    }
};
//clothing
class Clothing : public Item {
	public:
	    Clothing(string idValue,string nameValue,int quantityValue,double priceValue) {
	        id=idValue,name=nameValue,quantity=quantityValue,price=priceValue,category="Clothing";
	    }
	
	    void displayItem() const override {
	        cout<<left<<setw(10)<<id<<"| "<<left<<setw(20)<<name<<"| "<<left<<setw(10)<<quantity<<"| "<<left<<setw(10)<<price<<"|" << endl;
	    }
};
//electronics catte
class Electronics : public Item {
	public:
	    Electronics(string idValue,string nameValue,int quantityValue,double priceValue) {
	        id=idValue;
	        name=nameValue;
	        quantity=quantityValue;
	        price=priceValue;
	        category="Electronics";
	    }
	
	    void displayItem() const override {
	        cout<<left<<setw(10)<<id<<"| "<<left<<setw(20)<<name<<"| "<<left<<setw(10)<<quantity<<"| "<<left<<setw(10)<<price<<"|" << endl;
	    }
};
//entertainment cat
class Entertainment : public Item {
	public:
	    Entertainment(string idValue,string nameValue,int quantityValue,double priceValue) {
	        id=idValue;
	        name=nameValue;
	        quantity=quantityValue;
	        price=priceValue;
	        category="Entertainment";
	    }
	
	    void displayItem() const override {
	        cout<<left<<setw(10)<<id<<"| "<<left<<setw(20)<<name<<"| "<<left<<setw(10)<<quantity<<"| "<<left<<setw(10)<<price<<"|" << endl;
	    }
};

class Inventory {
	private:
	    Item* items[100]; 
	    int itemCount;
	
	public:
	    Inventory() {
	        itemCount=0;  
	    }
	//1) Add Item
	void addItem() {
	    char addAnother='y';
	
	    while(addAnother=='y'||addAnother=='Y') {
	        string id,name,category;
	        int quantity;
	        double price;
	        bool condition=true;
	
	        while(condition) {
	            cout<<"Enter Category (Clothing, Electronics, Entertainment): ";
	            cin>>category;
	            system("cls");
	
	            for(auto &c:category) {
	                c=tolower(c);
	            }
	
	            if(category=="clothing"||category=="electronics"||category=="entertainment") {
	                condition=false;
	            } else {
	                cout<<"Category "<<category<<" does not exist!\n\n";
	            }
	        }
	
	        if(category=="clothing") {
	            category="Clothing";
	        } else if(category=="electronics") {
	            category="Electronics";
	        } else if(category=="entertainment") {
	            category="Entertainment";
	        }
	
	        cout<<"A D D  I T E M\n\n";
	        bool validID=true;
	        while(validID) {
	            cout<<"Enter ID: ";
	            cin>>id;
	
	            bool sameID=false;
	            for(int i=0;i<itemCount;i++) {
	                if(items[i]->getID()==id) {
	                    sameID=true;
	                    break;
	                }
	            }
	
	            if(sameID) {
	                cout<<"ID already exists. Please enter a unique ID.\n";
	            } else if(id.empty()) {
	                cout<<"ID cannot be empty. Please enter a valid ID.\n";
	            } else {
	                validID=false;
	            }
	        }
	
	        bool validName=true;
	        while(validName) {
	            cout<<"Enter Name: ";
	            cin.ignore();
	            getline(cin,name);
	
	            bool sameName=false;
	            for(int i=0;i<itemCount;i++) {
	                if(items[i]->getName()==name) {
	                    sameName=true;
	                    break;
	                }
	            }
	
	            if(sameName) {
	                cout<<"Name already exists. Please enter a unique name.\n";
	            } else if(name.empty()) {
	                cout<<"Name cannot be empty. Please enter a valid name.\n";
	            } else {
	                bool hasNumber=false;
	                for(char c:name) {
	                    if(isdigit(c)) {
	                        hasNumber=true;
	                        break;
	                    }
	                }
	                if(hasNumber) {
	                    cout<<"Name cannot contain numbers. Please enter a valid name.\n";
	                } else {
	                    validName=false;
	                }
	            }
	        }
	
	        bool validQuantity=true;
	        while(validQuantity) {
	            cout<<"Enter Quantity (must be > 0): ";
	            cin>>quantity;
	            if(cin.fail()||quantity<=0) {
	                cin.clear();
	                cin.ignore(1000,'\n');
	                cout<<"Invalid quantity. Please enter a positive integer greater than 0.\n";
	            } else {
	                validQuantity=false;
	            }
	        }
	
	        bool validPrice=true;
	        while(validPrice) {
	            cout<<"Enter Price (must be > 0): ";
	            cin>>price;
	            if(cin.fail()||price<=0) {
	                cin.clear();
	                cin.ignore(1000,'\n');
	                cout<<"Invalid price. Please enter a positive number greater than 0.\n";
	            } else {
	                validPrice=false;
	            }
	        }
	
	        if(category=="Clothing") {
	            items[itemCount++]=new Clothing(id,name,quantity,price);
	        } else if(category=="Electronics") {
	            items[itemCount++]=new Electronics(id,name,quantity,price);
	        } else if(category=="Entertainment") {
	            items[itemCount++]=new Entertainment(id,name,quantity,price);
	        }
	
	        cout<<"\nItem added successfully!!!"<<endl;
	
	        cout<<"\nDo you want to add another item? (y/n): ";
	        cin>>addAnother;
	        cout<<endl;
	    }
	}

	//2) Update Itemm
	void updateItem() {
	    string id;
	    cout<<"U P D A T E  I T E M"<<endl<<endl;
	    cout<<"Enter ID to update: ";
	    cin>>id;
	    cout<<endl;
	
	    bool found=true;
	
	    for(int i=0;i<itemCount;i++) {
	        if(items[i]->getID()==id) {
	            found=false;
	            char option;
	
	            cout<<"Item found: "<<items[i]->getName()<<"\n";
	            cout<<"\nWhat would you like to update?\n";
	            cout<<"1 - Quantity\n";
	            cout<<"2 - Price\n";
	            cout<<"Enter your choice: ";
	            cin>>option;
	
	            if(option=='1') {
	                int oldQuantity=items[i]->getQuantity();
	                int newQuantity;
	
	                while(true) {
	                    cout<<"\nEnter new quantity: ";
	                    cin>>newQuantity;
	                    cout<<endl;
	
	                    if(cin.fail()||newQuantity<=0) {
	                        cin.clear();
	                        cin.ignore(1000,'\n');
	                        cout<<"Invalid quantity. Please enter a positive integer.\n";
	                    } else {
	                        items[i]->setQuantity(newQuantity);
	                        cout<<"Quantity of Item "<<items[i]->getName()<<" is updated from "<<oldQuantity<<" to "<<newQuantity<<".\n";
	                        break;
	                    }
	                }
	            } else if(option=='2') {
	                double oldPrice=items[i]->getPrice();
	                double newPrice;
	
	                while(true) {
	                    cout<<"\nEnter new price: ";
	                    cin>>newPrice;
	                    cout<<endl;
	
	                    if(cin.fail()||newPrice<=0) {
	                        cin.clear();
	                        cin.ignore(1000,'\n');
	                        cout<<"Invalid price. Please enter a positive number.\n";
	                    } else {
	                        items[i]->setPrice(newPrice);
	                        cout<<"Price of Item "<<items[i]->getName()<<" is updated from "<<oldPrice<<" to "<<newPrice<<".\n";
	                        break;
	                    }
	                }
	            } else {
	                cout<<"Invalid option selected. Please choose either 1 or 2.\n";
	            }
	
	            break;
	        }
	    }
	
	    if(found) {
	        cout<<"Item not found!\n";
	    }
	}
	//3) Remove Itemn
	void removeItem() {
	    string id;
	    cout<<"R E M O V E  I T E M\n\n";
	    cout<<"Enter ID to remove: ";
	    cin>>id;
	    cout<<endl;
	    bool found=true;
	
	    for(int i=0;i<itemCount;i++) {
	        if(items[i]->getID()==id) {
	            cout<<"Item "<<items[i]->getName()<<" has been removed from the inventory.\n";
	            delete items[i];
	            items[i]=items[itemCount-1];
	            itemCount--;
	            found=false;
	            break;
	        }
	    }
	
	    if(found) {
	        cout<<"\nItem not found!\n";
	    }
	}

    //4)displaay by category
	void displayItemsByCategory() const {
	    string category;
	    cout<<"Enter Category (Clothing, Electronics, Entertainment): ";
	    cin>>category;
	
	    for(auto &c:category) {
	        c=towlower(c);
	    }
	
	    if(category=="clothing") {
	        category="Clothing";
	    } else if(category=="electronics") {
	        category="Electronics";
	    } else if(category=="entertainment") {
	        category="Entertainment";
	    } else {
	        cout<<"Category "<<category<<" does not exist!"<<endl;
	        return;
	    }
	
	    bool found=true;
	    cout<<"\nDisplaying items in category: "<<category<<endl;
	    cout<<endl;
	
	    cout<<left<<setw(10)<<"ID"<<"| "<<left<<setw(15)<<"Name"<<"| "<<left<<setw(10)<<"Quantity"<<"| "<<left<<setw(10)<<"Price"<<"|"<<endl;
	
	    for(int i=0;i<itemCount;i++) {
	        if(items[i]->getCategory()==category) {
	            items[i]->displayItem();
	            found=false;
	        }
	    }
	
	    if(found) {
	        cout<<"\n   -----No items found in this category.-----\n";
	    }
	}
	
	//5)displayitems
	void displayAllItems() const {
	    cout<<"D I S P L A Y  A L L  I T E M S\n";
	    if(itemCount==0) {
	        cout<<"\nNo items in the inventory.\n";
	        return;
	    }
	    cout<<left<<setw(10)<<"ID"<<"| "<<left<<setw(20)<<"Name"<<"| "<<left<<setw(10)<<"Quantity"<<"| "<<left<<setw(10)<<"Price"<<"| "<<left<<setw(15)<<"Category"<<"|\n";
	    for(int i=0;i<itemCount;i++) {
	        cout<<left<<setw(10)<<items[i]->getID()<<"| "<<left<<setw(20)<<items[i]->getName()<<"| "<<left<<setw(10)<<items[i]->getQuantity()<<"| "<<left<<setw(10)<<fixed<<setprecision(2)<<items[i]->getPrice()<<"| "<<left<<setw(15)<<items[i]->getCategory()<<"|\n";
	    }
	}
	
	//6)Sort Items
	void searchItem() const {
	    string id;
	    cout<<"S E A R C H\n";
	    cout<<"\nEnter ID to search: ";
	    cin>>id;
	    bool found=false;
	
	    for(int i=0;i<itemCount;i++) {
	        if(items[i]->getID()==id) {
	            cout<<"\nItem found:\n";
	            cout<<"ID: "<<items[i]->getID()<<"\n";
	            cout<<"Name: "<<items[i]->getName()<<"\n";
	            cout<<"Quantity: "<<items[i]->getQuantity()<<"\n";
	            cout<<"Price: "<<fixed<<setprecision(2)<<items[i]->getPrice()<<"\n";
	            cout<<"Category: "<<items[i]->getCategory()<<"\n";
	            found=true;
	            break;
	        }
	    }
	
	    if(!found) {
	        cout<<"\nItem not found!\n";
	    }
	}
 	//7)sortitemss
	void sortItems() {
	    cout<<"S O R T  I T E M S\n";
	
	    if(itemCount<=1) {
	        cout<<"No items to sort.\n";
	        return;
	    }
	
	    char sort;
	    char order;
	    bool condition=true;
	
	    while(condition) {
	        cout<<"\nSort by:\n1. Price\n2. Quantity\nChoose option (1 or 2): ";
	        cin>>sort;
	        cout<<endl;
	
	        if(cin.fail()||(sort!='1'&&sort!='2')) {
	            cin.clear();
	            cin.ignore(1000,'\n');
	            cout<<"\nInvalid input! Please enter 1 or 2.\n\n";
	        } else {
	            condition=false;
	        }
	    }
	
	    condition=true;
	
	    while(condition) {
	        cout<<"Sort by:\n1. Ascending order\n2. Descending order\nChoose option (1 or 2): ";
	        cin>>order;
	        cout<<endl;
	
	        if(cin.fail()||(order!='1'&&order!='2')) {
	            cin.clear();
	            cin.ignore(1000,'\n');
	            cout<<"\nInvalid input! Please enter 1 or 2.\n\n";
	        } else {
	            condition=false;
	        }
	    }
	
	    for(int i=0;i<itemCount-1;i++) {
	        int index=i;
	
	        for(int j=i+1;j<itemCount;j++) {
	            bool condition=false;
	            if(sort=='1') {
	                if(order=='1') {
	                    condition=(items[j]->getPrice()<items[index]->getPrice());
	                } else {
	                    condition=(items[j]->getPrice()>items[index]->getPrice());
	                }
	            } else {
	                if(order=='1') {
	                    condition=(items[j]->getQuantity()<items[index]->getQuantity());
	                } else {
	                    condition=(items[j]->getQuantity()>items[index]->getQuantity());
	                }
	            }
	
	            if(condition) {
	                index=j;
	            }
	        }
	
	        if(index!=i) {
	            Item* temp=items[i];
	            items[i]=items[index];
	            items[index]=temp;
	        }
	    }
	
	    cout<<"\nItems sorted successfully!\n\n";
	    displayAllItems();
	}

	//8)display low stocks
	void displayLowStockItems() const {
	    cout<<"L O W  S T O C K S"<<endl;
		cout<<endl;
	    cout<<left<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"Quantity"<<setw(10)<<"Price"<<setw(15)<<"Category"<<endl;
	
	    bool found=true;
	    for(int i=0;i<itemCount;i++) {
	        if(items[i]->getQuantity()<=5) {
	            cout<<left<<setw(10)<<items[i]->getID()<<setw(20)<<items[i]->getName()<<setw(10)<<items[i]->getQuantity()<<setw(10)<<items[i]->getPrice()<<setw(15)<<items[i]->getCategory()<<endl;
	            found=false;
	        }
	    }
	
	    if(found) {
	        cout<<"\nNo low stock items found.\n";
	    }
	}
};

int main() {
	cout<<"--- Inventory Management System ---\n";
	cout<<endl;	
    Inventory i1;
    char choice;
    bool condition=true;

    while(condition) {
    	cout<<"M E N U\n";
        cout<<"1 - Add Item\n";
        cout<<"2 - Update Item\n";
        cout<<"3 - Remove Item\n";
        cout<<"4 - Display Items by Category\n";
        cout<<"5 - Display All Items\n";
        cout<<"6 - Search Item\n";
        cout<<"7 - Sort Items\n";
        cout<<"8 - Display Low Stock Items\n";
        cout<<"9 - Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        system("cls");

        switch(choice) {
            case '1':
                i1.addItem();
      	  		system("cls");
                break;
            case '2':
                i1.updateItem();
                system("pause");
      	  		system("cls");
                break;
            case '3':
                i1.removeItem();
                system("pause");
      	  		system("cls");
                break;
            case '4':
                i1.displayItemsByCategory();
				system("pause");
      	  		system("cls");
                break;
            case '5':
                i1.displayAllItems();
                system("pause");
      	  		system("cls");
                break;
            case '6':
                i1.searchItem();
                system("pause");
      	  		system("cls");
                break;
            case '7':
                i1.sortItems();
                system("pause");
      	  		system("cls");
                break;
            case '8':
                i1.displayLowStockItems();
                system("pause");
      	  		system("cls");
                break;
            case '9':
                cout<<"Exiting...\n";
                condition=false;
                break;
            default:
                cout<<"Invalid option! Please select again.\n";
        }
    }
}