#include <iostream>
#include <vector>
#include "global.h"
#include "product.h"
#include "productmanager.h"

#include <string>
using namespace std;
int global;
vector<Product> products;
ProductManager mgr; 

void acceptProducts(){
	for (int i = 1; i <=3 ; i++) 
    {
    	 cout<<"\n Enter flower Title  :";
    	 string title;
    	 getline(cin>>ws, title);
		 Product p(i, title);
		 mgr.Insert(p);
	}
}

void showProducts(){
 	cout << "\nMy Flowers Collection "; 
	vector<Product> allProducts=mgr.GetAll();
    for (auto i = allProducts.begin(); i != allProducts.end(); ++i) 
        cout <<"\n"<< (*i).GetId()<< " "<<(*i).GetTitle(); 	
    cout<< "\n _____________________________________\n";
}

void findProducts(int id){
	cout << "\nMy Flowers Collection "; 
	Product temp=mgr.GetById(id);
   // for (auto i = oneProducts.begin(); i != oneProducts.end(); ++i) 
      //<< " "<<(*i).GetTitle(); 	
    cout << "\n" << temp;
    cout<< "\n _____________________________________\n";
}


int main(int argc, char** argv) {
	int option=1;
	int id;
	while(option != 7){
		cout<< "Choose Option:\n";
		cout<< "1. Show All Products:\n";
		cout<< "2. Find Product:\n";
		cout<< "3. Insert Product:\n";
		cout<< "4. Update existing Product:\n";
		cout<< "5. Delete an existing product:\n";
		cout<< "6. Delete all available products:\n";
		cout<< "7. Exit:\n";
		
		cin>>option;
		switch(option){
			case 1:
				  showProducts();
			break;
			case 2:
					cout << "Enter product id to find: ";
					cin >> id;
					findProducts(id);
				  //find product
				break;
			case 3:
					acceptProducts();
			break;
			case 4:
				  //Update product
			break;
			case 5:
			{
				bool status=mgr.Delete(2);
			}	
			break;
			case 6:{
				bool status=mgr.DeleteAll();
			}
			break;
			case 7:{
				exit(0);
				break;
			}
		}				
	}
	
	
		acceptProducts();
		showProducts();
	return 0;
	}
