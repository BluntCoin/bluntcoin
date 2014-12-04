#ifndef MININGCALCULATOR_H
#define MININGCALCULATOR_H

#include <QWidget>

namespace Ui {
class MiningCalculator;
}

class MiningCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit MiningCalculator(QWidget *parent = 0);
    ~MiningCalculator();

private:
    Ui::MiningCalculator *ui;

private slots:
    void updateProfitLabel();
    void updateBreakevenLabel();
    void updateCostPer();
    void updateCoinsPer();
};



#endif // MININGCALCULATOR_H
