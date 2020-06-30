#include <stdio.h>

 struct fish {
	char name[50];
	char species[50];
	int teeth;
	int age;
};

int main()
{
	struct fish snappy={"Snappy", "Piranha", 69, 4};
	struct fish richchoi = snappy;
	snappy.name[0]='K';
	printf("Name = %s, teeth = %d",snappy.name, richchoi.teeth);
	system("cls");
	printf("\n %d",richchoi.teeth);
	return 0;
}
