#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "item.h"

#include <QMainWindow>
#include <qlcdnumber.h>
#include <qtimer.h>
#include <qpainter.h>
#include <qlabel.h>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //绘制图形
    void paintEvent(QPaintEvent *);
    //游戏棋盘的绘制
    void drawBoard();
    //左上角菜单栏的绘制
    void CreatMenu();
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *a);
    //是否点击到棋盘内
    bool InGameArea(QPoint pos);
    //递归翻开
    void openNULL(QPoint pos);
    //雷是否全部找到
    bool findAll();
    //开始新游戏
    void newGame();
    //结束游戏并显示雷
    void overGame();
    //初始化游戏
    void initItems();
    //右上角雷数显示屏
    void changeMinelcd();
    //雷数显示屏初始化
    void MinelcdDisplay();
    //鼠标释放函数
    void mouseReleaseEvent(QMouseEvent *a);
    bool pointInGameArea(QPoint pt);
    void releaseItems();



public slots://与计时相关的槽函数
    void slot_timeplus();
    void slot_time();
    void slot_timeclear();
    //开关声音
    void slot_musicChange();
    //开关安全模式
    void slot_safeChange();
    void slot_level_reStart();
    void slot_level_easy();
    void slot_level_normal();
    void slot_level_hard();
    void slot_level_diy();
    void slot_diy_return(int a,int b,int c);
    //游戏帮助显示
    void slot_help();

private:
    Ui::MainWindow *ui;

    int row;//行数
    int col;//列数
    int mineCount;//雷数
    int mineRight;//标记正确的数量
    int flagCount;//标记数
    int safeNum;//安全模式剩余悔棋次数

    bool ifover;//判断游戏是否结束
    bool FirstStep;//判断是否为第一步
    bool First;//判断是否为第一步
    bool music;//判断声音开关是否打开
    bool press;//判断是否按下
    bool safeOn;//判断是否处于安全模式
    bool timeOn;//判断计时开关是否打开

    QPoint bloodPt;//用来传回踩到雷的点的坐标
    QVector<QVector<Item*>> allpos;//动态数组，记录所有的点
    QVector<QPoint> Mines;//记录所有雷

    //以下为计时器和emoji所需变量
    int sec;
    QLCDNumber *timelcd;
    QTimer *timer;
    QLCDNumber *minelcd;
    QLabel *emoji;
    //以下为图片
    QPixmap pic0;
    QPixmap pic1;
    QPixmap pic2;
    QPixmap pic3;
    QPixmap pic4;
    QPixmap pic5;
    QPixmap pic6;
    QPixmap pic7;
    QPixmap pic8;
    QPixmap picMine;
    QPixmap picFlag;
    QPixmap picBlank;
    QPixmap picAsk;
    QPixmap picBlood;
    QPixmap picError;
    QPixmap picOoo;
    QPixmap picSmile;

};
#endif // MAINWINDOW_H
