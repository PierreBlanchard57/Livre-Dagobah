#include "endpage.h"

EndPage::EndPage(QWidget *parent) : Page(parent,nullptr),ui(new Ui::EndPage)
{
 ui->setupUi(this);
 Page::setPageFinished();//C'est la page de fin alors elle est directement terminée
}
void EndPage::enableSound(){}
void EndPage::disableSound(){}
EndPage::~EndPage(){delete ui;}
