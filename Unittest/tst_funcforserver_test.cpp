#include <QtTest>
#include "C:\Users\vertk\Downloads\1\1\server\task2.h"
#include "C:\Users\vertk\Downloads\1\1\server\task1.h"


// add necessary includes here

class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();

private slots:
    void test_case1();
    void test_case2();

};

FuncForServer_Test::FuncForServer_Test()
{

}

FuncForServer_Test::~FuncForServer_Test()
{

}

void FuncForServer_Test::test_case1()
{

    double res1 = secant("0", "2", "4", "sin(x)");
    double value1 = 4.94066e-324;
    QVERIFY2 ( res1 == value1  ,"task_1_false");
}
void FuncForServer_Test::test_case2()
{
    bool res2 = gg("1:2:1;2:1:1;1:3:1;3:1:1;2:5:1;5:2:1;2:6:1;6:2:1;2:7:1;7:2:1;3:4:1;4:3:1;3:5:1;5:3:1;3:6:1;6:3:1;4:6:1;6:4:1;4:7:1;7:4:1;5:6:1;6:5:1;5:7:1;7:5:1;6:7:1;7:6:1;", "1:2:5:3:1", 7);
    bool value2 = true;
    QVERIFY2 ( res2 == value2  ,"task_2_false");
}



QTEST_APPLESS_MAIN(FuncForServer_Test)

#include "tst_funcforserver_test.moc"
