#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // provides the main application window

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>             // must have printsupport enabled in the .pro file (QT       += core gui printsupport)
#include <QPrintDialog>         // must have printsupport enabled in project file

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    // Base class for QT objects. Handles events. Executes on its own thread.

public:
    explicit MainWindow(QWidget *parent = nullptr); // = nullptr states that this widget has no parent
    ~MainWindow();  // destructor

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;
    QString current_file = "";
};

#endif // MAINWINDOW_H
