#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");//creating window

    sf::RectangleShape windowTex1(sf::Vector2f(600.0f, 600.0f));//creating the shapeforBG
    windowTex1.setPosition(0.0f, 0.0f);//setting the BGShapePos

    sf::RectangleShape windowTex2(sf::Vector2f(600.0f, 600.0f));//creating second shapeforBG for scrolling infinite
    windowTex2.setPosition(-600.0f, 0.0f); // Position the second texture above the first one

    sf::Texture texture;//creating a texture var
    texture.loadFromFile("C:\\Users\\Umer\\Desktop\\C++\\Untitled design.png");//Loading a texture from file

    windowTex1.setTexture(&texture);//adding the texture on the shapeforBG
    windowTex2.setTexture(&texture);//adding the texture on the shapeforBG

    float scrollSpeed = 0.01f; // Adjust scrolling speed as needed

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();//clearing window before using

        // Update the position of the textures
        windowTex1.move(scrollSpeed, 0);//moving texture with move func
        windowTex2.move(scrollSpeed, 0);//same as above

        // If the first texture moves off the screen, reset its position above the second texture
        if (windowTex1.getPosition().x >= window.getSize().x)
            windowTex1.setPosition(windowTex2.getPosition().x - windowTex2.getSize().x, 0.0f);

        // If the second texture moves off the screen, reset its position above the first texture
        if (windowTex2.getPosition().x >= window.getSize().x)
            windowTex2.setPosition(windowTex1.getPosition().x - windowTex1.getSize().x,0.0f);

        window.draw(windowTex1);//drawing the shapes
        window.draw(windowTex2);// ////////
        window.display();// displaying everything
    }

    return 0;
}
