#include "Game.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

constexpr int _blockw = 15;
constexpr int _boardw = 25;
constexpr int _boardh = 25;



Game::Game(){

    //Empty
}

Game::~Game(){
 
    delete window;

}
void Game::update(){
    //update snake  
    //from back to front
    //tail
    if(scored){
        scored=false;
        snake.tail.push_back(snake.head);
    }
    else{
        for(int i = 0; i<snake.tail.size(); i++){
        if(i == snake.tail.size()-1)
            snake.tail[i] = snake.head;
        else
            snake.tail[i] = snake.tail[i+1];
        }
    }
    
    //head
    if(snake.dir == DIR::UP)
        snake.head.y--;
    if(snake.dir == DIR::DOWN)
        snake.head.y++;
    if(snake.dir == DIR::RIGHT)
        snake.head.x++;
    if(snake.dir == DIR::LEFT)
        snake.head.x--;
    
    //check if the snake is moved off board
    if(snake.head.x > _boardw-1)
        snake.head.x = 0;
    if(snake.head.x < 0)
        snake.head.x = _boardw-1;
    if(snake.head.y > _boardh-1)
        snake.head.y = 0;
    if(snake.head.y < 0)
        snake.head.y = _boardh-1;

    //new Pos for food and add a new segment to the tail
    if (snake.head.x == food.x && snake.head.y == food.y){

        scored = true;

        food.x = rand() % _boardh;
        food.y = rand() % _boardw;
        score++;
    }

    //update title
    title = "Snake, score: " + std::to_string(score);  
    this->window->setTitle(title);

    for(Block i : snake.tail){
        if(snake.head.x == i.x && snake.head.y == i.y)
            finished = true;
             
    }
}

void Game::draw(){
    sf::RectangleShape drawingBlock = sf::RectangleShape(sf::Vector2f(_blockw, _blockw));

    //render food 
    drawingBlock.setFillColor(sf::Color::Green);
    drawingBlock.setPosition(sf::Vector2f(food.x * _blockw, food.y * _blockw));
    this->window->draw(drawingBlock);

    //render the tail of the snake
    drawingBlock.setFillColor(sf::Color::Blue);
    for(Block i : snake.tail){
        drawingBlock.setPosition(sf::Vector2f(i.x * _blockw, i.y * _blockw)); 
        this->window->draw(drawingBlock);
    }

    //render head of the snake
    drawingBlock.setFillColor(sf::Color::Red);
    drawingBlock.setPosition(sf::Vector2f(snake.head.x * _blockw, snake.head.y* _blockw));
    this->window->draw(drawingBlock);

}

void Game::Run(){
    srand(time(0));

    title = "Snake, score: " + std::to_string(score); 
    window = new sf::RenderWindow(sf::VideoMode(_blockw * _boardw, _blockw * _boardh), title);

    food = {10,10};
    snake.head = {5,20};
    snake.tail = {{5,21}};

    while(window->isOpen() && !finished){
        sf::Event event;
        while(window->pollEvent(event)){
            if (event.type==sf::Event::Closed){
                window->close();
            }

            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Up:
                        if(snake.dir != DIR::DOWN)
                            snake.dir = DIR::UP;
                        break;
                    case sf::Keyboard::Down:
                        if(snake.dir != DIR::UP)
                            snake.dir = DIR::DOWN;
                        break;
                    case sf::Keyboard::Right:
                        if(snake.dir != DIR::LEFT)
                            snake.dir = DIR::RIGHT;
                        break;
                    case sf::Keyboard::Left:
                        if(snake.dir != DIR::RIGHT)
                            snake.dir = DIR::LEFT;
                        break;
                }
            }
        }
        dt = clock.getElapsedTime().asMilliseconds();
        if(dt > 1000/10){
            clock.restart();

            this->window->clear(sf::Color::White);
            update();
            draw();
            this->window->display();
            }


    }
    std::cout << "Game over!! Dein Score: " << score<<std::endl;
    window->close();

}
