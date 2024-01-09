#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

const double PI = 3.14159265358979323846;

int main()
{
    double CirclePoints = 25;
    double AngleW = 360;
    double Radius = 100; // Increase the radius to make the circle visible
    double AngleA = 0; // Initialize angle in radians
    std::vector<double> CirclePointsX;
    std::vector<double> CirclePointsY;
    int CentreX = 200;
    int CentreY = 200;

    for (int i = 0; i < CirclePoints; i++)
    {
        double CurrentX = CentreX + std::sin(AngleA) * Radius;
        double CurrentY = CentreY + std::cos(AngleA) * Radius;
        CirclePointsX.push_back(CurrentX);
        CirclePointsY.push_back(CurrentY);
        AngleA += (2 * PI) / CirclePoints; // Increment the angle in radians
    }

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    std::vector<sf::Vertex> Points;
    std::vector<sf::Vertex> Lines;

    sf::Color pointColor = sf::Color::Red;
    for (int i = 0; i < CirclePoints; i++)
    {
        Points.push_back(sf::Vertex(sf::Vector2f(CirclePointsX[i], CirclePointsY[i]),pointColor));

        // Connect points with lines
        if (i < CirclePoints - 1)
        {
            Lines.push_back(sf::Vertex(sf::Vector2f(CirclePointsX[i], CirclePointsY[i])));
            Lines.push_back(sf::Vertex(sf::Vector2f(CirclePointsX[i + 1], CirclePointsY[i + 1])));
        }
        else // Connect last point to the first point to close the loop
        {
            Lines.push_back(sf::Vertex(sf::Vector2f(CirclePointsX[i], CirclePointsY[i])));
            Lines.push_back(sf::Vertex(sf::Vector2f(CirclePointsX[0], CirclePointsY[0])));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Points.data(), Points.size(), sf::Points);
        window.draw(Lines.data(), Lines.size(), sf::Lines);

        window.display();
    }

    return 0;
} 