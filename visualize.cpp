#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm> // for std::max

void drawArray(sf::RenderWindow &window, const std::vector<int> &arr) {
    window.clear();

    float width = window.getSize().x;
    float height = window.getSize().y;
    float barWidth = width / arr.size();

    int maxVal = *std::max_element(arr.begin(), arr.end());

    for (size_t i = 0; i < arr.size(); ++i) {
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(barWidth - 2, (arr[i] / static_cast<float>(maxVal)) * height));
        bar.setPosition(i * barWidth, height - bar.getSize().y);
        bar.setFillColor(sf::Color::Green);

        window.draw(bar);
    }

    window.display();
}

void insertionSort(std::vector<int> &arr, sf::RenderWindow &window) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;

            drawArray(window, arr);
            sf::sleep(sf::milliseconds(100)); // to visualize the sorting steps
        }
        arr[j + 1] = key;

        drawArray(window, arr);
        sf::sleep(sf::milliseconds(100)); // to visualize the sorting steps
    }
}

int main() {
    std::vector<int> arr = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};

    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualization");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        insertionSort(arr, window);

        // Wait for window close to terminate the program
        sf::sleep(sf::seconds(5));
        window.close();
    }

    return 0;
}
