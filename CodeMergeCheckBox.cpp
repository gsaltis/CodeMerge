/*****************************************************************************
 * FILE NAME    : CodeMergeCheckBox.cpp
 * DATE         : December 03 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <trace_winnetqt.h>
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CodeMergeCheckBox.h"

/*****************************************************************************!
 * Function : CodeMergeCheckBox
 *****************************************************************************/
CodeMergeCheckBox::CodeMergeCheckBox
(QWidget* InParent) : QWidget(InParent)
{
  StartingColor = QColor(157, 183, 229);
  EndingColor = QColor(88, 104, 128);
  
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~CodeMergeCheckBox
 *****************************************************************************/
CodeMergeCheckBox::~CodeMergeCheckBox
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
CodeMergeCheckBox::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
CodeMergeCheckBox::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
CodeMergeCheckBox::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
CodeMergeCheckBox::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : SetChecked
 *****************************************************************************/
void
CodeMergeCheckBox::SetChecked
(bool InChecked)
{
  Checked = InChecked;
}

/*****************************************************************************!
 * Function : GetChecked
 *****************************************************************************/
bool
CodeMergeCheckBox::GetChecked(void)
{
  return Checked;
}

/*****************************************************************************!
 * Function : mousePressed
 *****************************************************************************/
void
CodeMergeCheckBox::mousePressed
(QMouseEvent* InEvent)
{
  Qt::KeyboardModifiers                 mods;
  Qt::MouseButton                       button;

  button = InEvent->button();
  mods = InEvent->modifiers();

  if ( mods != Qt::NoModifier ) {
    return;
  }
  if ( button == Qt::LeftButton ) {
    Checked = !Checked;
    repaint();
  }
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
CodeMergeCheckBox::paintEvent
(QPaintEvent* )
{
  QLinearGradient                       grad;
  QColor                                color2;
  QColor                                color1;
  int                                   height;
  QSize                                 s;
  QPainter                              painter(this);

  s = size();
  height = s.height();

  color1 = QColor(255, 128, 128);
  color2 = QColor(128, 64, 64);

  if ( Checked ) {
    color1 = StartingColor;
    color2 = EndingColor;
  }
  grad.setStart(QPoint(0, 0));
  grad.setFinalStop(QPoint(0, height));
  grad.setColorAt(0, color1);
  grad.setColorAt(1, color2);
  
  painter.setPen(QColor(0, 0, 0));
  painter.setBrush(QBrush(grad));
  painter.drawRect(QRect(QPoint(0, 0), s));
}
