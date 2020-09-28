#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pointgenerator.h"
#include "plot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

class QBoxLayout;
class QPushButton;
class QGraphicsScene;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QBoxLayout *m_rootLayout;
    QBoxLayout *m_buttonsLayout;
    QPushButton *m_playButton;
    QPushButton *m_pauseButton;
    QPushButton *m_stopButton;

    Plot *m_plot;

    PointGenerator *m_pointGenerator;
};
#endif // MAINWINDOW_H
