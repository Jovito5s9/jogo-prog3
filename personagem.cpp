#include "personagem.h"

Personagem::Personagem(int vida, int dano, int defesa, int velocidade) {
    this->vida = vida;
    this->dano = dano;
    this->defesa = defesa;
    this->velocidade = velocidade;
    this->jaAtacou = false;
}

void Personagem::setDano(int dano) {
    if (dano > 0) {
        this->dano = dano;
    }
}

void Personagem::setDefesa(int defesa) {
    if (defesa > 0) {
        this->defesa = defesa;
    }
}

void Personagem::setVelocidade(int velocidade) {
    if (velocidade > 0) {
        this->velocidade = velocidade;
    }
}

void Personagem::setVida(int vida) {
    if (vida > 0) {
        this->vida = vida;
    }
}

int Personagem::getDano() {
    return dano;
}

int Personagem::getDefesa() {
    return defesa;
}

int Personagem::getVelocidade() {
    return velocidade;
}

int Personagem::getVida() {
    return vida;
}


void Personagem::setJaAtacou(bool atacou) {
    this->jaAtacou = atacou;
}

bool Personagem::getJaAtacou() {
    return jaAtacou;
}

void Personagem::receberDano(int dano) {
    int danoRecebido = dano - defesa;

    if (danoRecebido < 0) {
        danoRecebido = 0;
    }

    vida -= danoRecebido;

    if (vida < 0) {
        vida = 0;
    }
}