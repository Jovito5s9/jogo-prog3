class Personagem {

private:
    int vida;
    int dano;
    int defesa;
    int velocidade;
    bool jaAtacou;

public: 

    Personagem(int vida, int dano, int defesa, int velocidade);

    void setVida(int vida);
    int getVida();

    void setDano(int dano);
    int getDano();

    void setDefesa(int defesa);
    int getDefesa();

    void setVelocidade(int velocidade);
    int getVelocidade();

    void receberDano(int dano);

    void setJaAtacou(bool atacou);
    bool getJaAtacou();
};