#include <SFML/Graphics.hpp>
#include <iostream>

void TextDef(sf::Text &text, sf::Font &font, float x, float y,std::string valuestring,int txtSize){
    text.setFont(font);
    text.setString(valuestring);
    text.setCharacterSize(txtSize);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(x,y);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");//creating window

    sf::RectangleShape windowTex1(sf::Vector2f(600.0f, 600.0f));//creating the shapeforBG
    windowTex1.setPosition(0.0f, 0.0f);//setting the BGShapePos

    sf::RectangleShape windowTex2(sf::Vector2f(600.0f, 600.0f));//creating second shapeforBG for scrolling infinite
    windowTex2.setPosition(-600.0f, 0.0f); // Position the second texture above the first one

    sf::RectangleShape playBTN(sf::Vector2f(100.0f,30.0f));
    playBTN.setPosition(240.0f,250.0f);
    sf::RectangleShape settingBTN(sf::Vector2f(190.0f,30.0f));
    settingBTN.setPosition(200.0f,300.0f);
    sf::RectangleShape exitBTN(sf::Vector2f(100.0f,30.0f));
    exitBTN.setPosition(240.0f,350.0f);
    bool exitbtnhover = false;


    sf::Texture texture;//creating a texture var
    texture.loadFromFile("C:\\Users\\Umer\\Desktop\\C++\\Untitled design.png");//Loading a texture from file

    sf::Font font;
    if (!font.loadFromFile("G:\\abdullah\\Abdullah(Dont Delete Any thing)\\FONTS\\Rubik_Mono_One\\RMOR.ttf"))
    {
        std::cout << "Cant load/find the file" << '\n';
    }

    windowTex1.setTexture(&texture);//adding the texture on the shapeforBG
    windowTex2.setTexture(&texture);//adding the texture on the shapeforBG
    sf::Text title;
    sf::Text playbtntxt;
    sf::Text settingbtntxt;
    sf::Text exitbtntxt;
    TextDef(title,font,200.0f,50.0f,"GAME",50);
    TextDef(playbtntxt,font,243.0f,250.0f,"PLAY",25);
    TextDef(settingbtntxt,font,205.0f,300.0f,"SETTINGS",25);
    TextDef(exitbtntxt,font,243.0f,350.0f,"EXIT",25);

    float scrollSpeed = 0.01f; // Adjust scrolling speed as needed

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(exitbtnhover == true){
                    window.close();
                }
                else{
                    std::cout << "sry cant go now\n";
                }
            }
        }

        window.clear();//clearing window before using

        // Update the position of the textures
        windowTex1.move(scrollSpeed, 0);//moving texture with move func
        windowTex2.move(scrollSpeed, 0);//same as above

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // If the first texture moves off the screen, reset its position above the second texture
        if (windowTex1.getPosition().x >= window.getSize().x)
            windowTex1.setPosition(windowTex2.getPosition().x - windowTex2.getSize().x, 0.0f);

        // If the second texture moves off the screen, reset its position above the first texture
        if (windowTex2.getPosition().x >= window.getSize().x)
            windowTex2.setPosition(windowTex1.getPosition().x - windowTex1.getSize().x,0.0f);

        if (mousePos.x >= playBTN.getPosition().x && mousePos.x <= playBTN.getPosition().x + playBTN.getSize().x &&
            mousePos.y >= playBTN.getPosition().y && mousePos.y <= playBTN.getPosition().y + playBTN.getSize().y)
        {
            playBTN.setFillColor(sf::Color::Green);
        }
        else if(mousePos.x >= settingBTN.getPosition().x && mousePos.x <= settingBTN.getPosition().x + settingBTN.getSize().x &&
            mousePos.y >= settingBTN.getPosition().y && mousePos.y <= settingBTN.getPosition().y + settingBTN.getSize().y)
        {
            settingBTN.setFillColor(sf::Color::Green);
        }
        else if(mousePos.x >= exitBTN.getPosition().x && mousePos.x <= exitBTN.getPosition().x + exitBTN.getSize().x &&
            mousePos.y >= exitBTN.getPosition().y && mousePos.y <= exitBTN.getPosition().y + exitBTN.getSize().y)
        {
            exitBTN.setFillColor(sf::Color::Green);
            exitbtnhover = true;
        }
        else{
            playBTN.setFillColor(sf::Color::White);
            settingBTN.setFillColor(sf::Color::White);
            exitBTN.setFillColor(sf::Color::White);
            exitbtnhover = false;
        }

        window.draw(windowTex1);//drawing the shapes
        window.draw(windowTex2);// ////////
        window.draw(playBTN);
        window.draw(settingBTN);
        window.draw(exitBTN);
        //text title
        window.draw(title);
        window.draw(playbtntxt);
        window.draw(settingbtntxt);
        window.draw(exitbtntxt);
        window.display();// displaying everything
    }

    return 0;
}
