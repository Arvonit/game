#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <print>

int main() {
    auto window = sf::RenderWindow({1920u, 1080u}, "Game");
    window.setFramerateLimit(144);

    auto block = sf::RectangleShape({25, 25});
    block.setFillColor(sf::Color::White);
    block.setPosition({(1920u - block.getSize().x) / 2, (1080 - block.getSize().y) / 2});

    auto circle = sf::CircleShape(12.5);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(300, 300);

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                std::println("Window has closed (now using std::println)");
                window.close();
            }
        }

        if (window.hasFocus()) {
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            //     block.move(0, -5);
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //     block.move(-5, 0);
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            //     block.move(0, 5);
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //     block.move(5, 0);
            // }

            // Control blocks with an xbox controller
            if (sf::Joystick::isConnected(0)) {
                auto leftX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
                auto leftY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

                auto rightX = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
                auto rightY = sf::Joystick::getAxisPosition(0, sf::Joystick::R);

                // Move the block with left joystick
                if (std::abs(leftX) > 15.f) {     // Apply a dead zone to ignore small inputs
                    block.move(leftX * 0.05f, 0); // Scale movement
                }
                if (std::abs(leftY) > 15.f) {
                    block.move(0, leftY * 0.05f);
                }

                // Move the circle with right joystick
                if (std::abs(rightX) > 15.f) {
                    circle.move(rightX * 0.05f, 0);
                }
                if (std::abs(rightY) > 15.f) {
                    circle.move(0, rightY * 0.05f);
                }
            }
        }

        window.clear();
        window.draw(block);
        window.draw(circle);
        window.display();
    }
}
