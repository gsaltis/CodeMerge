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
  elementWindow = new ASTElementWindow();
  elementWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ASTDisplayWindow::InitializeSubWindows()
{
  elementWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ASTDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   elementWindowW;
  int                                   elementWindowH;
  int                                   elementWindowY;
  int                                   elementWindowX;
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
  elementWindowX = 0;
  elementWindowY = 0;
  elementWindowW = width;
  elementWindowH = height;
  elementWindow->move(elementWindowX, elementWindowY);
  elementWindow->resize(elementWindowW, elementWindowH);
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
  ASTIndex = clang_createIndex(1, 1);
  TranslationUnit = clang_createTranslationUnit(ASTIndex, ASTFileName.toStdString().c_str());
  if ( NULL == TranslationUnit ) {
    TRACE_FUNCTION_LOCATION();
  }
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
