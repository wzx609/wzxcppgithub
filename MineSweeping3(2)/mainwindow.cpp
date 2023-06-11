#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include "dialog.h"
#include "list.cpp"

#include<qlcdnumber.h>
#include<qtimer.h>
#include<qtablewidget.h>
#include<QTableWidgetItem>
#include <QHeaderView>
#include<qactiongroup.h>
#include<qpainter.h>
#include<qpixmap.h>
#include<qlabel.h>
#include<QMouseEvent>
#include<qmessagebox.h>
#include<QTime>
#include<qdebug.h>
#include<QSound>

#define RECT_WIDTH      40//正方形宽
#define RECT_HEIGHT     40//正方形高

#define START_X         25//棋盘起始位置x
#define START_Y         125//棋盘起始位置y

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //把ui界面设置成mainwindow.ui
    ui->setupUi(this);

    this->setWindowTitle("扫雷");

    //设置图片路径
    pic0=QPixmap("://image/0.jpg");
    pic1.load("://image/1.jpg");
    pic2.load("://image/2.jpg");
    pic3.load("://image/3.jpg");
    pic4.load("://image/4.jpg");
    pic5.load("://image/5.jpg");
    pic6.load("://image/6.jpg");
    pic7.load("://image/7.jpg");
    pic8.load("://image/8.jpg");
    picAsk.load("://image/ask.jpg");
    picBlank=QPixmap("://image/blank1.jpg");
    picBlood.load("://image/blood.jpg");
    picError.load("://image/error.jpg");
    picFlag.load("://image/flag.jpg");
    picMine.load("://image/mine.jpg");
    picOoo.load("://image/Ooo.jpg");
    picSmile.load("://image/smile.jpg");

    //一、左上角菜单的绘制，即在左上角菜单栏中显示出“游戏”“功能”“帮助”三个选项
    //并且制作其下级菜单，包括其功能实现
    CreatMenu();

    //二、计时器和雷的计数器和表情的实现

    //初始令sec值为0
    sec = 0;

    //左上角time显示屏的实现
    timelcd = new QLCDNumber(4,this);                             //新创建一个lcdNumber，构造函数中的参数表示它可以显示4位数，this表示了它的父窗口是这个MainWindow
    timelcd->setStyleSheet("color:red;background-color:black"); //设置lcd的外观，设置颜色为红色，背景色为黑色
    timelcd->setFixedSize(140,60);                              //设置lcd的大小为宽140，高60，并且使其不能更改大小
    timelcd->display("0000");                                   //设置lcd最初显示为"0000"

    timer = new QTimer(this);//新建一个QTimer实例，用于计时
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timeplus()));//每次时间达到预计时间后，触发slot函数slot_timeplus，用于将sec自增并显示

    minelcd = new QLCDNumber(4,this);//新创建一个lcdNumber，参数同上
    minelcd->setStyleSheet("color:red;background-color:black");//外观也和上面的lcd一样
    minelcd->setFixedSize(140,60);//设置大小
    minelcd->display("0000");//初始化为"0000"

    emoji = new QLabel(this);//创建一个Label对象，名字为emoji，父窗口为MainWindow
    emoji->setPixmap(picSmile);//设置其显示图片为picSmile
    emoji->setScaledContents(true);//设置其图片会随着Label大小缩放
    emoji->resize(55,55);//重设大小为55,55

    //默认简单模式游戏开始
    row = 9;//设置行为9
    col = 9;//列为9
    mineCount = 10;//雷数为10
    mineRight = 0;//这是旗子是正确的个数
    flagCount = 0;//这是一共插下的旗子数量
    FirstStep = true;//这是判断是否是第一步，如果第一步就踩到了雷，那么就将雷挪到其他位置
    newGame(); //调用函数newGame，开始游戏
}

