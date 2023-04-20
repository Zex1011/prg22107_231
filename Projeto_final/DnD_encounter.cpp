//============================================================================
// Name        : DnD_encounter.cpp
// Author      : Jose Fidelis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice(int numDice = 1, int sides = 20, int bonus = 0)
{
    int total = bonus;
    for (int i = 0; i < numDice; i++)
    {
        total += (rand() % sides) + 1;
    }
    return total;
}
class bag{

};
class creature{
	//bonus base de ataque
	int bba;
	//dado de vida
	int HD;
	//arma (espada longa(1), espada/escudo(2), espada/adaga(3) ou espada/adaga(4))
	int WP;
	//class de armadura
	int CA;
	//status
	int stg; //força
	int dex; //destreza
	int con; //constituição
	bag inventario;

};





int main()
{
    srand(time(NULL)); // random seed

    bool restart_config = true;

    while (restart_config) {
        Configuration configs;
        configs.run(); // run the configuration before the game loop

        bool restart_encounter = false;

        do {
            Combat encounter(configs); // create a new encounter with the configuration

            while (!encounter.get_winner()) { // game loop
                encounter.next_turn();
            }

            std::cout << "The winner is " << encounter.get_winner() << std::endl;

            // pergunta se o jogador deseja o mesmo encontro
            std::string answer;
            do {
                std::cout << "Deseja repetir o combate(y/n)? ";
                std::cin >> answer;
            } while (answer != "y" && answer != "n");

            if (answer == "y") {
                restart_encounter = true;
            }
        } while (restart_encounter);

        // pergunta se o jogador deseja repetir com uma nova configuração
        std::string answer;
        do {
            std::cout << "Deseja um desafio diferente(y/n)? ";
            std::cin >> answer;
        } while (answer != "y" && answer != "n");

        if (answer != "y") {
            restart_config = false;
        }
    }

    return 0;
}
