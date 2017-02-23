#include <iostream>
#include <ctime>
#include <string>

enum class Weapon
{
	FISTS,
	GUN,
	SHOTGUN,
	REVOLVER,
	SNIPER,
	MACHINE_GUN,
	MAX
};
const int sizeHorda{ 10 };

class Zombie;

class Player 
{
public:
	
		Weapon weapon;
		float precision;
		int life;

		void attack(Zombie &Z);
		
		bool isAlive()
		{
			return (life > 0);
		}

	
		Player():weapon(static_cast <Weapon>(rand() % static_cast<int>(Weapon::MAX))),precision(rand() % (1)),life( rand()% 101)
		{
		}
		
		

};


class Zombie
{
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;

	void attack(Player &P);
	
	bool isAlive()
	{
		return (life > 0);
	}

	Zombie() :distanceToPlayer(20 + rand() % (200 - 20)), speed((rand() % 200) / 10), damage((rand() % 200) / 10),
		life(rand() % 101)
	{
	}



};

void Player::attack(Zombie &Z)
{
	Z.life -= (static_cast<float>(weapon)*precision);

}

void Zombie::attack(Player &P)
{
	if (distanceToPlayer <= 0)
	{
		P.life -= damage;
	}
	else
	{
		distanceToPlayer--;
	}
}




void main()
{
	srand(time(nullptr));

	Player Sergio;
	Zombie horda[sizeHorda];

	bool zombiesAreAlive = true;

	do {

		for (int i = 0; i < sizeHorda; i++)
		{
			zombiesAreAlive = false;
				if (horda[i].isAlive)
				{
					zombiesAreAlive = true;
				}

		}

	} while (zombiesAreAlive == true && Sergio.life == true);

	

}