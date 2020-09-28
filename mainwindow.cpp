#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_plot(new Plot(this)),
      m_pointGenerator(new PointGenerator(this->width()))
{
    ui->setupUi(this);

    m_rootLayout = new QVBoxLayout(ui->centralwidget);

    m_rootLayout->addWidget(m_plot);

    m_buttonsLayout = new QHBoxLayout;

    m_playButton = new QPushButton(tr("PLAY"), this);
    connect(m_playButton, &QPushButton::clicked, m_pointGenerator, &PointGenerator::play, Qt::QueuedConnection);
    m_buttonsLayout->addWidget(m_playButton);

    m_pauseButton = new QPushButton(tr("PAUSE"), this);
    connect(m_pauseButton, &QPushButton::clicked, m_pointGenerator, &PointGenerator::pause, Qt::QueuedConnection);
    m_buttonsLayout->addWidget(m_pauseButton);

    m_stopButton = new QPushButton(tr("STOP"), this);
    connect(m_stopButton, &QPushButton::clicked, m_pointGenerator, &PointGenerator::stop, Qt::QueuedConnection);
    connect(m_stopButton, &QPushButton::clicked, m_plot, &Plot::clear);
    m_buttonsLayout->addWidget(m_stopButton);

    m_rootLayout->addLayout(m_buttonsLayout);


    connect(m_pointGenerator, &PointGenerator::generatedPoint, m_plot, &Plot::drawPoint);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_pointGenerator->stop();
    m_pointGenerator->deleteLater();
}

