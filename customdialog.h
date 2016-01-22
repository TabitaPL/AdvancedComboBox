#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

class CustomDialog : public QDialog
{
    Q_OBJECT

public:
    CustomDialog();

private:
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;

public slots:
    void itemWasChosen(int index);
};

#endif // CUSTOMDIALOG_H