void MainWindow::CreatMenu()
{
    //在界面的左上角的显示"游戏""功能""帮助"三个菜单以及其下级菜单，用QMenu和QAction来实现
    QMenu *menu1 = new QMenu("游戏",this);//创建
    QMenu *menu2 = new QMenu("功能",this);
    QMenu *menu3 = new QMenu("帮助",this);
    ui->menuBar->addMenu(menu1);
    ui->menuBar->addMenu(menu2);
    ui->menuBar->addMenu(menu3);

    //"游戏"下级菜单
    QAction *reStart = new QAction("重新开始",this);
    QAction *easy = new QAction("简单",this);
    easy->setCheckable(true);//将菜单选项设置成选择类型
    easy->setChecked(true);//设置为默认勾选
    QAction *normal = new QAction("普通",this);
    normal->setCheckable(true);//将菜单选项设置成选择类型
    normal->setChecked(false);//默认不勾选
    QAction *hard = new QAction("困难",this);
    hard->setCheckable(true);//将菜单选项设置成选择类型
    hard->setChecked(false);//默认不勾选
    QAction *diy = new QAction("自定义",this);
    diy->setCheckable(true);//将菜单选项设置成选择类型
    diy->setChecked(false);//默认不勾选
    QAction *quit = new QAction("退出",this);//退出游戏
    connect(quit,SIGNAL(triggered()),qApp,SLOT(quit()));

    QActionGroup *level = new QActionGroup(this);//让四个选项化为一组，同时只能选择一个
    level->addAction(easy);
    level->addAction(normal);
    level->addAction(hard);
    level->addAction(diy);

    menu1->addAction(reStart);//将以下功能加到menu1中
    menu1->addSeparator();
    menu1->addAction(easy);
    menu1->addAction(normal);
    menu1->addAction(hard);
    menu1->addSeparator();//添加一条分隔符，方便美观
    menu1->addAction(diy);
    menu1->addSeparator();//添加一条分隔符，方便美观
    menu1->addAction(quit);

    connect(reStart,SIGNAL(triggered()),this,SLOT(slot_level_reStart()));
    connect(easy,SIGNAL(triggered()),this,SLOT(slot_level_easy()));
    connect(normal,SIGNAL(triggered()),this,SLOT(slot_level_normal()));
    connect(hard,SIGNAL(triggered()),this,SLOT(slot_level_hard()));
    connect(diy,SIGNAL(triggered()),this,SLOT(slot_level_diy()));

    //"功能"下级菜单
    QAction *safe = new QAction("安全模式",this);
    safe->setCheckable(true);
    safe->setChecked(false);
    safeNum = 3;//安全模式的悔棋次数共有三次
    safeOn = false;
    connect(safe,SIGNAL(triggered()),this,SLOT(slot_safeChange()));
    QAction *time = new QAction("计时暂停",this);//计时暂停开关
    time->setCheckable(true);
    time->setChecked(false);
    timeOn = true;
    connect(time,SIGNAL(triggered()),this,SLOT(slot_time()));
    QAction *sound = new QAction("声音开关",this);//声音开关
    sound->setCheckable(true);
    sound->setChecked(true);
    music = true;
    connect(sound,SIGNAL(triggered()),this,SLOT(slot_musicChange()));

    menu2->addAction(safe);//将以下三个选项添加到menu2中
    menu2->addAction(sound);
    menu2->addAction(time);

    //"帮助"下级菜单
    QAction *help = new QAction("扫雷规则",this);
    connect(help,SIGNAL(triggered()),this,SLOT(slot_help()));

    menu3->addAction(help);//将帮助文档添加到menu3中

    bloodPt.setX(-1);//将bloodPT初始化为（-1，-1），预防出错
    bloodPt.setY(-1);
}

