#include <SFML/Graphics.hpp>
#include <print>

int main() {
    auto window = sf::RenderWindow({1920u, 1080u}, "Game");
    window.setFramerateLimit(144);

    auto block = sf::RectangleShape({25, 25});
    block.setFillColor(sf::Color::White);
    block.setPosition({(1920u - block.getSize().x) / 2, (1080 - block.getSize().y) / 2});

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                std::println("Window has closed (now using std::println)");
                window.close();
            }
        }

        if (window.hasFocus()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                block.move(0, -5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                block.move(-5, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                block.move(0, 5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                block.move(5, 0);
            }
        }

        window.clear();
        window.draw(block);
        window.display();
    }
}
