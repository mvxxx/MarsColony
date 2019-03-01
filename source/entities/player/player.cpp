#include "player.hpp"

Player::Player(const sf::Vector2f& position,int16_t lev, int64_t experience, float speedValue,
        mv::Cache<sf::Texture>& playerTexture, mv::Cache<sf::Texture>& weaponsTexture)
    :state(state_t::STANDBY),level(lev),exp(experience),speed(speedValue)
{
    this->installComponents(position, weaponsTexture);
    this->setTextureOptions(playerTexture, weaponsTexture);
    this->getComponent<ProperBody>()->setCenter();
    this->assignInputs();
    this->updateRelativePositions();
}

void Player::setTextureOptions(mv::Cache<sf::Texture>& playerTexture, mv::Cache<sf::Texture>& weaponsTexture)
{
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("top")
            .setTexture(*playerTexture.get( mv::constants::path::PLAYER_TEXTURE_TOP ));
    this->getComponent<ProperBody>()->setCenter("top");

    this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom")
            .setTexture(*playerTexture.get( mv::constants::path::PLAYER_TEXTURE_BOTTOM ));
    this->getComponent<ProperBody>()->setCenter("bottom");
}

void Player::update(const std::shared_ptr<Scene>& scene, const CollisionManager& colManager,
        mv::Cache<sf::Texture>& playerTexture, mv::Cache<sf::Texture>& weaponsTexture)
{
    inputControl.update();
    this->getComponent<UnitPosition>()->update(this->getComponent<ProperBody>()->getAs<sf::Sprite>("top").getPosition());

    if(this->isAbleToMove(colManager))
    {
        this->accelerateMotion();
        this->fitTexture(Utilities::mouseWorldPosition(scene, Scene::viewType_t::DEFAULT));
        this->adaptView(scene);
    }
    this->updateRelativePositions();
    this->reduceVelocity();
}

