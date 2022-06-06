#include <iostream>
#include <string>
#include <vector>
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
	std::string imgPath_barricade = "images/";

	sf::Image ianImgStanding;
	ianImgStanding.loadFromFile(imgPath_ian + "ian_standing_scaled.png");
	sf::Image ianImgWalking0;
	ianImgWalking0.loadFromFile(imgPath_ian + "ian_walking0_scaled.png");
	sf::Image ianImgWalking1;
	ianImgWalking1.loadFromFile(imgPath_ian + "ian_walking1_scaled.png");

	sf::Image barricade0_img;
	barricade0_img.loadFromFile(imgPath_barricade + "barricade0_scaled.png");
	sf::Image barricade1_img;
	barricade1_img.loadFromFile(imgPath_barricade + "barricade1_scaled.png");
	sf::Texture barricade0_txtr;
	barricade0_txtr.loadFromImage(barricade0_img);
	sf::Texture barricade1_txtr;
	barricade1_txtr.loadFromImage(barricade1_img);

	std::vector<sf::Sprite> barricadesX(10);
	std::vector<sf::Sprite> barricadesY(10);

	float centerX = (float)window.getSize().x / 2;
	float centerY = (float)window.getSize().y / 2;
	float offsetX = 0.0;
	float offsetY = 0.0;

	for (size_t i = 0; i < barricadesX.size(); i++)
	{
		if (i % 2 == 0) {
			barricadesX.at(i).setTexture(barricade0_txtr);
			barricadesY.at(i).setTexture(barricade0_txtr);
		}
		else {
			barricadesX.at(i).setTexture(barricade1_txtr);
			barricadesY.at(i).setTexture(barricade1_txtr);
		}

		barricadesY.at(i).setPosition(centerX - 500, centerY - offsetY);

		offsetY += 100;
	}

	sf::Texture ianTxtr;
	ianTxtr.loadFromImage(ianImgStanding);

	sf::Sprite ianSprite;
	ianSprite.setTexture(ianTxtr);
	ianSprite.setPosition(sf::Vector2f((float)window.getSize().x/2, (float)window.getSize().y/2)); // absolute position

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				ianSprite.move(-10.f, 0.f);
				//ianTxtr.loadFromImage(ianImgWalking1);
				ianTxtr.update(ianImgWalking1);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				ianSprite.move(10.f, 0.f);
				//ianTxtr.loadFromImage(ianImgWalking0);
				ianTxtr.update(ianImgWalking0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				ianSprite.move(0.f, -10.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				ianSprite.move(0.f, 10.f);
			}
		}

		//ianTxtr.loadFromImage(ianImgStanding);

		window.clear();
		window.draw(ianSprite);
		for (sf::Sprite s : barricadesY) {
			window.draw(s);
		}
		window.display();
	}

	return 0;
}