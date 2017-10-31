/*
Example program to demonstrate how buffer overflow attacks can work.
Based on a standard C-style stack buffer overflow. 
*/
#include <iostream>

void main(void)
{
	char pwbuffer[9];	
	bool passcheck = false;
	
	std::cout << " Address of pwbuffer:\t " << (void *)pwbuffer << "\n";
	std::cout << " Address of password:\t " << (void *)passcheck << "\n";
	std::cout << " &passcheck - &pwbuffer = " << (int)&passcheck - (int)pwbuffer << "\n";
	std::cout << "\n-------------------------------------------------------------------\n";

	std::cout << "Please enter your password: ";

	//try entering a password 1 character longer than the number printed out for &passcheck - &pwbuffer
	std::cin >> pwbuffer;
	
	std::cout << "\n";

	if (strncmp(pwbuffer, "password", 8)) //look how good we are, we even use strncmp!
	{
		std::cout << "Incorrect password entered. No access granted!\n";
	}
	else
	{
		std::cout << "Correct password entered.\n";
		passcheck = true;
	}

	if (passcheck)
	{
		//Now our program would allow us to do stuff...
		std::cout <<  "_-=|Welcome to the inner sanctum, superuser!|=-_ \n";
	}

	system("pause");
}