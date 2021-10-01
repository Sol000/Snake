#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream> 

enum class DIR {UP, RIGHT, DOWN, LEFT};

struct Block{
    int x;
    int y;
};

struct Snake{
    Block head;
    std::vector<Block> tail; 
    DIR dir = DIR::UP;
};


class Game{

    public:
        Game();
        ~Game();

        void Run();

    private:
        float dt;
        bool finished = false;
        bool scored = false;
        Snake snake;
        Block food;
        Block lastSegment;
        int score = 0;

        sf::Clock clock;
        sf::RenderWindow* window = nullptr;        
        std::string title;

        //functions
        void draw();
        void update();
        void render();

};


