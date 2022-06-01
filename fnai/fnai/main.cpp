//#include <iostream>
//#include <string>
#include <SFML/Graphics.hpp>

//int main()
//{
//	int i;
//	std::string str;
//
//	std::cout << "Please enter an integer value: " << std::endl;
//	std::cin >> i;
//	std::cout << "The value you entered is " << i << std::endl;
//
//	//std::cout << "Press enter to close..." << std::endl;
//	//std::getline(std::cin, str);
//	//std::getline(std::cin, str);
//	return 0;
//}



int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}