#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <Windows.h>


class Clock {
public:
	int x, y;
	sf::CircleShape circle,centre;
	SYSTEMTIME systime;
	float mili = systime.wMilliseconds;
float second = systime.wSecond+mili/1000;
float minute = systime.wMinute + second / 60;
float hour = systime.wHour + minute / 60;
float hourHandAngle = (hour / 12.0f) * 360.0f - 180.0f ;
float minuteHandAngle = (minute / 60.0f) * 360.0f- 180.0f ;
float secondHandAngle = (second / 60.0f) * 360.0f -180.0f ;
	Clock() {
		GetLocalTime(&systime);
		this->x = 150;
		this->y = 200;
		circle.setRadius(120);
		circle.setOutlineThickness(5);
		circle.setPointCount(120);
		circle.setOutlineColor(sf::Color::White);
		circle.setFillColor(sf::Color::Black);
		circle.setScale(5, 5);
		circle.setPosition(x, y);
		centre.setRadius(20);
		centre.setOutlineColor(sf::Color::Black);
		centre.setFillColor(sf::Color::White);
		centre.setScale(2,2);
		centre.setPosition(710,760);
	}
	sf::CircleShape create() {
		
		return circle;
	}
	sf::CircleShape createcentre() {

		return centre;
	}
	sf::RectangleShape hr() {
		
		sf::RectangleShape line(sf::Vector2f(10,170));
		line.setFillColor(sf::Color::Red);
		line.setScale(2,2.5);
		line.setPosition(760,800);
		line.setRotation(hourHandAngle);
		return line;
	}
	sf::RectangleShape min() {
		sf::RectangleShape line(sf::Vector2f(10, 170));
		line.setFillColor(sf::Color::Blue);
		line.setScale(2, 3);
		line.setPosition(750, 800);
		
		line.setRotation(minuteHandAngle);
		return line;
	}
	
	sf::RectangleShape sc() {
		sf::RectangleShape line(sf::Vector2f(10, 170));
		line.setFillColor(sf::Color::Magenta);
		line.setScale(2, 3.5);
		line.setPosition(750, 800);
		line.setRotation(secondHandAngle);
		return line;
	}
};
int main() {
	
	
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "ClockbyNazish");
	while(window.isOpen())
	{
		Clock c;
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Request for closing the window
			if (event.type == sf::Event::Closed)
				window.close();
			break;
		}
		window.clear(sf::Color::Black);
		window.draw(c.create());
		
		window.draw(c.hr());
		window.draw(c.min());
		window.draw(c.sc());
		window.draw(c.createcentre());
		window.display();
	}
}