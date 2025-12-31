#include "titlepage.h"
#include "page.h"

TitlePage::TitlePage(QWidget *parent) : Page(parent,nullptr),ui(new Ui::TitlePage)
{
 ui->setupUi(this);
 Page::setPageFinished();//C'est la page de titre alors elle est directement terminée
}
