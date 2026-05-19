#include <iostream>
#include "personagem.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>

void printStatus(const std::string& nome, const Personagem& personagem) {
    std::cout << "+------------------------------------------------+" << std::endl;
    std::cout << "| " << nome << std::endl;
    std::cout << "+------------------------------------------------+" << std::endl;
    std::cout << "| Vida:       " << personagem.getVida() << std::endl;
    std::cout << "| Dano:       " << personagem.getDano() << std::endl;
    std::cout << "| Defesa:     " << personagem.getDefesa() << std::endl;
    std::cout << "| Velocidade: " << personagem.getVelocidade() << std::endl;
    std::cout << "+------------------------------------------------+" << std::endl;
}

int selectplayer(const std::vector<Personagem>& listaHerois) {
    int escolha;
    
    do {
        std::cout << "\nEscolha um personagem para atacar o monstro:" << std::endl;

        std::cout << "1. Guerreiro";
        if (listaHerois[0].getVida() > 0) {
            std::cout << " - Vida: " << listaHerois[0].getVida();
        } else {
            std::cout << " - MORTO";
        }
        std::cout << std::endl;

        std::cout << "2. Mago";
        if (listaHerois[1].getVida() > 0) {
            std::cout << " - Vida: " << listaHerois[1].getVida();
        } else {
            std::cout << " - MORTO";
        }
        std::cout << std::endl;

        std::cout << "3. Arqueiro";
        if (listaHerois[2].getVida() > 0) {
            std::cout << " - Vida: " << listaHerois[2].getVida();
        } else {
            std::cout << " - MORTO";
        }
        std::cout << std::endl;

        std::cout << "Digite o número do personagem: ";
        std::cin >> escolha;
    } while (escolha < 1 || escolha > 3 || listaHerois[escolha - 1].getVida() <= 0);

    return escolha;
}

int main(){
    
    char enter;
    unsigned seed = time(0);
    srand(seed);

    Personagem guerreiro(80, 50, 8, 5);
    Personagem mago(45, 65, 2, 5);
    Personagem arqueiro(60, 40, 4, 7);
    std::vector<Personagem> listaHerois{guerreiro, mago, arqueiro};

    Personagem monstro(rand() % 100 + 100, rand() % 80 + 1, rand() % 10 + 10, rand() % 4 + 3);

    std::cout << "\n================= MONSTRO =================" << std::endl;
    printStatus("Monstro", monstro);
    std::cout << "\n=============== HEROIS DISPONIVEIS ===============" << std::endl;
    printStatus("Guerreiro", listaHerois[0]);
    printStatus("Mago", listaHerois[1]);
    printStatus("Arqueiro", listaHerois[2]);

    bool jogoAtivo = true;
    bool jogoGanho = false;
    int playerAtual;
    playerAtual = selectplayer(listaHerois);

    do{
        if(monstro.getVelocidade() > listaHerois[playerAtual - 1].getVelocidade()){
            std::cout << "O monstro ataca primeiro!" << std::endl;
            listaHerois[playerAtual - 1].receberDano(monstro.getDano());
            std::cout << "Vida do " << (playerAtual == 1 ? "Guerreiro" : playerAtual == 2 ? "Mago" : "Arqueiro") << ": " << listaHerois[playerAtual - 1].getVida() << std::endl;

            sleep(1);
            std::cout << " sua vez. Pessione Enter para atacar..." << std::endl;
            std::cin >> enter;
            monstro.receberDano(listaHerois[playerAtual - 1].getDano());
        } 
        
        else {
            std::cout << "Você ataca primeiro!" << std::endl;
            sleep(1);
            std::cout << "Pessione Enter para atacar..." << std::endl;
        std::cin >> enter;
            monstro.receberDano(listaHerois[playerAtual - 1].getDano());
            std::cout << "Vida do Monstro: " << monstro.getVida() << std::endl;

            std::cout << "O monstro vai atacar agora!" << std::endl;
            listaHerois[playerAtual - 1].receberDano(monstro.getDano());
            std::cout << "Vida do " << (playerAtual == 1 ? "Guerreiro" : playerAtual == 2 ? "Mago" : "Arqueiro") << ": " << listaHerois[playerAtual - 1].getVida() << std::endl;
        }


        if(listaHerois[playerAtual -1].getVida()<=0){
            std::cout << "O " << (playerAtual == 1 ? "Guerreiro" : playerAtual == 2 ? "Mago" : "Arqueiro") << " morreu!" << std::endl;
            playerAtual = selectplayer(listaHerois);
        }

        if (guerreiro.getVida() <= 0 && mago.getVida() <= 0 && arqueiro.getVida() <= 0) {
            std::cout << "Todos os personagens morreram. Você perdeu!" << std::endl;
            jogoAtivo = false;
            break;
        } else if (monstro.getVida() <= 0) {
            std::cout << "O monstro foi derrotado. Você ganhou!" << std::endl;
            jogoAtivo = false;
            jogoGanho = true;
            break;
        }

        sleep(1);
        std::cout << "Fim do turno. Pessione Enter para continuar..." << std::endl;
        std::cin >> enter;
    
    } while (jogoAtivo);
    
    
    return 0;


}