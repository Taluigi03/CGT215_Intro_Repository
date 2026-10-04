#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    // File paths
    string background = "images1/backgrounds/winter.png";
    string foreground = "images1/characters/yoda.png";

    // Load background texture
    Texture backgroundTex;

    if (!backgroundTex.loadFromFile(background))
    {
        cout << "Couldn't Load Background Image" << endl;
        return 1;
    }

    // Load foreground texture
    Texture foregroundTex;

    if (!foregroundTex.loadFromFile(foreground))
    {
        cout << "Couldn't Load Foreground Image" << endl;
        return 1;
    }

    // Convert textures into images so we can access individual pixels
    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();

    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();

    // Get the size of the background image
    Vector2u size = backgroundImage.getSize();

    // Get the green-screen color from the corner of the foreground image
    Color greenScreenColor = foregroundImage.getPixel(0, 0);

    // Go through every pixel
    for (unsigned int y = 0; y < size.y; y++)
    {
        for (unsigned int x = 0; x < size.x; x++)
        {
            // Get the current foreground pixel
            Color foregroundPixel = foregroundImage.getPixel(x, y);

            // Check if the current pixel is the green-screen color
            if (foregroundPixel == greenScreenColor)
            {
                // Get the background pixel at the same location
                Color backgroundPixel = backgroundImage.getPixel(x, y);

                // Replace the green pixel with the background pixel
                foregroundImage.setPixel(x, y, backgroundPixel);
            }
        }
    }

    // Create a texture using the newly composited image
    Texture finalTexture;
    finalTexture.loadFromImage(foregroundImage);

    // Put the texture onto a sprite
    Sprite finalSprite;
    finalSprite.setTexture(finalTexture);

    // Create the program window
    RenderWindow window(VideoMode(1024, 768), "Image Compositing");

    // Display the finished image
    window.clear();
    window.draw(finalSprite);
    window.display();

    // Keep the window open
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}