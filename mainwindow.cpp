#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>

#include<iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSalva_triggered()
{

       QString filename = QFileDialog::getSaveFileName(this, "Salva file", "C://", tr("Text File (*.txt);;Riched Text File(*rtf);;All File(*);;HTML file(*.html)"));

       QFile file(filename);
       if(!file.open(QFile::WriteOnly | QFile::Text)){
           QMessageBox::warning(this, "Errore", "Impossibile salvare il file!");
       }
       QTextStream out(&file);

       QString text = ui->txt1->toPlainText();
       //file.write(ui->txt1->toMarkdown());
        QTextStream stream(&file);
        out.setEncoding(QStringConverter::Utf8);
        out.setGenerateByteOrderMark(true);
       out << ui->txt1->toHtml();
       file.flush();
       file.close();



    /*QString filedir = QFileDialog::getSaveFileName(this, "Select Location");
    QString content = ui->txt1->toPlainText().toLocal8Bit();
    if(!writeToFile(filedir, content)){
        QMessageBox::warning(this, "Save failed", "Can't acces "+filedir);
        return;
    }*/







}


void MainWindow::on_actionGrassetto_triggered()
{
    QTextCharFormat formato{};
    if(ui->actionGrassetto->isChecked()){
        formato.setFontWeight(QFont::Bold);
    }else{
        formato.setFontWeight(QFont::Normal);
    }

    ui->txt1->setCurrentCharFormat(formato);
}


void MainWindow::on_actionCorsivo_triggered()
{
        QTextCharFormat formato{};
       if(ui->actionCorsivo->isChecked())
           formato.setFontWeight(QFont::Cursive);
       else
           formato.setFontWeight(QFont::Normal);
       ui->txt1->setCurrentCharFormat(formato);
}


void MainWindow::on_actionApri_triggered()
{
    const QString& filename = QFileDialog::getOpenFileName(this, "Apri un File", "C://");
       QFile file(filename);

       if(!file.open(QFile::ReadOnly | QFile::Text)){
           QMessageBox::warning(this, "Errore", "Impossibile aprire il file!");
       }

       QTextStream in(&file);
       QGuiApplication::setOverrideCursor(Qt::WaitCursor);


        //QTextEdit::setHtml(in.readAll());
       //QString text = in.readAll();
       ui->txt1->setHtml(in.readAll());

       file.close();
}

bool MainWindow::writeToFile(QString directory, QString content)
{
    QFile file(directory);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        return false;
    }

    QTextStream outStrem(&file);
    outStrem<<content;
    file.close();
    return true;
}

bool MainWindow::loadFile(const QString &fileName){
    QFile file(fileName);
       if (!file.open(QFile::ReadOnly | QFile::Text)) {
           QMessageBox::warning(this, tr("Notepad"),
                                tr("Cannot read file %1:\n%2.")
                                .arg(fileName)
                                .arg(file.errorString()));
           return false;
       }
       QTextStream in(&file);
       QGuiApplication::setOverrideCursor(Qt::WaitCursor);

       QGuiApplication::restoreOverrideCursor();


       return true;
}

void MainWindow::on_actionRosso_triggered()
{

    QTextEdit* textEdit = ui->txt1;
    textEdit->setTextColor(QColor("red"));
}


void MainWindow::on_actionEsci_triggered()
{
    QCoreApplication::quit();
}


void MainWindow::on_actioninfo_triggered()
{
    QMessageBox::information(this,"Info","TNotepad: A simple notepad write in qt 5.0 and c++\nVersion: 0.0.1");
}


void MainWindow::on_actionBlu_triggered()
{
    QTextEdit* textEdit = ui->txt1;
    textEdit->setTextColor(QColor("blue"));
}


void MainWindow::on_actionVerde_triggered()
{
    QTextEdit* textEdit = ui->txt1;
    textEdit->setTextColor(QColor("green"));
}


void MainWindow::on_actionGiallo_triggered()
{
    QTextEdit* textEdit = ui->txt1;
    textEdit->setTextColor(QColor("yellow"));
}


void MainWindow::on_actionnero_triggered()
{
    QTextEdit* textEdit = ui->txt1;
    textEdit->setTextColor(QColor("black"));
}


void MainWindow::on_actionBianco_triggered()
{
    QTextEdit* textEdit = ui->txt1;
    textEdit->setTextColor(QColor("white"));
}

