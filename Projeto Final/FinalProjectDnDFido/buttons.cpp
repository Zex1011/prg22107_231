#include "buttons.h"

buttons::buttons(QWidget *parent) : QWidget(parent)
{
    this->setLayout(&_hud);

    // Add widgets/layouts to the layouts
    _hud.addLayout(&_acoes);
    _acoes.addWidget(&_itens);
    _acoes.addLayout(&_inti_atac);
    _inti_atac.addWidget(&_intimidar);
    _inti_atac.addWidget(&_atacar);
    _acoes.addWidget(&_defender);

    // Set button texts
    int with = 100;
    int heigh = 40;
//    _itens.setText("Itens");
    _itens.setIcon(QIcon(":/Boleadeira.png"));
    _itens.setIconSize(QSize(with, heigh));
    _itens.setFixedSize(QSize(with, heigh));

//    _intimidar.setText("Intimidar");
    _intimidar.setIcon(QIcon(":/Intimidar.png"));
    _intimidar.setIconSize(QSize(with, heigh));
    _intimidar.setFixedSize(QSize(with, heigh));
//    _atacar.setText("Atacar");
    _atacar.setIcon(QIcon(":/Atacar.png"));
    _atacar.setIconSize(QSize(with, heigh));
    _atacar.setFixedSize(QSize(with, heigh));
//    _defender.setText("Defender");
    _defender.setIcon(QIcon(":/Defender.png"));
    _defender.setIconSize(QSize(with, heigh));
    _defender.setFixedSize(QSize(with, heigh));

    // Connect signals and slots
    connect(&_itens, &QPushButton::clicked, this, &buttons::onItensClicked);
    connect(&_intimidar, &QPushButton::clicked, this, &buttons::onIntimidarClicked);
    connect(&_atacar, &QPushButton::clicked, this, &buttons::onAtacarClicked);
    connect(&_defender, &QPushButton::clicked, this, &buttons::onDefenderClicked);
}

void buttons::setButtonsEnabled(bool enabled) {
    _itens.setEnabled(enabled);
    _intimidar.setEnabled(enabled);
    _atacar.setEnabled(enabled);
    _defender.setEnabled(enabled);
}

void buttons::onItensClicked()
{
    emit actionChosen(Action::Itens);
}

void buttons::onIntimidarClicked()
{
    emit actionChosen(Action::Intimidar);
}

void buttons::onAtacarClicked()
{
    emit actionChosen(Action::Atacar);
}

void buttons::onDefenderClicked()
{
    emit actionChosen(Action::Defender);
}
