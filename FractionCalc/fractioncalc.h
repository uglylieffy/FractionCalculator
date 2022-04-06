#ifndef FRACTIONCALC_H
#define FRACTIONCALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FractionCalc; }
QT_END_NAMESPACE

class FractionCalc : public QMainWindow
{
    Q_OBJECT

public:
    FractionCalc(QWidget *parent = nullptr);
    ~FractionCalc();

private slots:

    void on_exit_clicked();

    void on_add_clicked();

    void on_subtract_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_Lnum_editingFinished();

    void on_Ldenom_editingFinished();

    void on_Rnum_editingFinished();

    void on_Rdenom_editingFinished();

    void on_equal_clicked();

    void on_clear_clicked();

    void on_Lnum_cursorPositionChanged(int arg1, int arg2);

    void on_Ldenom_cursorPositionChanged(int arg1, int arg2);

    void on_Rnum_textChanged(const QString &arg1);

    void on_Rdenom_textChanged(const QString &arg1);

private:
    Ui::FractionCalc *ui;
    QString valid(QString str);
    void refresh();
    void normal(int x, int y);
    int gcdenom(int n, int m);
};
#endif // FRACTIONCALC_H
