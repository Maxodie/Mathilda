#include <stdio.h>
#include <stdlib.h>

#include "ILDA_vector.h"

int main(void)
{
	printf("Hello Mathilda !");

	ILDA_vector2 vector2Test = { .x = 1.0, .y = 2.0 };
	ILDA_vector2 vector22 = {.x = 10.0, .y = 20.0};

	printf("first vector2 double x : %f, y : %f", vector2Test.x, vector2Test.y);

	ILDA_vector2_add(&vector2Test, &vector22);

	printf("\nsecond vector2 double x : %f, y : %f", vector2Test.x, vector2Test.y);



	printf("\n\ntest but with float nerd guys");


	ILDA_vector2_float vector2Testk = { .x = 1.0f, .y = 2.0f };
	ILDA_vector2_float vector22k = { .x = 10.0f, .y = 20.0f };

	printf("\nfirst vector2 double x : %f, y : %f", vector2Testk.x, vector2Testk.y);

	ILDA_vector2_float_add(&vector2Testk, &vector22k);

	printf("\nsecond vector2 double x : %f, y : %f\n", vector2Testk.x, vector2Testk.y);
}
