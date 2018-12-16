//MTS3013

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//function prototype
int mainmenu();
void transaction();
void customer();
void vendor();
void product();

//Transactions
void buy();
void sell();
void delete_data();

//customers
void cus_Add();
void cus_Display();
void cus_Edit();

//vendors
void ven_Add();
void ven_Display();
void ven_Edit();

//products
void product_Add();
void product_Display();	//inventory value
void product_Edit();

int main()
{
	mainmenu();
	
	return 0;
}//end of main function

int mainmenu()
{
	//declare constant and variable
	int choice = 0;
	
	//Main menu select
	cout << endl;
	cout << "Please select: " << endl;
	cout << "[1] Transaction " << endl;
	cout << "[2] Customer " << endl;
	cout << "[3] Vendor " << endl;
	cout << "[4] Product " << endl;
	cin >> choice;
	
	//main menu
	if (choice == 1)
		transaction();
	else if (choice == 2)
		customer;
	else if (choice == 3)
		vendor;
	else if (choice == 4)
		product();
	else
		cout << "Please enter a valid number." << endl;
	//end if
}//end of main menu function

//**************transaction*********************************************

void transaction()
{
	//declare constant and variable
	int choice = 0;
	
	cout << endl;
	cout << "Please select: " << endl;
	cout << "[1] Buy Product" << endl;
	cout << "[2] Sell Product" << endl;
	cout << "[3] Back" << endl;
	cin >> choice;
	
	//transaction menu
	if (choice == 1)
		buy();
	else if (choice == 2)
		sell;
	else if (choice == 3)
		mainmenu();
	//end if	
}//end of transaction function

void buy()
{
	//declare constant and variable
	string product_name = "";
	int product_code = 0;
	int product_no = 0;
	double product_price = 0.0;
	double product_cost = 0.0;
	int inventory_value = 0;
	int quantity = 0;
	double subtotal = 0;
	double discount = 0.0;
	double total = 0.0;
	char choice = ' ';
	ifstream inProductFile;
	ofstream outProductFile;

	//open file
	inProductFile.open("Product.txt", ios::in);
	
	//determine whether file is opened
	if (inProductFile.is_open())
	{
		//display list of product
		
		inProductFile >> product_no;
		inProductFile.ignore();
		getline(inProductFile, product_name, '#');
		inProductFile >> product_price;
		inProductFile.ignore();
		inProductFile >> product_cost;
		inProductFile.ignore();
		inProductFile >> inventory_value;
		inProductFile.ignore();
		
		cout << "Product Code \t \t Product Name \t \t Price \t \tInventory Value" << endl;
		
		while(!inProductFile.eof())
		{
			cout << product_no << "\t \t \t " << product_name << "\t \t \t RM";
			cout << fixed << setprecision(2) << product_price <<  "\t \t";
			cout << inventory_value << endl;
			
			inProductFile >> product_no;
			inProductFile.ignore();
			getline(inProductFile, product_name, '#');
			inProductFile >> product_price;
			inProductFile.ignore();
			inProductFile >> product_cost;
			inProductFile.ignore();
			inProductFile >> inventory_value;
			inProductFile.ignore();
		
		}//end while
		
		inProductFile.close();
	}
	else 
		cout << "Product.txt could not be opened" << endl;
	//end if 
	
	//Select product
	cout << "Please enter Product code: ";
	cin >> product_code;
	
	//open file
	inProductFile.open("Product.txt", ios::app);
	
	//determine whether file is opened
	if (inProductFile.is_open())
	{
		
		//display list of product 
		
		inProductFile >> product_no;
		inProductFile.ignore();
		getline(inProductFile, product_name, '#');
		inProductFile >> product_price;
		inProductFile.ignore();
		inProductFile >> product_cost;
		inProductFile.ignore();
		inProductFile >> inventory_value;
		inProductFile.ignore();
		
		while (product_code != product_no)
		{
			inProductFile >> product_no;
			inProductFile.ignore();
			getline(inProductFile, product_name, '#');
			inProductFile >> product_price;
			inProductFile.ignore();
			inProductFile >> product_cost;
			inProductFile.ignore();
			inProductFile >> inventory_value;
			inProductFile.ignore();
		}//end while
		inProductFile.close();
	}
	else 
		cout << "Product.txt could not be opened" << endl;
	//end if 
	
	cout << "Enter quantity of product: ";
	cin >> quantity;
	
	subtotal = product_price * static_cast<double>(quantity);
	inventory_value -= quantity;
	
	//rewrite new product
	//open file for append
	outProductFile.open("Product.txt", ios::app);
	
	//determine whether file is opened
	if (outProductFile.is_open())
	{
		outProductFile << product_no << "#" <<  product_name << "#" << product_price << "#" << product_cost << "#" << inventory_value << endl;
		outProductFile.close();
	}
	else
		cout << "Product.txt file could not be opened" << endl;
	//end if

	//display receipt
	cout << endl;
	cout << "Product Code: " << product_no << endl;
	cout << "Product Name: " << product_name << endl;
	cout << "Product Price: RM" << product_price << endl;
	cout << "Subtotal: RM" << subtotal << endl;
	
	cout << endl;
	cout << "Next transaction? [Y/N] ";
	cin >> choice;
	choice = toupper(choice);
	
	if (choice == 'Y')
		mainmenu();
	//end if
}//end of buy function

