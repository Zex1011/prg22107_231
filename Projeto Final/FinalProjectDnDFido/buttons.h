#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QPushButton>

enum class Action {
    Itens,
    Intimidar,
    Atacar,
    Defender
};

class buttons : public QWidget
{
        Q_OBJECT
    public:
        explicit buttons(QWidget *parent = nullptr);

    signals:
        void actionChosen(Action action);

    public slots:
        void onItensClicked();
        void onIntimidarClicked();
        void onAtacarClicked();
        void onDefenderClicked();
        void setButtonsEnabled(bool enabled);

    private:
        QHBoxLayout _hud;//2
        //caixa_de_texto log;//3
        QVBoxLayout _acoes;//3
        QPushButton _itens;//4
        QHBoxLayout _inti_atac;//4
        QPushButton _intimidar;//5
        QPushButton _atacar;//5
        QPushButton _defender;//4
};


#endif // BUTTONS_H
