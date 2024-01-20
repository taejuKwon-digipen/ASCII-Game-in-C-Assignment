// Name: Taeju Kwon, Geonhwi Sim
// Assignment Name: C ASCII game
// Course Name: CS170
// Term: 2021 Spring
#include "bitwise.h"

unsigned int add(unsigned int num1, unsigned int num2)
{
	unsigned int carry_value = (num1 & num2);
	unsigned int sum_value = (num1 ^ num2);
	unsigned int shift_number = 1;

	if (carry_value == 0) {
		return sum_value;
	}
	else {
		carry_value = carry_value << shift_number;
		return add(carry_value, sum_value);
	}
}

unsigned int multiply(unsigned int num1, unsigned int num2)
{
	unsigned int total = 0;
	while (num2 != 0) {
		if ((num2 & 1) == 1) {
			total = add(total, num1);
		}
		num1 = num1 << 1;
		num2 = num2 >> 1;
	}
	return total;
}

unsigned int negate(unsigned int num)
{
	num = ~num;
	return add(num, 1);
}

unsigned int subtract(unsigned int num1, unsigned int num2)
{
	return add(num1, negate(num2));
}

unsigned int divide(unsigned int num1, unsigned int num2)
{
	unsigned int accumulator = 0;
	unsigned int one = 1;
	if (num2 == 0) {
		return 0;
	}
	while (num1 >= num2) {
		num1 = subtract(num1, num2);
		accumulator = add(accumulator, one);
	}
	return accumulator;
}

unsigned int modulus(unsigned int num1, unsigned int num2)
{
	unsigned int remainder = 0;
	if (num2 == 0) {
		return 0;
	}
	while (num1 >= num2) {
		num1 = subtract(num1, num2);
	}
	remainder = num1;
	return remainder;
}
