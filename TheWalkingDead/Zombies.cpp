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

Weapon t_weapon;
float t_precision;
int t_life;


std::ostream& operator<<(std::ostream, )//NO ESTA COMPLETO


class Zombie;

class Player 
{
public:
	
		Weapon weapon;
		float precision;
		int life;

		
	
		Player():
			weapon(static_cast <Weapon>(rand() % static_cast<int>(Weapon::MAX))),
			precision(rand() % (1)),
			life( rand()% 101)
		{
		}

		Player(const Weapon &t_weapon, float t_precision, int t_life):
			weapon(t_weapon),
			precision(t_precision),
			life(t_life) {};

		void attack(Zombie &Z);

		bool isAlive()
		{
			return (life > 0);
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
	srand(static_cast<unsigned>(time(nullptr)));

	Player player;
	const int MAX_ZOMBIES{ 10 };
	Zombie zombies[MAX_ZOMBIES];

	std::cout << "Player\n\initial life: " << player.life << " ,weapon: " << player.weapon << " , precision: " << player.precision << std::endl;
	std::cout << "ZOMBIES ARE COMING!" << std::endl;

	bool zombiesAreAlive;
	do {

		ZombiesAreAlive = false;
		std::cout << "Player\n\tlife" << player.life << std::endl;

		for (int i(0); i < MAX_ZOMBIES; ++i)
		{
			std::cout <<"Zombie[" << i << 
				"]\n\tlife: " << zombies[i].life <<
				", distancce: " << zombies[i].distanceToPlayer << 
				", "


		}


	} while ();

	/*srand(time(nullptr));

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

	} while (zombiesAreAlive == true && Sergio.life == true);*/



	

}