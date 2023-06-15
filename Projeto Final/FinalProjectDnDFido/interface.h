#ifndef INTERFACE_H
#define INTERFACE_H


#include <QObject>
#include <QtWidgets>
#include <string>


class Interface : public QWidget
{
        Q_OBJECT
    public:
        explicit Interface(QString name,int HP,int ATKbonus,int CA,int Ddice,int Dbonus,QString imagePath,QWidget *parent = nullptr);

        int getCurrentHP() const { return _current_HP; }
        int getCA() const { return _armor_class; }
        int getATK() const { return _hit_bonus; }
        int getDice() const { return _damage_dice; }
        int getBonus() const { return _damage_bonus; }
        int getDefending()  const { return _defending; }
        int getTotalHP()  const { return _total_HP; }
        void setATKbonus(int value);
        void setDefending(bool value);

    public slots:
        void setHPValue(int value);
        void setCAValue(int value);



    signals:
        void currentHPChanged(int);
        void armorClassChanged(int);


    private:
        QVBoxLayout _layout;
        QHBoxLayout _status;
        QLabel      _HP_display;
        QLabel      _name;
        QLabel      _HP;
        QProgressBar _HP_bar;
        QLabel      _CA;
        QLabel      _display_CA;
        QLabel      _imageLabel;


        int         _armor_class;//
        int         _hit_bonus;//
        int         _total_HP;//
        int         _current_HP;//
        int         _damage_dice;//
        int         _damage_bonus;//
        bool        _defending = false;//




};

#endif // INTERFACE_H
