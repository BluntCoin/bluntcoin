#include "miningcalculator.h"
#include "ui_miningcalculator.h"

#include <QString>

MiningCalculator::MiningCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiningCalculator)
{
    ui->setupUi(this);

    connect(ui->rentalCostBox, SIGNAL(valueChanged(double)), this, SLOT(updateBreakevenLabel()));
    connect(ui->coinPriceBox, SIGNAL(valueChanged(double)), this, SLOT(updateBreakevenLabel()));

    connect(ui->coinPriceBox, SIGNAL(valueChanged(double)), this, SLOT(updateProfitLabel()));
    connect(ui->coinsMinedField, SIGNAL(valueChanged(double)), this, SLOT(updateProfitLabel()));

    connect(ui->rentalCostBox, SIGNAL(valueChanged(double)), this, SLOT(updateCostPer()));
    connect(ui->megaHashesField, SIGNAL(valueChanged(double)), this, SLOT(updateCostPer()));

    connect(ui->coinsMinedField, SIGNAL(valueChanged(double)), this, SLOT(updateCoinsPer()));
    connect(ui->megaHashesField, SIGNAL(valueChanged(double)), this, SLOT(updateCoinsPer()));
}

MiningCalculator::~MiningCalculator()
{
    delete ui;
}

void MiningCalculator::updateBreakevenLabel()
{
    ui->breakevenLabel->clear();
    ui->breakevenLabel->setNum(ui->rentalCostBox->value() / ui->coinPriceBox->value());
}

void MiningCalculator::updateProfitLabel()
{
    ui->profitLabel->clear();
    ui->profitLabel->setNum(ui->coinsMinedField->value() * ui->coinPriceBox->value() - ui->rentalCostBox->value());
}

void MiningCalculator::updateCostPer()
{
    ui->costPerMhLabel->clear();
    ui->costPerMhLabel->setNum(ui->rentalCostBox->value() / ui->megaHashesField->value());
}

void MiningCalculator::updateCoinsPer()
{
    ui->coinsPerMh->clear();
    ui->coinsPerMh->setNum(ui->coinsMinedField->value() / ui->megaHashesField->value());
}
