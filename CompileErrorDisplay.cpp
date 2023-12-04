/*****************************************************************************
 * FILE NAME    : CompileErrorDisplay.cpp
 * DATE         : December 04 2023
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
#include "CompileErrorDisplay.h"

/*****************************************************************************!
 * Function : CompileErrorDisplay
 *****************************************************************************/
CompileErrorDisplay::CompileErrorDisplay
() : QTextEdit()
{
  BackgroundColor = QColor(52, 82, 105);
  TextColor = QColor(255, 255, 0);
  setStyleSheet("QTextEdit { background-color : rgb(52, 82, 105); }");
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~CompileErrorDisplay
 *****************************************************************************/
CompileErrorDisplay::~CompileErrorDisplay
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
CompileErrorDisplay::initialize()
{
  setTextBackgroundColor(BackgroundColor);
  setTextColor(TextColor);
}

/*****************************************************************************!
 * Function : SlotErrorMessage
 *****************************************************************************/
void
CompileErrorDisplay::SlotErrorMessage
(QString InErrorMessage)
{
  setPlainText(InErrorMessage);
}
