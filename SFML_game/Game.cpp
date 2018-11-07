#include "Game.h"
const float Game::skPlayerSpeed = 2000.f;
const sf::Time Game::skTimePerFrame = sf::seconds(1.f / 60.f);
Game::Game()
  : mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close),
  mTexture(),
  mPlayer(),
  mFont(),
  mText(),
  mUpdateTime(),
  mNumFrames(0),
  mIsMovingUp(false),
  mIsMovingDown(false),
  mIsMovingLeft(false),
  mIsMovingRight(false) {
  if (!mTexture.loadFromFile("../Media/Textures/Eagle.png")) {
    //process Error;
  }
  mPlayer.setTexture(mTexture);
  mPlayer.setPosition(100.f, 100.f);
  mFont.loadFromFile("../Media/Sansation.ttf");
  mText.setFont(mFont);
  mText.setPosition(5.f, 5.f);
  mText.setCharacterSize(10);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (mWindow.isOpen()) {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;
    while (timeSinceLastUpdate > skTimePerFrame) {
      timeSinceLastUpdate -= skTimePerFrame;
      processEvent();
      update(timeSinceLastUpdate);
    }
    updateStatics(elapsedTime);
    render();
  }
}

void Game::processEvent() {
  sf::Event events;
  while (mWindow.pollEvent(events)) {
    switch (events.type) {
    case sf::Event::KeyPressed: {
      handlePlayerInput(events.key.code, true);
      break;
    }
    case sf::Event::KeyReleased: {
      handlePlayerInput(events.key.code, false);
      break;
    }
    case sf::Event::Closed: {
      mWindow.close();
      break;
    }
    default:
      break;
    }
  }
}

void Game::update(sf::Time deltaTime) {
  sf::Vector2f movement(0.f, 0.f);
  if (mIsMovingUp)
    movement.y -= skPlayerSpeed;
  if (mIsMovingDown)
    movement.y += skPlayerSpeed;
  if (mIsMovingLeft)
    movement.x -= skPlayerSpeed;
  if (mIsMovingRight)
    movement.x += skPlayerSpeed;

  mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render() {
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.draw(mText);
  mWindow.display();
}

void Game::updateStatics(sf::Time eplasedTime) {
  mUpdateTime += eplasedTime;
  mNumFrames += 1;
  if (mUpdateTime >= sf::seconds(1.0f)) {
    mText.setString(
      "Frames / Seconds = " + std::to_string(mNumFrames) + "\n" +
      "Time / Update = " + std::to_string((mUpdateTime.asMicroseconds() / mNumFrames)) + "us");
    mUpdateTime -= sf::seconds(1.0f);
    mNumFrames = 0;
  }
}

void Game::handlePlayerInput(sf::Keyboard::Key key,
  bool isPressed) {
  if (key == sf::Keyboard::W) {
    mIsMovingUp = isPressed;
  }
  else if (key == sf::Keyboard::S) {
    mIsMovingDown = isPressed;
  }
  else if (key == sf::Keyboard::A) {
    mIsMovingLeft = isPressed;
  }
  else if (key == sf::Keyboard::D) {
    mIsMovingRight = isPressed;
  }
}
