void draw( int red, int green, int blue )
{
    // draw something, somehow
}

enum Color
{
    C_RED,
    C_GREEN,
    C_BLUE,
};

int main( void )
{
    enum Color bg_color = C_GREEN;

    switch (bg_color)
    {
        case C_RED:
            draw(255, 0, 0);
            break;

        case C_GREEN:
            draw(0, 255, 0);
            break;

        case C_BLUE:
            draw(0, 0, 255);
            break;
    }
}
