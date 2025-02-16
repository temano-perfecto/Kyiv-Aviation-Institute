#include <iostream>

int main()
{
	int A = 18 + 5;
	int invertA = ~23;

	int B = 139, C = 70;
	int orBC = B | C;

	int D = 94;
	int E = 127;
	int andDE = D & E;
	
	int F = 39;
	int G = 83;
	int xorFG = F ^ G;
	
	int H = 912;
	int leftshift  = 912<<6;

	int J = -90;
	int rightshift = -90 >> 6;
	return 0;
}