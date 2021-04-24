#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <Windows.h>


class Clock {
public:
	SYSTEMTIME systime;
	float mili = systime.wMilliseconds;
	float second = systime.wSecond + mili / 1000;
	float minute = systime.wMinute + second / 60;
	float hour = systime.wHour + minute / 60;
	float hourHandAngle = (hour / 12.0f) * 360.0f - 180.0f;
	float minuteHandAngle = (minute / 60.0f) * 360.0f - 180.0f;
	float secondHandAngle = (second / 60.0f) * 360.0f - 180.0f;
	int x, y;
	sf::CircleShape circle,centre;
	
	Clock() {
		GetLocalTime(&systime);
		this->x = 730;
		this->y = 680;
		centre.setRadius(25);
		centre.setOutlineColor(sf::Color::Black);
		centre.setFillColor(sf::Color::White);
		centre.setPosition(x, y);
	}
	
	sf::CircleShape create() {
		
		return circle;
	}
	
	sf::CircleShape createcentre() {

		return centre;
	}
	sf::RectangleShape hr() {
		
		sf::RectangleShape line(sf::Vector2f(10,330));
		line.setFillColor(sf::Color::Red);
		line.setPosition(750, 707);
		line.setRotation(hourHandAngle);
		return line;
	}
	sf::VertexArray Circle(sf::Vector2f bl, int n, int radY, int radX,float clocktype,sf::Color color) {
		sf::VertexArray vertices;
		vertices.setPrimitiveType(sf::LinesStrip);
		vertices.resize(n);
		float angle = clocktype/360;

		float iniPointY = bl.y;

		float iniPointX = bl.x;

		float	rX = radX;

		float	rY = radY;

	int	num = n;

	float theta = 105.26;
	
	for (int i = 0; i < num; i++) {
		
			vertices[i].position = sf::Vector2f((iniPointX + std::cos(theta) * rX), (iniPointY + std::sin(theta) * rY));
			vertices[i].color = color;
			theta += angle;
		
	}
	
	return vertices;
	}
	sf::RectangleShape min() {
		sf::RectangleShape line(sf::Vector2f(10, 400));
		line.setFillColor(sf::Color::Blue);
		line.setPosition(750, 707);
		
		line.setRotation(minuteHandAngle);
		return line;
	}
	
	sf::RectangleShape sc() {
		sf::RectangleShape line(sf::Vector2f(10, 400));
		line.setFillColor(sf::Color::Magenta);
		line.setPosition(750, 707);
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
	   window.draw(c.Circle(sf::Vector2f(750, 707), 39, 600, 600,c.hour,sf::Color::Red));
	   window.draw(c.Circle(sf::Vector2f(750, 710), 39, 550, 550, c.minute,sf::Color::Blue));
	   window.draw(c.Circle(sf::Vector2f(750, 713), 39, 500, 500, c.second,sf::Color::Magenta));
	   window.draw(c.hr());
		window.draw(c.min());
		window.draw(c.sc());
		window.draw(c.createcentre());
		window.display();
	}
}