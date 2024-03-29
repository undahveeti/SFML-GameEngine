#include "../header/GameObject.hpp"

GameObject::GameObject() :
texture(),
sprite(),
pos(sf::Vector2f(0.f, 0.f))
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr) :
texture(tex),
sprite(spr)
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr, std::string str) :
texture(tex),
sprite(spr),
tag(str)
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr, sf::Vector2f pos) :
texture(tex),
sprite(spr),
pos(pos)
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr, sf::Vector2f pos, std::string str)  :
texture(tex),
sprite(spr),
pos(pos),
tag(str)
{}

GameObject::~GameObject() {}

void GameObject::setSprite(sf::Sprite spr) { sprite = spr; }
void GameObject::setTexture(sf::Texture tex) { texture = tex; }
void GameObject::setPos(sf::Vector2f vec) { pos = vec; }
void GameObject::setName(std::string str) { tag = str; }
void GameObject::addComponent(GameComponent* comp) { components.push_back(comp); }
void GameObject::removeComponent(int i) { components.erase(components.begin()+i); }

GameComponent* GameObject::getComponent(int i) { return components[i]; }
sf::Texture* GameObject::getTextureMutator() { return &texture; }
sf::Texture GameObject::getTexture() { return texture;}
sf::Sprite* GameObject::getSpriteMutator() { return &sprite; }
sf::Sprite GameObject::getSprite() { return sprite; }
sf::Vector2f* GameObject::getPosMutator() { return &pos; }
sf::Vector2f GameObject::getPos() { return pos; }
std::string* GameObject::getNameMutator() { return &tag; }
std::string GameObject::getName() { return tag; }