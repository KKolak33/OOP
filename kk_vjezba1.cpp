#include <iostream>
#include<iomanip>

int main()
{
    bool flag;
    std::cout << "unesi " << true << " - " << false << std::endl;
    std::cin >> flag;
    std::cout << "boolalpha " << std::boolalpha << flag << std::endl;
    std::cout << "noboolalpha " << std::noboolalpha << flag << std::endl;


    int a = 255;
    std::cout << "hex " << std::hex << a << std::endl;
    std::cout << "dec " << std::dec << a << std::endl;
    std::cout << "oct " << std::oct << a << std::endl;

    double pi = 3.141592;
    std::cout << "pi = " << std::scientific << std::uppercase;
    std::cout << std::setprecision(7) << std::setw(20) << std::setfill('0');
    std::cout << pi << std::endl;

    std::cout << "uppercase " << std::uppercase << std::hex << a << std::endl;
    std::cout << "nouppercase " << std::nouppercase << std::hex << a << std::endl;

    float x = 12.45;
    std::cout << "fixed " << std::fixed << x << std::endl;
	std::cout << "fixed " << std::scientific << x << std::endl;

	std::cout << "left " << std::setw(6) << std::left << a << std::endl;
	std::cout << "right " << std::setw(6) << std::right << a << std::endl;

	std::cout << "ends" << std::ends << std::endl;
	std::cout << "Novi ispis" << std::ends << " \n" << std::flush;

	int b = 15;
	std::cout << "setbase " << std::setbase(16) << b << std::endl;
	std::cout << "Setflag " << std::setiosflags(std::ios::uppercase) << b << std::endl;
	std::cout << "Resetflag " << std::resetiosflags(std::ios::uppercase) << b << std::endl;

	char s[10];
	std::cin >> std::ws;
	std::cin >> s;

	std::cout << "String je " << s;

	int y;
	std::cin >> y;

	return 0;
 
}
