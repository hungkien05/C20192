#include <stdio.h>
typedef struct {
 	const char *description;
 	float value;
} swag;
typedef struct {
 	swag *swag;
 	const char *sequence;
} combination;
typedef struct {
 	combination numbers;
 	const char *make;
} safe;
	
int main()
{
	swag gold = {"GOLD!", 1000000.0};
	combination numbers1 = {&gold, "6502"};
	safe s = {numbers1, "RAMACON250"};
	printf("%s", s.numbers.swag->description);
}