#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <vector>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->view_combobox->setEnabled(false);
    ui->on_graph_combobox->setEnabled(false);
    ui->off_graph_combobox->setEnabled(false);

    QStringList mode_cb_items;
    mode_cb_items.push_back("Single");
    mode_cb_items.push_back("Multi");
    ui->mode_combobox->addItems(mode_cb_items);

    QStringList on_graph_cb_items;
    on_graph_cb_items.push_back("SMA");
    on_graph_cb_items.push_back("EMA");
    ui->on_graph_combobox->addItems(on_graph_cb_items);

    QStringList off_graph_cb_items;
    off_graph_cb_items.push_back("RSI");
    off_graph_cb_items.push_back("MACD");
    ui->off_graph_combobox->addItems(off_graph_cb_items);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mode_go_push_button_clicked()
{
    ui->view_combobox->setEnabled(true);
    ui->on_graph_combobox->setEnabled(true);
    ui->off_graph_combobox->setEnabled(true);

    ui->view_combobox->clear();

    QStringList view_cb_items;
    view_cb_items.push_back("Mid");
    if (ui->mode_combobox->currentText() == "Single")
    {
        view_cb_items.push_back("Bid/Ask");
        view_cb_items.push_back("OHLC");
    }
    ui->view_combobox->addItems(view_cb_items);
}

void MainWindow::on_start_refresh_button_clicked()
{

}