void MainWindow::initItems()
{
    //随机初始化 雷
    Mines.clear();
    for(int i = 0;i < mineCount;i++)
    {
        qsrand(QTime::currentTime().msec());
        int x = qrand()%col;//随机取得列数
        int y = qrand()%row;//随机取得行数

        while(Mines.contains(QPoint(x,y)))
        {
            //当已经包含了这个雷 则重新随机生成一个雷
            x = qrand()%col;
            y = qrand()%row;
        }
        Mines.append(QPoint(x,y));
    }
    //建立2维数组保存所有元素位置，方便索引
    for(int i = 0;i < col;i++) //列
    {
        QVector<Item*> rowItems;//Item对象指针的容器
        for(int j = 0;j < row;j++)
        {
            QPoint pos = QPoint(i,j);
            Item* pItem = new Item(pos);
            if(Mines.contains(pos))   //若该位置是雷
            {
                pItem->ismine = true;
            }
            rowItems.append(pItem);
        }
        allpos.append(rowItems);
    }
    //计算格子的数字
    for(int i = 0; i<col; i++)
    {
        for(int j = 0; j<row; j++)
        {
            if (allpos[i][j]->ismine)
            {
                continue;
            }
            int nCountMines = 0;
            //求每个点附近的8个点的是雷的总数，此数字即为该格对应的数字
            for (int m = -1;m <= 1;m++)
            {
                for (int n = -1; n <= 1;n++)
                {
                    if (m == 0 && n == 0)
                    {
                        continue;
                    }
                    QPoint ptNew = QPoint(i+m,j+n);
                    if (!pointInGameArea(ptNew))
                    {
                        continue;
                    }

                    if (allpos[i+m][j+n]->ismine)
                    {
                        nCountMines++;
                    }
                }
            }
            allpos[i][j]->num = nCountMines;
        }
    }
}
//判断鼠标所点击的位置是否位于游戏区域内，在则返回true，否则返回false
bool MainWindow::pointInGameArea(QPoint pt)
{
    if(pt.x() >= 0 && pt.x() < col && pt.y() >= 0&& pt.y() < row)
    {
        return true;
    }
    return false;
}
//界面绘制函数
void MainWindow::drawBoard()
{
    QPainter BoardPainter(this);
    for(int i = 0;i<col;i++)//遍历各个坐标
    {
        for(int j = 0;j<row;j++)
        {
            if(allpos[i][j]->ismark)//针对被标记的格子的绘图操作
            {
                if(allpos[i][j]->isask)//如果该格子被标记且isask为true则绘制picAsk（即问号图片）
                    BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                            ,40,40,picAsk);
                else if(ifover&&allpos[i][j]->ismine==false)//如果游戏结束，并且此格被标记且标记错误，那么绘制picError图片（即带叉的雷）
                    BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                            ,40,40,picError);
                else//其余情况，则绘制旗帜图片
                    BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                            ,40,40,picFlag);
            }
            else if(!allpos[i][j]->isopen)//针对没有打开的格子的绘图操作，若没有打开则绘制picBlank（即遮罩）
                BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                        ,40,40,picBlank);
            else if(allpos[i][j]->ismine)//针对是雷的格子的绘图操作
            {
                if(i == bloodPt.x() && j == bloodPt.y())//如果当前鼠标点击是雷的格子，那么就绘制picBlood（即红色的雷）
                    BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                            ,40,40,picBlood);
                else BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40//其他情况则绘制普通雷
                                             ,40,40,picMine);
            }
            else
            {
                switch(allpos[i][j]->num)//根据当前的格子对应的数字，绘制对应的数字图片
                {
                    case 0:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic0);//0
                        break;
                    case 1:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic1);//1
                        break;
                    case 2:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic2);//2
                        break;
                    case 3:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic3);//3
                        break;
                    case 4:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic4);//4
                        break;
                    case 5:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic5);//5
                        break;
                    case 6:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic6);//6
                        break;
                    case 7:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic7);//7
                        break;
                    case 8:
                        BoardPainter.drawPixmap(START_X+i*40,START_Y+j*40
                                                ,40,40,pic8);//8
                        break;
                }
            }
        }
    }
    QPainter RecPainter(this);
    RecPainter.setPen(QPen(Qt::darkGray,1));
    for(int i = 0;i < col;i++)
    {
        for(int j = 0;j < row;j++)
        {
            QRect Rec=QRect(START_X+i*40,START_Y+j*40,40,40);
            RecPainter.drawRect(Rec);
        }
    }

    this->setFixedSize(START_X+col*RECT_WIDTH+25,START_Y+row*RECT_HEIGHT+25);
    emoji->move((width()-55)/2,50);
    minelcd->move(width()-165,45);
    timelcd->move(25,45);
}
//判断鼠标当前点位是否位于游戏区域之内
bool MainWindow::InGameArea(QPoint pos)
{
    if(pos.x()>=0&&pos.x()<col&&pos.y()>=0&&pos.y()<row)
    {
        return true;//如果在游戏区域之内则返回true
    }
    else
        return false;//如果不在游戏区域内则返回false
}
//鼠标松开emoji就会变回笑脸
void MainWindow::mouseReleaseEvent(QMouseEvent *a)
{
    emoji->setPixmap(picSmile);
    a->x();
}
//鼠标操作
void MainWindow::mousePressEvent(QMouseEvent *a)
{
    emoji->setPixmap(picOoo);//鼠标按下则绘制picOoo图片，即张嘴的脸
    if(First)
    {
        FirstStep=First;
        First=false;
    }
    if(FirstStep&&timeOn)//如果是第一步，并且计时暂停没有开启，那么就以1000毫秒为上限开始计时
        timer->start(1000);
    //取得当前坐标
    QPoint pt;
    pt.setX((a->pos().x()-START_X)/RECT_WIDTH);
    pt.setY((a->pos().y()-START_Y)/RECT_HEIGHT);
    //点到emoji会重新开始
    if(a->pos().x()>=(width()-55)/2&&a->pos().x()<=(width()-55)/2+55)
    {
        if(a->pos().y()>=50&&a->pos().y()<=105&&a->button()==Qt::LeftButton)
        {
            newGame();
            return;
        }
    }
    //判断是否位于游戏区域内，
    if(!InGameArea(pt))
    {
        return;
    }
    Item *m=allpos[pt.x()][pt.y()];//声明一个指向Item类的指针
    //对于未打开的格子，左右键的操作
    if(m->isopen==false)
    {
        //右键点击
        if(a->button()==Qt::RightButton)
        {
            if(m->isask)//如果该格子已经被打上问号
            {
                m->isask=false;//右键后问号取消
                m->ismark=false;//右键后标记取消（由于在绘制时优先绘制问号，所以有可能二者当时都为true）
            }
            else if(m->ismark)//该格子仅被打上标记
            {
                m->isask=true;//让该格子打上问号
                if(m->ismine) mineRight--;//打上问号后，如果该格子是雷，那么就让表示标记正确的数量的变量mineRight减一
                flagCount--;//已经插旗的数量减一
                changeMinelcd();//改变以下右上角计数器显示的雷数
            }
            else
            {
                m->ismark=true;//其余情况则让该格子被标记
                if(m->ismine) mineRight++;//表示标记正确的数量的变量mineRight加一
                flagCount++;//插旗数量加一
                changeMinelcd();//改变以下右上角计数器显示的雷数
            }
        }
        //左键点击
        if(a->button()==Qt::LeftButton&&m->ismark==false)//左键点击且该格子没有被标记
        {
            if(m->ismine==false)//如果这不是雷
                {
                    m->isopen=true;//打开这个格子
                    if(m->num==0)//如果这个格子的数字为0，代表周围没有雷
                    {
                         openNULL(pt);//那么就递归打开周围格子，知道不是0
                    }
                }
            else//如果这个格是雷
            {
                if(FirstStep)//如果这是游戏中第一次点击左键
                {
                    while(true)//那么就在格子的范围内取随机数，知道取到不是雷的格子
                    {
                        int a=qrand()%col;
                        int b=qrand()%row;
                        if(allpos[a][b]->ismine==false)//当这个格子不是雷
                        {
                            QPoint tem(a,b);//创建一个点
                            if(!InGameArea(tem))//判断这个点是否位于游戏区域内
                                continue;//不是则中断本次循环，继续循环
                            allpos[pt.x()][pt.y()]->ismine=false;//如果是那么就让鼠标点击的位置设为不是雷
                            allpos[a][b]->ismine=true;//将随机到的位置设为是雷
                            allpos[pt.x()][pt.y()]->isopen=true;//让鼠标点击的位置打开
                            int TemMineCount=0;//创建一个临时变量，用来记录点击格子的周围的雷数
                            for(int i=pt.x()-1;i<=pt.x()+1;i++)//循环遍历鼠标点击处周围的8个格子
                            {
                                for(int j=pt.y()-1;j<=pt.y()+1;j++)
                                {
                                    if(i==pt.x()&&j==pt.y())//跳过鼠标点击处的格子
                                        continue;
                                    QPoint s(i,j);//判断此格子是否位于游戏区域内（鼠标点击边框的情况，防止越界）
                                    if(InGameArea(s))
                                    {
                                        allpos[i][j]->num--;//让周围格子的数字减一（因为移走了雷）
                                        if(allpos[i][j]->ismine)
                                            TemMineCount++;//如果周围有雷就让该变量加一
                                    }
                                }
                            }
                            allpos[pt.x()][pt.y()]->num=TemMineCount;//将雷移走后的格子的数字设为TemMineCount（即周围的雷数）
                            for(int i=a-1;i<=a+1;i++)//循环遍历被交换的另一个格子周围（即随机取到的一个非雷格）
                            {
                                for(int j=b-1;j<=b+1;j++)
                                {
                                    if(i==a&&j==b)//跳过此格
                                       continue;
                                    QPoint o(i,j);
                                    if(InGameArea(o))//判断是否位于游戏区域内
                                    allpos[i][j]->num++;//让周围的格子数字加一，因为将雷移到了这个位置
                                }
                            }
                            if(allpos[pt.x()][pt.y()]->num==0)//如果是将0与雷进行交换
                                openNULL(pt);//那么就递归打开周围的格子
                            break;//中断循环
                        }
                    }
                    FirstStep=false;//让Firststep为false，只让他在第一步是可以交换
                    return;//终端函数执行
                }
                bloodPt.setX(pt.x());//不是第一次，且踩到雷，绘制踩到雷的图片
                bloodPt.setY(pt.y());

                if(music)//如果声音开关打开
                {
                    QSound *startsound=new QSound("://sound/lose.wav",nullptr);//那么播放失败音乐
                    startsound->play();  //播放
                    startsound->setLoops(0);//循环次数，-1代表一直循环
                }
                if(safeOn&&safeNum>0)//如果当前处于安全模式，且悔棋次数大于0
                {
                    QMessageBox::StandardButton ret;
                    QString safeStr=QString::number(safeNum);//将数字转为字符串
                    ret=QMessageBox::information(this,
                                                 "你踩到了雷，但处于安全模式",
                                                 "你还有"+safeStr+"次机会，是否继续",
                                                 QMessageBox::Yes|QMessageBox::No);//弹出对话框，询问是否继续
                    if(QMessageBox::Yes==ret)
                    {
                        safeNum--;//继续，则让悔棋次数减一
                    }
                    if(QMessageBox::No==ret){
                        releaseItems();//不继续，则释放空间，开始新游戏
                        newGame();
                    }
                }
                else//若不处于安全模式
                {
                    overGame();//游戏结束。显示格子内容
                    QMessageBox::StandardButton ret;
                    timer->stop();//停止计时
                    ret=QMessageBox::information(this,"你踩到了雷，游戏结束！",
                                                 "是否再试一次",
                                                 QMessageBox::Yes|QMessageBox::No);//弹出对话框，询问退出或继续游戏
                    if(QMessageBox::Yes==ret)
                    {
                        First=true;//用于保证第一部不会踩到雷
                        newGame();//继续，则开始新游戏
                    }
                    if(QMessageBox::No==ret){
                        releaseItems();//退出，则释放空间
                        QApplication::quit();//退出游戏
                    }
                }
            }

        }
    }
    if(findAll())//如果游戏胜利
    {

        if(music)//如果打开了音乐开关
        {
            QSound *startsound=new QSound("://sound/win.wav",nullptr);
            startsound->play();  //播放胜利音乐
            startsound->setLoops(0);//循环次数，-1代表一直循环
        }
        overGame();//游戏结束，显示格子的内容
        QMessageBox::StandardButton ret;
        timer->stop();//计时暂停
        ret=QMessageBox::information(this,"你找到了所有的雷！","是否继续？"
                                     ,QMessageBox::Yes|QMessageBox::No);//弹出对话框，询问是否继续游戏或退出游戏
        if(QMessageBox::Yes==ret)
            newGame();//继续，则开始新游戏
        if(QMessageBox::No==ret){
            releaseItems();//不会继续则释放空间，退出游戏
            QApplication::quit();
        }
    }
    FirstStep=false;//让FirstStep为false，只让游戏第一次点击可以避免踩雷
}

