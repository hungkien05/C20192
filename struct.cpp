#include <iostream>
#include <string>
using namespace std;

 struct fish {
	string name;
	string species;
	int teeth;
	int age;
};

int main()
{
	struct fish snappy={"Snappy", "Piranha", 69, 4};
	cout << "Name = " << snappy.name << endl << "Teeth = "<< snappy.teeth << endl;
	return 0;
}
	
