#include "customdialog.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QInputDialog>

CustomDialog::CustomDialog()
{
    label = new QLabel(tr("&Tekst"));
    lineEdit = new QLineEdit;
    comboBox = new QComboBox;

    label->setBuddy(lineEdit);
    comboBox->setDuplicatesEnabled(false);
    comboBox->setInsertPolicy(QComboBox::InsertBeforeCurrent);
    comboBox->insertItem(comboBox->count(), tr(""));
    comboBox->insertItem(comboBox->count(), tr("<Save as>"));

    connect(comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &CustomDialog::itemWasChosen);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(comboBox);

    setLayout(layout);

    qDebug() << comboBox->insertPolicy();
}

void CustomDialog::itemWasChosen(int index)
{
    comboBox->disconnect();
    if (comboBox->count()-1 == index) // this is the last item in ComboBox, so it's Save As
    {
        qDebug() << "ADD item: " << lineEdit->text();
        bool ok = false;
        QString text = QInputDialog::getText(this, tr("Save as..."), tr("Save text as:"),QLineEdit::Normal, tr("new name"), &ok);
        if (ok && !text.isEmpty())
            comboBox->insertItem(comboBox->count()-1, text,lineEdit->text());
    }
    else
    {
        if (comboBox->itemData(index) == QVariant::Invalid)
            lineEdit->setText(comboBox->itemText(index));
        else
            lineEdit->setText(comboBox->itemData(index).toString());
    }
    connect(comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &CustomDialog::itemWasChosen);
}