void MainWindow::openNULL(QPoint pos)//递归打开0格周围的格子
{
    QPoint b;
    for(int i=pos.x()-1;i<=pos.x()+1;i++)//遍历0格周围的格子
    {
        for(int j=pos.y()-1;j<=pos.y()+1;j++)
        {
            QPoint tempos(i,j);
            if(!InGameArea(tempos))//如果该格子不在游戏范围内，就继续遍历
                continue;
            if(i>=0&&i<col&&j>=0&&j<row&&allpos[i][j]->isopen==false&&allpos[i][j]->ismark==false)//如果该格子没有被打开，并且没有被标记
            {
                allpos[i][j]->isopen=true;//让他打开
                b.setX(i);//将此点的坐标赋给b
                b.setY(j);
                if(allpos[i][j]->num==0)//如果这个点的数值也为0
                openNULL(b);//那么就递归翻开
            }
        }
    }
}

bool MainWindow::findAll()//判断游戏是否胜利
 {
    if(flagCount==mineCount&&mineRight==mineCount)//标记的数量等于标记正确的数量
        return true;

    bool flag=false;
    int opennum=0;//记录打开的格子数量
    for(int i=0;i<allpos.size();i++)//遍历格子
    {
        for(int j=0;j<allpos[i].size();j++)
        {
            if(allpos[i][j]->isopen==true)//如果该格子被打开就让opennum加一
                opennum++;

        }
    }
    if(opennum==row*col-mineCount)//如果打开的格子的数量等于所有格子的个数减去是雷的格子的数量
        flag=true;//那么就代表达到胜利条件，游戏胜利
    return flag;
}

