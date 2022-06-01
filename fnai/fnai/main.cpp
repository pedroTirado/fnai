#include <iostream>
#include <string>
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

	std::string imgPath_ian = "images/sprites/ian/";

	sf::Image ianImgStanding;
	ianImgStanding.loadFromFile(imgPath_ian + "ian_standing_scaled.png");
	sf::Image ianImgWalking0;
	ianImgWalking0.loadFromFile(imgPath_ian + "ian_walking0_scaled.png");
	sf::Image ianImgWalking1;
	ianImgWalking1.loadFromFile(imgPath_ian + "ian_walking1_scaled.png");

	sf::Texture ianTxtr;
	ianTxtr.loadFromImage(ianImgStanding);

	sf::Sprite ianSprite;
	ianSprite.setTexture(ianTxtr);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				ianSprite.move(-5.f, 0.f);
				//ianTxtr.loadFromImage(ianImgWalking1);
				ianTxtr.update(ianImgWalking1);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				ianSprite.move(5.f, 0.f);
				//ianTxtr.loadFromImage(ianImgWalking0);
				ianTxtr.update(ianImgWalking0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				ianSprite.move(0.f, -5.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				ianSprite.move(0.f, 5.f);
			}
		}

		//ianTxtr.loadFromImage(ianImgStanding);

		window.clear();
		window.draw(ianSprite);
		window.display();
	}

	return 0;
}