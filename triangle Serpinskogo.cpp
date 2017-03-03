#include <SFML\Graphics.hpp>

int drawTriangle(sf::RenderWindow& window, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
	sf::Vertex line1[] =
	{
		sf::Vertex(a),
		sf::Vertex(b)
	};

	sf::Vertex line2[] =
	{
		sf::Vertex(a),
		sf::Vertex(c)
	};

	sf::Vertex line3[] =
	{
		sf::Vertex(b),
		sf::Vertex(c)
	};

	window.draw(line1, 3, sf::Lines);
	window.draw(line2, 3, sf::Lines);
	window.draw(line3, 3, sf::Lines);

	return 0;
}

int drawTriangleSerp(sf::RenderWindow& window, int nLines, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
	if (nLines <= 0)
	{
		return 0;
	}

	drawTriangle(window, a, b, c);

	sf::Vector2f mid1((a.x + b.x) / 2, (a.y + b.y) / 2);
	sf::Vector2f mid2((a.x + c.x) / 2, (a.y + c.y) / 2);
	sf::Vector2f mid3((b.x + c.x) / 2, (b.y + c.y) / 2);

	drawTriangle(window, mid1, mid2, mid3);

	drawTriangleSerp(window, nLines - 1, a   , mid1, mid2);
	drawTriangleSerp(window, nLines - 1, mid2, mid3, c   );
	drawTriangleSerp(window, nLines - 1, mid1, b   , mid3);

	return 0;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "My window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		drawTriangleSerp(window, 10, sf::Vector2f(10, 800), sf::Vector2f(1200, 800), sf::Vector2f(600, 10));

		window.display();
	}

  return 0;
}
