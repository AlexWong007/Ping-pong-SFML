#include <SFML/Graphics.hpp>
#include <iostream>

// void menu()
// {
//     sf::RenderWindow window(sf::VideoMode(1200, 800), "Ping Pong by Alex Wong");
//     sf::Font font;
//     sf::Text title;
//     sf::Text desc;

//     if(!font.loadFromFile("ARCADE_I.TTF"))
//     {
//         std:: cout << "Unable to load font." << std:: endl;
//     }
//     title.setFont(font);
//     title.setFillColor(sf::Color::White);
//     title.setString("Ping Pong");
//     title.setPosition(465, 20);

//     desc.setFont(font);
//     desc.setFillColor(sf::Color::White);
//     desc.setString("Left click to start...");
//     desc.setPosition(300, 700);

//     while (window.isOpen())
//     {
//         sf::Event event;

//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }
        
//         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//         {
//             //game();
//         }

//         window.clear(sf::Color::Black);
//         window.draw(title);
//         window.draw(desc);
//         window.display();
//     }
// } 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Ping Pong by Alex Wong");
    sf::Font font;
    sf::Text title;
    sf::RectangleShape rectangle1;
    sf::RectangleShape rectangle2;
    sf::Keyboard keyboard;
    sf::CircleShape ball(15);
    sf::RectangleShape middleline(sf::Vector2f(10, 50));
    sf::Text score1;
    sf::Text score2;

    ball.setPosition(sf::Vector2f(600.f, 400.f));
    float xballVelocity = 0.1f;
    float yballVelocity = 0.1f;

    if(!font.loadFromFile("ARCADE_I.TTF"))
    {
        std:: cout << "Unable to load font." << std:: endl;
    }

    int score1int = 0;
    int score2int = 0;

    score1.setFillColor(sf::Color::White);
    score2.setFillColor(sf::Color::White);
    score1.setFont(font);
    score2.setFont(font);
    score1.setPosition(1100, 0);
    score2.setPosition(15, 0);
    score1.setString(std::to_string(score1int));
    score2.setString(std::to_string(score2int));
    score1.setCharacterSize(100);
    score2.setCharacterSize(100);

    title.setFont(font);
    title.setFillColor(sf::Color::White);
    title.setString("Ping Pong");
    title.setPosition(465, 20);

    rectangle1.setSize(sf::Vector2f(20.f, 80.f));
    rectangle1.setPosition(sf::Vector2f(50.f, 360.f));
    sf::Vector2f rectangle1TopPos(50.f, 0.f);
    sf::Vector2f rectangle1BottomPos(50.f, 720.f);

    rectangle2.setSize(sf::Vector2f(20.f, 80.f));
    rectangle2.setPosition(sf::Vector2f(1130.f, 360.f));
    sf::Vector2f rectangle2TopPos(1130.f, 0.f);
    sf::Vector2f rectangle2BottomPos(1130.f, 720.f);

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

        sf::Vector2f r1position = rectangle1.getPosition();
        sf::Vector2f r2position = rectangle2.getPosition();

        sf::Vector2f ballposition = ball.getPosition();

        if (r1position.y < 0.f)
        {
            rectangle1.setPosition(rectangle1TopPos);
        }
        else if (r1position.y > 720.f)
        {
            rectangle1.setPosition(rectangle1BottomPos);
        }

        if (r2position.y < 0.f)
        {
            rectangle2.setPosition(rectangle2TopPos);
        }
        else if (r2position.y > 720.f)
        {
            rectangle2.setPosition(rectangle2BottomPos);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            rectangle1.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            rectangle1.move(0.f, -0.1f); 
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rectangle2.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rectangle2.move(0.f, -0.1f);
        }

        ballposition.x += xballVelocity;
        ballposition.y += yballVelocity;
        ball.setPosition(ballposition);

        if (ballposition.y < 15)
        {
            ball.setPosition(sf::Vector2f(ballposition.x, 15.f));
            yballVelocity *= -1;
        }
        else if (ballposition.y > 775)
        {
            ball.setPosition(sf::Vector2f(ballposition.x, 775.f));
            yballVelocity *= -1;
        }

        if (ballposition.x >= (r2position.x - 20))
        {
            if (ballposition.y >= r2position.y && ballposition.y <= (r2position.y + 80))
            {
                xballVelocity *= -1;
            }
        }

        if (ballposition.x <= (r1position.x + 20))
        {
            if (ballposition.y >= r1position.y && ballposition.y <= (r1position.y + 80))
            {
                xballVelocity *= -1;
            }
        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < 800; i = i + 100)
        {
            middleline.setPosition(590, i);
            window.draw(middleline);
        }

        if(ballposition.x <= 0)
        {
            score1int++;
            score1.setString(std::to_string(score1int));
            ball.setPosition(sf::Vector2f(600.f, 400.f));
        }
        if(ballposition.x >= 1200)
        {
            score2int++;
            score2.setString(std::to_string(score2int));
            ball.setPosition(sf::Vector2f(600.f, 400.f));
        }

        window.draw(middleline);
        window.draw(title);
        window.draw(ball);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(score1);
        window.draw(score2);
        window.display();
    }
}