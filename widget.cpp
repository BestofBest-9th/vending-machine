#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(this->money);
    ui->pbTea->setEnabled(this->money);
    ui->pbMilk->setEnabled(this->money);
}

widget::~widget()
{
    delete ui;
}


void widget::changeMoney(int coin)
{

    money += coin;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(this->money >=100);
    ui->pbTea->setEnabled(this->money >=150);
    ui->pbMilk->setEnabled(this->money >=200);

}

void widget::on_pb10_clicked()
{
    changeMoney(10);
}

void widget::on_pb50_clicked()
{
    changeMoney(50);
}

void widget::on_pb100_clicked()
{
    changeMoney(100);
}

void widget::on_pb500_clicked()
{
    changeMoney(500);
}

void widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void widget::on_pbReset_clicked()
{
    QMessageBox m;
    const int numCoin = 4;
    int coin[numCoin] = {500, 100, 50, 10};
    int chargeNum[numCoin]={0};
    int charge = money;
    
    for(int i=0;i<numCoin;i++){
        chargeNum[i]=charge/coin[i];
        charge = charge % coin[i];
    }
    money = 0;
    changeMoney(money);
    ui->lcdNumber->display(money);

    m.information(nullptr, "charge", QString("500 : %1, 100 : %2, 50 : %3, 10 : %4\n").arg(chargeNum[0]).arg(chargeNum[1]).arg(chargeNum[2]).arg(chargeNum[3]));
}
