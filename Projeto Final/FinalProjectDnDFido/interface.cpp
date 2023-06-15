#include "interface.h"

Interface::Interface(QString name,int HP, int ATKbonus,int CA,int Ddice,int Dbonus, QString imagePath,QWidget *parent)
    : QWidget{parent}, _name(name), _total_HP(HP), _hit_bonus(ATKbonus),
    _armor_class(CA), _damage_dice(Ddice), _damage_bonus(Dbonus)
{
    _HP.setText("HP");
    _CA.setText("CA");
    this->setHPValue(HP);
    this->setCAValue(CA);
    _HP_bar.setRange(0, _total_HP);

    QPixmap imagePixmap(imagePath);
    if(imagePixmap.isNull())
        qDebug() << "Failed to load image from " << imagePath;
    else
        qDebug() << "Image loaded successfully from " << imagePath;
    int desiredWidth = 250;  // replace with the width you want
    int desiredHeight = 230;  // replace with the height you want
    _imageLabel.setPixmap(imagePixmap.scaled(desiredWidth, desiredHeight, Qt::KeepAspectRatio));



    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->setStyleSheet("QLabel{color : red; font : bold 24px;}");


    _HP_display.setAlignment(Qt::AlignCenter);
    _name.setAlignment(Qt::AlignCenter);
    _imageLabel.setAlignment(Qt::AlignCenter);
    _HP_bar.setTextVisible(false);

    _layout.addWidget(&_name);
    _layout.addLayout(&_status);
    _status.addWidget(&_HP_display);
    _status.addWidget(&_HP);
    _status.addWidget(&_HP_bar);
    _status.addWidget(&_display_CA);
    _status.addWidget(&_CA);
    _layout.addWidget(&_imageLabel);

    this->setLayout(&_layout);


}

void Interface::setHPValue(int hp) {

    int value = hp;
    if (value<0){
        value = 0;
    }
    _current_HP = value;
    _HP_display.setText(QString::number(value));

    _HP_bar.setValue(this->getCurrentHP());

    emit currentHPChanged(value);
}

void Interface::setCAValue(int ca) {
    int value = ca;
    if (value<5){
        value = 5;
    }
    _armor_class = value;
    _display_CA.setText(QString::number(value));

    emit armorClassChanged(value);
}

void Interface::setDefending(bool status) {
    _defending = status;
}
void Interface::setATKbonus(int value){
    _hit_bonus = value;
}
