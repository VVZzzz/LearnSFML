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
	//设置帧速率,由于在内部使用了sleep,故精确度有可能不准确。
	window.setFramerateLimit(20);
	//加载Texture资源类
	ResourceHolder<sf::Texture, Textures::ID> textures;
	try {
		textures.load(Textures::ID::LandScape, "../Media/Textures/Desert.png");
		textures.load(Textures::ID::Airplane, "../Media/Textures/Eagle.png");
	}		//load发生异常会抛出runtime_error异常,所以捕获runtime_error异常
	catch (const std::runtime_error &e) {
		std::cout << "exception: " << e.what() << std::endl;
		return 1;
	}

	//get()会返回资源的引用
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