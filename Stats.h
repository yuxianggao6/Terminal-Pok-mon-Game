class Stats{
    public:
    int HP;
    int attack;
    int defense;
    int spAtk;
    int spDef;
    int speed;

    public:
    Stats();
    Stats(int HP, int attack, int defense, int spAtk, int spDef,int speed);
    Stats(const Stats& other);
};