void Player::moveTop()
{
    this->getComponent<Velocity>()->y -= speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::moveRight()
{
    this->getComponent<Velocity>()->x += speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::moveDown()
{
    this->getComponent<Velocity>()->y += speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::moveLeft()
{
    this->getComponent<Velocity>()->x -= speed * mv::constants::mob::DEFAULT_SPEED;
}

void Player::accelerateMotion()
{
    std::vector<sf::Sprite*> sprites = this->getComponent<ProperBody>()->getAllElementsAs<sf::Sprite>();
    auto velocity = this->getComponent<Velocity>()->getAsVector();
    for(auto& spritesPtr: sprites)
    {
        spritesPtr->move(velocity);
    }
}

void Player::fitTexture(const sf::Vector2f& position)
{
    auto velocity = this->getComponent<Velocity>();
    this->fitBottom(velocity);
    this->fitTop(position, velocity);
    this->rotateWeapons(position);
}

void Player::rotateWeapons(const sf::Vector2f& position)
{
    std::function<float(std::string)> calculateAngle =
            [=](const std::string& name)
            {
                auto posOfWeapon = this->getComponent<ProperBody>()->getAs<sf::Sprite>(name).getPosition();

                float angle = Utilities::angleBetweenVectors(
                        {0.f, -1.f},
                        sf::Vector2f{position.x - posOfWeapon.x, position.y - posOfWeapon.y});

                return position.x - posOfWeapon.x >= 0 ? angle : 360.f - angle;
            };
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("primary_weapon").setRotation(calculateAngle("primary_weapon"));
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("secondary_weapon").setRotation(calculateAngle("secondary_weapon"));
}

void Player::adaptView(const std::shared_ptr<Scene>& scene)
{
    scene->moveDefaultView(this->getComponent<Velocity>()->getAsVector());
}

void Player::reduceVelocity()
{
    auto velocity = this->getComponent<Velocity>();
    velocity->x = 0;
    velocity->y = 0;
}

void Player::installComponents(const sf::Vector2f& position, mv::Cache<sf::Texture>& weaponsTexture)
{
    this->addComponent<ProperBody>();
    this->addComponent<UnitPosition>();
    this->addComponent<Velocity>();
    this->getComponent<ProperBody>()->appendType<sf::Sprite>("top");
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("top").setPosition( position );
    this->getComponent<ProperBody>()->appendType<sf::Sprite>("bottom");
    this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom").setPosition( position );
    this->setWeaponSettings(position,"primary_weapon",weapon_t::machine_gun, weaponsTexture);
    this->setWeaponSettings(position,"secondary_weapon",weapon_t::rocket_launcher, weaponsTexture);
}

void Player::setWeaponSettings(const sf::Vector2f& position, const std::string& label, weapon_t type,
        mv::Cache<sf::Texture>& weaponsTexture)
{
    this->getComponent<ProperBody>()->appendType<sf::Sprite>(label);
    this->getComponent<ProperBody>()->getAs<sf::Sprite>(label).setTexture(
            *weaponsTexture.get(mv::constants::path::WEAPON_TEXTURE_ATLAS));

    this->getComponent<ProperBody>()->getAs<sf::Sprite>(label).setTextureRect( sf::IntRect(
            static_cast<int>(static_cast<int>(type)*mv::constants::defaults::WEAPON_DIMENSIONS.x),
            0, static_cast<int>(mv::constants::defaults::WEAPON_DIMENSIONS.x),
            static_cast<int>(mv::constants::defaults::WEAPON_DIMENSIONS.y)));

    this->getComponent<ProperBody>()->getAs<sf::Sprite>(label).setPosition(position);
}

void Player::assignInputs()
{
    auto own_pointer = std::make_shared<Player>(*this);
    inputControl.addKeyToCheck( sf::Keyboard::A, std::function<void( Player& )>( &Player::moveLeft ),own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::D, std::function<void( Player& )>( &Player::moveRight ), own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::S, std::function<void( Player& )>( &Player::moveDown ), own_pointer );
    inputControl.addKeyToCheck( sf::Keyboard::W, std::function<void( Player& )>( &Player::moveTop ), own_pointer );
}

void Player::fitBottom(const std::shared_ptr<Velocity>& velocity)
{
    if(velocity->getValue() != 0)
    {
        int sign = velocity->x < 0 ? -1 : 1;
        this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom")
                .setRotation(sign*Utilities::angleBetweenVectors({0.f,-1.f},velocity->getAsVector()));
    }
}

void Player::fitTop(const sf::Vector2f& position, const std::shared_ptr<Velocity>& velocity)
{
    auto selfPosition = this->getComponent<ProperBody>()->getAs<sf::Sprite>("top").getPosition();

    float angle = Utilities::angleBetweenVectors(
            {0.f,-1.f},
            sf::Vector2f{position.x-selfPosition.x,position.y-selfPosition.y});

    angle = position.x - selfPosition.x >= 0 ? angle : 360.f - angle;

    this->getComponent<ProperBody>()->getAs<sf::Sprite>("top")
         .setRotation(angle);
}

bool Player::isAbleToMove(const CollisionManager &colManager)
{
    //Positions in unit system (i,j)
    sf::Vector2i nextPos =
            Utilities::convertToUnitPosition(this->getComponent<ProperBody>()->getAs<sf::Sprite>("bottom").getPosition() +
                                             this->getComponent<Velocity>()->getAsVector());

    sf::Vector2i currentPos= {this->getComponent<UnitPosition>()->i,this->getComponent<UnitPosition>()->j};

    //assumption: velocity is bounded so T(n) = O(1) (n-number of considered tiles)
    //assumption: velocity.x < Tile.x
    for(int i = std::min(currentPos.x,nextPos.x); i <= std::max(currentPos.x,nextPos.x); i++)
    {
        for(int j = std::min(currentPos.y,nextPos.y); j <= std::max(currentPos.y,nextPos.y); j++)
        {
            if(colManager.checkCollsionStatus(i,j))
            {
                return false;
            }
        }
    }
    return true;
}

void Player::updateRelativePositions()
{
    this->setRelativePosition("primary_weapon",weapon_t::machine_gun);
    this->setRelativePosition("secondary_weapon",weapon_t::rocket_launcher);
}

void Player::setRelativePosition(const std::string& name, const weapon_t& label)
{
    auto sprite = this->getComponent<ProperBody>()->getAs<sf::Sprite>("top");
    int8_t sign = -1;

    if(label == weapon_t::machine_gun)
    {
        sign = 1;
    }

    float new_X = 0.5f * static_cast<float>(sprite.getLocalBounds().width*std::cos(Utilities::degreeToRadian(sprite.getRotation())));
    float new_Y = 0.5f * static_cast<float>(sprite.getLocalBounds().width*std::sin(Utilities::degreeToRadian(sprite.getRotation())));
    this->getComponent<ProperBody>()->getAs<sf::Sprite>(name).setPosition(sprite.getPosition() + sf::Vector2f{sign*new_X,sign*new_Y});
}

