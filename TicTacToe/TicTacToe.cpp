#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

void TextDef(sf::Text &text, sf::Font &font, float x, float y,std::string valuestring,int txtSize,bool isBold){
    text.setFont(font);
    text.setString(valuestring);
    text.setCharacterSize(txtSize);
    text.setFillColor(sf::Color::Black);
    if (isBold) {
        text.setStyle(sf::Text::Bold);
    } else {
        text.setStyle(sf::Text::Regular);
    }
    text.setPosition(x,y);
}
void Hover(sf::Vector2i &mousePos, sf::RectangleShape &HoverShape, bool &shapeHover) {
    if (mousePos.x >= HoverShape.getPosition().x && mousePos.x <= HoverShape.getPosition().x + HoverShape.getSize().x && mousePos.y >= HoverShape.getPosition().y && mousePos.y <= HoverShape.getPosition().y + HoverShape.getSize().y) {
        HoverShape.setFillColor(sf::Color::Green);
        shapeHover = true;
    } else {
        HoverShape.setFillColor(sf::Color(20,200,36));
        shapeHover = false;
    }
}
bool CheckWinner(sf::RectangleShape Cube1TX, sf::RectangleShape Cube2TX, sf::RectangleShape Cube3TX,
                 sf::RectangleShape Cube4TX, sf::RectangleShape Cube5TX, sf::RectangleShape Cube6TX,
                 sf::RectangleShape Cube7TX, sf::RectangleShape Cube8TX, sf::RectangleShape Cube9TX,
                 sf::Texture &CurrentTX, sf::Texture &PlayerTx,sf::Texture &ComputerTx,bool &WinnerDecided) {
    // Check for a winning condition and return true if found
    if ((Cube1TX.getTexture() == &CurrentTX && Cube2TX.getTexture() == &CurrentTX && Cube3TX.getTexture() == &CurrentTX) ||
        (Cube4TX.getTexture() == &CurrentTX && Cube5TX.getTexture() == &CurrentTX && Cube6TX.getTexture() == &CurrentTX) ||
        (Cube7TX.getTexture() == &CurrentTX && Cube8TX.getTexture() == &CurrentTX && Cube9TX.getTexture() == &CurrentTX) ||
        (Cube1TX.getTexture() == &CurrentTX && Cube4TX.getTexture() == &CurrentTX && Cube7TX.getTexture() == &CurrentTX) ||
        (Cube2TX.getTexture() == &CurrentTX && Cube5TX.getTexture() == &CurrentTX && Cube8TX.getTexture() == &CurrentTX) ||
        (Cube3TX.getTexture() == &CurrentTX && Cube6TX.getTexture() == &CurrentTX && Cube9TX.getTexture() == &CurrentTX) ||
        (Cube1TX.getTexture() == &CurrentTX && Cube5TX.getTexture() == &CurrentTX && Cube9TX.getTexture() == &CurrentTX) ||
        (Cube3TX.getTexture() == &CurrentTX && Cube5TX.getTexture() == &CurrentTX && Cube7TX.getTexture() == &CurrentTX)) {
        
        if (&CurrentTX == &PlayerTx) {
            std::cout << "Player wins!" << std::endl;
            WinnerDecided = true;
        } else if (&CurrentTX == &ComputerTx) {
            std::cout << "Computer wins!" << std::endl;
            WinnerDecided = true;
        }

        // You might want to handle the game state here, such as displaying a message or ending the game.
        return true;
    }

    bool allCubesFilled = Cube1TX.getTexture() && Cube2TX.getTexture() && Cube3TX.getTexture() &&
                          Cube4TX.getTexture() && Cube5TX.getTexture() && Cube6TX.getTexture() &&
                          Cube7TX.getTexture() && Cube8TX.getTexture() && Cube9TX.getTexture();

    if (allCubesFilled) {
        std::cout << "It's a tie!" << std::endl;
        WinnerDecided = true;

        // You might want to handle the game state here, such as displaying a message or ending the game.
        return true;
    }

    // No winner found
    return false;
}
int main()
{   
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(600, 600), "TicTacToe!");//creating window

    sf::RectangleShape windowTex1(sf::Vector2f(600.0f, 600.0f));//creating the shapeforBG
    windowTex1.setPosition(0.0f, 0.0f);//setting the BGShapePos

    sf::RectangleShape windowTex2(sf::Vector2f(600.0f, 600.0f));//creating second shapeforBG for scrolling infinite
    windowTex2.setPosition(-600.0f, 0.0f); // Position the second texture above the first one
    //Cube grid
    sf::RectangleShape Cube1(sf::Vector2(50.0f,50.0f));
    Cube1.setPosition(215.0f,210.0f);
    sf::RectangleShape Cube2(sf::Vector2(50.0f,50.0f));
    Cube2.setPosition(275.0f,210.0f);
    sf::RectangleShape Cube3(sf::Vector2(50.0f,50.0f));
    Cube3.setPosition(335.0f,210.0f);
    sf::RectangleShape Cube4(sf::Vector2(50.0f,50.0f));
    Cube4.setPosition(215.0f,270.0f);
    sf::RectangleShape Cube5(sf::Vector2(50.0f,50.0f));
    Cube5.setPosition(275.0f,270.0f);
    sf::RectangleShape Cube6(sf::Vector2(50.0f,50.0f));
    Cube6.setPosition(335.0f,270.0f);
    sf::RectangleShape Cube7(sf::Vector2(50.0f,50.0f));
    Cube7.setPosition(215.0f,330.0f);
    sf::RectangleShape Cube8(sf::Vector2(50.0f,50.0f));
    Cube8.setPosition(275.0f,330.0f);
    sf::RectangleShape Cube9(sf::Vector2(50.0f,50.0f));
    Cube9.setPosition(335.0f,330.0f);
    sf::RectangleShape playBTN(sf::Vector2f(100.0f,30.0f));
    playBTN.setPosition(240.0f,250.0f);
    sf::RectangleShape settingBTN(sf::Vector2f(190.0f,30.0f));
    settingBTN.setPosition(195.0f,300.0f);
    sf::RectangleShape exitBTN(sf::Vector2f(100.0f,30.0f));
    exitBTN.setPosition(240.0f,350.0f);
    bool PlayerTurn = true;
    bool ComputerTurn = false;
    bool exitbtnhover = false;
    bool playbtnhover = false;
    bool settingbtnhover = false;
    bool inGame = false;
    bool inSettings = false;
    bool inMenu = true;
    bool Cube1hover = false;
    bool Cube1Clicked = false;
    bool Cube2hover = false;
    bool Cube2Clicked = false;
    bool Cube3hover = false;
    bool Cube3Clicked = false;
    bool Cube4hover = false;
    bool Cube4Clicked = false;
    bool Cube5hover = false;
    bool Cube5Clicked = false;
    bool Cube6hover = false;
    bool Cube6Clicked = false;
    bool Cube7hover = false;
    bool Cube7Clicked = false;
    bool Cube8hover = false;
    bool Cube8Clicked = false;
    bool Cube9hover = false;
    bool Cube9Clicked = false;
    bool WinnerDecided = false;


    sf::Texture texture;//creating a texture var
    texture.loadFromFile("C:\\Users\\Umer\\Desktop\\C++\\Untitled design.png");//Loading a texture from file
    sf::Texture XTexture;
    XTexture.loadFromFile("G:\\abdullah\\Abdullah(Dont Delete Any thing)\\Textures\\X.png");
    sf::Texture OTexture;
    OTexture.loadFromFile("G:\\abdullah\\Abdullah(Dont Delete Any thing)\\Textures\\O.png");

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
    TextDef(title,font,100.0f,50.0f,"TicTacToe",50,true);
    TextDef(playbtntxt,font,246.0f,250.0f,"PLAY",25,false);
    TextDef(settingbtntxt,font,204.0f,300.0f,"SETTINGS",25,false);
    TextDef(exitbtntxt,font,246.0f,350.0f,"EXIT",25,false);

    float scrollSpeed = 0.01f; // Adjust scrolling speed as needed

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {   
                if(exitbtnhover == true){
                    if (inMenu == true)
                    {
                        window.close();
                    }
                }else if (playbtnhover == true)
                {   
                    if (!inGame)
                    {
                        std::cout << "Game starting" << '\n';
                        inGame = true;
                        inSettings = false;
                        inMenu = false;
                    }
                    
                }else if (settingbtnhover == true)
                {   
                    if (!inSettings && !inGame)
                    {
                        std::cout << "In to Settings" << '\n';
                        inGame = false;
                        inSettings = true;
                        inMenu = false;
                    }
                    
                }else if (Cube1hover == true && PlayerTurn == true && Cube1Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube1" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube1.setTexture(&XTexture);
                    ComputerTurn = true;
                    PlayerTurn = false;
                    Cube1Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                }else if (Cube2hover == true && PlayerTurn == true && Cube2Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube2" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube2.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube2Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube3hover == true && PlayerTurn == true && Cube3Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube3" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube3.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube3Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube4hover == true && PlayerTurn == true && Cube4Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube4" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube4.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube4Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube5hover == true && PlayerTurn == true && Cube5Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube5" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube5.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube5Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube6hover == true && PlayerTurn == true && Cube6Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube6" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube6.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube6Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube7hover == true && PlayerTurn == true && Cube7Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube7" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube7.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube7Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube8hover == true && PlayerTurn == true && Cube8Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube8" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube8.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube8Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }else if (Cube9hover == true && PlayerTurn == true && Cube9Clicked == false && WinnerDecided == false && ComputerTurn == false)
                {
                    std::cout << "Cube9" << '\n';
                    std::cout << "ComputerTurn" << '\n';
                    Cube9.setTexture(&XTexture);
                    PlayerTurn = false;
                    Cube9Clicked = true;
                    CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,XTexture,XTexture,OTexture,WinnerDecided);
                    ComputerTurn = true;
                }               
                else{
                    std::cout << "sry cant go now\n";
                }
            }
            if (ComputerTurn == true && PlayerTurn == false && WinnerDecided == false)
                {
                    int CChoice = (rand() % 9) + 1;
                    switch (CChoice)
                    {
                        case 1:
                            if(Cube1Clicked==false){
                                Cube1.setTexture(&OTexture);
                                PlayerTurn = true;
                                ComputerTurn = false;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                Cube1Clicked = true;
                                std::cout << "CUBE1COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                                break;
                            }
                            break;
                        case 2:
                            if(Cube2Clicked==false){
                                Cube2.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube2Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE2COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 3:
                            if(Cube3Clicked==false){
                                Cube3.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube3Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE3COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 4:
                            if(Cube4Clicked==false){
                                Cube4.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube4Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE4COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 5:
                            if(Cube5Clicked==false){
                                Cube5.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube5Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE5COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 6:
                            if(Cube6Clicked==false){
                                Cube6.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube6Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE6COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 7:
                            if(Cube7Clicked==false){
                                Cube7.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube7Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE7COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 8:
                            if(Cube8Clicked==false){
                                Cube8.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube8Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE8COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        case 9:
                            if(Cube9Clicked==false){
                                Cube9.setTexture(&OTexture);
                                PlayerTurn = true;
                                Cube9Clicked = true;
                                CheckWinner(Cube1,Cube2,Cube3,Cube4,Cube5,Cube6,Cube7,Cube8,Cube9,OTexture,XTexture,OTexture,WinnerDecided);
                                ComputerTurn = false;
                                std::cout << "CUBE9COMPUTER" << '\n';
                                std::cout << "playerTurn" << '\n';
                            }
                            break;
                        default:
                            std::cout << "Cant choose already chosen" << '\n';
                            break;
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
            playBTN.setFillColor(sf::Color(227,244,36));
            playbtnhover = true;
        }
        else if(mousePos.x >= settingBTN.getPosition().x && mousePos.x <= settingBTN.getPosition().x + settingBTN.getSize().x &&
            mousePos.y >= settingBTN.getPosition().y && mousePos.y <= settingBTN.getPosition().y + settingBTN.getSize().y)
        {
            settingBTN.setFillColor(sf::Color(227,244,36));
            settingbtnhover = true;
        }
        else if(mousePos.x >= exitBTN.getPosition().x && mousePos.x <= exitBTN.getPosition().x + exitBTN.getSize().x &&
            mousePos.y >= exitBTN.getPosition().y && mousePos.y <= exitBTN.getPosition().y + exitBTN.getSize().y)
        {
            exitBTN.setFillColor(sf::Color(227,244,36));
            exitbtnhover = true;
        }
        else{
            playBTN.setFillColor(sf::Color(255,255,255,.8));
            settingBTN.setFillColor(sf::Color(255,255,255,.8));
            exitBTN.setFillColor(sf::Color(255,255,255,.8));
            exitbtnhover = false;
            playbtnhover = false;
            settingbtnhover = false;
        }
        Hover(mousePos,Cube1,Cube1hover);
        Hover(mousePos,Cube2,Cube2hover);
        Hover(mousePos,Cube3,Cube3hover);
        Hover(mousePos,Cube4,Cube4hover);
        Hover(mousePos,Cube5,Cube5hover);
        Hover(mousePos,Cube6,Cube6hover);
        Hover(mousePos,Cube7,Cube7hover);
        Hover(mousePos,Cube8,Cube8hover);
        Hover(mousePos,Cube9,Cube9hover);
        window.draw(windowTex1);//drawing the shapes
        window.draw(windowTex2);// ////////
        if (inMenu == true)
        {      
            window.draw(playBTN);
            window.draw(settingBTN);
            window.draw(exitBTN);
            window.draw(title);
            window.draw(playbtntxt);
            window.draw(settingbtntxt);
            window.draw(exitbtntxt);  
        }else if (inGame == true)
        {
            window.draw(Cube1);
            window.draw(Cube2);
            window.draw(Cube3);
            window.draw(Cube4);
            window.draw(Cube5);
            window.draw(Cube6);
            window.draw(Cube7);
            window.draw(Cube8);
            window.draw(Cube9);
            
        }else if (inSettings == true)
        {
            window.draw(settingBTN);
        }
        
        
        
        window.display();// displaying everything
    }

    return 0;
}
