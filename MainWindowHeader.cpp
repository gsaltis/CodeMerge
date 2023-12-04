/*****************************************************************************
 * FILE NAME    : MainWindowHeader.cpp
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindowHeader.h"

/*****************************************************************************!
 * Function : MainWindowHeader
 *****************************************************************************/
MainWindowHeader::MainWindowHeader
(QString InText, QWidget* InParent) : QWidget(InParent)
{
  QPalette pal;
  text = InText;
  FontSize = 9;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainWindowHeader
 *****************************************************************************/
MainWindowHeader::~MainWindowHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainWindowHeader::initialize()
{
  StartingColor = QColor(142, 142, 142);
  EndingColor = QColor(240, 240, 240);
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainWindowHeader::CreateSubWindows()
{

  //! Create label  
  TextLabel = new QLabel();
  TextLabel->setParent(this);
  TextLabel->move(0, 0);
  TextLabel->resize(size().width(), size().height());
  TextLabel->setText(text);
  TextLabel->setAlignment(Qt::AlignLeft);
  TextLabel->setIndent(5);
  TextLabel->setFont(QFont("Segoe UI", FontSize, QFont::Normal));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainWindowHeader::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainWindowHeader::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  TextLabel->resize(width, height);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
MainWindowHeader::paintEvent
(QPaintEvent* )
{
  QPainter                              painter(this);
  QSize                                 s;
  QLinearGradient                       grad;

  s = size();

  grad.setStart(QPoint(0, 0));
  grad.setFinalStop(QPoint(0, size().height()));
  grad.setColorAt(0, StartingColor);
  grad.setColorAt(1, EndingColor);
  painter.setBrush(QBrush(grad));
  painter.setPen(QPen(QColor(StartingColor)));
  painter.drawRect(QRect(QPoint(0, 0), s));
}

/*****************************************************************************!
 * Function : SetColors
 *****************************************************************************/
void
MainWindowHeader::SetColors
(QColor InStartingColor, QColor InEndingColor)
{
  StartingColor = InStartingColor;
  EndingColor = InEndingColor;
  repaint();
}

/*****************************************************************************!
 * Function : GetFontSize
 *****************************************************************************/
int
MainWindowHeader::GetFontSize(void)
{
  return FontSize;  
}

/*****************************************************************************!
 * Function : SetFontSize
 *****************************************************************************/
void
MainWindowHeader::SetFontSize
(int InFontSize)
{
  FontSize = InFontSize;  
  TextLabel->setFont(QFont("Segoe UI", FontSize, QFont::Normal));
}

/*****************************************************************************!
 * Function : SetText
 *****************************************************************************/
void
MainWindowHeader::SetText
(QString InText)
{
  text = InText;
  TextLabel->setText(text);
}
