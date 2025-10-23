#include "asciiArt.h" 
#include "funValue.h"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <thread>

using namespace std;

int main()
{
	cout << "This is intended for fullscreen. \nSome aspects will not be as visible if in windowed mode.\n\n";
	system("pause");  // Lets the player input something before continuing
	system("cls");  // Clears the screen to avoid clutter
	cout << "Zoom in/out until this text is at the very top of the screen and the 'Press any key' text is at the very bottom (Optional, prevents needing to scroll)\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	cout << thumbsUp;  // All ASCII art and animations can be found in 'asciiArt.h'
	this_thread::sleep_for(chrono::seconds(2));  // Pauses for an amount of time. Here, it's for 2 seconds.
	system("cls");

	bool namingLoop = true;  // The variable that allows the while loop to work
	string namingYesNo;
	string heroName; 

	while (namingLoop)  // Allows the naming sequence to loop until the player confirms the hero's name
	{
		cout << "Name the hero (NO SPACES):  ";
		cin >> heroName;  // Using cin causes the program to freak out if a space is entered (see line 74 for why I didn't use getline)
		system("cls");

		if (heroName == "Skip" || heroName == "Skipping")  // Added this to skip past the naming dialogue while testing
		{
			namingLoop = false;  // Ends the loop, but the loop would continue until it finishes anyways
			break;  // Ignores the rest of the loop, fully ending it
		}

		if (heroName == name || heroName == Name2 || heroName == NAME3)
		{
			return 66;
		}

		dotDotDotAnimation();  // An example of an animation, stored in 'asciiArt.h'
		cout << heroName << ". ";
		this_thread::sleep_for(chrono::seconds(3));
		
		if (heroName == heroOne || heroName == heroTwo || heroName == heroThree)
		{
			cout << "An excellent choice.\n\n";
			this_thread::sleep_for(chrono::seconds(3));
		}

		if (heroName == altHeroThree)
		{
			cout << "This is not okay, but... ";
			this_thread::sleep_for(chrono::seconds(3));
		}

		cout << "Is this correct? ('yes' or 'no')\n\n";

		if (heroName.length() > 12)  //Names 13 characters or longer won't break the program, but they will look weird in the battle box
		{
			this_thread::sleep_for(chrono::milliseconds(1300));  // Instead of seconds, I use milliseconds to get more timing precision
			cout << "WARNING: Naming the hero anything longer than 12 characters will break the battle UI.\n\n";
		}

		cin >> namingYesNo;

		if (namingYesNo == "no")  // The option to rename stops working if I use getline() to store the hero's name
		{
			system("cls");
			dotDotDotAnimation();
			cout << " Very well then.";
			this_thread::sleep_for(chrono::seconds(3));
			system("cls");
		}
		else  // The user can only change the name if they say 'no' exactly, input is not case sensitive
		{
			system("cls");
			cout << "Excellent. ";
			this_thread::sleep_for(chrono::milliseconds(2500));
			cout << "Truly ";
			this_thread::sleep_for(chrono::milliseconds(1700));
			cout << "excellent.\n\n";
			this_thread::sleep_for(chrono::milliseconds(2500));

			if (namingYesNo != "yes" && namingYesNo != "no")
			{
				cout << "Though...";
				this_thread::sleep_for(chrono::milliseconds(1700));
				cout << " You seem to have entered something you were not supposed to.";
				this_thread::sleep_for(chrono::seconds(4));
				cout << "\n\nAvoid doing so again. Enter exactly what you are supposed to.";
				this_thread::sleep_for(chrono::seconds(4));
				cout << "\n\nThe enemy does not like mistakes.";  // This line is very important, don't enter letters in battle
				this_thread::sleep_for(chrono::seconds(5));
				system("cls");
			}

			cout << "Now then " << heroName << "...";
			this_thread::sleep_for(chrono::milliseconds(2500));
			cout << "\n\nAre you ready?";
			this_thread::sleep_for(chrono::milliseconds(2500));
			namingLoop = false;
		}
	}

	bool loopAfterGameOver = true;
	bool skipGameOverText = false;
	bool isFightRepeated = false;
	
	int heroLevel = 10;  // The hero's level doesn't do anything, it is just there for the UI

	//   I was considering letting the hero gain a level every time they win, and that would increase their
	//   health and magic points. However, I figured that would take too much time and lines, and players
	//   would likely only win the battle or test the program once, so the feature wouldn't matter.

	while (loopAfterGameOver)  // Allows players to restart the fight if they win or lose
	{
		system("cls");  // Gives an animation to prevent a sudden cut to the fight

		//   Rather than making a lot of ASCII art for this animation, I have a while loop
		//   print a line of '=' 35 times, giving a sliding effect to start the battle

		int introAnimLoopCount = 0;

		while (introAnimLoopCount != 35)
		{
			cout << "===================================================================================\n";
			this_thread::sleep_for(chrono::milliseconds(20));
			introAnimLoopCount++;
		}


		system("cls");
		cout << bossIdle;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "\n\nThe Nightmare Knight Approaches.";
		
		if (isFightRepeated)  // Gives some variation for refights
		{
			cout << ".. ";
			this_thread::sleep_for(chrono::milliseconds(900));
			cout << "Again.";
		}

		cout << "\n\n";
		system("pause");

		if (heroName == altHeroOne)
		{
			system("cls");
			cout << bossIdle << "\n\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "* So, isn't this terrifying?\n\n";
			this_thread::sleep_for(chrono::milliseconds(2500));
			cout << "  I'm terrified, too.\n\n\n";
			system("pause");
		}

		int hitPoints = 300;
		int magicPoints = 120;
		int bossHitPoints = 900;  // Boss HP is not shown in battle, but is used to change boss status and tell when the battle ends
		string bossStatus = "Healthy";

		bool fightGoing = true;
		bool bossAlive = true;
		bool bossChargeAttack = false;
		bool gameOver = false;
		int actionChoice;

		if (heroName == altHeroThree)  // Hard mode. I haven't beaten it, but it's theoretically possible if you're lucky
		{
			hitPoints = 1;
			magicPoints = 0;
			heroLevel = 1;
		}

		if (heroName == strongestHero)  // Easy mode.
		{
			hitPoints = 999;
			magicPoints = 999;
			heroLevel = 20;
		}
		

		while (fightGoing)  // Allows the fight to go back and forth between the hero and boss's turn
		{
			random_device rd;
			system("cls");
			
			cout << bossIdle << "\n======== Name ============= Lvl ===== HP ===== MP ===== Boss Status =======\n=" << setw(75) << "=\n";
			cout << right << "=" << setw(12) << heroName << setw(17) << heroLevel << setw(11) << hitPoints << setw(9) << magicPoints << setw(13) << bossStatus << setw(12) << "=";
			cout << "\n=" << setw(74) << "=" << "\n=========================================================================== ";
			cout << "\nEnter the number for the action you want (Example: '1'):\n";
			cout << "	1. FIGHT       Physically attacks the enemy, dealing damage \n";
			cout << "	2. MAGIC       Magically attacks the enemy, dealing triple damage (40 MP)\n";
			cout << "	3. HEAL        Recovers half of your HP (20 MP)\n";
			cout << "	4. ULTRAHEAL   Recovers all of your HP (35 MP)\n";
			cout << "	5. GUARD       Reduces the damage you take by two-thirds and gain 15 MP\n\nChoice:  ";

			cin >> actionChoice;  // If you input something like '1 4', the first action will happen, the boss gets their turn,
			                      // the second action happen, and the boss will get their second turn without any more inputs.
			                      // Similar to the heroName cin, the action cin breaks when any letter is inputted. (See line 334)

			if (actionChoice == 1)  // Basic attack, does between 50 to 100 damage normally
			{
				mt19937 damageRandom(rd());  // Establishes a random chance, in this case for critical hits, misses, and damage
				mt19937 missChance(rd() + 1);
				uniform_int_distribution<> damageRange(50, 100);
				uniform_int_distribution<> missRange(1, 10);
				int attackDamage = damageRange(damageRandom);
				int attackMiss = missRange(missChance);
				system("cls");
				cout << bossIdle << "\n\n" << heroName << " strikes the enemy!";
				this_thread::sleep_for(chrono::seconds(2));

				if (attackMiss == 1)  // 1 in 10 chance to miss, dealing no damage
				{
					cout << " Barely missed!\n\n";
					this_thread::sleep_for(chrono::milliseconds(1500));
					system("pause");

					//   The chance to miss was originally 1 in 15, but it took me 
					//   over 50 attempts to get it once, so I increased the chance
				}

				else
				{
					system("cls");
					this_thread::sleep_for(chrono::milliseconds(325));
					cout << bossIdle << "\n\n" << heroName << " strikes the enemy! ";

					if (attackMiss == 10)  // 1 in 10 chance to get a critical hit, dealing double damage (100 to 200 damage)
					{
						attackDamage = (attackDamage * 2);
						this_thread::sleep_for(chrono::seconds(1));
						cout << "Critical hit! ";
					}
					this_thread::sleep_for(chrono::seconds(1));
					cout << "Dealt " << attackDamage << " damage!\n\n";
					bossHitPoints = bossHitPoints - attackDamage;
					this_thread::sleep_for(chrono::milliseconds(1500));
					system("pause");
				}
			}

			else if (actionChoice == 2)  // Magic attack, deals between 125 and 300 damage, can't miss or crit, and it uses 40 MP
			{
				mt19937 magicDamageRandom(rd() + 2);
				uniform_int_distribution<> magicDamageRange(125, 300);
				int magicAttackDamage = magicDamageRange(magicDamageRandom);
				system("cls");
				cout << bossIdle << "\n\n" << heroName << " fires a magic beam at the enemy! ";

				if (magicPoints >= 40)  //Ensures that the player has enough MP for the attack, also used for both healing actions
				{
					this_thread::sleep_for(chrono::milliseconds(1500));
					system("cls");
					this_thread::sleep_for(chrono::milliseconds(425));
					cout << bossIdle << "\n\n" << heroName << " fires a magic beam at the enemy! ";
					this_thread::sleep_for(chrono::seconds(1));
					cout << "Dealt " << magicAttackDamage << " damage!\n\n";
					bossHitPoints = bossHitPoints - magicAttackDamage;
					magicPoints = magicPoints - 40;
					system("pause");
				}

				else  // If the player doesn't have enough MP and chooses the action, it gives this dialogue and skips their turn
				{
					this_thread::sleep_for(chrono::seconds(2));
					cout << "Not enough MP!\n\n";
					system("pause");
				}
			}

			else if (actionChoice == 3)  // Basic healing action, heals half health and takes minimal MP
			{
				if (magicPoints >= 20)
				{
					system("cls");
					cout << bossIdle << "\n\nA soft glow surrounds " << heroName << ".\n\n";
					this_thread::sleep_for(chrono::milliseconds(2500));
					cout << "Recovered 150 HP!\n\n";
					hitPoints = hitPoints + 150;

					if (hitPoints > 300 && heroName != strongestHero)  // Prevents healing over max health
					{
						hitPoints = 300;
					}

					magicPoints = magicPoints - 20;
					system("pause");
				}

				else
				{
					system("cls");
					cout << bossIdle << "\n\nNot enough MP!\n\n";
					system("pause");
				}
			}

			else if (actionChoice == 4)  // Upgraded healing, takes 15 more MP, but heals fully
			{
				if (magicPoints >= 35)
				{
					system("cls");
					cout << bossIdle << "\n\nA brilliant glow surrounds " << heroName << "!\n\n";
					this_thread::sleep_for(chrono::milliseconds(2500));
					cout << "HP fully recovered!\n\n";
					hitPoints = 300;
					magicPoints = magicPoints - 35;
					system("pause");
				}

				else
				{
					system("cls");
					cout << bossIdle << "\n\nNot enough MP!\n\n";
					system("pause");
				}
			}

			else if (actionChoice == 5)  // Decreases damage by 2/3 and gains 15 MP
			{
				system("cls");
				cout << bossIdle << "\n\n" << heroName << " is guarding...";
				this_thread::sleep_for(chrono::milliseconds(2500));
				cout << " 15 MP restored!\n\n";
				magicPoints = magicPoints + 15;
				if (magicPoints > 120 && heroName != strongestHero && heroName != altHeroThree)  // Prevents going over max MP
				{
					magicPoints = 120;
				}
				system("pause");
			}

			//      Originally, I was going to have an else statement that would check for an input that isn't 1-5. It would
			//      say something along the lines of "[heroName] tripped!" and then skip your turn. However, when I had someone 
			//      try my program and they entered letters, it caused the boss to take their turn over and over. This was not
			//      intentional, but I felt it was fitting, so I let it be. The enemy still gets their turn if you input a number.

			if (bossHitPoints <= 0)  // Checks if enough damage was dealt to win
			{
				bossDeathAnimation();
				fightGoing = false;
				gameOver = false;
				bossAlive = false;
				system("cls");
				cout << "YOU WON!\n\n";
				this_thread::sleep_for(chrono::seconds(2));
				cout << heroName << " gained 999 exp.\n\n";  // Again, EXP does nothing but give weight to winning
				heroLevel = heroLevel + 1;
				this_thread::sleep_for(chrono::seconds(2));
				system("pause");
			}

			if (bossAlive)  // Checks if the boss is dead or not before it's turn
			{
				if (!bossChargeAttack)  // If the flag for the roar attack isn't active, the turn will go normally
				{
					system("cls");
					mt19937 bossAttackChoice(rd() + 6);  // Picks the boss's attack. Can be a sword slash (1 to 4) or a roar attack (5)
					uniform_int_distribution<> bossAttackRange(1, 5);
					int bossAttack = bossAttackRange(bossAttackChoice);

					if (bossAttack != 5)
					{
						mt19937 bossSwordMissChance(rd() + 7);  // Gives a 1 in 6 chance for the boss to miss
						uniform_int_distribution<> bossSwordMissRange(1, 6);
						int bossSwordMiss = bossSwordMissRange(bossSwordMissChance);
						cout << bossIdle << "\n\nThe Knight swings their sword.\n\n";
						system("pause");
						bossSlashAnimation();

						if (bossSwordMiss != 1)
						{
							mt19937 bossSwordHitDamage(rd() + 8);  // Deals between 60 and 125 damage without guarding
							uniform_int_distribution<> bossSwordDamageRange(60, 125);
							int bossSwordDamage = bossSwordDamageRange(bossSwordHitDamage);
							system("cls");
							this_thread::sleep_for(chrono::milliseconds(325));
							cout << bossSlashEnd;
							this_thread::sleep_for(chrono::seconds(1));

							if (actionChoice == 5)  // While guarding, you take 19 to 41 damage
							{
								cout << "\n\n" << heroName << " is on guard...";
								bossSwordDamage = bossSwordDamage * 0.33333;
								this_thread::sleep_for(chrono::seconds(2));
							}

							cout << "\n\n" << heroName << " took " << bossSwordDamage << " damage.\n\n";
							hitPoints = hitPoints - bossSwordDamage;
							system("pause");
						}

						//   I decided not to give the boss critical hits, as I felt that 
						//   would make the fight too difficult (120 to 250 damage!)

						else
						{
							cout << "\n\nBarely missed!\n\n";
							system("pause");
						}
					}

					else
					{
						system("cls");
						cout << bossWindUp << "\n\nThe Knight prepares a strong attack!\n\n";
						bossChargeAttack = true;
						system("pause");
					}
				}

				else if (bossChargeAttack)  // If the flag for the roar attack is active, the roar attack will occur
				{
					mt19937 bossRoarHitDamage(rd() + 9);  // Deals between 150 and 250 damage while not guarding
					uniform_int_distribution<> bossRoarDamageRange(150, 250);
					int bossRoarDamage = bossRoarDamageRange(bossRoarHitDamage);
					system("cls");
					cout << bossWindUp << "\n\nThe Knight fires a cluster of stars!\n\n";
					system("pause");
					bossRoarAnimation();

					if (actionChoice == 5)  // Deals between 49 and 83 damage while guarding
					{
						cout << "\n\n" << heroName << " is on guard...";
						bossRoarDamage = bossRoarDamage * 0.33333;
						this_thread::sleep_for(chrono::seconds(2));
					}

					cout << "\n\n" << heroName << " took " << bossRoarDamage << " damage!\n\n";
					hitPoints = hitPoints - bossRoarDamage;
					bossChargeAttack = false;
					system("pause");
				}
			}

			if (hitPoints <= 0)  // Checks if the boss did enough damage to defeat the hero
			{
				system("cls");
				cout << heroName << " got hurt and collapsed...\n\n";
				this_thread::sleep_for(chrono::seconds(2));
				cout << heroName << " lost the battle...\n\n";
				fightGoing = false;
				gameOver = true;
				system("pause");
			}
			
			//    I didn't want to directly show the boss's HP in order to mimic
			//    older RPG battles, but I didn't want to not show the boss's HP 
			//    in some way, so I opted for the statuses below (Shows 'Healthy' 
			//    above 700 HP, 'Damaged' between 700 and 501 HP, 'Bruised' 
			//    between 500 and 201 HP, and 'Wounded' between 200 and 1 HP)

			if (bossHitPoints <= 700 && bossHitPoints >= 501)
			{
				bossStatus = "Damaged";
			}
			else if (bossHitPoints <= 500 && bossHitPoints >= 201)
			{
				bossStatus = "Bruised";
			}
			else if (bossHitPoints <= 200 && bossHitPoints >= 1)
			{
				bossStatus = "Wounded";
			}
		}

		if (gameOver)  // Enables if the player's HP reached 0 (or below)
		{
			system("cls");
			cout << gameOverText << "\n\n\n";
			system("pause");

			if (!skipGameOverText)  // Skips the game over dialogue if you lose more than once
			{
				system("cls");
				dotDotDotAnimation();
				cout << " You've met with a terrible fate, ";
				this_thread::sleep_for(chrono::milliseconds(2500));
				cout << "haven't you?";
				this_thread::sleep_for(chrono::milliseconds(2500));
				cout << "\n\nNo need to be shy.";
				this_thread::sleep_for(chrono::seconds(2));
				cout << " I can see the fire in your eyes.";
				this_thread::sleep_for(chrono::seconds(3));
				system("cls");

				if (heroName == altHeroTwo)
				{
					cout << "Now, now, " << heroName << ", there's no need to cry.\n\n";
					this_thread::sleep_for(chrono::seconds(3));
					cout << "After all... ";
					this_thread::sleep_for(chrono::seconds(2));
					cout << "There's no crying until the end.";
					this_thread::sleep_for(chrono::seconds(3));
					system("cls");
				}

				skipGameOverText = true;
			}

			system("cls");
			string continuePlayingChoice;
			cout << "Well? ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << "Would you like to try again?";
			this_thread::sleep_for(chrono::seconds(2));
			cout << " ('yes' or 'no')\n\n";
			cin >> continuePlayingChoice;
			system("cls");

			if (continuePlayingChoice != "yes") 
			{
				dotDotDotAnimation();
				cout << " I understand. ";
				this_thread::sleep_for(chrono::seconds(2));
				cout << "\n\nFarewell then, " << heroName << ".\n\n";
				this_thread::sleep_for(chrono::seconds(2));
				return 0;
			}

			else
			{
				cout << "Then I wish you luck, " << heroName << ".\n\n";
				this_thread::sleep_for(chrono::milliseconds(2500));
				cout << "Are you ready?";
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
		}

		else
		{
			system("cls");
			cout << "So, " << heroName << "...";
			this_thread::sleep_for(chrono::seconds(2));
			cout << " You really did it.";

			if (heroName == altHeroThree)
			{
				this_thread::sleep_for(chrono::seconds(2));
				cout << " A near impossible feat at that.";

				//   I believe hard mode is only possible if the boss 
				//   misses three times in a row (1 in 216 chance)
			}

			this_thread::sleep_for(chrono::seconds(3));
			cout << "\n\nThough, you can try again if you would like.";
			this_thread::sleep_for(chrono::seconds(4));
			system("cls");

			string continuePlayingChoice;
			cout << "Well hero? ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << "Would you like to do it again?";
			this_thread::sleep_for(chrono::seconds(2));
			cout << " ('yes' or 'no')\n\n";
			cin >> continuePlayingChoice;
			system("cls");

			if (continuePlayingChoice != "yes")
			{
				cout << "I understand. ";
				this_thread::sleep_for(chrono::seconds(2));
				cout << "\n\nAfter all, once is enough.";
				this_thread::sleep_for(chrono::seconds(2));
				cout << "\n\nGoodbye, " << heroName << ". ";
				this_thread::sleep_for(chrono::seconds(2));
				cout << "May we meet again someday.\n\n";
				this_thread::sleep_for(chrono::seconds(3));
				return 0;
			}

			else
			{
				cout << "Then I wish you luck again, " << heroName << ".\n\n";
				this_thread::sleep_for(chrono::milliseconds(2500));
				cout << "Are you ready for another round?";
				isFightRepeated = true;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
		}
	}
}