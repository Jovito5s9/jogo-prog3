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
    int getVida() const;

    void setDano(int dano);
    int getDano() const;

    void setDefesa(int defesa);
    int getDefesa() const;

    void setVelocidade(int velocidade);
    int getVelocidade() const;

    void receberDano(int dano);

    void setJaAtacou(bool atacou);
    bool getJaAtacou() const;
};