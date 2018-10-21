#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :       // constructor
    QMainWindow(parent),    // calls parent contructor
    ui(new Ui::MainWindow)  // creates the ui class and assigns to the ui member variable
{
    ui->setupUi(this);  // sets up user interface for us
    this->setCentralWidget(ui->textEdit);   // central widget is the widget that will occupy the whole screen
}

MainWindow::~MainWindow()       // destructor; destroy the ui
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    current_file.clear();
    ui->textEdit->setText(QString());   // creates a new file for us to work with inside the application
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    current_file = filename;
    // Check for errors
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in_file(&file);
    QString text = in_file.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");   // Opens up dialog box for user
    QFile file(filename);   // creates object used for reading and writing files
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    current_file = filename;    // save file name
    setWindowTitle(filename);
    QTextStream out_file(&file);
    QString text = ui->textEdit->toPlainText();
    out_file << text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;   // allows to interact with any printer that is on our network
    printer.setPrinterName("Printer Name");
    QPrintDialog p_dialog(&printer, this);            // create a dialog that the user can use to select the printer they want to use
    if (p_dialog.exec() == QDialog::Rejected) {         // verify that we could connect to the printer
        QMessageBox::warning(this, "Warning", "Cannot access printer.");
        return;
    }
    ui->textEdit->print(&printer);                      // send text to printer to print
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();                               // closes application
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
