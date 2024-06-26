#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <QLabel>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *cr = new QLabel(this);
    cr->setText("®Ablameyko");
    cr->setGeometry(0, 300, 300, 300);
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Coefficients File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }

    std::ifstream inputFile(fileName.toStdString());
    if (!inputFile) {
        QMessageBox::critical(this, tr("Error"), tr("Error opening file!"));
        return;
    }

    ComplexNumber a, b, c;
    inputFile >> a >> b >> c;
    inputFile.close();

    auto roots = solveQuadratic(a, b, c);
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::black);
    scene->addLine(0,90,180,90,pen);//x
    scene->addLine(90,0,90,180,pen);//y
    ui->graphicsView->setScene(scene);
    double a1,b1,c1,d1;
    a1 =0;
    b1 =0;
    c1 =roots.first.real;
    d1 =roots.first.imagenary;
    QPen pen2(Qt::red);//Карандаш для графика
    scene->addLine(a1*15+90,90-b1*15,c1*15+90,90-d1*15,pen2);


    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_2_clicked()
{    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Coefficients File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }

    std::ifstream inputFile(fileName.toStdString());
    if (!inputFile) {
        QMessageBox::critical(this, tr("Error"), tr("Error opening file!"));
        return;
    }

    ComplexNumber a, b, c;
    inputFile >> a >> b >> c;
    inputFile.close();

    auto roots = solveQuadratic(a, b, c);
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::black);
    scene->addLine(0,90,180,90,pen);//x
    scene->addLine(90,0,90,180,pen);//y
    ui->graphicsView->setScene(scene);
    double a1,b1,c1,d1;
    a1 =0;
    b1 =0;
    c1 =roots.second.real;
    d1 =roots.second.imagenary;
    QPen pen2(Qt::red);//Карандаш для графика
    scene->addLine(a1*15+90,90-b1*15,c1*15+90,90-d1*15,pen2);

    ui->graphicsView->setScene(scene);
}


void MainWindow::on_lineEdit_editingFinished()
{

}


void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    QString text = QString("%1 %2 года, %3 часов %4 минут %5 секунд").arg(QLocale().toString(dateTime.date(), QStringLiteral("d MMMM"))).arg(QLocale().toString(dateTime.date(), QStringLiteral("yyyy"))).arg(QLocale().toString(dateTime.time(), QStringLiteral("h"))).arg(QLocale().toString(dateTime.time(), QStringLiteral("m"))).arg(QLocale().toString(dateTime.time(), QStringLiteral("s")));
    ui->lineEdit->setText(text);
}

