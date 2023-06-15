#ifndef DND_ENCOUNTER_H
#define DND_ENCOUNTER_H


#include <QtWidgets>
#include <QPalette>
#include <QPixmap>
#include "interface.h"
#include "buttons.h"

enum class GameState {
    PlayerTurn,
    EnemyTurn,
    GameOver
};



QT_BEGIN_NAMESPACE
namespace Ui { class DnD_encounter; }
QT_END_NAMESPACE

class DnD_encounter :   public QWidget
{
    Q_OBJECT


public:
    DnD_encounter(QWidget *parent = nullptr);
    ~DnD_encounter();


private slots:
    void handleAction(Action action);

private:
    QVBoxLayout _layout;//1
    QHBoxLayout _combate;//2
    Interface _player;//3
    Interface _enemy;//3
    QHBoxLayout _hud;//2
    buttons _acoes;//3
    QTextEdit _log;//3

    GameState currentState = GameState::PlayerTurn;
    void updateGameState();
};
#endif // DND_ENCOUNTER_H