void MainWindow::newGame()//开始新游戏
{
    ifover=false;//让判断游戏是否结束的变量ifover为false
    mineRight=0;//让记录插旗正确的数字为0
    flagCount=0;//让插旗的数字为0
    FirstStep=true;//让判断第一步的变量为true
    timer->stop();//计时暂停
    safeNum=3;//重新设定悔棋次数为3
    emoji->setPixmap(picSmile);//绘制笑脸

    update();//更新界面
    releaseItems();//释放空间
    initItems();//重新加载游戏
    slot_timeclear();//从零开始计时
    MinelcdDisplay();//重新记录雷的数量
}
//游戏结束，让所有的格子打开，显示所有的格子内容
void MainWindow::overGame()
{
    ifover=true;
    for(int i=0;i<allpos.size();i++){
        for(int j=0;j<allpos[i].size();j++){   //！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
            if(allpos[i][j]->ismine==true)
                allpos[i][j]->isopen=true;
            else
            {
                allpos[i][j]->isopen=true;
            }

        }
    }
}

void MainWindow::releaseItems()
{
    //清除所有的指针
    //释放空间
    for (int i=0; i<allpos.size(); i++)
    {
        for (int j=0;j<allpos[i].size(); j++)
        {
            if (allpos[i][j] != nullptr)
            {
                delete allpos[i][j];
                allpos[i][j] = nullptr;
            }
        }
    }
    allpos.clear();
}

