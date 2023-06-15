#include "dnd_encounter.h"
#include "dice.h"

DnD_encounter::DnD_encounter(QWidget *parent)
    : QWidget(parent),
    _player("Cassius", 30, 4, 16, 8, 3, ":/player.png"),
    _enemy("Vroc", 40, 3, 14, 10, 4, ":/enemy.png")
    //nome, HP, bonusROLL, CA, dado, bonusDMG

{
    srand(time(0));

    _log.setReadOnly(true);
    _log.setFixedWidth(300);

    _layout.addLayout(&_combate);
    _combate.addWidget(&_player);
    _combate.addWidget(&_enemy);


    _layout.addLayout(&_hud);
    _hud.addWidget(&_acoes);
    _hud.addWidget(&_log);

    this->setLayout(&_layout);

    this->setFixedSize(QSize(600, 400));
    QPixmap backgroundImage(":/background.png"); // replace with your image file name
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(backgroundImage));
    this->setPalette(palette);



    connect(&_acoes, &buttons::actionChosen, this, &DnD_encounter::handleAction);

}

void DnD_encounter::updateGameState() {
    int damage;
    int roll;
    float hpPercent;
    bool def;

    switch(currentState) {
    case GameState::PlayerTurn:
        // Enable the buttons
        if (_player.getDefending() == true){
            _player.setCAValue(_player.getCA()-3);
            _player.setDefending(false);
        }
        _acoes.setButtonsEnabled(true);
        break;


    case GameState::EnemyTurn:
        // Disable the buttons
        _acoes.setButtonsEnabled(false);

        if (_enemy.getDefending() == true){
            _enemy.setCAValue(_enemy.getCA()-3);
            _enemy.setDefending(false);
        }


        hpPercent = static_cast<float>(_enemy.getCurrentHP()) / _enemy.getTotalHP() * 100;
        def = (rand() % 100 > hpPercent);


        if (def){
            _log.append("O Vroc está se defendendo!!!");
            _enemy.setCAValue(_enemy.getCA()+3);
            _enemy.setDefending(true);
            }
        else{
            _log.append("O Vroc ataca com, suas garras...");
            roll = dice::roll(1, 20, _enemy.getATK());
            if (roll>=_player.getCA())
            {
                damage = dice::roll(1, _enemy.getDice(), _enemy.getBonus());
                _player.setHPValue(_player.getCurrentHP()-damage);
                _log.append(QString::number(roll)+ " Ele acerta!!! Causando um dano de " +QString::number(damage));
            }
            else{
                _log.append(QString::number(roll)+ " Ele erra!!!");
                if(_player.getDefending()){
                    damage = dice::roll(1, _player.getDice(), _player.getBonus());
                    _enemy.setHPValue(_enemy.getCurrentHP()-damage);
                    _log.append("E recebe um contra ataque de: " +QString::number(damage));
                }
            }
        }


        // When enemy turn ends
        if (_player.getCurrentHP()>0){
            currentState = GameState::PlayerTurn;
        }
        else{
            _log.append("VOCÊ PERDEU!!!");
        }
        updateGameState();
        break;

    case GameState::GameOver:
        // Handle game over
        // ...
        break;
    }

}

DnD_encounter::~DnD_encounter()
{

}


void DnD_encounter::handleAction(Action action) {

    switch(action) {
    case Action::Itens:{
        // Handle "Itens" action
        _log.append("Que item utilizará?");
        currentState = GameState::EnemyTurn;

        break;
    }

    case Action::Intimidar:{
        // Handle "Intimidar" action
        _log.append("Você tenta intimidar e...");
        if ((_enemy.getCurrentHP()<(_enemy.getTotalHP()*0.3))&&(rand() % 2)){
            _enemy.setHPValue(0);
            _log.append("O Vroc se rende!!!");
        }
        else if ((_enemy.getCurrentHP()<(_enemy.getTotalHP()*0.7))&&(rand() % 2)){
                _enemy.setCAValue(_enemy.getCA()-2);
                _enemy.setATKbonus(_enemy.getATK()-1);
                _log.append("O Vroc fica desestabilizado! -2 CA, -1 Acerto");
        }
        else {
            _log.append("A intimidação falhou.");
        }

        if (_enemy.getCurrentHP()>0){
            currentState = GameState::EnemyTurn;
        }
        else{
            _log.append("VOCÊ GANHOU!!!");
            currentState = GameState::GameOver;
        }



        break;
    }

    case Action::Atacar:{
        // Handle "Atacar" action
        _log.append("Você vai atacar, e...");
        int roll = dice::roll(1, 20, _player.getATK());

        if (roll>=_enemy.getCA())
        {
            int damage = dice::roll(1, _enemy.getDice(), _enemy.getBonus());
            _enemy.setHPValue(_enemy.getCurrentHP()-damage);
            _log.append(QString::number(roll) + " Você acerta!!! Causando um dano de "+QString::number(damage));
        }
        else{
            _log.append(QString::number(roll) + " Você erra!!!");
                if(_enemy.getDefending()){
                _player.setHPValue(_player.getCurrentHP()-_enemy.getBonus());
                _log.append("E recebe um contra ataque de: " +QString::number(_enemy.getBonus()));
                }
        }

        currentState = GameState::EnemyTurn;

        if (_enemy.getCurrentHP()>0){
            currentState = GameState::EnemyTurn;
        }
        else{
            _log.append("VOCÊ GANHOU!!!");
            currentState = GameState::GameOver;
        }

        break;
    }

    case Action::Defender:{
        // Handle "Defender" action
        _log.append("Você se defente! +3 CA, +Ataque Preparado");

        _player.setCAValue(_player.getCA()+3);
        _player.setDefending(true);

        currentState = GameState::EnemyTurn;

        break;
    }
    }
    updateGameState();
}

