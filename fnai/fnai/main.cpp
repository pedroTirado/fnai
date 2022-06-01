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
	system("dir"); // prints current working dir
	
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Image ianImg;
	ianImg.loadFromFile("images/sprites/ian/ian_walking0_scaled.png");

	sf::Texture ianTxtr;
	ianTxtr.loadFromImage(ianImg);

	sf::Sprite ianSprite;
	ianSprite.setTexture(ianTxtr);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ianSprite);
		window.display();
	}

	return 0;
}