//绘制界面
void MainWindow::paintEvent(QPaintEvent *)
{
    drawBoard();

    //刷新游戏画面
    update();
}

void MainWindow::slot_timeplus()//时间加一
{
    sec++;
    QString secstr=QString::number(sec);
    if(secstr.length()==1) secstr="000"+secstr;
    else if(secstr.length()==2) secstr="00"+secstr;
    else if(secstr.length()==3) secstr="0"+secstr;
    this->timelcd->display(secstr);
}

void MainWindow::slot_timeclear()//计时清零
{
    sec=0;
    this->timelcd->display("0000");
}

void MainWindow::MinelcdDisplay()//初始化右上角的雷数
{
    QString minestr=QString::number(mineCount);
    if(minestr.length()==1) minestr="000"+minestr;
    else if(minestr.length()==2) minestr="00"+minestr;
    else if(minestr.length()==3) minestr="0"+minestr;
    minelcd->display(minestr);
}

void MainWindow::changeMinelcd()//每当标记一个雷数减一
{
    if(mineCount-flagCount<0)
    {
        QString minestr=QString::number(flagCount-mineCount);
        if(minestr.length()==1) minestr="-00"+minestr;
        else if(minestr.length()==2) minestr="-0"+minestr;
        else if(minestr.length()==3) minestr="-"+minestr;
        minelcd->display(minestr);
    }
    else
    {
        QString minestr=QString::number(mineCount-flagCount);
        if(minestr.length()==1) minestr="000"+minestr;
        else if(minestr.length()==2) minestr="00"+minestr;
        else if(minestr.length()==3) minestr="0"+minestr;
        minelcd->display(minestr);
    }
}

void MainWindow::slot_time()//计时开关
{
    timeOn=!timeOn;
    if(timer->isActive()) timer->stop();
}

void MainWindow::slot_level_reStart()//重新开始游戏
{
    newGame();
}

void MainWindow::slot_level_easy()//简单难度
{
    col=9;
    row=9;
    mineCount=10;
    newGame();
}

void MainWindow::slot_level_normal()//普通难度
{
    col=16;
    row=16;
    mineCount=40;
    newGame();
}

void MainWindow::slot_level_hard()//困难难度
{
    col=30;
    row=16;
    mineCount=99;
    newGame();
}

void MainWindow::slot_level_diy()//自定义难度
{
    Dialog a(this);
    a.show();
    connect(&a,SIGNAL(getattribute(int,int,int)),this,SLOT(slot_diy_return(int,int,int)));//将信号与槽函数连接
    a.exec();
}

void MainWindow::slot_diy_return(int a,int b,int c)//返回自定义得到的参数，开始新游戏
{
    row=a;
    col=b;
    mineCount=c;
    newGame();
}

void MainWindow::slot_help()//帮助文档
{
    Help a(this);
    a.show();
    a.exec();
}

void MainWindow::slot_musicChange()//音乐开关
{
    music=!music;
}

void MainWindow::slot_safeChange()//安全模式开关
{
    safeOn=!safeOn;
}

MainWindow::~MainWindow()//析构函数
{
    delete ui;
}

