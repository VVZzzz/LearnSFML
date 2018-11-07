#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include <iostream>

namespace Textures {
	enum ID {
	LandScape,
	Airplane,
	};
}

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Resources");
	//����֡����,�������ڲ�ʹ����sleep,�ʾ�ȷ���п��ܲ�׼ȷ��
	window.setFramerateLimit(20);
	//����Texture��Դ��
	ResourceHolder<sf::Texture, Textures::ID> textures;
	try {
		textures.load(Textures::ID::LandScape, "../Media/Textures/Desert.png");
		textures.load(Textures::ID::Airplane, "../Media/Textures/Eagle.png");
	}		//load�����쳣���׳�runtime_error�쳣,���Բ���runtime_error�쳣
	catch (const std::runtime_error &e) {
		std::cout << "exception: " << e.what() << std::endl;
		return 1;
	}

	//get()�᷵����Դ������
	sf::Sprite landscape(textures.get(Textures::ID::LandScape));
	sf::Sprite airplane(textures.get(Textures::ID::Airplane));
	airplane.setPosition(200.f, 200.f);
	//landscape.setPosition(200.f, 200.f);

	while (window.isOpen()) {
		sf::Event events;
		while (window.pollEvent(events)) {
			if (events.type == sf::Event::KeyPressed || events.type == sf::Event::Closed)
				return 0;
		}
		window.clear();
		window.draw(airplane);
		window.draw(landscape);
		window.display();

	}

}