#include "Game.h"

void Game::setUpGame()
{
	partyGold = 200;
	P1.setAlive(true);
	P1.setAttack(4);
	P1.setCombat(false);
	P1.setDefence(2);
	P1.setGuarding(false);
	P1.setTown(false);
	P1.setX(1);
	P1.setY(1);
	P1.setMaxHealth(20);
	P1.setHealth(P1.getMaxHealth());

	Area.SetRandom(16);
	Area.setSize(5);
	Area.setX(0);
	Area.setY(3);

	

	
}

Game::Game()
{
	setUpGame();
}

bool Game::GetRunning()
{
	return running;
}

void Game::gameplay()
{
	std::cout << "Your journey begins Go forth!" << std::endl;

	while (P1.getAlive())
	{

		

		if(explore)
		{





			Exploring();
		}

		if (combat)
		{
			Combat();
		}
		if (!P1.getAlive())
		{

			running = false;
			
		}
	}
}

void Game::Exploring()
{
	choosing = true;
	while (explore)
	{
		
			
		while (choosing)
		{

			std::cout << ">you are at position X" << P1.getX() << " Y" << P1.getY() <<"\n nearest town is at X" << Area.getX() << "Y"
				<< Area.getY() << "\n gold: "<<partyGold << "\nhealth:" <<P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;
			std::cout << ">1 to go north\n>2 to go south\n>3 to go west\n>4 to go east\n";
			std::cin >> input;

			switch (input)
			{
			default:
				std::cout << "\n>Please choose A valid option:\n" << std::endl;
				break;
			case 1: 
				std::cout << "\n>You head North:\n" << std::endl;
				P1.up();
			
			
				
				break;
			case 2:
				std::cout << "\n>You head South:\n" << std::endl;
				P1.down();
				
				
				
				break;
			case 3:
				std::cout << "\n>You head West:\n" << std::endl;
				P1.left();
				
				
				break;
			case 4:
				std::cout << "\n>You head East:\n" << std::endl;
				P1.right();
				
				
				break;
			}
			std::cout << (Area.spawnEnemy() && (P1.getX() != Area.getX() && P1.getY() != Area.getY()));
			if (Area.spawnEnemy() && (P1.getX() != Area.getX() && P1.getY() != Area.getY()))
			{

				P1.setCombat(true);
				combat = true;
				explore = false;
				choosing = false;
			}
			if (Area.getX() == P1.getX() && Area.getY() == P1.getY())
			{

				while (choosing)
				{
					std::cout << "You found a town do you wish to enter?\n 1)yes\t 2)no\n";
					std::cin >> input;
					switch (input)
					{

					default:
						std::cout << "\n>Please choose A valid option:" << std::endl;
						break;
					case 1:
						town = true;
						downtown();
						choosing = false;
						break;
					case 2:
						choosing = false;
						break;
					}
				}
				choosing = true;
			}
		}

		
		
	}
	
}

void Game::Combat()
{
	playerTurn = true;
	flee = false;
	enemyAmount = createEnemy();;
	aliveEnemies = enemyAmount;
	for (int i = 0; i < enemyAmount ; i++)
	{
		for (int j = 0; j < enemyAmount; j++)
		{
			if (enemies[i].getName() == enemies[j].getName())
			{
				enemies[j].changeRank();
				enemies[j].setName(enemies[j].getName() + " " + enemies[j].getRank());
				

			}
			
		}
	}

	for (int i = 0; i < enemyAmount; i++)
	{
		std::cout << "An attack! " << enemies[i].getName() << "smirks" << std::endl;
	}
	while (combat)
	{
		if (P1.getHealth() <= 0)
		{
			P1.setAlive(false);
			playerTurn = false;
			enemyTurn = false;
			combat = false;
			explore = true;
			std::cout << ">You are dead! Game Over" << std::endl;
		}
		for (int i = 0; i < enemyAmount; i++)
		{
			
			if (enemies[i].getHealth() <= 0 && enemies[i].getAlive())
			{
				enemies[i].setAlive(false);
				aliveEnemies = aliveEnemies - 1;
			}
			
		}
		if (aliveEnemies <= 0)
		{
			playerTurn = false;
			enemyTurn = false;
			combat = false;
			explore = true;
			std::cout << ">You are victorious! you looted them!\n"  << std::endl;
			partyGold += rand() % (1 - 100) + 1;
		}
		if (flee)
		{
			playerTurn = false;
			enemyTurn = false;
			combat = false;
			explore = true;
			std::cout << ">You ran away...!\n" << std::endl;
		}

		while (playerTurn)
		{
			choosing = true;
			std::cout << ">Your health is " << P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;
			for (int i = 0; i < enemyAmount; i++)
			{
				std::cout << enemies[i].getName() << "health is " <<enemies[i].getHealth()<<"/"<< enemies[i].getMaxHealth() << std::endl;
			}
			std::cout <<">Choose an option:\n > 1)attack\n >2)guard\n >3)flee\n\n";
			
			std::cin >> input ;
			while (choosing)
			{
				switch (input)
				{
				default:
					std::cout << ">Please choose A valid option:\n" << std::endl;
					break;
				case 1:
					std::cout << ">Attack choose a target:\n" << std::endl;
					for (int i = 0; i < enemyAmount; i++)
					{
						std::cout << i+1 << ") attack: " << enemies[i].getName()<< "\n";
					}
					
					 attacking = true;
					while (attacking)
					{
						std::cin >> input;

						for (int i = 0; i < enemyAmount; i++)
						{

							if (input == i + 1)
							{
								if (enemies[i].getAlive())
								{
									enemies[i].takeDamage(P1.dealDamage());
									choosing = false;
									attacking = false;
								}
								else
								{
									std::cout << ">Please choose A valid Target they are dead already!:" << std::endl;
									break;
								}
								break;
							}
						}
					}
					break;
				case 2:
					std::cout << ">You guard:\n" << std::endl;
					choosing = false;
					P1.setGuarding(true);
					break;
				case 3:
					std::cout << ">You try run away:\n" << std::endl;
					if (rand() % (1 - 4) + 1 >= 2)
					{
						flee = true;
					}

					choosing = false;
					break;
				}
			}
			playerTurn = false;
			if (flee)
			{
				break;
			}
			else
			{


				enemyTurn = true;
			}
			std::cout << ">Your health is " << P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;
			for (int i = 0; i < enemyAmount; i++)
			{
				std::cout << enemies[i].getName() << "health is " << enemies[i].getHealth() << "/" << enemies[i].getMaxHealth() << std::endl;
			}
			std::cin;
		}
		while (enemyTurn)
		{
			for (int i = 0; i < enemyAmount; i++)
			{
				if (enemies[i].getAlive())
				{
					std::cout << enemies[i].getName() << "Attacked  you  for  " << P1.takeDamage(enemies[i].dealDamage());
					
				}
				std::cout << ">Your health is now:" << P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;
				std::cin;
			}
			enemyTurn = false;
			playerTurn = true;
		}
		
	}

	
}

