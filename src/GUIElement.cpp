#include "../header/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string message) {
  this->message = message;
  this->position = position;
  this->text = new sf::Text();

  this->text->setString(this->message);

  this->text->setPosition(position);
}

GUIText::~GUIText() {
  delete text;
}

void GUIText::setStyle(GUIStyle* style) {
  this->text->setFont(*style->font);
  this->text->setCharacterSize(style->subheadingSize);
  this->text->setFillColor(style->primaryColor);
  this->text->setOutlineThickness(style->textOutlineSize);
  this->text->setOutlineColor(style->outlineColor);
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->text, states); 
}

// GUIHedingText
void GUIHeadingText::setStyle(GUIStyle* style) {
  GUIText::setStyle(style);
  this->text->setCharacterSize(style->headerSize);
  sf::FloatRect textRect = this->text->getLocalBounds();
  this->text->setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top + textRect.height/2.0f);
}

GUIHeadingText::~GUIHeadingText() {
}

// GUISubheadingText
void GUISubheadingText::setStyle(GUIStyle* style) {
  GUIText::setStyle(style);
  this->text->setCharacterSize(style->subheadingSize);
  sf::FloatRect textRect = this->text->getLocalBounds();
  this->text->setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top + textRect.height/2.0f);
}

GUISubheadingText::~GUISubheadingText() {
}

// GUIShape
GUIRect::GUIRect(sf::Vector2f position, sf::Vector2f size) : GUIElement(position), size(size) {
  this->rect = new sf::RectangleShape();
  this->rect->setSize(this->size);
  sf::FloatRect textRect = this->rect->getLocalBounds();
  this->rect->setPosition(position);
}

void GUIRect::setStyle(GUIStyle* style) {
  this->rect->setFillColor(style->secondaryColor);
  this->rect->setOutlineThickness(style->shapeOutlineSize);
  this->rect->setOutlineColor(style->outlineColor);
  sf::FloatRect rectRect = this->rect->getLocalBounds();
  this->rect->setOrigin(rectRect.left + rectRect.width/2.0f,
                        rectRect.top + rectRect.height/2.0f);
}

void GUIRect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->rect, states);
}