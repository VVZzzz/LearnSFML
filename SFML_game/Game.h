#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Game {
public:
  Game();
  void run();
private:
  void									processEvent();		//轮询并处理用户输入输出事件
  void									update(sf::Time);	//游戏状态更新
  void									render();					//渲染方法

  void									updateStatics(sf::Time eplasedTime);  //更新统计信息
  void									handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
  static const float		skPlayerSpeed;
  static const sf::Time     skTimePerFrame;

  sf::RenderWindow			        mWindow;
  sf::Texture						mTexture;
  sf::Sprite						mPlayer;
  sf::Font							mFont;
  sf::Text							mText;
  sf::Time							mUpdateTime;

  std::size_t						mNumFrames;
  bool								mIsMovingUp;
  bool								mIsMovingDown;
  bool								mIsMovingLeft;
  bool								mIsMovingRight;


};