int Game::createEnemy()
{
	int amount = rand() % (1 - 3) + 1;
	for (int i = 0; i < amount; i++)
	{
		enemies[i] = Enemy(rand() % (1 - 3) + 1);

	}

	return amount;
}

void Game::downtown()
{
	
	while (town)
	{
		std::cout << "you enter the town." << std::endl;
		choosing = true;
		while (choosing)
		{
			std::cout << "there's a tavern, a shop and a city hall nearby...\n 1) enter the city hall\n 2) enter the shop\n 3) enter the tavern\n4) leave the town\n";
			std::cin >> input;

			switch (input)
			{
			default:
				std::cout << ">Please choose A valid option!:" << std::endl;
				break;
			case 1:
				std::cout << ">its definetly a city hall...the mayor is out he would have given you a hunting job but hes off doing construction" << std::endl;
				break;
			case 2:
				shop();
				break;
			case 3:
				tavern();
				break;
			case 4:
				choosing = false;
				town = false;
				std::cout << "Back to the wilds with vigor you ni-!:" << std::endl;
				break;
			}

		}

	}
}

void Game::shop()
{
	std::cout << "you enter the shop." << std::endl;
	choosing = true;
		while (choosing)
		{

			std::cout << "your options are\n1)small potion 10G\n 2)mid potion 30G 3) full heal potion 100g\n 4) just leave\n you have  " <<
				partyGold << "\n gold left.\n";
			std::cin >> input;
			switch (input)
			{
			default:
				std::cout << ">Please choose A valid option!:" << std::endl;

				break;
			case 1:
				if (partyGold - 10 >0)
				{
					std::cout << ">Small potion drank health is now:";
					if (P1.getHealth() + 5 > P1.getMaxHealth())
					{
						std::cout << P1.getMaxHealth() << "/" << P1.getMaxHealth() << std::endl;
						P1.setHealth(P1.getMaxHealth());
					}
					else
					{
						P1.setHealth(P1.getHealth() +5);
						std::cout << P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;
					
					}
					partyGold = partyGold - 10;
				}
				else
				{
					std::cout << "not enough cash stranger" << std::endl;
				}
				break;
			case 2:
				if (partyGold - 30 > 0)
				{
					std::cout << ">mid potion drank health is now:";
					if (P1.getHealth() + 10 > P1.getMaxHealth())
					{
						std::cout << P1.getMaxHealth() << "/" << P1.getMaxHealth() << std::endl;
						P1.setHealth(P1.getMaxHealth());
					}
					else
					{
						P1.setHealth(P1.getHealth() + 10);
						std::cout << P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;

					}
					partyGold = partyGold - 30;
				}
				else
				{
					std::cout << "not enough cash stranger" << std::endl;
				}
			case 3:
				if (partyGold - 100 > 0)
				{
					std::cout << ">full potion drank health is now:";
					{
						P1.setHealth(P1.getMaxHealth());
						std::cout << P1.getHealth() << "/" << P1.getMaxHealth() << std::endl;

					}
					partyGold = partyGold - 100;
				}
				else
				{
					std::cout << "not enough cash stranger" << std::endl;
				}
				break;
			case 4:
				choosing = false;
				std::cout << ">Good never come back:\n";
				break;
			}

			

		}



}

void Game::tavern()
{
	std::cout << "YOU ENTER THE MIGHTY TAVERN enter the correct drink to win otherwise you are ejected!\n what is the shot to kill allexwah today(or tomorrow idk when you see this)";
	std::string answer = "";
	std::cin >> answer;
	if(answer == "chartreuse" || answer == "Chartreuse")
	{
		std::cout << "correct unlocking full potential go monkey and slaughter with glee! *monkey noises*\n";
		partyGold = 99999999;
		P1.setMaxHealth(999999);
		P1.setAttack(999999);
		P1.setDefence(999999);
	}
	else
	{
		std::cout << "Wrong....Bideeeen Blast...simp\n";

	}

}
