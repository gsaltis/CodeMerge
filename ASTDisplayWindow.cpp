/*****************************************************************************
 * FILE NAME    : ASTDisplayWindow.cpp
 * DATE         : December 04 2023
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
#include "ASTDisplayWindow.h"

/*****************************************************************************!
 * Function : ASTDisplayWindow
 *****************************************************************************/
ASTDisplayWindow::ASTDisplayWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(253, 242, 233)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ASTDisplayWindow
 *****************************************************************************/
ASTDisplayWindow::~ASTDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ASTDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ASTDisplayWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ASTDisplayWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ASTDisplayWindow::resizeEvent
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
 * Function : GetASTFileName
 *****************************************************************************/
QString
ASTDisplayWindow::GetASTFileName(void)
{
  return ASTFileName;  
}

/*****************************************************************************!
 * Function : SetASTFileName
 *****************************************************************************/
void
ASTDisplayWindow::SetASTFileName
(QString InASTFileName)
{
  ASTFileName = InASTFileName;  
}

/*****************************************************************************!
 * Function : SlotCompileSuccess
 * Purpose  : Pass AST Compile Success Message
 *****************************************************************************/
void
ASTDisplayWindow::SlotCompileSuccess
(QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  TRACE_FUNCTION_QSTRING(InASTPath);
}
