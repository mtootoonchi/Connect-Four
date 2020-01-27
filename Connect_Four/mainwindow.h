#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TopNode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TopNode* root;
    char Board[6][7];
    bool RedGo;
    bool ComputerRed;
    short whichMode; // 0 is Human, 1 is AI Easy, 2 is AI Impossible
    void CreateGameBoard(ofstream& SaveFile);
    bool isParam(string line);
    short whichSaveFile;
    void AIhardPick();
    void AIeasyPick();
    bool checkWin(short WWin);
    bool Drop(short loc);
    void Dropped(short loc);
    short WhoWin(short location);
    short goLeft(short row, short col);
    short goRight(short row, short col);
    short goDown(short row, short col);
    short goUpRight(short row, short col);
    short goUpLeft(short row, short col);
    short goDownRight(short row, short col);
    short goDownLeft(short row, short col);

private slots:
    void LoadSaveFile1();
    void NewSaveFile1();
    void DeleteSaveFile1();
    void LoadSaveFile2();
    void NewSaveFile2();
    void DeleteSaveFile2();
    void LoadSaveFile3();
    void NewSaveFile3();
    void DeleteSaveFile3();
    void goBack();
    void HumanMode();
    void ArtificialIntelligenceMode();
    void EasyMode();
    void ImpossibleMode();
    void RedMode();
    void YellowMode();
    void CreateSaveFile();
    void Drop0();
    void Drop1();
    void Drop2();
    void Drop3();
    void Drop4();
    void Drop5();
    void Drop6();
    void PlayAgain();
    void Exit();
};
#endif // MAINWINDOW_H
