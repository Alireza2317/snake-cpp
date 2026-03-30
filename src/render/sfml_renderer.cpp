
static sf::Color to_sf_color(snake::common::Color color) {
	using Color_snake = snake::common::Color;
	switch (color) {
		case Color_snake::Black:
			return sf::Color::Black;
		case Color_snake::White:
			return sf::Color::White;
		case Color_snake::Green:
			return sf::Color::Green;
		case Color_snake::Gray:
			return sf::Color(50, 50, 50, 255);
		case Color_snake::Red:
			return sf::Color::Red;
		case Color_snake::Blue:
			return sf::Color::Blue;
		case Color_snake::Yellow:
			return sf::Color::Yellow;
		case Color_snake::Orange:
			return sf::Color(255, 150, 50, 255);
		case Color_snake::Violet:
			return sf::Color::Magenta;
		case Color_snake::Cyan:
			return sf::Color::Cyan;
		case Color_snake::Transparent:
			return sf::Color::Transparent;
	}
	return sf::Color::Black;
}

