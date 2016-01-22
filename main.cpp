#include "customdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomDialog cd;
    cd.show();

    return a.exec();
}

/*
 * Masz tak: włączasz aplikację, masz w comboboxie pustkę i pusty textbox
[11:37:19 AM] Marek Panek: klpeisz coś w textboxie
[11:38:00 AM] Marek Panek: po czym rozwijasz strzałkę w comboboxie  widzisz że jest do wyboru tylko "<Save As>"
[11:38:06 AM] Marek Panek: klikasz to
[11:38:27 AM] Marek Panek: Aplikacja czeka aż użytkownik wprowadzi jakąś nazwę i wciśnie enter
 */
