#include "string"
#define u16 unsigned int
#define u32 unsigned long
#defien u8  unsigned char

class Product{
	private:{//The values you can't access from outside
		int code = 0;
		string name = "";
		double price = 0.0;
		double cost = 0.0;
		int inventory = 0;
	}
	public:{
		void SetValues(int code, string name, double price, double cost, int inventory);
		void GetValuesFromLine(String PruductInfoLine);
		void PutInfoToLine();
	}
};

void Product::SetValues(int Scode, string Sname, double Sprice, double Scost, int Sinventory){
	//Directly Set product info from values
	code= Scode;
	name= Sname;
	price= Sprice;
	cost= Scost;
	inventory= Sinventory;
	return;
}
void Product::GetValuesFromLine(String PruductInfoLine){
	//Set product info from String
	int Lcode= 0;
	string Lname= "";
	double Lprice= 0.0;
	double Lcost= 0.0;
	int Linventory= 0;
	pass---------------------------------------------//
	Product::SetValues(Lcode, Lname, Lprice, Lcost, Linventory);//put Valuse into class
}
void Product::PutInfoToLine(){
	string InfoLine;
}