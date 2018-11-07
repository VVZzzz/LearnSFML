#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Game {
public:
  Game();
  void run();
private:
  void									processEvent();		//��ѯ�������û���������¼�
  void									update(sf::Time);	//��Ϸ״̬����
  void									render();					//��Ⱦ����

  void									updateStatics(sf::Time eplasedTime);  //����ͳ����Ϣ
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
