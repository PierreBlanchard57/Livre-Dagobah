#include "luketrainpage.h"
#include "page.h"
LukeTrainPage::LukeTrainPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::LukeTrainPage)
{
ui->setupUi(this);
connect(ui->unlock,&QPushButton::clicked,this,[=](){
mainWindow->unlockNextPage();
});
}

void LukeTrainPage::unlock(){
        mainWindow->unlockNextPage();
}
