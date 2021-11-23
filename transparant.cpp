#include "transparant.h"
#include "ui_transparant.h"

Transparant::Transparant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transparant)
{
    ui->setupUi(this);
}

Transparant::~Transparant()
{
    delete ui;
}
