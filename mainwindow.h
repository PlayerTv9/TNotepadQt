#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QObject>
#include <QMainWindow>
#include <QMdiArea>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSalva_triggered();

    void on_actionGrassetto_triggered();

    void on_actionCorsivo_triggered();

    void on_actionApri_triggered();

    void on_actionRosso_triggered();

    void on_actionEsci_triggered();

    void on_actioninfo_triggered();

private:
    Ui::MainWindow *ui;

    bool writeToFile(QString directory, QString content);
    bool loadFile(const QString &fileName);
};
#endif // MAINWINDOW_H
