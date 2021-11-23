#ifndef TRANSPARANT_H
#define TRANSPARANT_H

#include <QWidget>

namespace Ui {
class Transparant;
}

class Transparant : public QWidget
{
    Q_OBJECT

public:
    explicit Transparant(QWidget *parent = nullptr);
    ~Transparant();

private:
    Ui::Transparant *ui;
};

#endif // TRANSPARANT_H