void sell()
{
	//declare constant and variable
	int product_no = 0;
	string product_name = "";
	double product_price = 0.0;
	double product_cost = 0.0;
	int quantity = 0;
	int inventory_value = 0;
	double discount = 0.0;
	double subtotal = 0.0;
	double total = 0.0;
	ifstream inProductFile;
	
	//open file to read
	inProductFile.open("Product.txt", ios::in);
	
	//determine whether file is opened
	if (inProductFile.is_open())
	{
		inProductFile >> product_no;
		inProductFile.ignore();
		getline(inProductFile, product_name, '#');
		inProductFile >> product_price;
		inProductFile.ignore();
		inProductFile >> product_cost;
		inProductFile.ignore();
		inProductFile >> inventory_value;
		inProductFile.ignore();
		
		cout << "Product Code \t \t Product Name \t \t Product Cost \t \tInventory Value" << endl;
		
	//	if(!inProductFile)
	}

}

//*****************product****************************************************************

void product()
{
	//declare constant and variable
	int choice = 0;
	
	cout << endl;
	cout << "Please select: " << endl;
	cout << "[1] Add Product " << endl;
	cout << "[2] Display Product " << endl;
	cout << "[3] Edit Product " << endl;
	cout << "[4] Back" << endl;
	cin >> choice;
	
	if (choice == 1)
		product_Add();
	else if (choice == 2)
		product_Display();
	else if (choice == 3)
		product_Edit;
	else if (choice == 4)
		mainmenu();
	else
		cout << "Invalid!!" << endl;
	//end if
}//end of product function

void product_Add()
{
	//declare constant and variable
	string product_name = "";
	double product_price = 0.0;
	double product_cost = 0.0;
	int product_code = 0;
	static int no_product = 0;	//auto generate code
	static int inventory_value = 0;
	ofstream outProductFile;
	char choice = ' ';
	
	//open file for append
	outProductFile.open("Product.txt", ios::app);
	
	//determine whether file is opened
	if (outProductFile.is_open())
	{
		cout << "Enter product name (X to stop): ";
		cin >> product_name;
		while(product_name != "x" && product_name != "X")
		{
			cout << "Enter product price: ";
			cin >> product_price;
			cin.ignore(100, '\n');
			cout << "Enter product cost: ";
			cin >> product_cost;
			cin.ignore(100, '\n');
			cout << "Enter inventory value: ";
			cin >> inventory_value;
			cin.ignore(100, '\n');
			no_product +=1;
			
			outProductFile << no_product << "#" <<  product_name << "#" << product_price << "#" << product_cost << "#" << inventory_value << endl;
			
			cout << "Enter product name (X to stop): ";
			getline(cin, product_name);
		}//end while
		outProductFile.close();
	}
	else
		cout << "Product.txt file could not be opened" << endl;
	//end if

	cout << endl;
	cout << "Next transaction? [Y/N] ";
	cin >> choice;
	choice = toupper(choice);
	
	if (choice == 'Y')
		mainmenu();
	//end if	
}//end of product_Add file

void product_Display()
{
	//declare constant and variable
	string product_name = "";
	double product_price = 0.0;
	double product_cost = 0.0;
	int product_no = 0;
	int inventory_value = 0;
	ifstream inProductFile;
	char choice = ' ';
	
	//open file to read
	inProductFile.open("Product.txt", ios::in);
	
	//determine whether file is opened
	if (inProductFile.is_open())
	{
		inProductFile >> product_no;
		inProductFile.ignore();
		getline(inProductFile, product_name, '#');
		inProductFile >> product_price;
		inProductFile.ignore();
		inProductFile >> product_cost;
		inProductFile.ignore();
		inProductFile >> inventory_value;
		inProductFile.ignore();
		
		cout << "***************************************************************************" << endl;
		cout << "Product Code \t \t Product Name \t \t Selling Price \tProduct Cost \t Inventory Value" << endl;
		
		while (!inProductFile.eof())
		{	
			cout << product_no << "\t \t \t " << product_name << "\t \t \t RM";
			cout << fixed << setprecision(2) << product_price <<  "\t \t" << product_cost << "\t \t";
			cout << inventory_value << endl;
		
			inProductFile >> product_no;
			inProductFile.ignore();	
			getline(inProductFile, product_name, '#');
			inProductFile >> product_price;
			inProductFile.ignore();
			inProductFile >> product_cost;
			inProductFile.ignore();
			inProductFile >> inventory_value;
			inProductFile.ignore();
		
		}//end while
		
		inProductFile.close();
		cout << "***************************************************************************" << endl;
	}
	else 
		cout << "Product.txt could not be opened" << endl;
	//end if 
	
	cout << endl;
	cout << "Next transaction? [Y/N] ";
	cin >> choice;
	choice = toupper(choice);
	
	if (choice == 'Y')
		mainmenu();
	//end if	
}//end of display product function


